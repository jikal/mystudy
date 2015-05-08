#include "form1.h"
#include "ui_form1.h"
//extern list <QString> stu;
#include <QList>
#include <QDebug>
#include <iterator>

form1::form1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::form1)
{
    ui->setupUi(this);
}

form1::~form1()
{
    delete ui;
}
//添加返回界面
void form1::on_pushButton_clicked()
{
    this->close();
}

void form1::on_pushButton_2_clicked()
{

    stu.push_back(ui->lineEdit->text());

}
