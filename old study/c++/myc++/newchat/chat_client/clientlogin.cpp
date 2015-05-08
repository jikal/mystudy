#include "clientlogin.h"
#include "ui_clientlogin.h"
clientlogin::clientlogin(QTcpSocket *p,QWidget *parent):
    QWidget(parent),
    ui(new Ui::clientlogin)
{
    ui->setupUi(this);
    tcpsocket = p;
}

clientlogin::~clientlogin()
{
    delete ui;
}

void clientlogin::on_regPushButton_clicked()
{
    regusr *reGusr = new regusr(tcpsocket);
    reGusr -> show();
}
