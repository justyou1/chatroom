#include "serverwin.h"
#include "ui_serverwin.h"

ServerWin::ServerWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServerWin)
{
    ui->setupUi(this);
    if(server.listen(QHostAddress::Any,8880)){
        connect(&server,SIGNAL(newConnection()),this,SLOT(onNewConnect()));
    }
}
bool ServerWin::isReady()
{
    return server.isListening();
}
void ServerWin::onNewConnect()
{

    while(server.hasPendingConnections())
    {
        QTcpSocket * cli = server.nextPendingConnection();
        connect(cli,SIGNAL(readyRead()),this,SLOT(onRead()));
        connect(cli,SIGNAL(disconnected()),this,SLOT(onDisconnect()));
        cliList.append(cli);
    }
}
void ServerWin::onRead(){
    QTcpSocket* cli = dynamic_cast<QTcpSocket*>(sender());
    QByteArray bytes = cli->readAll();
    foreach (QTcpSocket* cli_v , cliList) {
        cli_v->write(bytes);
    }
}
void ServerWin::onDisconnect(){
    QTcpSocket* cli = dynamic_cast<QTcpSocket*>(sender());
    cliList.removeOne(cli);
}
ServerWin::~ServerWin()
{
    delete ui;
}
