/********************************************************************************
** Form generated from reading UI file 'stockmanageform.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOCKMANAGEFORM_H
#define UI_STOCKMANAGEFORM_H

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

class Ui_StockManageForm
{
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *stockTitleLabel;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_5;
    QLabel *commodityStockLabel;
    QSpacerItem *horizontalSpacer_7;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *addCommodityButton;
    QPushButton *updateButton;
    QTableWidget *stockInfoTable;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *changePriceButton;
    QPushButton *deleteButton;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *activeButton;
    QPushButton *forSaleButton;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_6;
    QLabel *stockRecordLabel;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *addStockButton;
    QPushButton *updateRecordButton;
    QTableWidget *stockRecordTable;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *cancelRecordButton;

    void setupUi(QWidget *StockManageForm)
    {
        if (StockManageForm->objectName().isEmpty())
            StockManageForm->setObjectName(QStringLiteral("StockManageForm"));
        StockManageForm->resize(631, 357);
        verticalLayout_4 = new QVBoxLayout(StockManageForm);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        stockTitleLabel = new QLabel(StockManageForm);
        stockTitleLabel->setObjectName(QStringLiteral("stockTitleLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        stockTitleLabel->setFont(font);

        horizontalLayout->addWidget(stockTitleLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        commodityStockLabel = new QLabel(StockManageForm);
        commodityStockLabel->setObjectName(QStringLiteral("commodityStockLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        commodityStockLabel->setFont(font1);

        horizontalLayout_4->addWidget(commodityStockLabel);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);


        verticalLayout_2->addLayout(horizontalLayout_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        addCommodityButton = new QPushButton(StockManageForm);
        addCommodityButton->setObjectName(QStringLiteral("addCommodityButton"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        addCommodityButton->setFont(font2);

        horizontalLayout_2->addWidget(addCommodityButton);

        updateButton = new QPushButton(StockManageForm);
        updateButton->setObjectName(QStringLiteral("updateButton"));
        updateButton->setFont(font2);

        horizontalLayout_2->addWidget(updateButton);


        verticalLayout->addLayout(horizontalLayout_2);

        stockInfoTable = new QTableWidget(StockManageForm);
        stockInfoTable->setObjectName(QStringLiteral("stockInfoTable"));

        verticalLayout->addWidget(stockInfoTable);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);

        changePriceButton = new QPushButton(StockManageForm);
        changePriceButton->setObjectName(QStringLiteral("changePriceButton"));
        changePriceButton->setFont(font2);

        horizontalLayout_8->addWidget(changePriceButton);

        deleteButton = new QPushButton(StockManageForm);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setFont(font2);

        horizontalLayout_8->addWidget(deleteButton);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_11);

        activeButton = new QPushButton(StockManageForm);
        activeButton->setObjectName(QStringLiteral("activeButton"));
        activeButton->setFont(font2);

        horizontalLayout_3->addWidget(activeButton);

        forSaleButton = new QPushButton(StockManageForm);
        forSaleButton->setObjectName(QStringLiteral("forSaleButton"));
        forSaleButton->setFont(font2);

        horizontalLayout_3->addWidget(forSaleButton);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_9->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        stockRecordLabel = new QLabel(StockManageForm);
        stockRecordLabel->setObjectName(QStringLiteral("stockRecordLabel"));
        stockRecordLabel->setFont(font1);

        horizontalLayout_5->addWidget(stockRecordLabel);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_8);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_9);

        addStockButton = new QPushButton(StockManageForm);
        addStockButton->setObjectName(QStringLiteral("addStockButton"));
        addStockButton->setFont(font2);

        horizontalLayout_6->addWidget(addStockButton);

        updateRecordButton = new QPushButton(StockManageForm);
        updateRecordButton->setObjectName(QStringLiteral("updateRecordButton"));
        updateRecordButton->setFont(font2);

        horizontalLayout_6->addWidget(updateRecordButton);


        verticalLayout_3->addLayout(horizontalLayout_6);

        stockRecordTable = new QTableWidget(StockManageForm);
        stockRecordTable->setObjectName(QStringLiteral("stockRecordTable"));

        verticalLayout_3->addWidget(stockRecordTable);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_10);

        cancelRecordButton = new QPushButton(StockManageForm);
        cancelRecordButton->setObjectName(QStringLiteral("cancelRecordButton"));
        cancelRecordButton->setFont(font2);

        horizontalLayout_7->addWidget(cancelRecordButton);


        verticalLayout_3->addLayout(horizontalLayout_7);


        horizontalLayout_9->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_9);


        retranslateUi(StockManageForm);

        QMetaObject::connectSlotsByName(StockManageForm);
    } // setupUi

    void retranslateUi(QWidget *StockManageForm)
    {
        StockManageForm->setWindowTitle(QApplication::translate("StockManageForm", "Form", 0));
        stockTitleLabel->setText(QApplication::translate("StockManageForm", "\345\272\223\345\255\230\347\256\241\347\220\206", 0));
        commodityStockLabel->setText(QApplication::translate("StockManageForm", "\345\225\206\345\223\201\344\277\241\346\201\257", 0));
        addCommodityButton->setText(QApplication::translate("StockManageForm", "\346\267\273\345\212\240\346\226\260\345\225\206\345\223\201", 0));
        updateButton->setText(QApplication::translate("StockManageForm", "\346\233\264\346\226\260\344\277\241\346\201\257", 0));
        changePriceButton->setText(QApplication::translate("StockManageForm", "\344\273\267\346\240\274\344\277\256\346\224\271", 0));
        deleteButton->setText(QApplication::translate("StockManageForm", "\345\210\240\351\231\244\345\225\206\345\223\201", 0));
        activeButton->setText(QApplication::translate("StockManageForm", "\344\270\212\346\236\266", 0));
        forSaleButton->setText(QApplication::translate("StockManageForm", "\344\270\213\346\236\266", 0));
        stockRecordLabel->setText(QApplication::translate("StockManageForm", "\345\205\245\345\272\223\346\270\205\345\215\225", 0));
        addStockButton->setText(QApplication::translate("StockManageForm", "\346\267\273\345\212\240\345\272\223\345\255\230", 0));
        updateRecordButton->setText(QApplication::translate("StockManageForm", "\346\233\264\346\226\260\344\277\241\346\201\257", 0));
        cancelRecordButton->setText(QApplication::translate("StockManageForm", "\345\217\226\346\266\210\345\205\245\345\272\223\345\215\225", 0));
    } // retranslateUi

};

namespace Ui {
    class StockManageForm: public Ui_StockManageForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOCKMANAGEFORM_H
