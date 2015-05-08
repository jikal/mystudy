#include <QtGui/QApplication>
#include "tcpserver.h"
#include "tcpsocket.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TcpSocket sql;
    sql.createUsersql();
    TcpServer w;
    w.show();
    
    return a.exec();
}
