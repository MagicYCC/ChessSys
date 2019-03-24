/********************************************************************************
** Form generated from reading UI file 'roomrecordqueryform.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMRECORDQUERYFORM_H
#define UI_ROOMRECORDQUERYFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <timeslotform.h>

QT_BEGIN_NAMESPACE

class Ui_RoomRecordQueryForm
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *roomRecordTable;
    TimeSlotForm *timeSlotWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *outputButton;
    QPushButton *qureyButton;

    void setupUi(QWidget *RoomRecordQueryForm)
    {
        if (RoomRecordQueryForm->objectName().isEmpty())
            RoomRecordQueryForm->setObjectName(QStringLiteral("RoomRecordQueryForm"));
        RoomRecordQueryForm->resize(554, 396);
        verticalLayout = new QVBoxLayout(RoomRecordQueryForm);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        roomRecordTable = new QTableWidget(RoomRecordQueryForm);
        roomRecordTable->setObjectName(QStringLiteral("roomRecordTable"));

        verticalLayout->addWidget(roomRecordTable);

        timeSlotWidget = new TimeSlotForm(RoomRecordQueryForm);
        timeSlotWidget->setObjectName(QStringLiteral("timeSlotWidget"));

        verticalLayout->addWidget(timeSlotWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        outputButton = new QPushButton(RoomRecordQueryForm);
        outputButton->setObjectName(QStringLiteral("outputButton"));
        QFont font;
        font.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        font.setStyleStrategy(QFont::PreferAntialias);
        outputButton->setFont(font);

        horizontalLayout->addWidget(outputButton);

        qureyButton = new QPushButton(RoomRecordQueryForm);
        qureyButton->setObjectName(QStringLiteral("qureyButton"));
        qureyButton->setFont(font);

        horizontalLayout->addWidget(qureyButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(RoomRecordQueryForm);

        QMetaObject::connectSlotsByName(RoomRecordQueryForm);
    } // setupUi

    void retranslateUi(QWidget *RoomRecordQueryForm)
    {
        RoomRecordQueryForm->setWindowTitle(QApplication::translate("RoomRecordQueryForm", "Form", 0));
        outputButton->setText(QApplication::translate("RoomRecordQueryForm", "\345\257\274\345\207\272", 0));
        qureyButton->setText(QApplication::translate("RoomRecordQueryForm", "\346\237\245\350\257\242", 0));
    } // retranslateUi

};

namespace Ui {
    class RoomRecordQueryForm: public Ui_RoomRecordQueryForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMRECORDQUERYFORM_H
