#ifndef _FILESENDER_H
#define _FILESENDER_H

#include <QDialog>
#include <QTcpServer>
#include <QFile>
#include <QTime>

namespace Ui {
    class FileSender;
}

class FileSender : public QDialog
{
    Q_OBJECT

public:
    explicit FileSender(QWidget *parent = 0);
    ~FileSender();
    void refused();
    void initSender();//初始化
    void SenderStart(QString, QString);//开始传送

protected:
    void changeEvent(QEvent *e);//窗体改变

private:
    Ui::FileSender *ui;
    qint16 tcpPort;//端口号
    QTcpServer *fileSender;//TCP服务器对象
    QString fileName;
    QString theFileName;
    QFile *localFile;
    qint64 TotalBytes;//文件的字节数
    qint64 bytesWritten;//写入TCP的字节数
    qint64 bytesToWrite;
    qint64 loadSize;
    QByteArray outBlock;//缓存一次发送的数据
    QTcpSocket *clientConnection;//TCP socket
    QTime time;//计时器

private slots:
    void on_btnQuit_clicked();//放弃传送
    void sendMessage();//开始发送数据
    void updateClientProgress(qint64 numBytes);//根据发送情况实时更新进度条

signals:
    void sendFileName(QString fileName,QString addr);
};

#endif
