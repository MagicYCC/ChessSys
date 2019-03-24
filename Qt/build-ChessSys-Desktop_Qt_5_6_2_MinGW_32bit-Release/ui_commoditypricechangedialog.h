/********************************************************************************
** Form generated from reading UI file 'commoditypricechangedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMODITYPRICECHANGEDIALOG_H
#define UI_COMMODITYPRICECHANGEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CommodityPriceChangeDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *commodityPricelabel;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *nameLabel;
    QLineEdit *nameEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *newPriceLabel;
    QLineEdit *newPriceEdit;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *sureButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *CommodityPriceChangeDialog)
    {
        if (CommodityPriceChangeDialog->objectName().isEmpty())
            CommodityPriceChangeDialog->setObjectName(QStringLiteral("CommodityPriceChangeDialog"));
        CommodityPriceChangeDialog->resize(336, 148);
        verticalLayout = new QVBoxLayout(CommodityPriceChangeDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        commodityPricelabel = new QLabel(CommodityPriceChangeDialog);
        commodityPricelabel->setObjectName(QStringLiteral("commodityPricelabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        commodityPricelabel->setFont(font);

        horizontalLayout->addWidget(commodityPricelabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        nameLabel = new QLabel(CommodityPriceChangeDialog);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setBold(true);
        font1.setWeight(75);
        nameLabel->setFont(font1);

        horizontalLayout_2->addWidget(nameLabel);

        nameEdit = new QLineEdit(CommodityPriceChangeDialog);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        nameEdit->setFont(font2);
        nameEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(nameEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        newPriceLabel = new QLabel(CommodityPriceChangeDialog);
        newPriceLabel->setObjectName(QStringLiteral("newPriceLabel"));
        newPriceLabel->setFont(font1);

        horizontalLayout_3->addWidget(newPriceLabel);

        newPriceEdit = new QLineEdit(CommodityPriceChangeDialog);
        newPriceEdit->setObjectName(QStringLiteral("newPriceEdit"));
        newPriceEdit->setFont(font2);

        horizontalLayout_3->addWidget(newPriceEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        sureButton = new QPushButton(CommodityPriceChangeDialog);
        sureButton->setObjectName(QStringLiteral("sureButton"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        sureButton->setFont(font3);

        horizontalLayout_4->addWidget(sureButton);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(CommodityPriceChangeDialog);

        QMetaObject::connectSlotsByName(CommodityPriceChangeDialog);
    } // setupUi

    void retranslateUi(QDialog *CommodityPriceChangeDialog)
    {
        CommodityPriceChangeDialog->setWindowTitle(QApplication::translate("CommodityPriceChangeDialog", "Dialog", 0));
        commodityPricelabel->setText(QApplication::translate("CommodityPriceChangeDialog", "\345\225\206\345\223\201\344\273\267\346\240\274\344\277\256\346\224\271", 0));
        nameLabel->setText(QApplication::translate("CommodityPriceChangeDialog", "\345\225\206\345\223\201\345\220\215\347\247\260\357\274\232", 0));
        newPriceLabel->setText(QApplication::translate("CommodityPriceChangeDialog", "\346\226\260\344\273\267\346\240\274\357\274\232", 0));
        sureButton->setText(QApplication::translate("CommodityPriceChangeDialog", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class CommodityPriceChangeDialog: public Ui_CommodityPriceChangeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMODITYPRICECHANGEDIALOG_H
