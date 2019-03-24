/********************************************************************************
** Form generated from reading UI file 'commodityadddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMODITYADDDIALOG_H
#define UI_COMMODITYADDDIALOG_H

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

class Ui_CommodityAddDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *CommodityAddLabel;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *clearButton;
    QPushButton *categoryAddButton;
    QPushButton *updateCategoryButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *nameLabel;
    QLineEdit *nameEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *categoryLabel;
    QComboBox *categoryCombo;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_3;
    QLabel *priceLabel;
    QLineEdit *priceEdit;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *sureButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *CommodityAddDialog)
    {
        if (CommodityAddDialog->objectName().isEmpty())
            CommodityAddDialog->setObjectName(QStringLiteral("CommodityAddDialog"));
        CommodityAddDialog->resize(501, 344);
        verticalLayout = new QVBoxLayout(CommodityAddDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        CommodityAddLabel = new QLabel(CommodityAddDialog);
        CommodityAddLabel->setObjectName(QStringLiteral("CommodityAddLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        CommodityAddLabel->setFont(font);

        horizontalLayout->addWidget(CommodityAddLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        clearButton = new QPushButton(CommodityAddDialog);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        clearButton->setFont(font1);

        horizontalLayout_4->addWidget(clearButton);

        categoryAddButton = new QPushButton(CommodityAddDialog);
        categoryAddButton->setObjectName(QStringLiteral("categoryAddButton"));
        categoryAddButton->setFont(font1);

        horizontalLayout_4->addWidget(categoryAddButton);

        updateCategoryButton = new QPushButton(CommodityAddDialog);
        updateCategoryButton->setObjectName(QStringLiteral("updateCategoryButton"));
        updateCategoryButton->setFont(font1);

        horizontalLayout_4->addWidget(updateCategoryButton);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        nameLabel = new QLabel(CommodityAddDialog);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setBold(true);
        font2.setWeight(75);
        nameLabel->setFont(font2);

        horizontalLayout_2->addWidget(nameLabel);

        nameEdit = new QLineEdit(CommodityAddDialog);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        nameEdit->setFont(font3);

        horizontalLayout_2->addWidget(nameEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        categoryLabel = new QLabel(CommodityAddDialog);
        categoryLabel->setObjectName(QStringLiteral("categoryLabel"));
        categoryLabel->setFont(font2);

        horizontalLayout_6->addWidget(categoryLabel);

        categoryCombo = new QComboBox(CommodityAddDialog);
        categoryCombo->setObjectName(QStringLiteral("categoryCombo"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(categoryCombo->sizePolicy().hasHeightForWidth());
        categoryCombo->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(categoryCombo);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        priceLabel = new QLabel(CommodityAddDialog);
        priceLabel->setObjectName(QStringLiteral("priceLabel"));
        priceLabel->setFont(font2);

        horizontalLayout_3->addWidget(priceLabel);

        priceEdit = new QLineEdit(CommodityAddDialog);
        priceEdit->setObjectName(QStringLiteral("priceEdit"));
        priceEdit->setFont(font3);

        horizontalLayout_3->addWidget(priceEdit);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        sureButton = new QPushButton(CommodityAddDialog);
        sureButton->setObjectName(QStringLiteral("sureButton"));
        sureButton->setFont(font1);

        horizontalLayout_5->addWidget(sureButton);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(20, 137, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(CommodityAddDialog);

        QMetaObject::connectSlotsByName(CommodityAddDialog);
    } // setupUi

    void retranslateUi(QDialog *CommodityAddDialog)
    {
        CommodityAddDialog->setWindowTitle(QApplication::translate("CommodityAddDialog", "Dialog", 0));
        CommodityAddLabel->setText(QApplication::translate("CommodityAddDialog", "\345\225\206\345\223\201\346\267\273\345\212\240", 0));
        clearButton->setText(QApplication::translate("CommodityAddDialog", "\346\270\205\347\251\272\350\276\223\345\205\245", 0));
        categoryAddButton->setText(QApplication::translate("CommodityAddDialog", "\346\267\273\345\212\240\347\261\273\345\210\253", 0));
        updateCategoryButton->setText(QApplication::translate("CommodityAddDialog", "\346\233\264\346\226\260\347\261\273\345\210\253\344\277\241\346\201\257", 0));
        nameLabel->setText(QApplication::translate("CommodityAddDialog", "\345\225\206\345\223\201\345\220\215\347\247\260\357\274\232", 0));
        categoryLabel->setText(QApplication::translate("CommodityAddDialog", "\345\225\206\345\223\201\347\261\273\345\210\253\357\274\232", 0));
        priceLabel->setText(QApplication::translate("CommodityAddDialog", "\344\273\267\346\240\274\357\274\232", 0));
        sureButton->setText(QApplication::translate("CommodityAddDialog", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class CommodityAddDialog: public Ui_CommodityAddDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMODITYADDDIALOG_H
