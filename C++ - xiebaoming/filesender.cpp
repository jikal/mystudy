#include "filesender.h"
#include "ui_filesender.h"
#include <QTcpSocket>
#include <QFileDialog>
#include <QMessageBox>

FileSender::FileSender(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FileSender)
{
    ui->setupUi(this);
    this->setFixedSize(350, 180);//设置窗口尺寸，不可改变
    tcpPort = 6666;//设置端口号
    fileSender = new QTcpServer();//创建QTcpServer对象
    connect(fileSender, SIGNAL(newConnection()), this, SLOT(sendMessage()));//新连接成功信号与相应槽的映射
}

FileSender::~FileSender()
{
    delete ui;
}

//窗体改变
void FileSender::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type())
    {
        case QEvent::LanguageChange:
            ui->retranslateUi(this);
            break;
        default:
            break;
    }
}

//当有新连接时触发//开始发送数据
void FileSender::sendMessage()
{
    clientConnection = fileSender->nextPendingConnection();//获取连接的socket
    connect(clientConnection, SIGNAL(bytesWritten(qint64)), this, SLOT(updateClientProgress(qint64)));

    ui->serverStatusLabel->setText(tr("开始传送文件 %1 ！").arg(theFileName));

    localFile = new QFile(fileName);
    if(!localFile->open((QFile::ReadOnly)))//以只读方式打开
    {
        QMessageBox::warning(this, tr("应用程序"), tr("无法读取文件 %1:\n%2").arg(fileName).arg(localFile->errorString()));
        return ;
    }
    TotalBytes = localFile->size();//获取文件大小
    QDataStream sendOut(&outBlock, QIODevice::WriteOnly);//声明QDataStream
    sendOut.setVersion(QDataStream::Qt_4_6);//设置版本
    time.start();//开始计时
    QString currentFile = fileName.right(fileName.size() - fileName.lastIndexOf('/') - 1);
    sendOut << qint64(0) << qint64(0) << currentFile;
    TotalBytes += outBlock.size();
    sendOut.device()->seek(0);
    sendOut << TotalBytes << qint64((outBlock.size() - sizeof(qint64)*2));
    bytesToWrite = TotalBytes - clientConnection->write(outBlock);
    qDebug() << currentFile << TotalBytes;
    outBlock.resize(0);
}

//根据发送情况实时更新进度条//更新进度条
void FileSender::updateClientProgress(qint64 numBytes)
{
    bytesWritten += (int)numBytes;
    if(bytesToWrite > 0)//还没有传送完毕
    {
        outBlock = localFile->read(qMin(bytesToWrite, loadSize));
        bytesToWrite -= (int)clientConnection->write(outBlock);
        outBlock.resize(0);
    }
    else
    {
        localFile->close();
    }
    ui->progressBar->setMaximum(TotalBytes);//设置最大值
    ui->progressBar->setValue(bytesWritten);//更新progressBar的值

    float useTime = time.elapsed();
    double speed = bytesWritten / useTime;
    ui->serverStatusLabel->setText(tr("已发送 %1MB (%2MB/s) \n共%3MB 已用时:%4秒\n估计剩余时间：%5秒")
                                  .arg(bytesWritten / (1024*1024))//已发送
                                  .arg(speed*1000/(1024*1024),0,'f',2)//速度
                                  .arg(TotalBytes / (1024 * 1024))//总大小
                                  .arg(useTime/1000,0,'f',0)//用时
                                  .arg(TotalBytes/speed/1000 - useTime/1000,0,'f',0));//剩余时间
    if(bytesWritten == TotalBytes)
    {
        ui->serverStatusLabel->setText(tr("传送文件 %1 成功").arg(theFileName));
    }
}

//被拒绝时触发,主窗体调用//被对方拒绝
void FileSender::refused()
{
    fileSender->close();//关闭TCP服务器
    ui->serverStatusLabel->setText(tr("对方拒绝接收！！！"));
}

//当需要发送文件时  主窗体调用初始化//初始化
void FileSender::initSender()
{
    loadSize = 4*1024;//64
    TotalBytes = 0;
    bytesWritten = 0;
    bytesToWrite = 0;
    ui->progressBar->reset();

    fileSender->close();
}

//选择完文件 初始化完成后 自动调用 等待 触发主窗口通知接收方
void FileSender::SenderStart(QString file, QString addr)
{
    this->fileName = file;
    this->theFileName = fileName.right(fileName.size() - fileName.lastIndexOf('/') - 1);

    if(!fileSender->listen(QHostAddress::Any, tcpPort))//开始监听连接
    {
        qDebug() << fileSender->errorString();
        close();
        return ;
    }
    ui->serverStatusLabel->setText(tr("等待对方接收... ..."));
    emit sendFileName(theFileName, addr);
   // this->close();
}

//发送完成后点击退出//退出窗口
void FileSender::on_btnQuit_clicked()
{
    if(fileSender->isListening())
    {
        fileSender->close();
    }
    this->close();
}
