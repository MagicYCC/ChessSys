/********************************************************************************
** Form generated from reading UI file 'commoditysaledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMODITYSALEDIALOG_H
#define UI_COMMODITYSALEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CommoditySaleDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *commoditySaleLabel;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *commodityListLabel;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *updateCommodityButton;
    QTableWidget *commodityTable;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_7;
    QLabel *budgetLabel;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *updateBudgetButton;
    QTextEdit *dudgetEdit;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *sureButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *CommoditySaleDialog)
    {
        if (CommoditySaleDialog->objectName().isEmpty())
            CommoditySaleDialog->setObjectName(QStringLiteral("CommoditySaleDialog"));
        CommoditySaleDialog->resize(729, 473);
        verticalLayout_3 = new QVBoxLayout(CommoditySaleDialog);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        commoditySaleLabel = new QLabel(CommoditySaleDialog);
        commoditySaleLabel->setObjectName(QStringLiteral("commoditySaleLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        commoditySaleLabel->setFont(font);

        horizontalLayout->addWidget(commoditySaleLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        commodityListLabel = new QLabel(CommoditySaleDialog);
        commodityListLabel->setObjectName(QStringLiteral("commodityListLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        commodityListLabel->setFont(font1);

        horizontalLayout_2->addWidget(commodityListLabel);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        updateCommodityButton = new QPushButton(CommoditySaleDialog);
        updateCommodityButton->setObjectName(QStringLiteral("updateCommodityButton"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        updateCommodityButton->setFont(font2);

        horizontalLayout_3->addWidget(updateCommodityButton);


        verticalLayout_2->addLayout(horizontalLayout_3);

        commodityTable = new QTableWidget(CommoditySaleDialog);
        commodityTable->setObjectName(QStringLiteral("commodityTable"));

        verticalLayout_2->addWidget(commodityTable);


        horizontalLayout_7->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        budgetLabel = new QLabel(CommoditySaleDialog);
        budgetLabel->setObjectName(QStringLiteral("budgetLabel"));
        budgetLabel->setFont(font1);

        horizontalLayout_4->addWidget(budgetLabel);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        updateBudgetButton = new QPushButton(CommoditySaleDialog);
        updateBudgetButton->setObjectName(QStringLiteral("updateBudgetButton"));
        updateBudgetButton->setFont(font2);

        horizontalLayout_5->addWidget(updateBudgetButton);


        verticalLayout->addLayout(horizontalLayout_5);

        dudgetEdit = new QTextEdit(CommoditySaleDialog);
        dudgetEdit->setObjectName(QStringLiteral("dudgetEdit"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        dudgetEdit->setFont(font3);

        verticalLayout->addWidget(dudgetEdit);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_9);

        sureButton = new QPushButton(CommoditySaleDialog);
        sureButton->setObjectName(QStringLiteral("sureButton"));
        sureButton->setFont(font2);

        horizontalLayout_6->addWidget(sureButton);


        verticalLayout->addLayout(horizontalLayout_6);


        horizontalLayout_7->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout_7);

        verticalSpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer);


        retranslateUi(CommoditySaleDialog);

        QMetaObject::connectSlotsByName(CommoditySaleDialog);
    } // setupUi

    void retranslateUi(QDialog *CommoditySaleDialog)
    {
        CommoditySaleDialog->setWindowTitle(QApplication::translate("CommoditySaleDialog", "Dialog", 0));
        commoditySaleLabel->setText(QApplication::translate("CommoditySaleDialog", "\345\225\206\345\223\201\351\224\200\345\224\256", 0));
        commodityListLabel->setText(QApplication::translate("CommoditySaleDialog", "\345\225\206\345\223\201\345\210\227\350\241\250", 0));
        updateCommodityButton->setText(QApplication::translate("CommoditySaleDialog", "\345\210\267\346\226\260\345\225\206\345\223\201\344\277\241\346\201\257", 0));
        budgetLabel->setText(QApplication::translate("CommoditySaleDialog", "\351\242\204\347\256\227", 0));
        updateBudgetButton->setText(QApplication::translate("CommoditySaleDialog", "\346\230\276\347\244\272\351\242\204\347\256\227", 0));
        sureButton->setText(QApplication::translate("CommoditySaleDialog", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class CommoditySaleDialog: public Ui_CommoditySaleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMODITYSALEDIALOG_H
