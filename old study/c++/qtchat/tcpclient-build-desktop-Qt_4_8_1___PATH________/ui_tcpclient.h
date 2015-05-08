/********************************************************************************
** Form generated from reading UI file 'tcpclient.ui'
**
** Created: Fri Mar 27 15:19:10 2015
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
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TcpClient
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
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
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TcpClient)
    {
        if (TcpClient->objectName().isEmpty())
            TcpClient->setObjectName(QString::fromUtf8("TcpClient"));
        TcpClient->resize(301, 441);
        centralWidget = new QWidget(TcpClient);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 0, 264, 377));
        verticalLayout_5 = new QVBoxLayout(layoutWidget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        contentListWidget = new QListWidget(layoutWidget);
        contentListWidget->setObjectName(QString::fromUtf8("contentListWidget"));

        verticalLayout->addWidget(contentListWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        sendLineEdit = new QLineEdit(layoutWidget);
        sendLineEdit->setObjectName(QString::fromUtf8("sendLineEdit"));

        horizontalLayout->addWidget(sendLineEdit);

        sendButton = new QPushButton(layoutWidget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));

        horizontalLayout->addWidget(sendButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        usrLineEdit = new QLineEdit(layoutWidget);
        usrLineEdit->setObjectName(QString::fromUtf8("usrLineEdit"));

        horizontalLayout_2->addWidget(usrLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        serverIpLineEdit = new QLineEdit(layoutWidget);
        serverIpLineEdit->setObjectName(QString::fromUtf8("serverIpLineEdit"));

        horizontalLayout_3->addWidget(serverIpLineEdit);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        portLineEdit = new QLineEdit(layoutWidget);
        portLineEdit->setObjectName(QString::fromUtf8("portLineEdit"));

        horizontalLayout_4->addWidget(portLineEdit);


        verticalLayout_3->addLayout(horizontalLayout_4);


        verticalLayout_4->addLayout(verticalLayout_3);


        verticalLayout_5->addLayout(verticalLayout_4);

        entryButton = new QPushButton(layoutWidget);
        entryButton->setObjectName(QString::fromUtf8("entryButton"));

        verticalLayout_5->addWidget(entryButton);

        TcpClient->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TcpClient);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 301, 26));
        TcpClient->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TcpClient);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TcpClient->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TcpClient);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TcpClient->setStatusBar(statusBar);

        retranslateUi(TcpClient);

        QMetaObject::connectSlotsByName(TcpClient);
    } // setupUi

    void retranslateUi(QMainWindow *TcpClient)
    {
        TcpClient->setWindowTitle(QApplication::translate("TcpClient", "TcpClient", 0, QApplication::UnicodeUTF8));
        sendButton->setText(QApplication::translate("TcpClient", "send", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TcpClient", "name:", 0, QApplication::UnicodeUTF8));
        usrLineEdit->setText(QString());
        label_2->setText(QApplication::translate("TcpClient", "ip:", 0, QApplication::UnicodeUTF8));
        serverIpLineEdit->setText(QString());
        label_3->setText(QApplication::translate("TcpClient", "port", 0, QApplication::UnicodeUTF8));
        portLineEdit->setText(QString());
        entryButton->setText(QApplication::translate("TcpClient", "\350\277\233\345\205\245\350\201\212\345\244\251\345\256\244", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TcpClient: public Ui_TcpClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPCLIENT_H
