/********************************************************************************
** Form generated from reading UI file 'tcpserver.ui'
**
** Created: Fri Mar 27 14:16:42 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPSERVER_H
#define UI_TCPSERVER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TcpServer
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QTextEdit *messagTextEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *portLineEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *TcpServer)
    {
        if (TcpServer->objectName().isEmpty())
            TcpServer->setObjectName(QString::fromUtf8("TcpServer"));
        TcpServer->resize(294, 277);
        widget = new QWidget(TcpServer);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 0, 258, 262));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        messagTextEdit = new QTextEdit(widget);
        messagTextEdit->setObjectName(QString::fromUtf8("messagTextEdit"));

        verticalLayout->addWidget(messagTextEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        portLineEdit = new QLineEdit(widget);
        portLineEdit->setObjectName(QString::fromUtf8("portLineEdit"));

        horizontalLayout->addWidget(portLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(TcpServer);

        QMetaObject::connectSlotsByName(TcpServer);
    } // setupUi

    void retranslateUi(QDialog *TcpServer)
    {
        TcpServer->setWindowTitle(QApplication::translate("TcpServer", "TcpServer", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TcpServer", "port", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("TcpServer", "createchatroom", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TcpServer: public Ui_TcpServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPSERVER_H
