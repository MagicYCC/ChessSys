/********************************************************************************
** Form generated from reading UI file 'scheduletransactiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCHEDULETRANSACTIONDIALOG_H
#define UI_SCHEDULETRANSACTIONDIALOG_H

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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ScheduleTransactionDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *scheduleTransactionLabel;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *updateButton;
    QTextEdit *detailEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *amoutLabel;
    QLineEdit *amoutEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *bonusLabel;
    QLineEdit *bonusEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *detailButton;
    QPushButton *cancelTransactionButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *sureButton;

    void setupUi(QDialog *ScheduleTransactionDialog)
    {
        if (ScheduleTransactionDialog->objectName().isEmpty())
            ScheduleTransactionDialog->setObjectName(QStringLiteral("ScheduleTransactionDialog"));
        ScheduleTransactionDialog->resize(339, 364);
        verticalLayout = new QVBoxLayout(ScheduleTransactionDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        scheduleTransactionLabel = new QLabel(ScheduleTransactionDialog);
        scheduleTransactionLabel->setObjectName(QStringLiteral("scheduleTransactionLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        scheduleTransactionLabel->setFont(font);

        horizontalLayout->addWidget(scheduleTransactionLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        updateButton = new QPushButton(ScheduleTransactionDialog);
        updateButton->setObjectName(QStringLiteral("updateButton"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        updateButton->setFont(font1);

        horizontalLayout_3->addWidget(updateButton);


        verticalLayout->addLayout(horizontalLayout_3);

        detailEdit = new QTextEdit(ScheduleTransactionDialog);
        detailEdit->setObjectName(QStringLiteral("detailEdit"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(10);
        detailEdit->setFont(font2);
        detailEdit->setReadOnly(true);

        verticalLayout->addWidget(detailEdit);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        amoutLabel = new QLabel(ScheduleTransactionDialog);
        amoutLabel->setObjectName(QStringLiteral("amoutLabel"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setBold(true);
        font3.setWeight(75);
        amoutLabel->setFont(font3);

        horizontalLayout_5->addWidget(amoutLabel);

        amoutEdit = new QLineEdit(ScheduleTransactionDialog);
        amoutEdit->setObjectName(QStringLiteral("amoutEdit"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        amoutEdit->setFont(font4);

        horizontalLayout_5->addWidget(amoutEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        bonusLabel = new QLabel(ScheduleTransactionDialog);
        bonusLabel->setObjectName(QStringLiteral("bonusLabel"));
        bonusLabel->setFont(font3);

        horizontalLayout_4->addWidget(bonusLabel);

        bonusEdit = new QLineEdit(ScheduleTransactionDialog);
        bonusEdit->setObjectName(QStringLiteral("bonusEdit"));
        bonusEdit->setFont(font4);

        horizontalLayout_4->addWidget(bonusEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        detailButton = new QPushButton(ScheduleTransactionDialog);
        detailButton->setObjectName(QStringLiteral("detailButton"));
        detailButton->setFont(font1);

        horizontalLayout_2->addWidget(detailButton);

        cancelTransactionButton = new QPushButton(ScheduleTransactionDialog);
        cancelTransactionButton->setObjectName(QStringLiteral("cancelTransactionButton"));
        cancelTransactionButton->setFont(font1);

        horizontalLayout_2->addWidget(cancelTransactionButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        sureButton = new QPushButton(ScheduleTransactionDialog);
        sureButton->setObjectName(QStringLiteral("sureButton"));
        sureButton->setFont(font1);

        horizontalLayout_2->addWidget(sureButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(ScheduleTransactionDialog);

        QMetaObject::connectSlotsByName(ScheduleTransactionDialog);
    } // setupUi

    void retranslateUi(QDialog *ScheduleTransactionDialog)
    {
        ScheduleTransactionDialog->setWindowTitle(QApplication::translate("ScheduleTransactionDialog", "Dialog", 0));
        scheduleTransactionLabel->setText(QApplication::translate("ScheduleTransactionDialog", "\351\242\204\344\272\244\346\230\223\344\277\241\346\201\257", 0));
        updateButton->setText(QApplication::translate("ScheduleTransactionDialog", "\346\233\264\346\226\260\344\272\244\346\230\223\344\277\241\346\201\257", 0));
        amoutLabel->setText(QApplication::translate("ScheduleTransactionDialog", "\345\256\236\346\224\266\351\207\221\351\242\235\357\274\232", 0));
        bonusLabel->setText(QApplication::translate("ScheduleTransactionDialog", "\347\272\242\345\214\205\357\274\232 -", 0));
        detailButton->setText(QApplication::translate("ScheduleTransactionDialog", "\350\256\242\345\215\225\350\257\246\346\203\205", 0));
        cancelTransactionButton->setText(QApplication::translate("ScheduleTransactionDialog", "\345\217\226\346\266\210\350\256\242\345\215\225", 0));
        sureButton->setText(QApplication::translate("ScheduleTransactionDialog", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class ScheduleTransactionDialog: public Ui_ScheduleTransactionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCHEDULETRANSACTIONDIALOG_H
