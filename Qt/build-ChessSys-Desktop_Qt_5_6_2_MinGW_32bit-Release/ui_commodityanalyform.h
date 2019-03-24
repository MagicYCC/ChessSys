/********************************************************************************
** Form generated from reading UI file 'commodityanalyform.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMODITYANALYFORM_H
#define UI_COMMODITYANALYFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CommodityAnalyForm
{
public:

    void setupUi(QWidget *CommodityAnalyForm)
    {
        if (CommodityAnalyForm->objectName().isEmpty())
            CommodityAnalyForm->setObjectName(QStringLiteral("CommodityAnalyForm"));
        CommodityAnalyForm->resize(400, 300);

        retranslateUi(CommodityAnalyForm);

        QMetaObject::connectSlotsByName(CommodityAnalyForm);
    } // setupUi

    void retranslateUi(QWidget *CommodityAnalyForm)
    {
        CommodityAnalyForm->setWindowTitle(QApplication::translate("CommodityAnalyForm", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class CommodityAnalyForm: public Ui_CommodityAnalyForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMODITYANALYFORM_H
