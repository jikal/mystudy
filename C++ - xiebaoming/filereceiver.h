#ifndef _FILERECEIVER_H
#define _FILERECEIVER_H

#include <QDialog>
#include <QTcpSocket>
#include <QHostAddress>
#include <QFile>
#include <QTime>

namespace Ui {
    class fileReceiver;
}

class fileReceiver : public QDialog
{
    Q_OBJECT

public:
    explicit fileReceiver(QWidget *parent = 0);
    ~fileReceiver();
    void setHostAddress(QHostAddress address);//设置服务器地址，并链接服务器
    void setFileName(QString fileName){localFile = new QFile(fileName);}//新建文件
    void newConnect();//重新连接服务器

protected:
    void changeEvent(QEvent *e);

private:
    Ui::fileReceiver *ui;
    QTcpSocket *FileReceiver;//声明TCP对象
    quint16 blockSize;//缓存大小
    QHostAddress hostAddress;//服务器地址
    qint16 tcpPort;//端口号
    qint64 TotalBytes;//全部字节数
    qint64 bytesReceived;//收到的字节数
    qint64 bytesToReceive;
    qint64 fileNameSize;//文件大小
    QString fileName;//文件名
    QFile *localFile;
    QByteArray inBlock;
    QTime time;//时间变量

private slots:
    void on_btnClose_clicked();//关闭接收窗口
    void on_btnCancel_clicked();//中途取消接收
    void readMessage();//读取收到的文件
    void displayError(QAbstractSocket::SocketError);//错误处理
};

#endif
