#include <QCoreApplication>
#include <QCommandLineParser>
#include <QFile>

namespace {
int i = 0;
// will be called for each modbus table on the page
QString processTable(QString content)
{
    qDebug() << content;
    return QString("<!-- TODO %0 -->\n").arg(i++);
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

    QFile file{positionalArguments.first()};
    if (!file.open(QIODevice::ReadWrite))
    {
        qFatal("could not open file: %s", qPrintable(file.errorString()));
        return -3;
    }

    QString content = file.readAll();
    if (!file.seek(0))
    {
        qFatal("could not seek: %s", qPrintable(file.errorString()));
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
            return -6;
        }
    }

    if (file.size() > file.pos())
    {
        if (!file.resize(file.pos()))
        {
            qFatal("could not resize (shrink) file: %s", qPrintable(file.errorString()));
            return -7;
        }
    }

    return 0;
}
