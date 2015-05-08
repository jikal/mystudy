#include <QtGui/QApplication>
#include "tcpclient.h"
#include <QTextCodec>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    TcpClient w;
    w.show();
    
    return a.exec();
}
