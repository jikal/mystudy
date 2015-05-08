#include "regusr.h"
#include "ui_regusr.h"
#include <QTcpSocket>
#include <QMessageBox>
regusr::regusr(QTcpSocket *p,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::regusr)
{
    ui->setupUi(this);
    tcpsocket = p;
}

regusr::~regusr()
{
    delete ui;
    //QObject::connect(tcpsocket,SIGNAL(readyRead()),this,SLOT(dataReceived()));
}

void regusr::on_regButton_clicked()
{
    QString name;
    QString passwd;
    QString repasswd;
    name = ui->regUsridLineEdit ->text();
    passwd = ui->regPasswordLineEdit ->text();
    repasswd = ui->reregPasswordLineEdit->text();
    if(passwd != repasswd){
        qDebug() << "your firstpasswd unequal your secondpasswd" << endl;
        return;
    }
    MESSAGE msg = {MT_NULL,0};
    msg.name = name;
    msg.msgtype = REGUSR;
    msg.pass = passwd;
    tcpsocket->writeData((char *)&msg,MESSAGE_LEN);
}

void regusr::dataReceived(){
    MESSAGE msg = {MT_NULL,0};
    tcpsocket->readData((char*)&msg,MESSAGE_LEN);
    if(msg.msgtype == REGUSR){
        qDebug()<< "1";
    }
}



