/********************************************************************************
** Form generated from reading UI file 'clientlogin.ui'
**
** Created: Fri Mar 27 12:52:02 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTLOGIN_H
#define UI_CLIENTLOGIN_H

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

class Ui_clientlogin
{
public:
    QWidget *widget;
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

    void setupUi(QWidget *clientlogin)
    {
        if (clientlogin->objectName().isEmpty())
            clientlogin->setObjectName(QString::fromUtf8("clientlogin"));
        clientlogin->resize(302, 129);
        widget = new QWidget(clientlogin);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 10, 262, 104));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        idLabel = new QLabel(widget);
        idLabel->setObjectName(QString::fromUtf8("idLabel"));

        horizontalLayout->addWidget(idLabel);

        idLineEdit = new QLineEdit(widget);
        idLineEdit->setObjectName(QString::fromUtf8("idLineEdit"));

        horizontalLayout->addWidget(idLineEdit);

        regPushButton = new QPushButton(widget);
        regPushButton->setObjectName(QString::fromUtf8("regPushButton"));

        horizontalLayout->addWidget(regPushButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        passwodLabel = new QLabel(widget);
        passwodLabel->setObjectName(QString::fromUtf8("passwodLabel"));

        horizontalLayout_2->addWidget(passwodLabel);

        passWordLineEdit = new QLineEdit(widget);
        passWordLineEdit->setObjectName(QString::fromUtf8("passWordLineEdit"));

        horizontalLayout_2->addWidget(passWordLineEdit);

        retPasswordButton = new QPushButton(widget);
        retPasswordButton->setObjectName(QString::fromUtf8("retPasswordButton"));

        horizontalLayout_2->addWidget(retPasswordButton);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        loginButton = new QPushButton(widget);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));

        verticalLayout_2->addWidget(loginButton);


        retranslateUi(clientlogin);

        QMetaObject::connectSlotsByName(clientlogin);
    } // setupUi

    void retranslateUi(QWidget *clientlogin)
    {
        clientlogin->setWindowTitle(QApplication::translate("clientlogin", "Form", 0, QApplication::UnicodeUTF8));
        idLabel->setText(QApplication::translate("clientlogin", "\350\264\246\345\217\267", 0, QApplication::UnicodeUTF8));
        regPushButton->setText(QApplication::translate("clientlogin", "\346\263\250\345\206\214\350\264\246\345\217\267", 0, QApplication::UnicodeUTF8));
        passwodLabel->setText(QApplication::translate("clientlogin", "\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        retPasswordButton->setText(QApplication::translate("clientlogin", "\346\211\276\345\233\236\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        loginButton->setText(QApplication::translate("clientlogin", "\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class clientlogin: public Ui_clientlogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTLOGIN_H
