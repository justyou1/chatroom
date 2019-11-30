#ifndef SERVERWIN_H
#define SERVERWIN_H
#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>
namespace Ui {
class ServerWin;
}
class ServerWin : public QMainWindow
{
    Q_OBJECT
    QList<QTcpSocket * > cliList;
    QTcpServer server;
public:
    explicit ServerWin(QWidget *parent = nullptr);
    bool isReady();
    ~ServerWin();

private slots:
    void onNewConnect();
    void onRead();
    void onDisconnect();
private:
    Ui::ServerWin *ui;


};

#endif // SERVERWIN_H
