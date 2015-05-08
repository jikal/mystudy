#include "admin.h"
#include "ui_admin.h"
#include "mainwindow.h"
#include "form1.h"
admin::admin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
}

admin::~admin()
{
    delete ui;
}

void admin::on_pushButton_5_clicked()
{
    MainWindow *m = new MainWindow;
    m->show();
    this->close();
}
//添加学生
void admin::on_pushButton_clicked()
{
    form1 *f = new form1;
    f->show();
}
