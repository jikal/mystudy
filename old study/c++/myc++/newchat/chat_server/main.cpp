#include <QtGui/QApplication>
#include "chat_server.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    chat_Server w;
    w.show();
    
    return a.exec();
}
