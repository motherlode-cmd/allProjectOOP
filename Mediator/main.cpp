#include "commandreader.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "mediator.h"
std::string insert(const std::string& str, char s) {
    std::string ser = "";
    for(size_t i = 0; i < str.length(); i++) {
        if(str[i] != s)
            ser+=str[i];
        else
            ser+= '\\' + str[i];
    }
    return ser;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Mediator_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    Controller c;
    CommandReader w;
    Mediator m(&c, &w);
    w.addMediator(&m);

    return a.exec();
}

