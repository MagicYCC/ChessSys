/********************************************************************************
** Form generated from reading UI file 'transactioninfodialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSACTIONINFODIALOG_H
#define UI_TRANSACTIONINFODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TransactionInfoDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *infoLabel;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *infoEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *sureButton;

    void setupUi(QDialog *TransactionInfoDialog)
    {
        if (TransactionInfoDialog->objectName().isEmpty())
            TransactionInfoDialog->setObjectName(QStringLiteral("TransactionInfoDialog"));
        TransactionInfoDialog->resize(336, 331);
        verticalLayout = new QVBoxLayout(TransactionInfoDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        infoLabel = new QLabel(TransactionInfoDialog);
        infoLabel->setObjectName(QStringLiteral("infoLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        infoLabel->setFont(font);

        horizontalLayout->addWidget(infoLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        infoEdit = new QTextEdit(TransactionInfoDialog);
        infoEdit->setObjectName(QStringLiteral("infoEdit"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        infoEdit->setFont(font1);

        verticalLayout->addWidget(infoEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        sureButton = new QPushButton(TransactionInfoDialog);
        sureButton->setObjectName(QStringLiteral("sureButton"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        sureButton->setFont(font2);

        horizontalLayout_2->addWidget(sureButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(TransactionInfoDialog);

        QMetaObject::connectSlotsByName(TransactionInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *TransactionInfoDialog)
    {
        TransactionInfoDialog->setWindowTitle(QApplication::translate("TransactionInfoDialog", "Dialog", 0));
        infoLabel->setText(QApplication::translate("TransactionInfoDialog", "\344\272\244\346\230\223\344\277\241\346\201\257", 0));
        sureButton->setText(QApplication::translate("TransactionInfoDialog", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class TransactionInfoDialog: public Ui_TransactionInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSACTIONINFODIALOG_H
