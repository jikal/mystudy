/********************************************************************************
** Form generated from reading UI file 'clientlogin.ui'
**
** Created: Mon May 4 17:52:58 2015
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
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *idLabel;
    QLineEdit *idLineEdit;
    QPushButton *regPushButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *passwodLabel;
    QLineEdit *passWordLineEdit;
    QPushButton *loginButton;

    void setupUi(QWidget *clientlogin)
    {
        if (clientlogin->objectName().isEmpty())
            clientlogin->setObjectName(QString::fromUtf8("clientlogin"));
        clientlogin->resize(308, 142);
        layoutWidget = new QWidget(clientlogin);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 266, 107));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
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


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        loginButton = new QPushButton(layoutWidget);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));

        verticalLayout_2->addWidget(loginButton);


        verticalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(clientlogin);

        QMetaObject::connectSlotsByName(clientlogin);
    } // setupUi

    void retranslateUi(QWidget *clientlogin)
    {
        clientlogin->setWindowTitle(QApplication::translate("clientlogin", "Form", 0, QApplication::UnicodeUTF8));
        idLabel->setText(QApplication::translate("clientlogin", "\350\264\246\345\217\267", 0, QApplication::UnicodeUTF8));
        regPushButton->setText(QApplication::translate("clientlogin", "\346\263\250\345\206\214\350\264\246\345\217\267", 0, QApplication::UnicodeUTF8));
        passwodLabel->setText(QApplication::translate("clientlogin", "\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        loginButton->setText(QApplication::translate("clientlogin", "\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class clientlogin: public Ui_clientlogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTLOGIN_H
