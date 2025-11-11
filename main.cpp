#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

#include "managerwpisow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ManagerWpisow managerWpisow;

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "LabPK_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    MainWindow w(&managerWpisow);
    w.show();
    return a.exec();
}
