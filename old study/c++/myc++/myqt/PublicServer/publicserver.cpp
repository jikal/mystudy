#include "publicserver.h"

publicserver::publicserver(MainWindow *Pmainwin)
{
    _Pmainwin=Pmainwin;

}
void publicserver::updateServer(QString msg,int length)
{
    _Pmainwin->displayRecive();
}
void publicserver::reviceTell(QString ServerReciveFrom)
{
    _Pmainwin->recvFrom=ServerReciveFrom;
    _Pmainwin->displayRecive();
}

void publicserver::creatServer()
{
    QString temppublicclientPort = _Pmainwin->getlineEdit_2();//动态获取端口
    port=temppublicclientPort.toInt();
    server = new publicserver_server(this,port);
    connect(server,SIGNAL(updateServer(QString,int)),this,SLOT(updateServer(QString,int)));
    connect(server,SIGNAL(tellpublicserver_sig(QString)),this,SLOT(reviceTell(QString)));
}
