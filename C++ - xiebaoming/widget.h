#ifndef _WIDGET_H
#define _WIDGET_H

#include <QWidget>
#include <QtNetwork>
#include <QtGui>
//#include <qmap.h>
#include <QMap>
#include "chatwidgit.h"
#include "filesender.h"
#include "mainform.h"

namespace Ui {
    class Widget;
}

//枚举变量,标志信息的类型，分别为消息，新用户加入，和用户退出
enum MessageType
{
    Message, NewParticipant, ParticipantLeft, FileName, Refuse, AskStartChat, StartChat, RefuseChat
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    //QString getUserName();//没有定义？？？？？？？？
    void SetName(QString);//登录后设置主窗口用户名，并广播新用户

protected:
    void changeEvent(QEvent *);//窗体改变事件//光标位于聊天输入栏中不同格式字体处，字体格式工具栏发生相应改变
    void closeEvent(QCloseEvent *);//窗体关闭事件//主窗口关闭引发所有子窗口关闭
    void sendMessage(MessageType type, QString serverAddress="", QString message = "");//发送消息
    void newParticipant(QString localHostName, QString ipAddress);//新用户加入
    //void participantLeft(QString localHostName, QString time);//用户离开
    void participantLeft(QString localHostName);//用户离开
    void hasPendingFile(QString localhostname, QString serverAddress, QString clientAddress, QString fileName);//有文件需要接收

private:
    Ui::Widget *ui;
    QString Name;
    QUdpSocket *udpSocket;
    QMap<QString, ChatWidgit *> list;//聊天窗口列表
    qint16 port;//端口号
    FileSender * Sender;//文件发送窗口
    QString getIP();
    int isGame;

private slots:
    void on_btnAll_clicked();
    void on_btnCancel_clicked();
    void on_btnGame_clicked();
    void btnGame_able();
    void on_tableWidget_doubleClicked(QModelIndex index);//请求聊天
    void closeFromChat(QString);//聊天窗口关闭事件信号处理函数
    void sendMessagesToMain(QString, QString);//聊天窗口的聊天消息的信号对应的槽函数
    void processPendingDatagrams();//接收数据处理过程
    void sendFileName(QString, QString);//发送文件窗口的发送文件信号对应的槽函数
    void hasFileToSend(QString, QString);//私聊窗口的发送文件的信号对应的槽函数


signals:
    //主窗口受到聊天消息后，以信号形式发送给相应的聊天窗口
    void sendMessagesZ(QString address, QString first, QString second);//IP地址  用户名和时间  聊天内容
    void closeGame();
};

#endif
