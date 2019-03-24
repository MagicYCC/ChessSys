/********************************************************************************
** Form generated from reading UI file 'usercreatedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERCREATEDIALOG_H
#define UI_USERCREATEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_UserCreateDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QLabel *crateUserLabel;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *nameLabel;
    QLineEdit *nameEdit;
    QLabel *levelLabel;
    QComboBox *levelCombo;
    QLabel *pwdLabel;
    QLineEdit *pwdEdit;
    QLabel *confirmPwdLabel;
    QLineEdit *confirmPwdEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *sureButton;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *UserCreateDialog)
    {
        if (UserCreateDialog->objectName().isEmpty())
            UserCreateDialog->setObjectName(QStringLiteral("UserCreateDialog"));
        UserCreateDialog->resize(361, 242);
        verticalLayout_2 = new QVBoxLayout(UserCreateDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        crateUserLabel = new QLabel(UserCreateDialog);
        crateUserLabel->setObjectName(QStringLiteral("crateUserLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        crateUserLabel->setFont(font);

        horizontalLayout_3->addWidget(crateUserLabel);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        nameLabel = new QLabel(UserCreateDialog);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setBold(true);
        font1.setWeight(75);
        nameLabel->setFont(font1);

        gridLayout->addWidget(nameLabel, 0, 0, 1, 1);

        nameEdit = new QLineEdit(UserCreateDialog);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        nameEdit->setFont(font2);

        gridLayout->addWidget(nameEdit, 0, 1, 1, 1);

        levelLabel = new QLabel(UserCreateDialog);
        levelLabel->setObjectName(QStringLiteral("levelLabel"));
        levelLabel->setFont(font1);

        gridLayout->addWidget(levelLabel, 1, 0, 1, 1);

        levelCombo = new QComboBox(UserCreateDialog);
        levelCombo->setObjectName(QStringLiteral("levelCombo"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(levelCombo->sizePolicy().hasHeightForWidth());
        levelCombo->setSizePolicy(sizePolicy);
        levelCombo->setFont(font2);

        gridLayout->addWidget(levelCombo, 1, 1, 1, 1);

        pwdLabel = new QLabel(UserCreateDialog);
        pwdLabel->setObjectName(QStringLiteral("pwdLabel"));
        pwdLabel->setFont(font1);

        gridLayout->addWidget(pwdLabel, 2, 0, 1, 1);

        pwdEdit = new QLineEdit(UserCreateDialog);
        pwdEdit->setObjectName(QStringLiteral("pwdEdit"));
        pwdEdit->setFont(font2);

        gridLayout->addWidget(pwdEdit, 2, 1, 1, 1);

        confirmPwdLabel = new QLabel(UserCreateDialog);
        confirmPwdLabel->setObjectName(QStringLiteral("confirmPwdLabel"));
        confirmPwdLabel->setFont(font1);

        gridLayout->addWidget(confirmPwdLabel, 3, 0, 1, 1);

        confirmPwdEdit = new QLineEdit(UserCreateDialog);
        confirmPwdEdit->setObjectName(QStringLiteral("confirmPwdEdit"));
        confirmPwdEdit->setFont(font2);

        gridLayout->addWidget(confirmPwdEdit, 3, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        sureButton = new QPushButton(UserCreateDialog);
        sureButton->setObjectName(QStringLiteral("sureButton"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        sureButton->setFont(font3);

        horizontalLayout->addWidget(sureButton);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 34, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        retranslateUi(UserCreateDialog);

        QMetaObject::connectSlotsByName(UserCreateDialog);
    } // setupUi

    void retranslateUi(QDialog *UserCreateDialog)
    {
        UserCreateDialog->setWindowTitle(QApplication::translate("UserCreateDialog", "Dialog", 0));
        crateUserLabel->setText(QApplication::translate("UserCreateDialog", "\345\210\233\345\273\272\347\224\250\346\210\267", 0));
        nameLabel->setText(QApplication::translate("UserCreateDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", 0));
        levelLabel->setText(QApplication::translate("UserCreateDialog", "\347\272\247\345\210\253\357\274\232", 0));
        pwdLabel->setText(QApplication::translate("UserCreateDialog", "\345\257\206\347\240\201\357\274\232", 0));
        confirmPwdLabel->setText(QApplication::translate("UserCreateDialog", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", 0));
        sureButton->setText(QApplication::translate("UserCreateDialog", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class UserCreateDialog: public Ui_UserCreateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERCREATEDIALOG_H
