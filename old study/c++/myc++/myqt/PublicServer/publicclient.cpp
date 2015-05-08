#include "publicclient.h"
publicclient::publicclient(MainWindow *Pmainwin)
{
    tcpSocket = new QTcpSocket(this);
    serverIP =new QHostAddress();
    _Pmainwin=Pmainwin;
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(clientrecvFrom()));
}
publicclient::~publicclient()
{
    delete tcpSocket;
    delete serverIP;
}
void publicclient::clientSendto()
{
    _Pmainwin->sendTo=_Pmainwin->gettextEdit_2();

///////////////////////////////////////////////////////////////
    QString temppublicclientIP = _Pmainwin->getlineEdit_3();//动态获取IP
    QString temppublicclientPort = _Pmainwin->getlineEdit_4();//动态获取端口
    int intPort=temppublicclientPort.toInt();
    if(""==temppublicclientIP||""==temppublicclientPort)
    {
        QMessageBox::information(this,tr("error"),tr("IP地址或端口为空!"));
        return;
    }
    if(!serverIP->setAddress(temppublicclientIP))
    {
        QMessageBox::information(this,tr("error"),tr("IP地址错误!"));
        return;
    }
    tcpSocket->connectToHost(*serverIP,intPort);
    if(!tcpSocket->waitForConnected(30))
    {
        QMessageBox::information(this,tr("error"),tr("无法连接到该IP端口!"));
        return;
    }
    QString msg=_Pmainwin->sendTo;
    QByteArray packet=msg.toLocal8Bit();
    tcpSocket->write(packet);
//  tcpSocket->write(msg.toLatin1(),msg.length()+1);
    tcpSocket->waitForBytesWritten();
//////////////////////////////////////////////////////////////////
    _Pmainwin->settextEdit();
    _Pmainwin->settextEdit_2();

//    tcpSocket->disconnectFromHost();
}
void publicclient::clientrecvFrom()
{
    QByteArray data;
    while(tcpSocket->bytesAvailable()>0)
    {
        data = tcpSocket->readAll();
        if (QString(data)=="")
        {
            _Pmainwin->recvFrom="连接正常，返回字符串为空！";
        }
        else
        {
            _Pmainwin->recvFrom = QString::fromLocal8Bit(data);
        }
    }
    _Pmainwin->displayRecive();
    tcpSocket->disconnectFromHost();
}


