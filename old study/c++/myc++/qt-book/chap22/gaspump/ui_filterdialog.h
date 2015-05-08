/********************************************************************************
** Form generated from reading UI file 'filterdialog.ui'
**
** Created: Thu Mar 19 10:02:45 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERDIALOG_H
#define UI_FILTERDIALOG_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTimeEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FilterDialog
{
public:
    QVBoxLayout *vboxLayout;
    QLabel *topLabel;
    QFrame *frame;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout1;
    QLabel *dateBetweenLabel;
    QDateEdit *fromDateEdit;
    QLabel *dateAndLabel;
    QDateEdit *toDateEdit;
    QLabel *timeBetweenLabel;
    QTimeEdit *fromTimeEdit;
    QLabel *timeAndLabel;
    QTimeEdit *toTimeEdit;
    QLabel *pumpLabel;
    QComboBox *pumpComboBox;
    QLabel *userLabel;
    QComboBox *userComboBox;
    QLabel *companyLabel;
    QComboBox *companyComboBox;
    QLabel *quantityBetweenLabel;
    QDoubleSpinBox *fromQuantitySpinBox;
    QLabel *quantityAndLabel;
    QDoubleSpinBox *toQuantitySpinBox;
    QLabel *statusLabel;
    QComboBox *statusComboBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *FilterDialog)
    {
        if (FilterDialog->objectName().isEmpty())
            FilterDialog->setObjectName(QString::fromUtf8("FilterDialog"));
        FilterDialog->resize(424, 360);
        vboxLayout = new QVBoxLayout(FilterDialog);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        topLabel = new QLabel(FilterDialog);
        topLabel->setObjectName(QString::fromUtf8("topLabel"));

        vboxLayout->addWidget(topLabel);

        frame = new QFrame(FilterDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout1 = new QGridLayout();
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        dateBetweenLabel = new QLabel(frame);
        dateBetweenLabel->setObjectName(QString::fromUtf8("dateBetweenLabel"));
        dateBetweenLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout1->addWidget(dateBetweenLabel, 0, 0, 1, 1);

        fromDateEdit = new QDateEdit(frame);
        fromDateEdit->setObjectName(QString::fromUtf8("fromDateEdit"));

        gridLayout1->addWidget(fromDateEdit, 0, 1, 1, 2);

        dateAndLabel = new QLabel(frame);
        dateAndLabel->setObjectName(QString::fromUtf8("dateAndLabel"));
        dateAndLabel->setAlignment(Qt::AlignCenter);

        gridLayout1->addWidget(dateAndLabel, 0, 3, 1, 1);

        toDateEdit = new QDateEdit(frame);
        toDateEdit->setObjectName(QString::fromUtf8("toDateEdit"));
        toDateEdit->setDate(QDate(2999, 12, 31));

        gridLayout1->addWidget(toDateEdit, 0, 4, 1, 1);

        timeBetweenLabel = new QLabel(frame);
        timeBetweenLabel->setObjectName(QString::fromUtf8("timeBetweenLabel"));
        timeBetweenLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout1->addWidget(timeBetweenLabel, 1, 0, 1, 1);

        fromTimeEdit = new QTimeEdit(frame);
        fromTimeEdit->setObjectName(QString::fromUtf8("fromTimeEdit"));

        gridLayout1->addWidget(fromTimeEdit, 1, 1, 1, 2);

        timeAndLabel = new QLabel(frame);
        timeAndLabel->setObjectName(QString::fromUtf8("timeAndLabel"));
        timeAndLabel->setAlignment(Qt::AlignCenter);

        gridLayout1->addWidget(timeAndLabel, 1, 3, 1, 1);

        toTimeEdit = new QTimeEdit(frame);
        toTimeEdit->setObjectName(QString::fromUtf8("toTimeEdit"));
        toTimeEdit->setTime(QTime(23, 59, 59));

        gridLayout1->addWidget(toTimeEdit, 1, 4, 1, 1);

        pumpLabel = new QLabel(frame);
        pumpLabel->setObjectName(QString::fromUtf8("pumpLabel"));
        pumpLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout1->addWidget(pumpLabel, 2, 0, 1, 1);

        pumpComboBox = new QComboBox(frame);
        pumpComboBox->setObjectName(QString::fromUtf8("pumpComboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pumpComboBox->sizePolicy().hasHeightForWidth());
        pumpComboBox->setSizePolicy(sizePolicy);

        gridLayout1->addWidget(pumpComboBox, 2, 1, 1, 1);

        userLabel = new QLabel(frame);
        userLabel->setObjectName(QString::fromUtf8("userLabel"));
        userLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout1->addWidget(userLabel, 3, 0, 1, 1);

        userComboBox = new QComboBox(frame);
        userComboBox->setObjectName(QString::fromUtf8("userComboBox"));

        gridLayout1->addWidget(userComboBox, 3, 1, 1, 1);

        companyLabel = new QLabel(frame);
        companyLabel->setObjectName(QString::fromUtf8("companyLabel"));
        companyLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout1->addWidget(companyLabel, 4, 0, 1, 1);

        companyComboBox = new QComboBox(frame);
        companyComboBox->setObjectName(QString::fromUtf8("companyComboBox"));

        gridLayout1->addWidget(companyComboBox, 4, 1, 1, 1);

        quantityBetweenLabel = new QLabel(frame);
        quantityBetweenLabel->setObjectName(QString::fromUtf8("quantityBetweenLabel"));
        quantityBetweenLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout1->addWidget(quantityBetweenLabel, 5, 0, 1, 1);

        fromQuantitySpinBox = new QDoubleSpinBox(frame);
        fromQuantitySpinBox->setObjectName(QString::fromUtf8("fromQuantitySpinBox"));
        fromQuantitySpinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        fromQuantitySpinBox->setDecimals(1);
        fromQuantitySpinBox->setMaximum(100000);

        gridLayout1->addWidget(fromQuantitySpinBox, 5, 1, 1, 2);

        quantityAndLabel = new QLabel(frame);
        quantityAndLabel->setObjectName(QString::fromUtf8("quantityAndLabel"));
        quantityAndLabel->setAlignment(Qt::AlignCenter);

        gridLayout1->addWidget(quantityAndLabel, 5, 3, 1, 1);

        toQuantitySpinBox = new QDoubleSpinBox(frame);
        toQuantitySpinBox->setObjectName(QString::fromUtf8("toQuantitySpinBox"));
        toQuantitySpinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        toQuantitySpinBox->setDecimals(1);
        toQuantitySpinBox->setMaximum(100000);
        toQuantitySpinBox->setValue(100000);

        gridLayout1->addWidget(toQuantitySpinBox, 5, 4, 1, 1);

        statusLabel = new QLabel(frame);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout1->addWidget(statusLabel, 6, 0, 1, 1);

        statusComboBox = new QComboBox(frame);
        statusComboBox->setObjectName(QString::fromUtf8("statusComboBox"));

        gridLayout1->addWidget(statusComboBox, 6, 1, 1, 1);


        gridLayout->addLayout(gridLayout1, 0, 0, 1, 1);


        vboxLayout->addWidget(frame);

        buttonBox = new QDialogButtonBox(FilterDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Ok);

        vboxLayout->addWidget(buttonBox);

#ifndef QT_NO_SHORTCUT
        dateBetweenLabel->setBuddy(fromDateEdit);
        timeBetweenLabel->setBuddy(fromTimeEdit);
        pumpLabel->setBuddy(pumpComboBox);
        userLabel->setBuddy(userComboBox);
        companyLabel->setBuddy(companyComboBox);
        quantityBetweenLabel->setBuddy(fromQuantitySpinBox);
        statusLabel->setBuddy(statusComboBox);
#endif // QT_NO_SHORTCUT

        retranslateUi(FilterDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), FilterDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), FilterDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(FilterDialog);
    } // setupUi

    void retranslateUi(QDialog *FilterDialog)
    {
        FilterDialog->setWindowTitle(QApplication::translate("FilterDialog", "Filter Transactions", 0, QApplication::UnicodeUTF8));
        topLabel->setText(QApplication::translate("FilterDialog", "Only keep the transactions that meet the following criteria:", 0, QApplication::UnicodeUTF8));
        dateBetweenLabel->setText(QApplication::translate("FilterDialog", "&Date between", 0, QApplication::UnicodeUTF8));
        dateAndLabel->setText(QApplication::translate("FilterDialog", "and", 0, QApplication::UnicodeUTF8));
        timeBetweenLabel->setText(QApplication::translate("FilterDialog", "&Time between", 0, QApplication::UnicodeUTF8));
        timeAndLabel->setText(QApplication::translate("FilterDialog", "and", 0, QApplication::UnicodeUTF8));
        pumpLabel->setText(QApplication::translate("FilterDialog", "&Pump:", 0, QApplication::UnicodeUTF8));
        pumpComboBox->clear();
        pumpComboBox->insertItems(0, QStringList()
         << QApplication::translate("FilterDialog", "Any", 0, QApplication::UnicodeUTF8)
        );
        userLabel->setText(QApplication::translate("FilterDialog", "&User:", 0, QApplication::UnicodeUTF8));
        userComboBox->clear();
        userComboBox->insertItems(0, QStringList()
         << QApplication::translate("FilterDialog", "Any", 0, QApplication::UnicodeUTF8)
        );
        companyLabel->setText(QApplication::translate("FilterDialog", "&Company:", 0, QApplication::UnicodeUTF8));
        companyComboBox->clear();
        companyComboBox->insertItems(0, QStringList()
         << QApplication::translate("FilterDialog", "Any", 0, QApplication::UnicodeUTF8)
        );
        quantityBetweenLabel->setText(QApplication::translate("FilterDialog", "&Quantity between", 0, QApplication::UnicodeUTF8));
        quantityAndLabel->setText(QApplication::translate("FilterDialog", "and", 0, QApplication::UnicodeUTF8));
        statusLabel->setText(QApplication::translate("FilterDialog", "&Status:", 0, QApplication::UnicodeUTF8));
        statusComboBox->clear();
        statusComboBox->insertItems(0, QStringList()
         << QApplication::translate("FilterDialog", "Any", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class FilterDialog: public Ui_FilterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERDIALOG_H
