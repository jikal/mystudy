#include "form.h"
#include "ui_form.h"
#include <QMessageBox>
#include <QString>
#include "mainwindow.h"
#include "admin.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
    this->close();
}
//管理员登陆
void Form::on_pushButton_2_clicked()
{
    QString name = ui->nameLine->text();
    QString pass = ui->passLine->text();

    QString m_name = "admin";
    QString m_pass = "123";

    if(name == m_name && pass == m_pass){
        QMessageBox::information(this,"登陆成功！",m_name);
        admin *f = new admin;
        f->show();
    }else{
        QMessageBox::information(this,"登陆失败！","登陆失败！");
    }

}
