#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _Ppublicclient=new publicclient(this);   //公用客户端，发包，并接收返回
    _Ppublicserver=new publicserver(this);   //公用服务器，接包，并返回报文

    sendTo="  39V200090120112020040|0000000|V0.0.0";               //公用发送报文
    recvFrom="";             //公用接收报文

    ui->textEdit->setText(recvFrom);
    ui->textEdit_2->setText(sendTo);
    ui->lineEdit_2->setText("9060");
    ui->lineEdit_3->setText("192.168.8.182");
    ui->lineEdit_4->setText("9060");

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(slotclientSend()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(slotserverCreat()));

    mainLayout =new QGridLayout(ui->centralWidget);
    mainLayout->addWidget(ui->textEdit,0,0,1,5,0);
    mainLayout->addWidget(ui->textEdit_2,2,0,1,5,0);
    mainLayout->addWidget(ui->label,4,0,1,1,0);
    mainLayout->addWidget(ui->lineEdit_2,4,3,1,1,0);
    mainLayout->addWidget(ui->label_2,5,0,1,1,0);
    mainLayout->addWidget(ui->lineEdit_3,5,1,1,2,0);
    mainLayout->addWidget(ui->lineEdit_4,5,3,1,1,0);
    mainLayout->addWidget(ui->pushButton_2,6,0,1,3,0);
    mainLayout->addWidget(ui->pushButton,6,3,1,1,0);

    this->setWindowTitle("Usay");

//    setWindowFlags(Qt::WindowStaysOnTopHint);
    this->setMinimumSize(300,500);
    this->move(1000,100);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete _Ppublicclient;
    delete _Ppublicserver;
//    delete _Ppublicthread;
}

void MainWindow::slotclientSend()
{
    _Ppublicclient->clientSendto();
}
void MainWindow::slotserverCreat()
{
    _Ppublicserver->creatServer();
    ui->pushButton_2->setEnabled(false);
}
void MainWindow::settextEdit()
{
    QDateTime sysTime = QDateTime::currentDateTime();
    QString timebuff=sysTime.toString("yyyy-MM-dd hh:mm:ss");
    ui->textEdit->append(timebuff);
    ui->textEdit->append(sendTo);

    QScrollBar *scrollbar = ui->textEdit->verticalScrollBar();
    scrollbar->setSliderPosition(scrollbar->maximum()); //滚动条置底
}
void MainWindow::settextEdit_2()
{
    ui->textEdit_2->setText("");
}
void MainWindow::displayRecive()
{
    QDateTime sysTime = QDateTime::currentDateTime();
    QString timebuff=sysTime.toString("yyyy-MM-dd hh:mm:ss");
    ui->textEdit->append(timebuff);
    ui->textEdit->append(recvFrom);

    QScrollBar *scrollbar = ui->textEdit->verticalScrollBar();
    scrollbar->setSliderPosition(scrollbar->maximum()); //滚动条置底

    return;
}
QString MainWindow::gettextEdit()
{
    qDebug()<<ui->textEdit->toPlainText()<<endl;
   return ui->textEdit->toPlainText();
}
QString MainWindow::gettextEdit_2()
{
    qDebug()<<ui->textEdit_2->toPlainText()<<endl;
   return ui->textEdit_2->toPlainText();
}

QString MainWindow::getlineEdit_2()
{
   return ui->lineEdit_2->text();
}
QString MainWindow::getlineEdit_3()
{
   return ui->lineEdit_3->text();
}
QString MainWindow::getlineEdit_4()
{
   return ui->lineEdit_4->text();
}
void setlineEdit(){}
void setlineEdit_2(){}
void setlineEdit_3(){}
void setlineEdit_4(){}
