#include <QCoreApplication>
#include <QCommandLineParser>
#include <QFile>
#include <QRegularExpression>
#include <QDebug>

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
#define SHITTY_UBUNTU_QT
#endif

namespace {
// will be called for each modbus table on the page
QString processTable(QString content)
{
    auto lines = content.split(QChar{'\n'});

    QList<QStringList> rows;
    for (QString &line : lines)
    {
        line = line.trimmed();
        if (line.isEmpty())
            continue;
        if (line.startsWith(QChar{'|'}))
            line.remove(0, 1);
        if (line.endsWith(QChar{'|'}))
            line.chop(1);
        QStringList row;
        for (QString &part : line.split(QChar{'|'}))
            row << part.trimmed();
        rows << std::move(row);
    }

    QStringList columnNames;
    if (!rows.isEmpty())
    {
        auto row = rows.takeFirst();
        columnNames = std::move(row);
    }

    if (!rows.isEmpty())
    {
        // ignoring | ---- | row
        rows.removeFirst();
    }

    const QRegularExpression setAddrExpr{"\\<!-- MODBUS-SET-ADDR: ([0-9]+) --\\>"};
    const QRegularExpression skipAddrExpr{"\\<!-- MODBUS-SKIP-ADDR: ([0-9]+) --\\>"};

    int address{30001};
    for (auto &row : rows)
    {
        if (!row.isEmpty())
        {
            const auto &first = row.first();
            if (const auto &match = setAddrExpr.match(first); match.hasMatch())
            {
                bool ok{};
                int newAddress = match.captured(1).toInt(&ok);
                if (ok)
                    address = newAddress;
                else
                    qWarning() << "invalid set-addr opcode:" << match.captured(0);
                continue;
            }
            else if (const auto &match = skipAddrExpr.match(first); match.hasMatch())
            {
                bool ok{};
                int addressOffset = match.captured(1).toInt(&ok);
                if (ok)
                    address += addressOffset;
                else
                    qWarning() << "invalid skip-addr opcode:" << match.captured(0);
                continue;
            }
        }

        if (row.size() < 1)
        {
            qWarning() << "register addr missing";
            continue;
        }
        if (row.size() < 2)
        {
            qWarning() << "register type missing";
            continue;
        }
        if (row.size() < 3)
        {
            qWarning() << "register datatype missing";
            continue;
        }

        int registers;

        if (const auto &type = row.at(2); type == "Float32")
            registers = 2;
        else if (type == "Float64")
            registers = 4;
        else if (type == "Int16")
            registers = 1;
        else if (type == "UInt16")
            registers = 1;
        else if (type == "Int32")
            registers = 2;
        else if (type == "UInt32")
            registers = 2;
        else if (type == "Int64")
            registers = 4;
        else if (type == "UInt64")
            registers = 4;
        else
        {
            qWarning() << "unknown register type" << type;
            continue;
        }

        QString addr;
        for (int i = 0; i < registers; i++)
        {
            if (!addr.isEmpty())
                addr += " <br /> ";
            addr += QString("%0 (%1)").arg(address++).arg(address > 40000 ? address-40002 : (address > 30000 ? address-30002 : -1));
        }
        row[0] = addr;
    }

    QVector<int> columnWidths;
    for (const auto &row : rows)
    {
#ifdef SHITTY_UBUNTU_QT
        // shitty ubuntu version of Qt doesnt have .resize()
        while (columnWidths.size() < row.size())
            columnWidths << 0;
#else
        if (columnWidths.size() < row.size())
            columnWidths.resize(row.size(), 0);
#endif
        int i{};
        for (const auto &cell : row)
        {
            const auto currentI = i++;
            if (columnWidths[currentI] < cell.size())
                columnWidths[currentI] = cell.size();
        }
    }

    {
#ifdef SHITTY_UBUNTU_QT
        // shitty ubuntu version of Qt doesnt have .resize()
        while (columnWidths.size() < columnNames.size())
            columnWidths << 0;
#else
        if (columnWidths.size() < columnNames.size())
            columnWidths.resize(columnNames.size(), 0);
#endif

        int i{};
        for (const auto &cell : columnNames)
        {
            const auto currentI = i++;
            if (columnWidths[currentI] < cell.size())
                columnWidths[currentI] = cell.size();
        }
    }

    QString result;

    constexpr const auto makeCell = [](auto str, int minWidth, QChar fill = {' '}) -> QString {
        QString result;
        result += str;
        while (result.size() < minWidth)
            result.append(fill);
        return result;
    };

    result += "| ";
    for (int i = 0; i < columnWidths.size(); i++)
    {
        if (i > 0)
            result += " | ";
        if (columnNames.size() > i)
            result += makeCell(columnNames[i], columnWidths[i], QChar{' '});
        else
            result += makeCell("??", columnWidths[i], QChar{' '});
    }
    result += " |\n";

    result += "| ";
    for (int i = 0; i < columnWidths.size(); i++)
    {
        if (i > 0)
            result += " | ";
        result += makeCell("-", columnWidths[i], QChar{'-'});
    }
    result += " |\n";

    for (const auto &row : rows)
    {
        result += "| ";
        for (int i = 0; i < columnWidths.size(); i++)
        {
            if (i > 0)
                result += " | ";
            if (row.size() > i)
                result += makeCell(row[i], columnWidths[i], QChar{' '});
            else
                result += makeCell("", columnWidths[i], QChar{' '});
        }
        result += " |\n";
    }

    return result;
}
}

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationDomain("go-e.com");
    QCoreApplication::setOrganizationName("go-e");
    QCoreApplication::setApplicationName("docshelper");

    QCoreApplication app{argc, argv};

    QCommandLineParser parser;
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("markdown-file", QCoreApplication::translate("main", "Markdown file to edit."));

    if (!parser.parse(app.arguments()))
    {
        qFatal("could not parse arguments: %s", qPrintable(parser.errorText()));
        return -1;
    }

    const auto &positionalArguments = parser.positionalArguments();
    if (positionalArguments.isEmpty())
    {
        qFatal("argument for file missing");
        return -2;
    }

    const auto &fileName = positionalArguments.first();

    QString content;

    QFile file{fileName};
    if (!file.open(QIODevice::ReadWrite))
    {
        qFatal("could not open input file: %s", qPrintable(file.errorString()));
        return -3;
    }

    content = file.readAll();

    if (!file.seek(0))
    {
        qFatal("could not seek to begin: %s", qPrintable(file.errorString()));
        return -4;
    }

    while (true)
    {
        qsizetype index;

        {
            constexpr std::string_view modbusTableBegin = "<!-- MODBUS TABLE BEGIN -->\n";
#ifdef SHITTY_UBUNTU_QT
            // shitty ubuntu version of Qt doesnt provide QByteArrayView
            index = content.indexOf(QString::fromUtf8(modbusTableBegin.data(), modbusTableBegin.size()));
#else
            index = content.indexOf(QString::fromUtf8(QByteArrayView{modbusTableBegin}));
#endif
            if (index == -1)
                break;

            index += modbusTableBegin.size();
        }

        if (auto asByteArray = content.left(index).toUtf8(); !asByteArray.isEmpty())
        {
            if (const auto written = file.write(asByteArray); written != asByteArray.size())
            {
#ifdef SHITTY_UBUNTU_QT
                // shitty ubuntu version of Qt uses int for array lengths
                qFatal("written!=size %lli %i", written, asByteArray.size());
#else
                qFatal("written!=size %lli %lli", written, asByteArray.size());
#endif
                return -5;
            }
        }

#ifdef SHITTY_UBUNTU_QT
        // shitty ubuntu version of Qt doesnt provide std api to manipulate containers
        content.remove(0, index);
#else
        content.erase(std::begin(content), std::begin(content) + index);
#endif

        constexpr std::string_view modbusTableEnd = "<!-- MODBUS TABLE END -->";
#ifdef SHITTY_UBUNTU_QT
        // shitty ubuntu version of Qt doesnt provide QByteArrayView
        index = content.indexOf(QString::fromUtf8(modbusTableEnd.data(), modbusTableEnd.size()));
#else
        index = content.indexOf(QString::fromUtf8(QByteArrayView{modbusTableEnd}));
#endif
        if (index == -1)
        {
            qWarning() << "table end missing";
            break;
        }

        if (auto asByteArray = processTable(content.left(index)).toUtf8(); !asByteArray.isEmpty())
        {
            if (const auto written = file.write(asByteArray); written != asByteArray.size())
            {
#ifdef SHITTY_UBUNTU_QT
                // shitty ubuntu version of Qt uses int for array lengths
                qFatal("written!=size %lli %i", written, asByteArray.size());
#else
                qFatal("written!=size %lli %lli", written, asByteArray.size());
#endif
                return -6;
            }
        }

#ifdef SHITTY_UBUNTU_QT
        // shitty ubuntu version of Qt doesnt provide std api to manipulate containers
        content.remove(0, index);
#else
        content.erase(std::begin(content), std::begin(content) + index);
#endif
    }

    if (auto asByteArray = content.toUtf8(); !asByteArray.isEmpty())
    {
        if (const auto written = file.write(asByteArray); written != asByteArray.size())
        {
#ifdef SHITTY_UBUNTU_QT
            // shitty ubuntu version of Qt uses int for array lengths
            qFatal("written!=size %lli %i", written, asByteArray.size());
#else
            qFatal("written!=size %lli %lli", written, asByteArray.size());
#endif
            return -7;
        }
    }

    if (file.size() > file.pos())
    {
        if (!file.resize(file.pos()))
        {
            qFatal("could not resize (shrink) file: %s", qPrintable(file.errorString()));
            return -8;
        }
    }

//    if (!file.rename(fileName))
//    {
//        qFatal("could not rename generated file: %s", qPrintable(file.errorString()));
//        return -9;
//    }

    return 0;
}
