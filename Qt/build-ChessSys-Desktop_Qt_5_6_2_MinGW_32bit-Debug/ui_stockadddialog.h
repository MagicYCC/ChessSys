/********************************************************************************
** Form generated from reading UI file 'stockadddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOCKADDDIALOG_H
#define UI_STOCKADDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_StockAddDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *stockAddLabel;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *nameLabel;
    QComboBox *nameCombo;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *purchasePriceLabel;
    QLineEdit *purchasePriceEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *numberLabel;
    QLineEdit *numberEdit;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *sureButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *StockAddDialog)
    {
        if (StockAddDialog->objectName().isEmpty())
            StockAddDialog->setObjectName(QStringLiteral("StockAddDialog"));
        StockAddDialog->resize(417, 266);
        verticalLayout = new QVBoxLayout(StockAddDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        stockAddLabel = new QLabel(StockAddDialog);
        stockAddLabel->setObjectName(QStringLiteral("stockAddLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        stockAddLabel->setFont(font);

        horizontalLayout->addWidget(stockAddLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        nameLabel = new QLabel(StockAddDialog);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setBold(true);
        font1.setWeight(75);
        nameLabel->setFont(font1);

        horizontalLayout_4->addWidget(nameLabel);

        nameCombo = new QComboBox(StockAddDialog);
        nameCombo->setObjectName(QStringLiteral("nameCombo"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(nameCombo->sizePolicy().hasHeightForWidth());
        nameCombo->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        font2.setBold(true);
        font2.setWeight(75);
        nameCombo->setFont(font2);

        horizontalLayout_4->addWidget(nameCombo);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        purchasePriceLabel = new QLabel(StockAddDialog);
        purchasePriceLabel->setObjectName(QStringLiteral("purchasePriceLabel"));
        purchasePriceLabel->setFont(font1);

        horizontalLayout_3->addWidget(purchasePriceLabel);

        purchasePriceEdit = new QLineEdit(StockAddDialog);
        purchasePriceEdit->setObjectName(QStringLiteral("purchasePriceEdit"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        purchasePriceEdit->setFont(font3);

        horizontalLayout_3->addWidget(purchasePriceEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        numberLabel = new QLabel(StockAddDialog);
        numberLabel->setObjectName(QStringLiteral("numberLabel"));
        numberLabel->setFont(font1);

        horizontalLayout_2->addWidget(numberLabel);

        numberEdit = new QLineEdit(StockAddDialog);
        numberEdit->setObjectName(QStringLiteral("numberEdit"));
        numberEdit->setFont(font3);

        horizontalLayout_2->addWidget(numberEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        sureButton = new QPushButton(StockAddDialog);
        sureButton->setObjectName(QStringLiteral("sureButton"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        sureButton->setFont(font4);

        horizontalLayout_5->addWidget(sureButton);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(20, 90, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(StockAddDialog);

        QMetaObject::connectSlotsByName(StockAddDialog);
    } // setupUi

    void retranslateUi(QDialog *StockAddDialog)
    {
        StockAddDialog->setWindowTitle(QApplication::translate("StockAddDialog", "Dialog", 0));
        stockAddLabel->setText(QApplication::translate("StockAddDialog", "\345\272\223\345\255\230\346\267\273\345\212\240", 0));
        nameLabel->setText(QApplication::translate("StockAddDialog", "\345\225\206\345\223\201\345\220\215\347\247\260\357\274\232", 0));
        purchasePriceLabel->setText(QApplication::translate("StockAddDialog", "\350\277\233\350\264\247\344\273\267\346\240\274\357\274\232", 0));
        numberLabel->setText(QApplication::translate("StockAddDialog", "\346\225\260\351\207\217\357\274\232", 0));
        sureButton->setText(QApplication::translate("StockAddDialog", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class StockAddDialog: public Ui_StockAddDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOCKADDDIALOG_H
