#include "tcpsocket.h"

TcpSocket::TcpSocket(QObject *parent)
    :QTcpSocket(parent){
    QObject::connect(this,SIGNAL(readyRead()),this,SLOT(dataReceived()));
    QObject::connect(this,SIGNAL(disconnected()),this,SLOT(slotDisconnected()));
}

TcpSocket::~TcpSocket(){

}
//zhk接受数据包判断
void TcpSocket::dataReceived(){
    if(bytesAvailable()<0){
        return;
    }
    QString str = readAll();
    QString type = str.mid(0,1);

    switch(type.toInt()){
        case 1:
            requestRegusr(str);
            break;
        case 2:
            requestLoginusr(str);
            break;
        case 3:
            requestSendmessage(str);
            break;
   }
}

void TcpSocket::slotDisconnected(){
    emit disconnected(this->socketDescriptor());
}
//zhk注册
void TcpSocket::requestRegusr(QString str){
    //openUsersql();
    int len = str.length();
    QString str1 = str.right(len-1);
    QString name = str1.section("*",1,1);
    QString pass = str1.section("*",2,2);
    regUsersql(name,pass);
}
void TcpSocket::requestLoginusr(QString str){//登陆
    int len = str.length();
    QString str1 = str.right(len-1);
    QString name = str1.section("*",1,1);
    QString pass = str1.section("*",2,2);
    loginUsersql(name,pass);
}
//zhk服务器端接受消息并群发
void TcpSocket::requestSendmessage(QString str){
    int len = str.length();
    QString str1 = str.right(len-1);
    int len1 = str1.length();
    emit sendClients(str1,len1);
}
//zhk百度的mysql用法使用的
void TcpSocket::regUsersql(QString strname,QString strpass){
    if(db.isOpen()){

    }else{
        db =  QSqlDatabase::addDatabase("QMYSQL");//与mysql关联
        db.setHostName("localhost");
        db.setDatabaseName("ht1422");//指定数据库
        db.setUserName("root");
        db.setPassword("220915");
        ok = db.open();
    }
    if(ok){
        qDebug()<< "test ok"<< endl;
        QString c_cmd = "select * from qtchatuser;";
        QSqlQuery c_query;
        bool b = c_query.exec(c_cmd);
        bool type = false;
        //qDebug(c_query.next();
        if(b){
            qDebug() << "select ok";
            while(c_query.next()){
                if(c_query.value(1).toString() == strname){
                    type = true;
                    break;
                }
           }
           if(type){
               QString ret = "1";
               write(ret.toLatin1());
           }else{
               /*
               QString cmd = QString( "insert into qtchatuser(name,pass) values('%1''%2');")
                      .arg(strname)
                      .arg(strpass);

                */
               QString cmd = "insert into qtchatuser(name,pass) values('"+strname+"','"+strpass+"');";
               QSqlQuery query;
               query.exec(cmd);
               QString ret = "0";
               write(ret.toLatin1());
           }
        }
        db.close();
        QSqlDatabase::removeDatabase("QMYSQL");
    }else{
        qDebug()<< "test error"<<db.lastError()<< endl;
    }
}

void TcpSocket::loginUsersql(QString strname,QString strpass){
    if(db.isOpen()){

    }else{
        db =  QSqlDatabase::addDatabase("QMYSQL");//与mysql关联
        db.setHostName("localhost");
        db.setDatabaseName("ht1422");//指定数据库
        db.setUserName("root");
        db.setPassword("220915");
        ok = db.open();
    }
    if(ok){
        qDebug()<< "test ok"<< endl;
        QString c_cmd = "select * from qtchatuser;";
        QSqlQuery c_query;
        bool b = c_query.exec(c_cmd);
        bool type = false;
        if(b){
            qDebug()<<"select ok";
            while(c_query.next()){
                if(c_query.value(1).toString() == strname && c_query.value(2).toString() == strpass){
                        type = true;
                        break;
                }
            }
            if(type){
                QString ret = "2";
                write(ret.toLatin1());
            }else{
                QString ret = "3";
                write(ret.toLatin1());
            }
        }
        db.close();
        QSqlDatabase::removeDatabase("QMYSQL");
    }else{
        qDebug()<< "test error"<<db.lastError()<< endl;
    }
}
//创建表格

//创建数据库

void TcpSocket::createUsersql(){
    if(db.isOpen()){

    }else{
        db =  QSqlDatabase::addDatabase("QMYSQL");//与mysql关联
        db.setHostName("localhost");
        db.setDatabaseName("ht1422");//指定数据库
        db.setUserName("root");
        db.setPassword("220915");
        ok = db.open();
    }
    if(ok){
        qDebug()<< "open mysql sucess!"<< endl;
        QString c_cmd = "create table qtchatuser(id int not null auto_increment,name varchar(20),pass varchar(20),primary key(id));";
        QSqlQuery c_query;
        c_query.exec(c_cmd);
        db.close();
        QSqlDatabase::removeDatabase("QMYSQL");
    }else{
        qDebug() << "open false!" << endl;
    }
}

