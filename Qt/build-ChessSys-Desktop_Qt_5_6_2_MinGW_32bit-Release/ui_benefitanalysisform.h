/********************************************************************************
** Form generated from reading UI file 'benefitanalysisform.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BENEFITANALYSISFORM_H
#define UI_BENEFITANALYSISFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BenefitAnalysisForm
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QSplitter *splitter;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *benefitTabel;
    QSpacerItem *horizontalSpacer_4;
    QTabWidget *benefitTabWidget;
    QWidget *generalTab;
    QWidget *commodityTab;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QLabel *recordTabel;
    QSpacerItem *horizontalSpacer_6;
    QTabWidget *recordTabWidget;
    QWidget *roomTab;
    QWidget *bonusTab;

    void setupUi(QWidget *BenefitAnalysisForm)
    {
        if (BenefitAnalysisForm->objectName().isEmpty())
            BenefitAnalysisForm->setObjectName(QStringLiteral("BenefitAnalysisForm"));
        BenefitAnalysisForm->resize(555, 407);
        verticalLayout_3 = new QVBoxLayout(BenefitAnalysisForm);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(BenefitAnalysisForm);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout);

        splitter = new QSplitter(BenefitAnalysisForm);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        widget = new QWidget(splitter);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        benefitTabel = new QLabel(widget);
        benefitTabel->setObjectName(QStringLiteral("benefitTabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setBold(true);
        font1.setWeight(75);
        benefitTabel->setFont(font1);

        horizontalLayout_2->addWidget(benefitTabel);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        benefitTabWidget = new QTabWidget(widget);
        benefitTabWidget->setObjectName(QStringLiteral("benefitTabWidget"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        benefitTabWidget->setFont(font2);
        generalTab = new QWidget();
        generalTab->setObjectName(QStringLiteral("generalTab"));
        benefitTabWidget->addTab(generalTab, QString());
        commodityTab = new QWidget();
        commodityTab->setObjectName(QStringLiteral("commodityTab"));
        benefitTabWidget->addTab(commodityTab, QString());

        verticalLayout->addWidget(benefitTabWidget);

        splitter->addWidget(widget);
        widget1 = new QWidget(splitter);
        widget1->setObjectName(QStringLiteral("widget1"));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        recordTabel = new QLabel(widget1);
        recordTabel->setObjectName(QStringLiteral("recordTabel"));
        recordTabel->setFont(font1);

        horizontalLayout_3->addWidget(recordTabel);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_3);

        recordTabWidget = new QTabWidget(widget1);
        recordTabWidget->setObjectName(QStringLiteral("recordTabWidget"));
        recordTabWidget->setFont(font2);
        roomTab = new QWidget();
        roomTab->setObjectName(QStringLiteral("roomTab"));
        recordTabWidget->addTab(roomTab, QString());
        bonusTab = new QWidget();
        bonusTab->setObjectName(QStringLiteral("bonusTab"));
        recordTabWidget->addTab(bonusTab, QString());

        verticalLayout_2->addWidget(recordTabWidget);

        splitter->addWidget(widget1);

        verticalLayout_3->addWidget(splitter);


        retranslateUi(BenefitAnalysisForm);

        recordTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(BenefitAnalysisForm);
    } // setupUi

    void retranslateUi(QWidget *BenefitAnalysisForm)
    {
        BenefitAnalysisForm->setWindowTitle(QApplication::translate("BenefitAnalysisForm", "Form", 0));
        label->setText(QApplication::translate("BenefitAnalysisForm", "\346\224\266\347\233\212\345\210\206\346\236\220", 0));
        benefitTabel->setText(QApplication::translate("BenefitAnalysisForm", "\346\224\266\347\233\212", 0));
        benefitTabWidget->setTabText(benefitTabWidget->indexOf(generalTab), QApplication::translate("BenefitAnalysisForm", "Tab 1", 0));
        benefitTabWidget->setTabText(benefitTabWidget->indexOf(commodityTab), QApplication::translate("BenefitAnalysisForm", "Tab 2", 0));
        recordTabel->setText(QApplication::translate("BenefitAnalysisForm", "\350\256\260\345\275\225", 0));
        recordTabWidget->setTabText(recordTabWidget->indexOf(roomTab), QApplication::translate("BenefitAnalysisForm", "Tab 1", 0));
        recordTabWidget->setTabText(recordTabWidget->indexOf(bonusTab), QApplication::translate("BenefitAnalysisForm", "Tab 2", 0));
    } // retranslateUi

};

namespace Ui {
    class BenefitAnalysisForm: public Ui_BenefitAnalysisForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BENEFITANALYSISFORM_H
