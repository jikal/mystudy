#ifndef _CHATWIDGIT_H
#define _CHATWIDGIT_H

#include <QWidget>
#include <QtNetwork>
#include <QtGui>
#include "filesender.h"
#include "filereceiver.h"

namespace Ui {
    class ChatWidgit;
}

class ChatWidgit : public QWidget
{
    Q_OBJECT

public:
    explicit ChatWidgit(QWidget *parent = 0);
    ~ChatWidgit();
    QString getSecAddr();//获得对方IP
    void setSecAddr(QString, QString);//完成聊天窗口相关设置

private:
    QFile saveFile;//操作文件的输入/输出设备的类
    QString secretAddress;//对方IP地址
    Ui::ChatWidgit *ui;
    QString getIP();
    void closeEvent(QCloseEvent *);
    QColor color;
    bool eventFilter(QObject *target, QEvent *event);//事件过滤器 监视代码具体实现 重写控件的事件处理函数：输入时按下Ctrl+Enter发送

private slots:
    void on_btnClose_clicked();
    void on_btnSend_clicked();//发送聊天内容
    void on_textHistory_clicked();
    void on_textcolor_clicked();
    void on_textitalic_clicked(bool checked);//设置字体倾斜
    void on_textbold_clicked(bool checked);//设置字体加粗
    void on_textunderline_clicked(bool checked);
    void on_textBin_clicked();//清空聊天框内容
    void on_textSave_clicked();//发送文件
    void on_comboBox_currentIndexChanged(QString );//设置字体大小
    void currentFormatChanged(const QTextCharFormat &format);//字体格式发生改变时，让相应部件的状态也随之改变//QTextCharFormat 字符格式化信息类
    void setMessage(QString address, QString first, QString second);//主窗口发来消息的相应槽

signals:
    void sendMessagesFromChat(QString, QString);//聊天窗口向主窗口发送的聊天数据的信号
    void closeChat(QString);//关闭聊天窗口时发送给主窗口的信号
    void sendFile(QString, QString);//想要发送文件时聊天窗口发送给主窗口的信号
};

#endif
