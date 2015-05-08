/********************************************************************************
** Form generated from reading UI file 'tcpserver.ui'
**
** Created: Thu May 7 19:00:51 2015
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPSERVER_H
#define UI_TCPSERVER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TcpServer
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *messagTextEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *portLineEdit;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TcpServer)
    {
        if (TcpServer->objectName().isEmpty())
            TcpServer->setObjectName(QString::fromUtf8("TcpServer"));
        TcpServer->resize(295, 348);
        centralWidget = new QWidget(TcpServer);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 258, 262));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        messagTextEdit = new QTextEdit(layoutWidget);
        messagTextEdit->setObjectName(QString::fromUtf8("messagTextEdit"));

        verticalLayout->addWidget(messagTextEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        portLineEdit = new QLineEdit(layoutWidget);
        portLineEdit->setObjectName(QString::fromUtf8("portLineEdit"));

        horizontalLayout->addWidget(portLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        TcpServer->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TcpServer);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 295, 26));
        TcpServer->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TcpServer);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TcpServer->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TcpServer);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TcpServer->setStatusBar(statusBar);

        retranslateUi(TcpServer);

        QMetaObject::connectSlotsByName(TcpServer);
    } // setupUi

    void retranslateUi(QMainWindow *TcpServer)
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
