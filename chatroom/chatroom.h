#ifndef CHATROOM_H
#define CHATROOM_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class chatroom; }
QT_END_NAMESPACE

class chatroom : public QMainWindow
{
    Q_OBJECT

public:
    chatroom(QWidget *parent = nullptr);
    ~chatroom();

private:
    Ui::chatroom *ui;
};
#endif // CHATROOM_H
