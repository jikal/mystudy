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

void clientlogin::on_loginButton_clicked()
{
    QString type = "2";
    QString name = ui->idLineEdit->text();
    QString pass = ui->passWordLineEdit->text();
    QString str = type +"*" + name +"*"+ pass;
    tcpsocket->write(str.toLatin1());
    tcpsocket->waitForReadyRead();
    QString acpt = tcpsocket->readAll();
    qDebug() << acpt <<endl;
    if(acpt == "2"){
        QMessageBox::information(this,"login success","login success");
        ui->loginButton->setEnabled(false);
        QString curName = ui->idLineEdit->text();
        chat *Chat = new chat(curName,tcpsocket);
        Chat->show();
        this->close();
    }else if(acpt == "3"){
       QMessageBox::information(this,"wrong passwd or user doesn't exist","wrong passwd or user doesn't exist");
    }
}


