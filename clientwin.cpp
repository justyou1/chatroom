#include "clientwin.h"
#include "ui_clientwin.h"

ClientWin::ClientWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientWin)
{
    ui->setupUi(this);
}

ClientWin::~ClientWin()
{
    delete ui;
}

void ClientWin::on_pushButton_3_clicked()
{
    quint16 port = static_cast<quint16>(ui->lineEdit->text().toUInt());
    cli.connectToHost("127.0.0.1",port);
    connect(&cli,SIGNAL(readyRead()),this,SLOT(onRead()));
    usrName = ui->lineEdit_2->text();
}
void ClientWin::onRead()
{
     QByteArray bytes = cli.readAll();
     ui->textEdit->append(bytes);
}
void ClientWin::on_pushButton_clicked()
{
    QString str =  usrName+": "+ui->lineEdit_3->text();
    cli.write(str.toUtf8());
}

void ClientWin::on_pushButton_2_clicked()
{
    cli.close();
    cli.disconnectFromHost();
    close();
}
