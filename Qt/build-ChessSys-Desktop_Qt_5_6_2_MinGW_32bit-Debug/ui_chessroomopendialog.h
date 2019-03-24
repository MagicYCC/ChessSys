/********************************************************************************
** Form generated from reading UI file 'chessroomopendialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHESSROOMOPENDIALOG_H
#define UI_CHESSROOMOPENDIALOG_H

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
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ChessRoomOpenDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *roomOpenLabel;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *nameLabel;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_2;
    QLabel *openTimeLabel;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_2;
    QDateEdit *openDateEdit;
    QTimeEdit *openTimeEdit;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *sureButton;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *ChessRoomOpenDialog)
    {
        if (ChessRoomOpenDialog->objectName().isEmpty())
            ChessRoomOpenDialog->setObjectName(QStringLiteral("ChessRoomOpenDialog"));
        ChessRoomOpenDialog->resize(255, 193);
        verticalLayout = new QVBoxLayout(ChessRoomOpenDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        roomOpenLabel = new QLabel(ChessRoomOpenDialog);
        roomOpenLabel->setObjectName(QStringLiteral("roomOpenLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        roomOpenLabel->setFont(font);

        horizontalLayout->addWidget(roomOpenLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        nameLabel = new QLabel(ChessRoomOpenDialog);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setBold(true);
        font1.setWeight(75);
        nameLabel->setFont(font1);

        horizontalLayout_6->addWidget(nameLabel);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        openTimeLabel = new QLabel(ChessRoomOpenDialog);
        openTimeLabel->setObjectName(QStringLiteral("openTimeLabel"));
        openTimeLabel->setFont(font1);

        horizontalLayout_2->addWidget(openTimeLabel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        openDateEdit = new QDateEdit(ChessRoomOpenDialog);
        openDateEdit->setObjectName(QStringLiteral("openDateEdit"));

        verticalLayout_2->addWidget(openDateEdit);

        openTimeEdit = new QTimeEdit(ChessRoomOpenDialog);
        openTimeEdit->setObjectName(QStringLiteral("openTimeEdit"));

        verticalLayout_2->addWidget(openTimeEdit);


        verticalLayout->addLayout(verticalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        sureButton = new QPushButton(ChessRoomOpenDialog);
        sureButton->setObjectName(QStringLiteral("sureButton"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        sureButton->setFont(font2);

        horizontalLayout_5->addWidget(sureButton);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer_2 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(ChessRoomOpenDialog);

        QMetaObject::connectSlotsByName(ChessRoomOpenDialog);
    } // setupUi

    void retranslateUi(QDialog *ChessRoomOpenDialog)
    {
        ChessRoomOpenDialog->setWindowTitle(QApplication::translate("ChessRoomOpenDialog", "Dialog", 0));
        roomOpenLabel->setText(QApplication::translate("ChessRoomOpenDialog", "\346\243\213\347\211\214\346\210\277\351\227\264\345\274\200\350\256\276", 0));
        nameLabel->setText(QApplication::translate("ChessRoomOpenDialog", "\346\210\277\351\227\264\345\220\215\357\274\232", 0));
        openTimeLabel->setText(QApplication::translate("ChessRoomOpenDialog", "\345\274\200\346\210\277\346\227\266\351\227\264\357\274\232", 0));
        sureButton->setText(QApplication::translate("ChessRoomOpenDialog", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class ChessRoomOpenDialog: public Ui_ChessRoomOpenDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHESSROOMOPENDIALOG_H
