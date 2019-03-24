/********************************************************************************
** Form generated from reading UI file 'timeslotform.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMESLOTFORM_H
#define UI_TIMESLOTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TimeSlotForm
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *timeSlotLabel;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *startTimeLabel;
    QDateEdit *startDateEdit;
    QTimeEdit *startTimeEdit;
    QCheckBox *startCheck;
    QHBoxLayout *horizontalLayout_2;
    QLabel *endTimeLabel;
    QDateEdit *endDateEdit;
    QTimeEdit *endTimeEdit;
    QCheckBox *endCheck;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *TimeSlotForm)
    {
        if (TimeSlotForm->objectName().isEmpty())
            TimeSlotForm->setObjectName(QStringLiteral("TimeSlotForm"));
        TimeSlotForm->resize(338, 112);
        verticalLayout = new QVBoxLayout(TimeSlotForm);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        timeSlotLabel = new QLabel(TimeSlotForm);
        timeSlotLabel->setObjectName(QStringLiteral("timeSlotLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setBold(true);
        font.setWeight(75);
        timeSlotLabel->setFont(font);

        horizontalLayout_3->addWidget(timeSlotLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        startTimeLabel = new QLabel(TimeSlotForm);
        startTimeLabel->setObjectName(QStringLiteral("startTimeLabel"));
        startTimeLabel->setFont(font);

        horizontalLayout->addWidget(startTimeLabel);

        startDateEdit = new QDateEdit(TimeSlotForm);
        startDateEdit->setObjectName(QStringLiteral("startDateEdit"));

        horizontalLayout->addWidget(startDateEdit);

        startTimeEdit = new QTimeEdit(TimeSlotForm);
        startTimeEdit->setObjectName(QStringLiteral("startTimeEdit"));

        horizontalLayout->addWidget(startTimeEdit);

        startCheck = new QCheckBox(TimeSlotForm);
        startCheck->setObjectName(QStringLiteral("startCheck"));
        startCheck->setChecked(false);

        horizontalLayout->addWidget(startCheck);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        endTimeLabel = new QLabel(TimeSlotForm);
        endTimeLabel->setObjectName(QStringLiteral("endTimeLabel"));
        endTimeLabel->setFont(font);

        horizontalLayout_2->addWidget(endTimeLabel);

        endDateEdit = new QDateEdit(TimeSlotForm);
        endDateEdit->setObjectName(QStringLiteral("endDateEdit"));

        horizontalLayout_2->addWidget(endDateEdit);

        endTimeEdit = new QTimeEdit(TimeSlotForm);
        endTimeEdit->setObjectName(QStringLiteral("endTimeEdit"));

        horizontalLayout_2->addWidget(endTimeEdit);

        endCheck = new QCheckBox(TimeSlotForm);
        endCheck->setObjectName(QStringLiteral("endCheck"));

        horizontalLayout_2->addWidget(endCheck);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(TimeSlotForm);

        QMetaObject::connectSlotsByName(TimeSlotForm);
    } // setupUi

    void retranslateUi(QWidget *TimeSlotForm)
    {
        TimeSlotForm->setWindowTitle(QApplication::translate("TimeSlotForm", "Form", 0));
        timeSlotLabel->setText(QApplication::translate("TimeSlotForm", "\346\227\266\351\227\264\346\256\265\357\274\232", 0));
        startTimeLabel->setText(QApplication::translate("TimeSlotForm", "\350\265\267\345\247\213\346\227\266\351\227\264\357\274\232", 0));
        startCheck->setText(QString());
        endTimeLabel->setText(QApplication::translate("TimeSlotForm", "\347\273\210\346\255\242\346\227\266\351\227\264\357\274\232", 0));
        endCheck->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TimeSlotForm: public Ui_TimeSlotForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMESLOTFORM_H
