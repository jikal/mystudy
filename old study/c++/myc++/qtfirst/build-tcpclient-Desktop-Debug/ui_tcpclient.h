/********************************************************************************
** Form generated from reading UI file 'tcpclient.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPCLIENT_H
#define UI_TCPCLIENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
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
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QListWidget *contentListWidget;
    QLineEdit *sendLineEdit;
    QPushButton *sendButton;
    QLabel *label;
    QLineEdit *usrLineEdit;
    QLabel *label_2;
    QLineEdit *serverIpLineEdit;
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
        TcpClient->resize(362, 478);
        centralWidget = new QWidget(TcpClient);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        contentListWidget = new QListWidget(centralWidget);
        contentListWidget->setObjectName(QString::fromUtf8("contentListWidget"));

        gridLayout->addWidget(contentListWidget, 0, 0, 1, 3);

        sendLineEdit = new QLineEdit(centralWidget);
        sendLineEdit->setObjectName(QString::fromUtf8("sendLineEdit"));

        gridLayout->addWidget(sendLineEdit, 1, 0, 1, 1);

        sendButton = new QPushButton(centralWidget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));

        gridLayout->addWidget(sendButton, 1, 2, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        usrLineEdit = new QLineEdit(centralWidget);
        usrLineEdit->setObjectName(QString::fromUtf8("usrLineEdit"));

        gridLayout->addWidget(usrLineEdit, 2, 1, 1, 2);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        serverIpLineEdit = new QLineEdit(centralWidget);
        serverIpLineEdit->setObjectName(QString::fromUtf8("serverIpLineEdit"));

        gridLayout->addWidget(serverIpLineEdit, 3, 1, 2, 2);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 2, 1);

        portLineEdit = new QLineEdit(centralWidget);
        portLineEdit->setObjectName(QString::fromUtf8("portLineEdit"));

        gridLayout->addWidget(portLineEdit, 5, 1, 1, 2);

        entryButton = new QPushButton(centralWidget);
        entryButton->setObjectName(QString::fromUtf8("entryButton"));

        gridLayout->addWidget(entryButton, 6, 0, 1, 2);


        verticalLayout->addLayout(gridLayout);

        TcpClient->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TcpClient);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 362, 28));
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
        sendButton->setText(QApplication::translate("TcpClient", "\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TcpClient", "\347\224\250\346\210\267\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        usrLineEdit->setText(QApplication::translate("TcpClient", "aa", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TcpClient", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200\357\274\232", 0, QApplication::UnicodeUTF8));
        serverIpLineEdit->setText(QApplication::translate("TcpClient", "127.0.0.1", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("TcpClient", "\347\253\257\345\217\243\357\274\232", 0, QApplication::UnicodeUTF8));
        portLineEdit->setText(QApplication::translate("TcpClient", "8010", 0, QApplication::UnicodeUTF8));
        entryButton->setText(QApplication::translate("TcpClient", "\350\277\233\345\205\245\350\201\212\345\244\251\345\256\244", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TcpClient: public Ui_TcpClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPCLIENT_H
