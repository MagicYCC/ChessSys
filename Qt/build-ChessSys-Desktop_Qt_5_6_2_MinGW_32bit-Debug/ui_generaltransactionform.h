/********************************************************************************
** Form generated from reading UI file 'generaltransactionform.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERALTRANSACTIONFORM_H
#define UI_GENERALTRANSACTIONFORM_H

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

class Ui_GeneralTransactionForm
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *generalAnalyTable;
    TimeSlotForm *timeSlotWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *outputButton;
    QPushButton *queryButton;

    void setupUi(QWidget *GeneralTransactionForm)
    {
        if (GeneralTransactionForm->objectName().isEmpty())
            GeneralTransactionForm->setObjectName(QStringLiteral("GeneralTransactionForm"));
        GeneralTransactionForm->resize(532, 428);
        verticalLayout = new QVBoxLayout(GeneralTransactionForm);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        generalAnalyTable = new QTableWidget(GeneralTransactionForm);
        generalAnalyTable->setObjectName(QStringLiteral("generalAnalyTable"));

        verticalLayout->addWidget(generalAnalyTable);

        timeSlotWidget = new TimeSlotForm(GeneralTransactionForm);
        timeSlotWidget->setObjectName(QStringLiteral("timeSlotWidget"));

        verticalLayout->addWidget(timeSlotWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        outputButton = new QPushButton(GeneralTransactionForm);
        outputButton->setObjectName(QStringLiteral("outputButton"));
        QFont font;
        font.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        outputButton->setFont(font);

        horizontalLayout->addWidget(outputButton);

        queryButton = new QPushButton(GeneralTransactionForm);
        queryButton->setObjectName(QStringLiteral("queryButton"));
        queryButton->setFont(font);

        horizontalLayout->addWidget(queryButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(GeneralTransactionForm);

        QMetaObject::connectSlotsByName(GeneralTransactionForm);
    } // setupUi

    void retranslateUi(QWidget *GeneralTransactionForm)
    {
        GeneralTransactionForm->setWindowTitle(QApplication::translate("GeneralTransactionForm", "Form", 0));
        outputButton->setText(QApplication::translate("GeneralTransactionForm", "\345\257\274\345\207\272", 0));
        queryButton->setText(QApplication::translate("GeneralTransactionForm", "\346\237\245\350\257\242", 0));
    } // retranslateUi

};

namespace Ui {
    class GeneralTransactionForm: public Ui_GeneralTransactionForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERALTRANSACTIONFORM_H
