/********************************************************************************
** Form generated from reading UI file 'chatlogin.ui'
**
** Created: Sun Mar 29 20:18:07 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATLOGIN_H
#define UI_CHATLOGIN_H

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

class Ui_chatlogin
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *idLabel;
    QLineEdit *idLineEdit;
    QPushButton *regPushButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *passwodLabel;
    QLineEdit *passWordLineEdit;
    QPushButton *retPasswordButton;
    QPushButton *loginButton;

    void setupUi(QWidget *chatlogin)
    {
        if (chatlogin->objectName().isEmpty())
            chatlogin->setObjectName(QString::fromUtf8("chatlogin"));
        chatlogin->resize(319, 146);
        layoutWidget = new QWidget(chatlogin);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 20, 262, 104));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        idLabel = new QLabel(layoutWidget);
        idLabel->setObjectName(QString::fromUtf8("idLabel"));

        horizontalLayout->addWidget(idLabel);

        idLineEdit = new QLineEdit(layoutWidget);
        idLineEdit->setObjectName(QString::fromUtf8("idLineEdit"));

        horizontalLayout->addWidget(idLineEdit);

        regPushButton = new QPushButton(layoutWidget);
        regPushButton->setObjectName(QString::fromUtf8("regPushButton"));

        horizontalLayout->addWidget(regPushButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        passwodLabel = new QLabel(layoutWidget);
        passwodLabel->setObjectName(QString::fromUtf8("passwodLabel"));

        horizontalLayout_2->addWidget(passwodLabel);

        passWordLineEdit = new QLineEdit(layoutWidget);
        passWordLineEdit->setObjectName(QString::fromUtf8("passWordLineEdit"));

        horizontalLayout_2->addWidget(passWordLineEdit);

        retPasswordButton = new QPushButton(layoutWidget);
        retPasswordButton->setObjectName(QString::fromUtf8("retPasswordButton"));

        horizontalLayout_2->addWidget(retPasswordButton);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        loginButton = new QPushButton(layoutWidget);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));

        verticalLayout_2->addWidget(loginButton);


        retranslateUi(chatlogin);

        QMetaObject::connectSlotsByName(chatlogin);
    } // setupUi

    void retranslateUi(QWidget *chatlogin)
    {
        chatlogin->setWindowTitle(QApplication::translate("chatlogin", "Form", 0, QApplication::UnicodeUTF8));
        idLabel->setText(QApplication::translate("chatlogin", "\350\264\246\345\217\267", 0, QApplication::UnicodeUTF8));
        regPushButton->setText(QApplication::translate("chatlogin", "\346\263\250\345\206\214\350\264\246\345\217\267", 0, QApplication::UnicodeUTF8));
        passwodLabel->setText(QApplication::translate("chatlogin", "\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        retPasswordButton->setText(QApplication::translate("chatlogin", "\346\211\276\345\233\236\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        loginButton->setText(QApplication::translate("chatlogin", "\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class chatlogin: public Ui_chatlogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATLOGIN_H
