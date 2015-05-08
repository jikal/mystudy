#include <QtGui/QApplication>
#include "chatclient.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    chatClient w;
    w.show();
    
    return a.exec();
}
