#include <QtGui/QApplication>
#include <QTextCodec>//处理不同语言编码的类
#include "login.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf-8"));
    //QTextCodec::setCodecForTr(QTextCodec::codecForLocale());//对不同的文字选择不同的编码
    Login login;
    login.show();
    return a.exec();
}
