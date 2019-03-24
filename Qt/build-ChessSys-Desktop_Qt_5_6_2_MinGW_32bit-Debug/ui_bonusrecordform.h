/********************************************************************************
** Form generated from reading UI file 'bonusrecordform.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BONUSRECORDFORM_H
#define UI_BONUSRECORDFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <timeslotform.h>

QT_BEGIN_NAMESPACE

class Ui_BonusRecordForm
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *bonusTable;
    TimeSlotForm *timeSlotWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *outputButton;
    QPushButton *queryButton;

    void setupUi(QWidget *BonusRecordForm)
    {
        if (BonusRecordForm->objectName().isEmpty())
            BonusRecordForm->setObjectName(QStringLiteral("BonusRecordForm"));
        BonusRecordForm->resize(520, 375);
        verticalLayout = new QVBoxLayout(BonusRecordForm);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        bonusTable = new QTableWidget(BonusRecordForm);
        bonusTable->setObjectName(QStringLiteral("bonusTable"));

        verticalLayout->addWidget(bonusTable);

        timeSlotWidget = new TimeSlotForm(BonusRecordForm);
        timeSlotWidget->setObjectName(QStringLiteral("timeSlotWidget"));

        verticalLayout->addWidget(timeSlotWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        outputButton = new QPushButton(BonusRecordForm);
        outputButton->setObjectName(QStringLiteral("outputButton"));
        QFont font;
        font.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        outputButton->setFont(font);

        horizontalLayout->addWidget(outputButton);

        queryButton = new QPushButton(BonusRecordForm);
        queryButton->setObjectName(QStringLiteral("queryButton"));
        queryButton->setFont(font);

        horizontalLayout->addWidget(queryButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(BonusRecordForm);

        QMetaObject::connectSlotsByName(BonusRecordForm);
    } // setupUi

    void retranslateUi(QWidget *BonusRecordForm)
    {
        BonusRecordForm->setWindowTitle(QApplication::translate("BonusRecordForm", "Form", 0));
        outputButton->setText(QApplication::translate("BonusRecordForm", "\345\257\274\345\207\272", 0));
        queryButton->setText(QApplication::translate("BonusRecordForm", "\346\237\245\350\257\242", 0));
    } // retranslateUi

};

namespace Ui {
    class BonusRecordForm: public Ui_BonusRecordForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BONUSRECORDFORM_H
