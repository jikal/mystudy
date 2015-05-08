#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->listButton,SIGNAL(clicked()),this,SLOT(listButtonSlot()));
    QObject::connect(ui->addButton,SIGNAL(clicked()),this,SLOT(addButtonSlot()));
    QObject::connect(ui->nameLineEdit,SIGNAL(returnPressed()),this,SLOT(addButtonSlot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::listButtonSlot(){
    ui->textBrowser->clear();
    if(db.isOpen()){

    }else{
        db =  QSqlDatabase::addDatabase("QMYSQL");//与mysql关联
        db.setHostName("localhost");
        db.setDatabaseName("test");//指定数据库
        db.setUserName("root");
        db.setPassword("123456");
        ok = db.open();
    }
    if(ok){
        qDebug()<< "test ok"<< endl;
        QString cmd = "select * from ht1422;";
        QSqlQuery query;
        bool b = query.exec(cmd);
        if(b){
            qDebug() <<"select ok"<< endl;
            while(query.next()){
                ui->textBrowser->append(query.value(0).toString()+" "+query.value(1).toString());
            }
        }else{
            qDebug() <<"select error"<< endl;
        }
        db.close();
        QSqlDatabase::removeDatabase("QMYSQL");
    }else{
        qDebug()<< "test error"<<db.lastError()<< endl;
    }

}

void MainWindow::addButtonSlot(){
    if(db.isOpen()){

    }else{
        db =  QSqlDatabase::addDatabase("QMYSQL");//与mysql关联
        db.setHostName("localhost");
        db.setDatabaseName("test");//指定数据库
        db.setUserName("root");
        db.setPassword("123456");
        ok = db.open();
    }
    if(ok){
        qDebug()<< "test ok"<< endl;
        QString cmd = "insert into ht1422 values(:id,:name);";
        QSqlQuery query;
        query.prepare(cmd);
        query.bindValue(":id",ui->idLineEdit->text());
        query.bindValue(":name",ui->nameLineEdit->text());
        bool b = query.exec();
        if(b){
           qDebug() <<"insert ok!"<< endl;
           ui->idLineEdit->clear();
           ui->nameLineEdit->clear();

        }else{
            qDebug() <<"insert  error"<< endl;
        }
        db.close();
        QSqlDatabase::removeDatabase("QMYSQL");
    }else{
        qDebug()<< "test error"<<db.lastError()<< endl;
    }
}




