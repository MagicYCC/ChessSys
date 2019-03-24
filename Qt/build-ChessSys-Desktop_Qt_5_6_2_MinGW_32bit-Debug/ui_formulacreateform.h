/********************************************************************************
** Form generated from reading UI file 'formulacreateform.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMULACREATEFORM_H
#define UI_FORMULACREATEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormulaCreateForm
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *priceLabel;
    QLineEdit *priceEdit;
    QLabel *jumpTimeLabel;
    QLineEdit *jumpTimeEdit;
    QLabel *gainLabel;
    QLineEdit *gainEdit;
    QLabel *minPriceLabel;
    QLineEdit *minPriceEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *formulaCreateButton;
    QHBoxLayout *horizontalLayout_3;
    QLabel *formulaLabel;
    QLineEdit *formulaEdit;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *FormulaCreateForm)
    {
        if (FormulaCreateForm->objectName().isEmpty())
            FormulaCreateForm->setObjectName(QStringLiteral("FormulaCreateForm"));
        FormulaCreateForm->resize(420, 198);
        verticalLayout = new QVBoxLayout(FormulaCreateForm);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        priceLabel = new QLabel(FormulaCreateForm);
        priceLabel->setObjectName(QStringLiteral("priceLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setBold(true);
        font.setWeight(75);
        priceLabel->setFont(font);

        gridLayout->addWidget(priceLabel, 0, 0, 1, 1);

        priceEdit = new QLineEdit(FormulaCreateForm);
        priceEdit->setObjectName(QStringLiteral("priceEdit"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        priceEdit->setFont(font1);

        gridLayout->addWidget(priceEdit, 0, 1, 1, 1);

        jumpTimeLabel = new QLabel(FormulaCreateForm);
        jumpTimeLabel->setObjectName(QStringLiteral("jumpTimeLabel"));
        jumpTimeLabel->setFont(font);

        gridLayout->addWidget(jumpTimeLabel, 1, 0, 1, 1);

        jumpTimeEdit = new QLineEdit(FormulaCreateForm);
        jumpTimeEdit->setObjectName(QStringLiteral("jumpTimeEdit"));
        jumpTimeEdit->setFont(font1);

        gridLayout->addWidget(jumpTimeEdit, 1, 1, 1, 1);

        gainLabel = new QLabel(FormulaCreateForm);
        gainLabel->setObjectName(QStringLiteral("gainLabel"));
        gainLabel->setFont(font);

        gridLayout->addWidget(gainLabel, 2, 0, 1, 1);

        gainEdit = new QLineEdit(FormulaCreateForm);
        gainEdit->setObjectName(QStringLiteral("gainEdit"));
        gainEdit->setFont(font1);

        gridLayout->addWidget(gainEdit, 2, 1, 1, 1);

        minPriceLabel = new QLabel(FormulaCreateForm);
        minPriceLabel->setObjectName(QStringLiteral("minPriceLabel"));
        minPriceLabel->setFont(font);

        gridLayout->addWidget(minPriceLabel, 3, 0, 1, 1);

        minPriceEdit = new QLineEdit(FormulaCreateForm);
        minPriceEdit->setObjectName(QStringLiteral("minPriceEdit"));
        minPriceEdit->setFont(font1);

        gridLayout->addWidget(minPriceEdit, 3, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        formulaCreateButton = new QPushButton(FormulaCreateForm);
        formulaCreateButton->setObjectName(QStringLiteral("formulaCreateButton"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        formulaCreateButton->setFont(font2);

        horizontalLayout_2->addWidget(formulaCreateButton);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        formulaLabel = new QLabel(FormulaCreateForm);
        formulaLabel->setObjectName(QStringLiteral("formulaLabel"));
        formulaLabel->setFont(font);

        horizontalLayout_3->addWidget(formulaLabel);

        formulaEdit = new QLineEdit(FormulaCreateForm);
        formulaEdit->setObjectName(QStringLiteral("formulaEdit"));
        formulaEdit->setFont(font1);

        horizontalLayout_3->addWidget(formulaEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(FormulaCreateForm);

        QMetaObject::connectSlotsByName(FormulaCreateForm);
    } // setupUi

    void retranslateUi(QWidget *FormulaCreateForm)
    {
        FormulaCreateForm->setWindowTitle(QApplication::translate("FormulaCreateForm", "Form", 0));
        priceLabel->setText(QApplication::translate("FormulaCreateForm", "\345\260\217\346\227\266\345\215\225\344\273\267\357\274\232", 0));
        priceEdit->setText(QApplication::translate("FormulaCreateForm", "15", 0));
        jumpTimeLabel->setText(QApplication::translate("FormulaCreateForm", "\350\267\263\350\264\271\346\227\266\351\225\277\357\274\210\345\210\206\351\222\237\357\274\211\357\274\232", 0));
        jumpTimeEdit->setText(QApplication::translate("FormulaCreateForm", "6", 0));
        gainLabel->setText(QApplication::translate("FormulaCreateForm", "\351\242\235\345\244\226\345\242\236\345\200\274\357\274\232", 0));
        gainEdit->setText(QApplication::translate("FormulaCreateForm", "20", 0));
        minPriceLabel->setText(QApplication::translate("FormulaCreateForm", "\346\234\200\344\275\216\346\266\210\350\264\271\357\274\232", 0));
        minPriceEdit->setText(QApplication::translate("FormulaCreateForm", "80", 0));
        formulaCreateButton->setText(QApplication::translate("FormulaCreateForm", "\347\224\237\346\210\220\345\205\254\345\274\217", 0));
        formulaLabel->setText(QApplication::translate("FormulaCreateForm", "\345\205\254\345\274\217\357\274\232", 0));
        formulaEdit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FormulaCreateForm: public Ui_FormulaCreateForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMULACREATEFORM_H
