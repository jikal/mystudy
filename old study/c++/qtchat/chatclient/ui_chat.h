/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created: Mon May 4 17:52:58 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chat
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QTextEdit *messageTextEdit;
    QLineEdit *sendMessageLineEdit;
    QPushButton *sendMessageButton;

    void setupUi(QWidget *chat)
    {
        if (chat->objectName().isEmpty())
            chat->setObjectName(QString::fromUtf8("chat"));
        chat->resize(301, 311);
        widget = new QWidget(chat);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 30, 258, 261));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        messageTextEdit = new QTextEdit(widget);
        messageTextEdit->setObjectName(QString::fromUtf8("messageTextEdit"));

        verticalLayout->addWidget(messageTextEdit);

        sendMessageLineEdit = new QLineEdit(widget);
        sendMessageLineEdit->setObjectName(QString::fromUtf8("sendMessageLineEdit"));

        verticalLayout->addWidget(sendMessageLineEdit);

        sendMessageButton = new QPushButton(widget);
        sendMessageButton->setObjectName(QString::fromUtf8("sendMessageButton"));

        verticalLayout->addWidget(sendMessageButton);

        sendMessageButton->raise();
        sendMessageLineEdit->raise();
        messageTextEdit->raise();

        retranslateUi(chat);

        QMetaObject::connectSlotsByName(chat);
    } // setupUi

    void retranslateUi(QWidget *chat)
    {
        chat->setWindowTitle(QApplication::translate("chat", "Form", 0, QApplication::UnicodeUTF8));
        sendMessageButton->setText(QApplication::translate("chat", "\345\217\221\351\200\201\346\266\210\346\201\257", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class chat: public Ui_chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
