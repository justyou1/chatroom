#include "chatroom.h"
#include "ui_chatroom.h"

chatroom::chatroom(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::chatroom)
{
    ui->setupUi(this);
}

chatroom::~chatroom()
{
    delete ui;
}

