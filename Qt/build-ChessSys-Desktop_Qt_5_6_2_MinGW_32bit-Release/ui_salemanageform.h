/********************************************************************************
** Form generated from reading UI file 'salemanageform.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SALEMANAGEFORM_H
#define UI_SALEMANAGEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SaleManageForm
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *saleManageLabel;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_7;
    QLabel *transactionsLabel;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *updateTransactionButton;
    QTableWidget *transactionTable;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *deleteTransactionButton;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_9;
    QLabel *saleRecordLabel;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *saleButton;
    QPushButton *updateSalesButton;
    QTableWidget *salesTable;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *deleteSaleButton;

    void setupUi(QWidget *SaleManageForm)
    {
        if (SaleManageForm->objectName().isEmpty())
            SaleManageForm->setObjectName(QStringLiteral("SaleManageForm"));
        SaleManageForm->resize(519, 386);
        verticalLayout_3 = new QVBoxLayout(SaleManageForm);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        saleManageLabel = new QLabel(SaleManageForm);
        saleManageLabel->setObjectName(QStringLiteral("saleManageLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        saleManageLabel->setFont(font);

        horizontalLayout->addWidget(saleManageLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        transactionsLabel = new QLabel(SaleManageForm);
        transactionsLabel->setObjectName(QStringLiteral("transactionsLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        transactionsLabel->setFont(font1);

        horizontalLayout_3->addWidget(transactionsLabel);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);

        updateTransactionButton = new QPushButton(SaleManageForm);
        updateTransactionButton->setObjectName(QStringLiteral("updateTransactionButton"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        updateTransactionButton->setFont(font2);

        horizontalLayout_7->addWidget(updateTransactionButton);


        verticalLayout_2->addLayout(horizontalLayout_7);

        transactionTable = new QTableWidget(SaleManageForm);
        transactionTable->setObjectName(QStringLiteral("transactionTable"));

        verticalLayout_2->addWidget(transactionTable);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        deleteTransactionButton = new QPushButton(SaleManageForm);
        deleteTransactionButton->setObjectName(QStringLiteral("deleteTransactionButton"));
        deleteTransactionButton->setFont(font2);

        horizontalLayout_5->addWidget(deleteTransactionButton);


        verticalLayout_2->addLayout(horizontalLayout_5);


        horizontalLayout_8->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_9);

        saleRecordLabel = new QLabel(SaleManageForm);
        saleRecordLabel->setObjectName(QStringLiteral("saleRecordLabel"));
        saleRecordLabel->setFont(font1);

        horizontalLayout_6->addWidget(saleRecordLabel);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_10);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        saleButton = new QPushButton(SaleManageForm);
        saleButton->setObjectName(QStringLiteral("saleButton"));
        saleButton->setFont(font2);

        horizontalLayout_2->addWidget(saleButton);

        updateSalesButton = new QPushButton(SaleManageForm);
        updateSalesButton->setObjectName(QStringLiteral("updateSalesButton"));
        updateSalesButton->setFont(font2);

        horizontalLayout_2->addWidget(updateSalesButton);


        verticalLayout->addLayout(horizontalLayout_2);

        salesTable = new QTableWidget(SaleManageForm);
        salesTable->setObjectName(QStringLiteral("salesTable"));

        verticalLayout->addWidget(salesTable);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        deleteSaleButton = new QPushButton(SaleManageForm);
        deleteSaleButton->setObjectName(QStringLiteral("deleteSaleButton"));
        deleteSaleButton->setFont(font2);

        horizontalLayout_4->addWidget(deleteSaleButton);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_8->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout_8);


        retranslateUi(SaleManageForm);

        QMetaObject::connectSlotsByName(SaleManageForm);
    } // setupUi

    void retranslateUi(QWidget *SaleManageForm)
    {
        SaleManageForm->setWindowTitle(QApplication::translate("SaleManageForm", "Form", 0));
        saleManageLabel->setText(QApplication::translate("SaleManageForm", "\351\224\200\345\224\256\347\256\241\347\220\206", 0));
        transactionsLabel->setText(QApplication::translate("SaleManageForm", "\344\272\244\346\230\223\346\270\205\345\215\225", 0));
        updateTransactionButton->setText(QApplication::translate("SaleManageForm", "\346\233\264\346\226\260\344\277\241\346\201\257", 0));
        deleteTransactionButton->setText(QApplication::translate("SaleManageForm", "\345\210\240\351\231\244\344\272\244\346\230\223", 0));
        saleRecordLabel->setText(QApplication::translate("SaleManageForm", "\345\225\206\345\223\201\351\224\200\345\224\256\350\256\260\345\275\225", 0));
        saleButton->setText(QApplication::translate("SaleManageForm", "\345\225\206\345\223\201\350\264\255\344\271\260", 0));
        updateSalesButton->setText(QApplication::translate("SaleManageForm", "\346\233\264\346\226\260\344\277\241\346\201\257", 0));
        deleteSaleButton->setText(QApplication::translate("SaleManageForm", "\345\210\240\351\231\244\351\224\200\345\224\256\350\256\260\345\275\225", 0));
    } // retranslateUi

};

namespace Ui {
    class SaleManageForm: public Ui_SaleManageForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALEMANAGEFORM_H
