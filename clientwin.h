#ifndef CLIENTWIN_H
#define CLIENTWIN_H

#include <QMainWindow>
#include <QTcpSocket>
namespace Ui {
class ClientWin;
}

class ClientWin : public QMainWindow
{
    Q_OBJECT
    QTcpSocket cli;
    QString usrName;
public:
    explicit ClientWin(QWidget *parent = nullptr);
    ~ClientWin();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();
    void onRead();
    void on_pushButton_2_clicked();

private:
    Ui::ClientWin *ui;
};

#endif // CLIENTWIN_H
