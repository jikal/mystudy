/********************************************************************************
** Form generated from reading UI file 'regusr.ui'
**
** Created: Mon May 4 17:52:58 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGUSR_H
#define UI_REGUSR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_regusr
{
public:
    QPushButton *regButton;
    QPushButton *regExitButton;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *regUsridLabel;
    QLineEdit *regUsridLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *regPasswordLabel;
    QLineEdit *regPasswordLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *reregPasswordLabel;
    QLineEdit *reregPasswordLineEdit;
    QHBoxLayout *horizontalLayout;

    void setupUi(QWidget *regusr)
    {
        if (regusr->objectName().isEmpty())
            regusr->setObjectName(QString::fromUtf8("regusr"));
        regusr->resize(311, 186);
        regButton = new QPushButton(regusr);
        regButton->setObjectName(QString::fromUtf8("regButton"));
        regButton->setGeometry(QRect(30, 140, 98, 27));
        regExitButton = new QPushButton(regusr);
        regExitButton->setObjectName(QString::fromUtf8("regExitButton"));
        regExitButton->setGeometry(QRect(180, 140, 98, 27));
        layoutWidget = new QWidget(regusr);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 30, 248, 109));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        regUsridLabel = new QLabel(layoutWidget);
        regUsridLabel->setObjectName(QString::fromUtf8("regUsridLabel"));

        horizontalLayout_4->addWidget(regUsridLabel);

        regUsridLineEdit = new QLineEdit(layoutWidget);
        regUsridLineEdit->setObjectName(QString::fromUtf8("regUsridLineEdit"));

        horizontalLayout_4->addWidget(regUsridLineEdit);


        formLayout->setLayout(0, QFormLayout::LabelRole, horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        regPasswordLabel = new QLabel(layoutWidget);
        regPasswordLabel->setObjectName(QString::fromUtf8("regPasswordLabel"));
        regPasswordLabel->setMinimumSize(QSize(0, 27));

        horizontalLayout_3->addWidget(regPasswordLabel);

        regPasswordLineEdit = new QLineEdit(layoutWidget);
        regPasswordLineEdit->setObjectName(QString::fromUtf8("regPasswordLineEdit"));

        horizontalLayout_3->addWidget(regPasswordLineEdit);


        formLayout->setLayout(1, QFormLayout::LabelRole, horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        reregPasswordLabel = new QLabel(layoutWidget);
        reregPasswordLabel->setObjectName(QString::fromUtf8("reregPasswordLabel"));

        horizontalLayout_2->addWidget(reregPasswordLabel);

        reregPasswordLineEdit = new QLineEdit(layoutWidget);
        reregPasswordLineEdit->setObjectName(QString::fromUtf8("reregPasswordLineEdit"));

        horizontalLayout_2->addWidget(reregPasswordLineEdit);


        formLayout->setLayout(2, QFormLayout::LabelRole, horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        formLayout->setLayout(3, QFormLayout::LabelRole, horizontalLayout);


        retranslateUi(regusr);

        QMetaObject::connectSlotsByName(regusr);
    } // setupUi

    void retranslateUi(QWidget *regusr)
    {
        regusr->setWindowTitle(QApplication::translate("regusr", "Form", 0, QApplication::UnicodeUTF8));
        regButton->setText(QApplication::translate("regusr", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        regExitButton->setText(QApplication::translate("regusr", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        regUsridLabel->setText(QApplication::translate("regusr", "\350\264\246\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        regPasswordLabel->setText(QApplication::translate("regusr", "\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        reregPasswordLabel->setText(QApplication::translate("regusr", "\345\206\215\346\254\241\350\276\223\345\205\245\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class regusr: public Ui_regusr {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGUSR_H
