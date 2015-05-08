/********************************************************************************
** Form generated from reading UI file 'chat_server.ui'
**
** Created: Thu Mar 26 12:51:08 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_SERVER_H
#define UI_CHAT_SERVER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chat_Server
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTextEdit *serverChat_text;
    QHBoxLayout *horizontalLayout;
    QLabel *serverPort_text;
    QLineEdit *serverPort_line;
    QPushButton *serverCreateButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *sendMessageLine;
    QPushButton *sendMessageButton;

    void setupUi(QWidget *chat_Server)
    {
        if (chat_Server->objectName().isEmpty())
            chat_Server->setObjectName(QString::fromUtf8("chat_Server"));
        chat_Server->resize(298, 357);
        widget = new QWidget(chat_Server);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 10, 262, 334));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        serverChat_text = new QTextEdit(widget);
        serverChat_text->setObjectName(QString::fromUtf8("serverChat_text"));

        verticalLayout->addWidget(serverChat_text);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        serverPort_text = new QLabel(widget);
        serverPort_text->setObjectName(QString::fromUtf8("serverPort_text"));

        horizontalLayout->addWidget(serverPort_text);

        serverPort_line = new QLineEdit(widget);
        serverPort_line->setObjectName(QString::fromUtf8("serverPort_line"));

        horizontalLayout->addWidget(serverPort_line);


        verticalLayout->addLayout(horizontalLayout);

        serverCreateButton = new QPushButton(widget);
        serverCreateButton->setObjectName(QString::fromUtf8("serverCreateButton"));

        verticalLayout->addWidget(serverCreateButton);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        sendMessageLine = new QLineEdit(widget);
        sendMessageLine->setObjectName(QString::fromUtf8("sendMessageLine"));

        horizontalLayout_2->addWidget(sendMessageLine);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout_2);

        sendMessageButton = new QPushButton(widget);
        sendMessageButton->setObjectName(QString::fromUtf8("sendMessageButton"));

        verticalLayout_3->addWidget(sendMessageButton);


        retranslateUi(chat_Server);

        QMetaObject::connectSlotsByName(chat_Server);
    } // setupUi

    void retranslateUi(QWidget *chat_Server)
    {
        chat_Server->setWindowTitle(QApplication::translate("chat_Server", "chat_Server", 0, QApplication::UnicodeUTF8));
        serverPort_text->setText(QApplication::translate("chat_Server", "port:", 0, QApplication::UnicodeUTF8));
        serverCreateButton->setText(QApplication::translate("chat_Server", "createchatroom", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("chat_Server", "sendmassage:", 0, QApplication::UnicodeUTF8));
        sendMessageButton->setText(QApplication::translate("chat_Server", "sendMassage", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class chat_Server: public Ui_chat_Server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_SERVER_H
