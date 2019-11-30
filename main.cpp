
#include "serverwin.h"
#include "clientwin.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ServerWin serverWin;
    ClientWin clientWin;
    if(serverWin.isReady())
        serverWin.show();
    else{
        clientWin.show();
    }
    return a.exec();
}
