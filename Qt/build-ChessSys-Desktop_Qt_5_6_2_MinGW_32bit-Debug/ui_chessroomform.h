/********************************************************************************
** Form generated from reading UI file 'chessroomform.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHESSROOMFORM_H
#define UI_CHESSROOMFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChessRoomForm
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *addRoomButton;
    QPushButton *deletRoomButton;
    QPushButton *changeFormulaButton;
    QPushButton *updateButton;
    QHBoxLayout *horizontalLayout_5;
    QTextEdit *roomInfoText;
    QVBoxLayout *verticalLayout;
    QListWidget *chessRoomList;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *openButton;
    QPushButton *scheduleButton;
    QPushButton *suspendButton;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *commoditySaleButton;
    QPushButton *closeRoomButton;

    void setupUi(QWidget *ChessRoomForm)
    {
        if (ChessRoomForm->objectName().isEmpty())
            ChessRoomForm->setObjectName(QStringLiteral("ChessRoomForm"));
        ChessRoomForm->resize(716, 369);
        verticalLayout_2 = new QVBoxLayout(ChessRoomForm);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(ChessRoomForm);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        addRoomButton = new QPushButton(ChessRoomForm);
        addRoomButton->setObjectName(QStringLiteral("addRoomButton"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        font1.setBold(false);
        font1.setWeight(50);
        addRoomButton->setFont(font1);

        horizontalLayout_2->addWidget(addRoomButton);

        deletRoomButton = new QPushButton(ChessRoomForm);
        deletRoomButton->setObjectName(QStringLiteral("deletRoomButton"));
        deletRoomButton->setFont(font1);

        horizontalLayout_2->addWidget(deletRoomButton);

        changeFormulaButton = new QPushButton(ChessRoomForm);
        changeFormulaButton->setObjectName(QStringLiteral("changeFormulaButton"));
        changeFormulaButton->setFont(font1);

        horizontalLayout_2->addWidget(changeFormulaButton);

        updateButton = new QPushButton(ChessRoomForm);
        updateButton->setObjectName(QStringLiteral("updateButton"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        updateButton->setFont(font2);

        horizontalLayout_2->addWidget(updateButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        roomInfoText = new QTextEdit(ChessRoomForm);
        roomInfoText->setObjectName(QStringLiteral("roomInfoText"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(roomInfoText->sizePolicy().hasHeightForWidth());
        roomInfoText->setSizePolicy(sizePolicy);
        roomInfoText->setMinimumSize(QSize(100, 0));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        roomInfoText->setFont(font3);
        roomInfoText->setReadOnly(true);

        horizontalLayout_5->addWidget(roomInfoText);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        chessRoomList = new QListWidget(ChessRoomForm);
        chessRoomList->setObjectName(QStringLiteral("chessRoomList"));
        chessRoomList->setViewMode(QListView::IconMode);

        verticalLayout->addWidget(chessRoomList);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        openButton = new QPushButton(ChessRoomForm);
        openButton->setObjectName(QStringLiteral("openButton"));
        openButton->setFont(font2);

        horizontalLayout_3->addWidget(openButton);

        scheduleButton = new QPushButton(ChessRoomForm);
        scheduleButton->setObjectName(QStringLiteral("scheduleButton"));
        scheduleButton->setFont(font2);

        horizontalLayout_3->addWidget(scheduleButton);

        suspendButton = new QPushButton(ChessRoomForm);
        suspendButton->setObjectName(QStringLiteral("suspendButton"));
        suspendButton->setFont(font2);

        horizontalLayout_3->addWidget(suspendButton);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        commoditySaleButton = new QPushButton(ChessRoomForm);
        commoditySaleButton->setObjectName(QStringLiteral("commoditySaleButton"));
        commoditySaleButton->setFont(font2);

        horizontalLayout_4->addWidget(commoditySaleButton);

        closeRoomButton = new QPushButton(ChessRoomForm);
        closeRoomButton->setObjectName(QStringLiteral("closeRoomButton"));
        closeRoomButton->setFont(font2);

        horizontalLayout_4->addWidget(closeRoomButton);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_5);


        retranslateUi(ChessRoomForm);

        QMetaObject::connectSlotsByName(ChessRoomForm);
    } // setupUi

    void retranslateUi(QWidget *ChessRoomForm)
    {
        ChessRoomForm->setWindowTitle(QApplication::translate("ChessRoomForm", "\346\243\213\347\211\214\346\210\277\351\227\264\347\256\241\347\220\206", 0));
        label->setText(QApplication::translate("ChessRoomForm", "\346\243\213\347\211\214\346\210\277\351\227\264\347\256\241\347\220\206", 0));
        addRoomButton->setText(QApplication::translate("ChessRoomForm", "\346\267\273\345\212\240\346\210\277\351\227\264", 0));
        deletRoomButton->setText(QApplication::translate("ChessRoomForm", "\345\210\240\351\231\244\346\210\277\351\227\264", 0));
        changeFormulaButton->setText(QApplication::translate("ChessRoomForm", "\344\277\256\346\224\271\350\256\241\350\264\271\345\205\254\345\274\217", 0));
        updateButton->setText(QApplication::translate("ChessRoomForm", "\346\233\264\346\226\260\346\210\277\351\227\264\344\277\241\346\201\257", 0));
        openButton->setText(QApplication::translate("ChessRoomForm", "\345\274\200\345\217\260", 0));
        scheduleButton->setText(QApplication::translate("ChessRoomForm", "\351\242\204\345\256\232", 0));
        suspendButton->setText(QApplication::translate("ChessRoomForm", "\346\214\202\350\265\267", 0));
        commoditySaleButton->setText(QApplication::translate("ChessRoomForm", "\350\264\255\344\271\260\345\225\206\345\223\201", 0));
        closeRoomButton->setText(QApplication::translate("ChessRoomForm", "\347\273\223\350\264\246", 0));
    } // retranslateUi

};

namespace Ui {
    class ChessRoomForm: public Ui_ChessRoomForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHESSROOMFORM_H
