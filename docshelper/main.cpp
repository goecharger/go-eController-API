#include <QCoreApplication>
#include <QCommandLineParser>
#include <QFile>

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

    for (auto &row : rows)
    {
        int registers{};
        if (row.size() > 2)
        {
            if (const auto &type = row.at(2); type == "Float32")
                registers = 2;
            else if (type == "Float64")
                registers = 4;
            else
                qWarning() << "unknown register type" << type;
        }
        else
            qWarning() << "register type missing";
    }

    QVector<int> columnWidths;
    for (const auto &row : rows)
    {
        if (columnWidths.size() < row.size())
            columnWidths.resize(row.size(), 0);
        int i{};
        for (const auto &cell : row)
        {
            const auto currentI = i++;
            if (columnWidths[currentI] < cell.size())
                columnWidths[currentI] = cell.size();
        }
    }

    {
        if (columnWidths.size() < columnNames.size())
            columnWidths.resize(columnNames.size(), 0);

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

    for (int i = 0; i < columnWidths.size(); i++)
    {
        if (i > 0)
            result += " | ";
        if (columnNames.size() > i)
            result += makeCell(columnNames[i], columnWidths[i], QChar{' '});
        else
            result += makeCell("??", columnWidths[i], QChar{' '});
    }

    result += "\n";

    for (int i = 0; i < columnWidths.size(); i++)
    {
        if (i > 0)
            result += " | ";
        result += makeCell("-", columnWidths[i], QChar{'-'});
    }

    result += "\n";

    for (const auto &row : rows)
    {
        qDebug() << row;
        for (int i = 0; i < columnWidths.size(); i++)
        {
            if (i > 0)
                result += " | ";
            if (row.size() > i)
                result += makeCell(row[i], columnWidths[i], QChar{' '});
            else
                result += makeCell("", columnWidths[i], QChar{' '});
        }
        result += "\n";
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

    QString content;

    {
        QFile file{positionalArguments.first()};
        if (!file.open(QIODevice::ReadOnly))
        {
            qFatal("could not open input file: %s", qPrintable(file.errorString()));
            return -3;
        }

        content = file.readAll();
    }

    QFile file{positionalArguments.first() + ".tmp"};
    if (!file.open(QIODevice::WriteOnly))
    {
        qFatal("could not open output file: %s", qPrintable(file.errorString()));
        return -4;
    }

    while (true)
    {
        qsizetype index;

        {
            constexpr std::string_view modbusTableBegin = "<!-- MODBUS TABLE BEGIN -->\n";
            index = content.indexOf(QString::fromUtf8(QByteArrayView{modbusTableBegin}));
            if (index == -1)
                break;

            index += modbusTableBegin.size();
        }

        if (auto asByteArray = content.left(index).toUtf8(); !asByteArray.isEmpty())
        {
            if (const auto written = file.write(asByteArray); written != asByteArray.size())
            {
                qFatal("written!=size %lli %lli", written, asByteArray.size());
                return -5;
            }
        }

        content.erase(std::begin(content), std::begin(content) + index);

        constexpr std::string_view modbusTableEnd = "<!-- MODBUS TABLE END -->";
        index = content.indexOf(QString::fromUtf8(QByteArrayView{modbusTableEnd}));
        if (index == -1)
        {
            qWarning() << "table end missing";
            break;
        }

        if (auto asByteArray = processTable(content.left(index)).toUtf8(); !asByteArray.isEmpty())
        {
            if (const auto written = file.write(asByteArray); written != asByteArray.size())
            {
                qFatal("written!=size %lli %lli", written, asByteArray.size());
                return -6;
            }
        }

        content.erase(std::begin(content), std::begin(content) + index);
    }

    if (auto asByteArray = content.toUtf8(); !asByteArray.isEmpty())
    {
        if (const auto written = file.write(asByteArray); written != asByteArray.size())
        {
            qFatal("written!=size %lli %lli", written, asByteArray.size());
            return -7;
        }
    }

//    if (file.size() > file.pos())
//    {
//        if (!file.resize(file.pos()))
//        {
//            qFatal("could not resize (shrink) file: %s", qPrintable(file.errorString()));
//            return -8;
//        }
//    }

    return 0;
}
