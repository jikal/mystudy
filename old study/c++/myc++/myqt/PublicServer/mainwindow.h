#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "publicclient.h"
#include "publicserver.h"
#include "publicthread.h"

#include <QMainWindow>
#include <QDebug>
#include <QDateTime>
#include <QScrollBar>
#include <QHostAddress>
#include <QMessageBox>
#include <QTcpSocket>
#include <QTcpServer>
#include <QGridLayout>
class publicclient;
class publicserver;
class publicthread;
typedef class publicthread TESTTHREAD;//typedef 类型别名
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    publicclient *_Ppublicclient;   //公用客户端，发包，并接收返回
    publicserver *_Ppublicserver;   //公用服务器，接包，并返回报文
    publicthread *_Ppublicthread;   //每十分钟，报时

    QString sendTo;                 //公用发送报文
    QString recvFrom;               //公用接收报文

    QHostAddress *publicserverIP;   //公用服务器IP
    QHostAddress *publicclientIP;   //公用客户端IP
    int publicserverPort;           //公用服务器地址
    int publicclientPort;           //公用客户端地址

    QGridLayout *mainLayout;
    void settextEdit();
    void settextEdit_2();
    void setlineEdit();
    void setlineEdit_2();
    void setlineEdit_3();
    void setlineEdit_4();
    void displayRecive();

    QString gettextEdit();
    QString gettextEdit_2();
    QString getlineEdit();
    QString getlineEdit_2();
    QString getlineEdit_3();
    QString getlineEdit_4();



private:
    Ui::MainWindow *ui;

signals:

public slots:
    void slotclientSend();
    void slotserverCreat();

};

#endif // MAINWINDOW_H
