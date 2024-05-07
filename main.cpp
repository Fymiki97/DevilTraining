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
    int num = pregame->GetTotalNum();
    for(int i=0 ;i<num;i++)
    {
        pregame->PrintEquation(i);
        int a;
        cin>>a;
        bool ret = pregame->RightOrWrong(i,a);
        if(!ret)
        {
            cout<<"Wrong!"<<endl;
        }
    }

    return a.exec();
}



