/********************************************************************************
** Form generated from reading UI file 'tripplanner.ui'
**
** Created: Thu Mar 19 09:57:51 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRIPPLANNER_H
#define UI_TRIPPLANNER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QRadioButton>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_TripPlanner
{
public:
    QGridLayout *gridLayout;
    QGroupBox *tripInfoGroupBox;
    QGridLayout *gridLayout1;
    QLabel *timeLabel;
    QDateTimeEdit *dateEdit;
    QDateTimeEdit *timeEdit;
    QLabel *dateLabel;
    QLabel *toLabel;
    QHBoxLayout *hboxLayout;
    QRadioButton *departureRadioButton;
    QRadioButton *arrivalRadioButton;
    QComboBox *fromComboBox;
    QComboBox *toComboBox;
    QLabel *fromLabel;
    QDialogButtonBox *buttonBox;
    QTableWidget *tableWidget;
    QHBoxLayout *hboxLayout1;
    QLabel *statusLabel;
    QProgressBar *progressBar;

    void setupUi(QDialog *TripPlanner)
    {
        if (TripPlanner->objectName().isEmpty())
            TripPlanner->setObjectName(QString::fromUtf8("TripPlanner"));
        TripPlanner->resize(382, 369);
        gridLayout = new QGridLayout(TripPlanner);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tripInfoGroupBox = new QGroupBox(TripPlanner);
        tripInfoGroupBox->setObjectName(QString::fromUtf8("tripInfoGroupBox"));
        gridLayout1 = new QGridLayout(tripInfoGroupBox);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        timeLabel = new QLabel(tripInfoGroupBox);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));

        gridLayout1->addWidget(timeLabel, 3, 0, 1, 1);

        dateEdit = new QDateTimeEdit(tripInfoGroupBox);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));

        gridLayout1->addWidget(dateEdit, 2, 1, 1, 1);

        timeEdit = new QDateTimeEdit(tripInfoGroupBox);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));

        gridLayout1->addWidget(timeEdit, 3, 1, 1, 1);

        dateLabel = new QLabel(tripInfoGroupBox);
        dateLabel->setObjectName(QString::fromUtf8("dateLabel"));

        gridLayout1->addWidget(dateLabel, 2, 0, 1, 1);

        toLabel = new QLabel(tripInfoGroupBox);
        toLabel->setObjectName(QString::fromUtf8("toLabel"));

        gridLayout1->addWidget(toLabel, 1, 0, 1, 1);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        departureRadioButton = new QRadioButton(tripInfoGroupBox);
        departureRadioButton->setObjectName(QString::fromUtf8("departureRadioButton"));
        departureRadioButton->setChecked(true);

        hboxLayout->addWidget(departureRadioButton);

        arrivalRadioButton = new QRadioButton(tripInfoGroupBox);
        arrivalRadioButton->setObjectName(QString::fromUtf8("arrivalRadioButton"));

        hboxLayout->addWidget(arrivalRadioButton);


        gridLayout1->addLayout(hboxLayout, 4, 0, 1, 2);

        fromComboBox = new QComboBox(tripInfoGroupBox);
        fromComboBox->setObjectName(QString::fromUtf8("fromComboBox"));

        gridLayout1->addWidget(fromComboBox, 0, 1, 1, 1);

        toComboBox = new QComboBox(tripInfoGroupBox);
        toComboBox->setObjectName(QString::fromUtf8("toComboBox"));

        gridLayout1->addWidget(toComboBox, 1, 1, 1, 1);

        fromLabel = new QLabel(tripInfoGroupBox);
        fromLabel->setObjectName(QString::fromUtf8("fromLabel"));

        gridLayout1->addWidget(fromLabel, 0, 0, 1, 1);


        gridLayout->addWidget(tripInfoGroupBox, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(TripPlanner);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        gridLayout->addWidget(buttonBox, 0, 1, 3, 1);

        tableWidget = new QTableWidget(TripPlanner);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setColumnCount(6);

        gridLayout->addWidget(tableWidget, 1, 0, 1, 1);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        statusLabel = new QLabel(TripPlanner);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(statusLabel->sizePolicy().hasHeightForWidth());
        statusLabel->setSizePolicy(sizePolicy);

        hboxLayout1->addWidget(statusLabel);

        progressBar = new QProgressBar(TripPlanner);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setMinimum(0);
        progressBar->setMaximum(100);
        progressBar->setOrientation(Qt::Horizontal);

        hboxLayout1->addWidget(progressBar);


        gridLayout->addLayout(hboxLayout1, 2, 0, 1, 1);

#ifndef QT_NO_SHORTCUT
        timeLabel->setBuddy(timeEdit);
        dateLabel->setBuddy(dateEdit);
        toLabel->setBuddy(toComboBox);
        fromLabel->setBuddy(fromComboBox);
#endif // QT_NO_SHORTCUT

        retranslateUi(TripPlanner);

        fromComboBox->setCurrentIndex(0);
        toComboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TripPlanner);
    } // setupUi

    void retranslateUi(QDialog *TripPlanner)
    {
        TripPlanner->setWindowTitle(QApplication::translate("TripPlanner", "Trip Planner", 0, QApplication::UnicodeUTF8));
        tripInfoGroupBox->setTitle(QApplication::translate("TripPlanner", "Trip Information", 0, QApplication::UnicodeUTF8));
        timeLabel->setText(QApplication::translate("TripPlanner", "Appro&ximate Time:", 0, QApplication::UnicodeUTF8));
        dateEdit->setDisplayFormat(QApplication::translate("TripPlanner", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        timeEdit->setDisplayFormat(QApplication::translate("TripPlanner", "hh:mm:ss", 0, QApplication::UnicodeUTF8));
        dateLabel->setText(QApplication::translate("TripPlanner", "&Date:", 0, QApplication::UnicodeUTF8));
        toLabel->setText(QApplication::translate("TripPlanner", "&To:", 0, QApplication::UnicodeUTF8));
        departureRadioButton->setText(QApplication::translate("TripPlanner", "D&eparture", 0, QApplication::UnicodeUTF8));
        departureRadioButton->setShortcut(QApplication::translate("TripPlanner", "Alt+E", 0, QApplication::UnicodeUTF8));
        arrivalRadioButton->setText(QApplication::translate("TripPlanner", "&Arrival", 0, QApplication::UnicodeUTF8));
        arrivalRadioButton->setShortcut(QApplication::translate("TripPlanner", "Alt+A", 0, QApplication::UnicodeUTF8));
        fromComboBox->clear();
        fromComboBox->insertItems(0, QStringList()
         << QApplication::translate("TripPlanner", "Berlin", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TripPlanner", "Bonn", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TripPlanner", "Bremen", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TripPlanner", "Dresden", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TripPlanner", "D\303\274sseldorf", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TripPlanner", "Dortmund", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TripPlanner", "Frankfurt am Main", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TripPlanner", "Hannover", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TripPlanner", "Hamburg", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TripPlanner", "M\303\274nchen", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TripPlanner", "N\303\274rnberg", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TripPlanner", "Rostock", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TripPlanner", "Stuttgart", 0, QApplication::UnicodeUTF8)
        );
        toComboBox->clear();
        toComboBox->insertItems(0, QStringList()
         << QApplication::translate("TripPlanner", "Berlin", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TripPlanner", "Bonn", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TripPlanner", "Bremen", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TripPlanner", "Dresden", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TripPlanner", "D\303\274sseldorf", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TripPlanner", "Dortmund", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TripPlanner", "Frankfurt am Main", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TripPlanner", "Hannover", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TripPlanner", "Hamburg", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TripPlanner", "M\303\274nchen", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TripPlanner", "N\303\274rnberg", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TripPlanner", "Rostock", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TripPlanner", "Stuttgart", 0, QApplication::UnicodeUTF8)
        );
        fromLabel->setText(QApplication::translate("TripPlanner", "&From:", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("TripPlanner", "Date", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("TripPlanner", "Departure", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("TripPlanner", "Arrival", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("TripPlanner", "Duration", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("TripPlanner", "Changes", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("TripPlanner", "Train type", 0, QApplication::UnicodeUTF8));
        statusLabel->setText(QApplication::translate("TripPlanner", "Ready", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TripPlanner: public Ui_TripPlanner {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIPPLANNER_H
