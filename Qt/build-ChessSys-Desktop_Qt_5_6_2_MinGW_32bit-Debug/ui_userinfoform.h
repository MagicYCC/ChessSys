/********************************************************************************
** Form generated from reading UI file 'userinfoform.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINFOFORM_H
#define UI_USERINFOFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserInfoForm
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *userInfoLabel;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_8;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLabel *nameLabel;
    QLineEdit *nameEdit;
    QLabel *levelLabel;
    QLineEdit *levelEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *createUserButton;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_5;
    QLabel *passwordChangeLabel;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_7;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QLabel *oldPasswordLabel;
    QLineEdit *oldPasswordEdit;
    QLabel *newPasswordLabel;
    QLineEdit *newPasswordEdit;
    QLabel *confirmPasswordLabel;
    QLineEdit *confirmPasswordEdit;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *sureButton;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *UserInfoForm)
    {
        if (UserInfoForm->objectName().isEmpty())
            UserInfoForm->setObjectName(QStringLiteral("UserInfoForm"));
        UserInfoForm->resize(437, 424);
        verticalLayout_3 = new QVBoxLayout(UserInfoForm);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        userInfoLabel = new QLabel(UserInfoForm);
        userInfoLabel->setObjectName(QStringLiteral("userInfoLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        userInfoLabel->setFont(font);

        horizontalLayout->addWidget(userInfoLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_8);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        nameLabel = new QLabel(UserInfoForm);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setBold(true);
        font1.setWeight(75);
        nameLabel->setFont(font1);

        gridLayout->addWidget(nameLabel, 0, 0, 1, 1);

        nameEdit = new QLineEdit(UserInfoForm);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        nameEdit->setFont(font2);
        nameEdit->setReadOnly(true);

        gridLayout->addWidget(nameEdit, 0, 1, 1, 1);

        levelLabel = new QLabel(UserInfoForm);
        levelLabel->setObjectName(QStringLiteral("levelLabel"));
        levelLabel->setFont(font1);

        gridLayout->addWidget(levelLabel, 1, 0, 1, 1);

        levelEdit = new QLineEdit(UserInfoForm);
        levelEdit->setObjectName(QStringLiteral("levelEdit"));
        levelEdit->setFont(font2);
        levelEdit->setReadOnly(true);

        gridLayout->addWidget(levelEdit, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        createUserButton = new QPushButton(UserInfoForm);
        createUserButton->setObjectName(QStringLiteral("createUserButton"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        createUserButton->setFont(font3);

        horizontalLayout_2->addWidget(createUserButton);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_6->addLayout(verticalLayout_2);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_9);


        verticalLayout_3->addLayout(horizontalLayout_6);

        verticalSpacer_2 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_3->addItem(verticalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        passwordChangeLabel = new QLabel(UserInfoForm);
        passwordChangeLabel->setObjectName(QStringLiteral("passwordChangeLabel"));
        passwordChangeLabel->setFont(font);

        horizontalLayout_4->addWidget(passwordChangeLabel);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        oldPasswordLabel = new QLabel(UserInfoForm);
        oldPasswordLabel->setObjectName(QStringLiteral("oldPasswordLabel"));
        oldPasswordLabel->setFont(font1);

        gridLayout_2->addWidget(oldPasswordLabel, 0, 0, 1, 1);

        oldPasswordEdit = new QLineEdit(UserInfoForm);
        oldPasswordEdit->setObjectName(QStringLiteral("oldPasswordEdit"));
        oldPasswordEdit->setFont(font2);

        gridLayout_2->addWidget(oldPasswordEdit, 0, 1, 1, 1);

        newPasswordLabel = new QLabel(UserInfoForm);
        newPasswordLabel->setObjectName(QStringLiteral("newPasswordLabel"));
        newPasswordLabel->setFont(font1);

        gridLayout_2->addWidget(newPasswordLabel, 1, 0, 1, 1);

        newPasswordEdit = new QLineEdit(UserInfoForm);
        newPasswordEdit->setObjectName(QStringLiteral("newPasswordEdit"));
        newPasswordEdit->setFont(font2);

        gridLayout_2->addWidget(newPasswordEdit, 1, 1, 1, 1);

        confirmPasswordLabel = new QLabel(UserInfoForm);
        confirmPasswordLabel->setObjectName(QStringLiteral("confirmPasswordLabel"));
        confirmPasswordLabel->setFont(font1);

        gridLayout_2->addWidget(confirmPasswordLabel, 2, 0, 1, 1);

        confirmPasswordEdit = new QLineEdit(UserInfoForm);
        confirmPasswordEdit->setObjectName(QStringLiteral("confirmPasswordEdit"));
        confirmPasswordEdit->setFont(font2);

        gridLayout_2->addWidget(confirmPasswordEdit, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        sureButton = new QPushButton(UserInfoForm);
        sureButton->setObjectName(QStringLiteral("sureButton"));
        sureButton->setFont(font3);

        horizontalLayout_3->addWidget(sureButton);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_5->addLayout(verticalLayout);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_10);


        verticalLayout_3->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(20, 89, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        retranslateUi(UserInfoForm);

        QMetaObject::connectSlotsByName(UserInfoForm);
    } // setupUi

    void retranslateUi(QWidget *UserInfoForm)
    {
        UserInfoForm->setWindowTitle(QApplication::translate("UserInfoForm", "Form", 0));
        userInfoLabel->setText(QApplication::translate("UserInfoForm", "\347\224\250\346\210\267\344\277\241\346\201\257", 0));
        nameLabel->setText(QApplication::translate("UserInfoForm", "\347\224\250\346\210\267\346\230\265\347\247\260\357\274\232", 0));
        levelLabel->setText(QApplication::translate("UserInfoForm", "\347\224\250\346\210\267\347\272\247\345\210\253\357\274\232", 0));
        createUserButton->setText(QApplication::translate("UserInfoForm", "\345\210\233\345\273\272\346\226\260\347\224\250\346\210\267", 0));
        passwordChangeLabel->setText(QApplication::translate("UserInfoForm", "\345\257\206\347\240\201\344\277\256\346\224\271", 0));
        oldPasswordLabel->setText(QApplication::translate("UserInfoForm", "\346\227\247\345\257\206\347\240\201\357\274\232", 0));
        newPasswordLabel->setText(QApplication::translate("UserInfoForm", "\346\226\260\345\257\206\347\240\201\357\274\232", 0));
        confirmPasswordLabel->setText(QApplication::translate("UserInfoForm", "\347\241\256\350\256\244\346\226\260\345\257\206\347\240\201\357\274\232", 0));
        sureButton->setText(QApplication::translate("UserInfoForm", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class UserInfoForm: public Ui_UserInfoForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINFOFORM_H
