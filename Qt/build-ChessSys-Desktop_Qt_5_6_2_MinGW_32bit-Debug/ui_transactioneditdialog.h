/********************************************************************************
** Form generated from reading UI file 'transactioneditdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSACTIONEDITDIALOG_H
#define UI_TRANSACTIONEDITDIALOG_H

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
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TransactionEditDialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *transactionEditLabel;
    QSpacerItem *horizontalSpacer_2;
    QSplitter *splitter;
    QGroupBox *roomGroup;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *roomUpdateButton;
    QTableWidget *roomTable;
    QGroupBox *commodityGroup;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *commodityUpdateButton;
    QTableWidget *commodityTable;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *commodityDeleteButton;
    QGroupBox *bonusGroup;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *bonusUpdateButton;
    QTableWidget *bonusTable;

    void setupUi(QDialog *TransactionEditDialog)
    {
        if (TransactionEditDialog->objectName().isEmpty())
            TransactionEditDialog->setObjectName(QStringLiteral("TransactionEditDialog"));
        TransactionEditDialog->resize(864, 497);
        verticalLayout_4 = new QVBoxLayout(TransactionEditDialog);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        transactionEditLabel = new QLabel(TransactionEditDialog);
        transactionEditLabel->setObjectName(QStringLiteral("transactionEditLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        transactionEditLabel->setFont(font);

        horizontalLayout->addWidget(transactionEditLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout);

        splitter = new QSplitter(TransactionEditDialog);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        roomGroup = new QGroupBox(splitter);
        roomGroup->setObjectName(QStringLiteral("roomGroup"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(roomGroup->sizePolicy().hasHeightForWidth());
        roomGroup->setSizePolicy(sizePolicy);
        roomGroup->setBaseSize(QSize(0, 0));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        roomGroup->setFont(font1);
        verticalLayout_2 = new QVBoxLayout(roomGroup);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        roomUpdateButton = new QPushButton(roomGroup);
        roomUpdateButton->setObjectName(QStringLiteral("roomUpdateButton"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        roomUpdateButton->setFont(font2);

        horizontalLayout_3->addWidget(roomUpdateButton);


        verticalLayout_2->addLayout(horizontalLayout_3);

        roomTable = new QTableWidget(roomGroup);
        roomTable->setObjectName(QStringLiteral("roomTable"));

        verticalLayout_2->addWidget(roomTable);

        splitter->addWidget(roomGroup);
        commodityGroup = new QGroupBox(splitter);
        commodityGroup->setObjectName(QStringLiteral("commodityGroup"));
        commodityGroup->setFont(font1);
        verticalLayout = new QVBoxLayout(commodityGroup);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        commodityUpdateButton = new QPushButton(commodityGroup);
        commodityUpdateButton->setObjectName(QStringLiteral("commodityUpdateButton"));
        commodityUpdateButton->setFont(font2);

        horizontalLayout_2->addWidget(commodityUpdateButton);


        verticalLayout->addLayout(horizontalLayout_2);

        commodityTable = new QTableWidget(commodityGroup);
        commodityTable->setObjectName(QStringLiteral("commodityTable"));

        verticalLayout->addWidget(commodityTable);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        commodityDeleteButton = new QPushButton(commodityGroup);
        commodityDeleteButton->setObjectName(QStringLiteral("commodityDeleteButton"));
        commodityDeleteButton->setFont(font2);

        horizontalLayout_5->addWidget(commodityDeleteButton);


        verticalLayout->addLayout(horizontalLayout_5);

        splitter->addWidget(commodityGroup);
        bonusGroup = new QGroupBox(splitter);
        bonusGroup->setObjectName(QStringLiteral("bonusGroup"));
        sizePolicy.setHeightForWidth(bonusGroup->sizePolicy().hasHeightForWidth());
        bonusGroup->setSizePolicy(sizePolicy);
        bonusGroup->setFont(font1);
        verticalLayout_3 = new QVBoxLayout(bonusGroup);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        bonusUpdateButton = new QPushButton(bonusGroup);
        bonusUpdateButton->setObjectName(QStringLiteral("bonusUpdateButton"));
        bonusUpdateButton->setFont(font2);

        horizontalLayout_4->addWidget(bonusUpdateButton);


        verticalLayout_3->addLayout(horizontalLayout_4);

        bonusTable = new QTableWidget(bonusGroup);
        bonusTable->setObjectName(QStringLiteral("bonusTable"));

        verticalLayout_3->addWidget(bonusTable);

        splitter->addWidget(bonusGroup);

        verticalLayout_4->addWidget(splitter);


        retranslateUi(TransactionEditDialog);

        QMetaObject::connectSlotsByName(TransactionEditDialog);
    } // setupUi

    void retranslateUi(QDialog *TransactionEditDialog)
    {
        TransactionEditDialog->setWindowTitle(QApplication::translate("TransactionEditDialog", "Dialog", 0));
        transactionEditLabel->setText(QApplication::translate("TransactionEditDialog", "\344\272\244\346\230\223\350\257\246\346\203\205", 0));
        roomGroup->setTitle(QApplication::translate("TransactionEditDialog", "\346\243\213\347\211\214\346\210\277\351\227\264\344\277\241\346\201\257", 0));
        roomUpdateButton->setText(QApplication::translate("TransactionEditDialog", "\346\233\264\346\226\260", 0));
        commodityGroup->setTitle(QApplication::translate("TransactionEditDialog", "\345\225\206\345\223\201\344\277\241\346\201\257", 0));
        commodityUpdateButton->setText(QApplication::translate("TransactionEditDialog", "\346\233\264\346\226\260", 0));
        commodityDeleteButton->setText(QApplication::translate("TransactionEditDialog", "\345\210\240\351\231\244", 0));
        bonusGroup->setTitle(QApplication::translate("TransactionEditDialog", "\347\272\242\345\214\205\344\277\241\346\201\257", 0));
        bonusUpdateButton->setText(QApplication::translate("TransactionEditDialog", "\346\233\264\346\226\260", 0));
    } // retranslateUi

};

namespace Ui {
    class TransactionEditDialog: public Ui_TransactionEditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSACTIONEDITDIALOG_H
