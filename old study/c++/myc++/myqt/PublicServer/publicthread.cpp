#include "publicthread.h"

publicthread::publicthread(MainWindow *pMainWindow)
{
    _pMainWindow =pMainWindow;
    connect(this,SIGNAL(tellClientSend()),this,SLOT(iwilltell()));
}
void publicthread::run()
{
    while(true)
    {
        QDateTime sysTime = QDateTime::currentDateTime();
        QString timebuff=sysTime.toString("mm:ss");

        if("00:00"==timebuff)
        {
            qDebug()<<"线程整点报时："<<QDateTime::currentDateTime()<<endl;
            emit tellClientSend();
        }
        else
        {
            qDebug()<<"每秒循环:"<<timebuff<<endl;
//            _pMainWindow->recvFrom="一秒钟发一次";
//            emit tellClientSend();
//            _pMainWindow->displayRecive();
        }
        sleep(1);
    }
}
void publicthread::iwilltell()
{
    _pMainWindow->displayRecive();
}


