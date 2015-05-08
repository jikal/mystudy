#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow duixiang;
    MainWindow *_pduixinag;

    duixiang.getlineEdit_2();
 _pduixinag->getlineEdit_2();


    MainWindow w;
    w.show();
    publicthread test(&w);
    test.start();
    return a.exec();
}
