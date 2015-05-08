#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "form.h"
#include "admin.h"
#include "form2.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->testButton,SIGNAL(clicked()),this,SLOT(testButtonClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
//学生登陆
void MainWindow::on_pushButton_clicked()
{
    //qDebug()<< "on_pushButton_clicked"<< endl;
    form2 *f=new form2;
    f->show();
}

void MainWindow::testButtonClicked(){
   // qDebug()<<"testButtonClicked"<<endl;
}

void MainWindow::on_testButton_clicked()
{
    this->close();
}
void MainWindow::on_pushButton_2_clicked()
{
    Form *f = new Form;
    f->show();
}
