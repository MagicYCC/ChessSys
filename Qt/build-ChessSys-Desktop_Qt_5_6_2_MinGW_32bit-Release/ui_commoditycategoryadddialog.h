/********************************************************************************
** Form generated from reading UI file 'commoditycategoryadddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMODITYCATEGORYADDDIALOG_H
#define UI_COMMODITYCATEGORYADDDIALOG_H

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

class Ui_CommodityCategoryAddDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *commodityCategoryAddLabel;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QLabel *nameLabel;
    QLineEdit *nameEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *sureButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *CommodityCategoryAddDialog)
    {
        if (CommodityCategoryAddDialog->objectName().isEmpty())
            CommodityCategoryAddDialog->setObjectName(QStringLiteral("CommodityCategoryAddDialog"));
        CommodityCategoryAddDialog->resize(344, 114);
        verticalLayout = new QVBoxLayout(CommodityCategoryAddDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        commodityCategoryAddLabel = new QLabel(CommodityCategoryAddDialog);
        commodityCategoryAddLabel->setObjectName(QStringLiteral("commodityCategoryAddLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        commodityCategoryAddLabel->setFont(font);

        horizontalLayout_3->addWidget(commodityCategoryAddLabel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        nameLabel = new QLabel(CommodityCategoryAddDialog);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setBold(true);
        font1.setWeight(75);
        nameLabel->setFont(font1);

        horizontalLayout->addWidget(nameLabel);

        nameEdit = new QLineEdit(CommodityCategoryAddDialog);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        nameEdit->setFont(font2);

        horizontalLayout->addWidget(nameEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        sureButton = new QPushButton(CommodityCategoryAddDialog);
        sureButton->setObjectName(QStringLiteral("sureButton"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        sureButton->setFont(font3);

        horizontalLayout_2->addWidget(sureButton);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(CommodityCategoryAddDialog);

        QMetaObject::connectSlotsByName(CommodityCategoryAddDialog);
    } // setupUi

    void retranslateUi(QDialog *CommodityCategoryAddDialog)
    {
        CommodityCategoryAddDialog->setWindowTitle(QApplication::translate("CommodityCategoryAddDialog", "Dialog", 0));
        commodityCategoryAddLabel->setText(QApplication::translate("CommodityCategoryAddDialog", "\345\225\206\345\223\201\347\261\273\345\210\253\346\267\273\345\212\240", 0));
        nameLabel->setText(QApplication::translate("CommodityCategoryAddDialog", "\347\261\273\345\210\253\345\220\215\347\247\260\357\274\232", 0));
        sureButton->setText(QApplication::translate("CommodityCategoryAddDialog", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class CommodityCategoryAddDialog: public Ui_CommodityCategoryAddDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMODITYCATEGORYADDDIALOG_H
