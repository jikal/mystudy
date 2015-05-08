/********************************************************************************
** Form generated from reading UI file 'chatclient.ui'
**
** Created: Sun Mar 29 20:05:52 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATCLIENT_H
#define UI_CHATCLIENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chatClient
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *ipLabel;
    QLineEdit *ipLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *portLabel;
    QLineEdit *portLineEdit;
    QPushButton *enterChatroomButton;

    void setupUi(QWidget *chatClient)
    {
        if (chatClient->objectName().isEmpty())
            chatClient->setObjectName(QString::fromUtf8("chatClient"));
        chatClient->resize(288, 157);
        layoutWidget = new QWidget(chatClient);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 20, 207, 111));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        ipLabel = new QLabel(layoutWidget);
        ipLabel->setObjectName(QString::fromUtf8("ipLabel"));

        horizontalLayout_4->addWidget(ipLabel);

        ipLineEdit = new QLineEdit(layoutWidget);
        ipLineEdit->setObjectName(QString::fromUtf8("ipLineEdit"));

        horizontalLayout_4->addWidget(ipLineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        portLabel = new QLabel(layoutWidget);
        portLabel->setObjectName(QString::fromUtf8("portLabel"));

        horizontalLayout_3->addWidget(portLabel);

        portLineEdit = new QLineEdit(layoutWidget);
        portLineEdit->setObjectName(QString::fromUtf8("portLineEdit"));

        horizontalLayout_3->addWidget(portLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        enterChatroomButton = new QPushButton(layoutWidget);
        enterChatroomButton->setObjectName(QString::fromUtf8("enterChatroomButton"));

        verticalLayout->addWidget(enterChatroomButton);


        retranslateUi(chatClient);

        QMetaObject::connectSlotsByName(chatClient);
    } // setupUi

    void retranslateUi(QWidget *chatClient)
    {
        chatClient->setWindowTitle(QApplication::translate("chatClient", "chatClient", 0, QApplication::UnicodeUTF8));
        ipLabel->setText(QApplication::translate("chatClient", "IP\345\234\260\345\235\200", 0, QApplication::UnicodeUTF8));
        portLabel->setText(QApplication::translate("chatClient", "PORT", 0, QApplication::UnicodeUTF8));
        enterChatroomButton->setText(QApplication::translate("chatClient", "\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class chatClient: public Ui_chatClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATCLIENT_H
