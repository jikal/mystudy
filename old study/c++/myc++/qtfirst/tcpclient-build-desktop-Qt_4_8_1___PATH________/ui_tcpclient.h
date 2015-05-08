/********************************************************************************
** Form generated from reading UI file 'tcpclient.ui'
**
** Created: Fri Mar 27 00:50:48 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPCLIENT_H
#define UI_TCPCLIENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QListWidget *contentListWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *sendLineEdit;
    QPushButton *sendButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *usrLineEdit;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *serverIpLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *portLineEdit;
    QPushButton *entryButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(310, 441);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 10, 264, 377));
        verticalLayout_5 = new QVBoxLayout(widget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        contentListWidget = new QListWidget(widget);
        contentListWidget->setObjectName(QString::fromUtf8("contentListWidget"));

        verticalLayout->addWidget(contentListWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        sendLineEdit = new QLineEdit(widget);
        sendLineEdit->setObjectName(QString::fromUtf8("sendLineEdit"));

        horizontalLayout->addWidget(sendLineEdit);

        sendButton = new QPushButton(widget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));

        horizontalLayout->addWidget(sendButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        usrLineEdit = new QLineEdit(widget);
        usrLineEdit->setObjectName(QString::fromUtf8("usrLineEdit"));

        horizontalLayout_2->addWidget(usrLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        serverIpLineEdit = new QLineEdit(widget);
        serverIpLineEdit->setObjectName(QString::fromUtf8("serverIpLineEdit"));

        horizontalLayout_3->addWidget(serverIpLineEdit);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        portLineEdit = new QLineEdit(widget);
        portLineEdit->setObjectName(QString::fromUtf8("portLineEdit"));

        horizontalLayout_4->addWidget(portLineEdit);


        verticalLayout_3->addLayout(horizontalLayout_4);


        verticalLayout_4->addLayout(verticalLayout_3);


        verticalLayout_5->addLayout(verticalLayout_4);

        entryButton = new QPushButton(widget);
        entryButton->setObjectName(QString::fromUtf8("entryButton"));

        verticalLayout_5->addWidget(entryButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 310, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        sendButton->setText(QApplication::translate("MainWindow", "send", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "name:", 0, QApplication::UnicodeUTF8));
        usrLineEdit->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "ip:", 0, QApplication::UnicodeUTF8));
        serverIpLineEdit->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "port", 0, QApplication::UnicodeUTF8));
        portLineEdit->setText(QString());
        entryButton->setText(QApplication::translate("MainWindow", "\350\277\233\345\205\245\350\201\212\345\244\251\345\256\244", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPCLIENT_H
