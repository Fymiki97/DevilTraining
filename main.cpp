#include <QCoreApplication>
#include <QLocale>
#include <QTranslator>

#include <iostream>
using namespace std;
#include "cplayer.h"
#include "cpregame.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "DevilTraining_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    // CPlayer* player = new CPlayer();
    CPreGame* pregame = new CPreGame();
    pregame->Display();
    cout<<"Game Over!"<<endl;


    return a.exec();
}

// TODO
//2024年5月7日 统计正确率  √
//添加时间
//n溯答


