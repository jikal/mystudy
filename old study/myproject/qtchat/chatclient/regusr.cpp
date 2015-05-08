#include "regusr.h"
#include "ui_regusr.h"

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
//注册函数
void regusr::on_regButton_clicked()
{
    QString type = "1";
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
    QString str = type + "*" + name + "*"+ passwd;
    tcpsocket -> write(str.toLatin1());
    dataReceived();
}
//注册接受函数
void regusr::dataReceived(){
    tcpsocket->waitForReadyRead();
    QString acpt = tcpsocket->readAll();
    qDebug() << acpt.toInt() <<endl;
    if(acpt == "0"){
        QMessageBox::information(this,"The success of the registration","The success of the registration");
        this->close();
    }else if(acpt == "1"){
        QMessageBox::information(this,"username areadly exist!","username areadly exist!");
    }
}
