/********************************************************************************
** Form generated from reading UI file 'scheduleroomdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCHEDULEROOMDIALOG_H
#define UI_SCHEDULEROOMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ScheduleRoomDialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *scheduleLabel;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_3;
    QLabel *scheduleTimeLabel;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QDateEdit *scheduleDateEdit;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_5;
    QTimeEdit *scheduleTimeEdit;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *remarkLabel;
    QSpacerItem *verticalSpacer;
    QTextEdit *remarkEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *sureButton;

    void setupUi(QDialog *ScheduleRoomDialog)
    {
        if (ScheduleRoomDialog->objectName().isEmpty())
            ScheduleRoomDialog->setObjectName(QStringLiteral("ScheduleRoomDialog"));
        ScheduleRoomDialog->resize(390, 297);
        verticalLayout_4 = new QVBoxLayout(ScheduleRoomDialog);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        scheduleLabel = new QLabel(ScheduleRoomDialog);
        scheduleLabel->setObjectName(QStringLiteral("scheduleLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        scheduleLabel->setFont(font);

        horizontalLayout->addWidget(scheduleLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        scheduleTimeLabel = new QLabel(ScheduleRoomDialog);
        scheduleTimeLabel->setObjectName(QStringLiteral("scheduleTimeLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setBold(true);
        font1.setWeight(75);
        scheduleTimeLabel->setFont(font1);

        verticalLayout_3->addWidget(scheduleTimeLabel);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        horizontalLayout_6->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        scheduleDateEdit = new QDateEdit(ScheduleRoomDialog);
        scheduleDateEdit->setObjectName(QStringLiteral("scheduleDateEdit"));

        horizontalLayout_4->addWidget(scheduleDateEdit);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        scheduleTimeEdit = new QTimeEdit(ScheduleRoomDialog);
        scheduleTimeEdit->setObjectName(QStringLiteral("scheduleTimeEdit"));

        horizontalLayout_5->addWidget(scheduleTimeEdit);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_5);


        horizontalLayout_6->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        remarkLabel = new QLabel(ScheduleRoomDialog);
        remarkLabel->setObjectName(QStringLiteral("remarkLabel"));
        remarkLabel->setFont(font1);

        verticalLayout->addWidget(remarkLabel);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout);

        remarkEdit = new QTextEdit(ScheduleRoomDialog);
        remarkEdit->setObjectName(QStringLiteral("remarkEdit"));

        horizontalLayout_3->addWidget(remarkEdit);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        sureButton = new QPushButton(ScheduleRoomDialog);
        sureButton->setObjectName(QStringLiteral("sureButton"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        sureButton->setFont(font2);

        horizontalLayout_2->addWidget(sureButton);


        verticalLayout_4->addLayout(horizontalLayout_2);


        retranslateUi(ScheduleRoomDialog);

        QMetaObject::connectSlotsByName(ScheduleRoomDialog);
    } // setupUi

    void retranslateUi(QDialog *ScheduleRoomDialog)
    {
        ScheduleRoomDialog->setWindowTitle(QApplication::translate("ScheduleRoomDialog", "Dialog", 0));
        scheduleLabel->setText(QApplication::translate("ScheduleRoomDialog", "\346\210\277\351\227\264\351\242\204\350\256\242", 0));
        scheduleTimeLabel->setText(QApplication::translate("ScheduleRoomDialog", "\351\242\204\350\256\242\346\227\266\351\227\264\357\274\232", 0));
        remarkLabel->setText(QApplication::translate("ScheduleRoomDialog", "\345\244\207\346\263\250\357\274\232", 0));
        sureButton->setText(QApplication::translate("ScheduleRoomDialog", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class ScheduleRoomDialog: public Ui_ScheduleRoomDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCHEDULEROOMDIALOG_H
