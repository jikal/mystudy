#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    if(db.isOpen()){
        qDebug() << "db opened" << endl;
        db.close();
    }

    db=QSqlDatabase::addDatabase("QSQLITE");//sqlite3
    db.setDatabaseName("student.db");
    bool ok = db.open();
    if(ok){
        qDebug()<<"connect ok"<<endl;
        QSqlQuery query;
        query.prepare("insert into stu(id,name) values(:id,:name)");
        //query.prepare("select * form student");
        query.bindValue(":id",ui->idLineEdit->text().toShort());
        query.bindValue(":name",ui->nameLineEdit->text());
        bool b = query.exec();
        if(b){
            qDebug()<<"insert ok"<<endl;
            ui->idLineEdit->clear();
            ui->nameLineEdit->clear();
        }else{
            qDebug()<<"insert error"<<endl;
        }

        db.close();
    }else{
        qDebug()<<"connect error"<<endl;
    }
}
