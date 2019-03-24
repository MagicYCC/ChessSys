/********************************************************************************
** Form generated from reading UI file 'chessroomformulachangedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHESSROOMFORMULACHANGEDIALOG_H
#define UI_CHESSROOMFORMULACHANGEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <formulacreateform.h>

QT_BEGIN_NAMESPACE

class Ui_ChessRoomFormulaChangeDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *formulaChangeLabel;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *formulaGroup;
    QVBoxLayout *verticalLayout;
    FormulaCreateForm *formulaWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *sureButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *ChessRoomFormulaChangeDialog)
    {
        if (ChessRoomFormulaChangeDialog->objectName().isEmpty())
            ChessRoomFormulaChangeDialog->setObjectName(QStringLiteral("ChessRoomFormulaChangeDialog"));
        ChessRoomFormulaChangeDialog->resize(436, 174);
        verticalLayout_2 = new QVBoxLayout(ChessRoomFormulaChangeDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        formulaChangeLabel = new QLabel(ChessRoomFormulaChangeDialog);
        formulaChangeLabel->setObjectName(QStringLiteral("formulaChangeLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        formulaChangeLabel->setFont(font);

        horizontalLayout->addWidget(formulaChangeLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);

        formulaGroup = new QGroupBox(ChessRoomFormulaChangeDialog);
        formulaGroup->setObjectName(QStringLiteral("formulaGroup"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        formulaGroup->setFont(font1);
        verticalLayout = new QVBoxLayout(formulaGroup);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formulaWidget = new FormulaCreateForm(formulaGroup);
        formulaWidget->setObjectName(QStringLiteral("formulaWidget"));

        verticalLayout->addWidget(formulaWidget);


        verticalLayout_2->addWidget(formulaGroup);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        sureButton = new QPushButton(ChessRoomFormulaChangeDialog);
        sureButton->setObjectName(QStringLiteral("sureButton"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        sureButton->setFont(font2);

        horizontalLayout_2->addWidget(sureButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        retranslateUi(ChessRoomFormulaChangeDialog);

        QMetaObject::connectSlotsByName(ChessRoomFormulaChangeDialog);
    } // setupUi

    void retranslateUi(QDialog *ChessRoomFormulaChangeDialog)
    {
        ChessRoomFormulaChangeDialog->setWindowTitle(QApplication::translate("ChessRoomFormulaChangeDialog", "Dialog", 0));
        formulaChangeLabel->setText(QApplication::translate("ChessRoomFormulaChangeDialog", "\346\210\277\351\227\264\350\256\241\350\264\271\345\205\254\345\274\217\344\277\256\346\224\271", 0));
        formulaGroup->setTitle(QApplication::translate("ChessRoomFormulaChangeDialog", "\350\256\241\350\264\271\345\205\254\345\274\217", 0));
        sureButton->setText(QApplication::translate("ChessRoomFormulaChangeDialog", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class ChessRoomFormulaChangeDialog: public Ui_ChessRoomFormulaChangeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHESSROOMFORMULACHANGEDIALOG_H
