/********************************************************************************
** Form generated from reading UI file 'chessroomadddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHESSROOMADDDIALOG_H
#define UI_CHESSROOMADDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <formulacreateform.h>

QT_BEGIN_NAMESPACE

class Ui_ChessRoomAddDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QLabel *titleLabel;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *nameLabel;
    QLineEdit *nameEdit;
    QSpacerItem *horizontalSpacer;
    QGroupBox *formulaGroup;
    QVBoxLayout *verticalLayout_2;
    FormulaCreateForm *formulaWidget;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *sureButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *ChessRoomAddDialog)
    {
        if (ChessRoomAddDialog->objectName().isEmpty())
            ChessRoomAddDialog->setObjectName(QStringLiteral("ChessRoomAddDialog"));
        ChessRoomAddDialog->resize(427, 321);
        verticalLayout = new QVBoxLayout(ChessRoomAddDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        titleLabel = new QLabel(ChessRoomAddDialog);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        titleLabel->setFont(font);

        horizontalLayout->addWidget(titleLabel);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        nameLabel = new QLabel(ChessRoomAddDialog);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setBold(true);
        font1.setWeight(75);
        nameLabel->setFont(font1);

        horizontalLayout_2->addWidget(nameLabel);

        nameEdit = new QLineEdit(ChessRoomAddDialog);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        nameEdit->setFont(font2);

        horizontalLayout_2->addWidget(nameEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        formulaGroup = new QGroupBox(ChessRoomAddDialog);
        formulaGroup->setObjectName(QStringLiteral("formulaGroup"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font3.setBold(false);
        font3.setWeight(50);
        formulaGroup->setFont(font3);
        verticalLayout_2 = new QVBoxLayout(formulaGroup);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        formulaWidget = new FormulaCreateForm(formulaGroup);
        formulaWidget->setObjectName(QStringLiteral("formulaWidget"));

        verticalLayout_2->addWidget(formulaWidget);


        verticalLayout->addWidget(formulaGroup);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        sureButton = new QPushButton(ChessRoomAddDialog);
        sureButton->setObjectName(QStringLiteral("sureButton"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        font4.setBold(false);
        font4.setWeight(50);
        sureButton->setFont(font4);

        horizontalLayout_4->addWidget(sureButton);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 156, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(ChessRoomAddDialog);

        QMetaObject::connectSlotsByName(ChessRoomAddDialog);
    } // setupUi

    void retranslateUi(QDialog *ChessRoomAddDialog)
    {
        ChessRoomAddDialog->setWindowTitle(QApplication::translate("ChessRoomAddDialog", "Dialog", 0));
        titleLabel->setText(QApplication::translate("ChessRoomAddDialog", "\346\243\213\347\211\214\346\210\277\351\227\264\346\267\273\345\212\240", 0));
        nameLabel->setText(QApplication::translate("ChessRoomAddDialog", "\346\210\277\351\227\264\345\220\215\357\274\232", 0));
        formulaGroup->setTitle(QApplication::translate("ChessRoomAddDialog", "\350\256\241\350\264\271\345\205\254\345\274\217", 0));
        sureButton->setText(QApplication::translate("ChessRoomAddDialog", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class ChessRoomAddDialog: public Ui_ChessRoomAddDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHESSROOMADDDIALOG_H
