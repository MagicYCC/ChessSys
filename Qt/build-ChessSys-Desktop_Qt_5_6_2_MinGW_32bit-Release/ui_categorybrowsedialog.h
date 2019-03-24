/********************************************************************************
** Form generated from reading UI file 'categorybrowsedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATEGORYBROWSEDIALOG_H
#define UI_CATEGORYBROWSEDIALOG_H

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
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CategoryBrowseDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *categoryBrowseLabel;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *categoryTable;
    QLabel *timeLabel;
    QLabel *startTimeLabel;
    QLabel *endTimeLabel;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *outputButton;

    void setupUi(QDialog *CategoryBrowseDialog)
    {
        if (CategoryBrowseDialog->objectName().isEmpty())
            CategoryBrowseDialog->setObjectName(QStringLiteral("CategoryBrowseDialog"));
        CategoryBrowseDialog->resize(378, 382);
        verticalLayout = new QVBoxLayout(CategoryBrowseDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        categoryBrowseLabel = new QLabel(CategoryBrowseDialog);
        categoryBrowseLabel->setObjectName(QStringLiteral("categoryBrowseLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        categoryBrowseLabel->setFont(font);

        horizontalLayout->addWidget(categoryBrowseLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        categoryTable = new QTableWidget(CategoryBrowseDialog);
        categoryTable->setObjectName(QStringLiteral("categoryTable"));

        verticalLayout->addWidget(categoryTable);

        timeLabel = new QLabel(CategoryBrowseDialog);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setBold(true);
        font1.setWeight(75);
        timeLabel->setFont(font1);

        verticalLayout->addWidget(timeLabel);

        startTimeLabel = new QLabel(CategoryBrowseDialog);
        startTimeLabel->setObjectName(QStringLiteral("startTimeLabel"));
        startTimeLabel->setFont(font1);

        verticalLayout->addWidget(startTimeLabel);

        endTimeLabel = new QLabel(CategoryBrowseDialog);
        endTimeLabel->setObjectName(QStringLiteral("endTimeLabel"));
        endTimeLabel->setFont(font1);

        verticalLayout->addWidget(endTimeLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        outputButton = new QPushButton(CategoryBrowseDialog);
        outputButton->setObjectName(QStringLiteral("outputButton"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        outputButton->setFont(font2);

        horizontalLayout_2->addWidget(outputButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(CategoryBrowseDialog);

        QMetaObject::connectSlotsByName(CategoryBrowseDialog);
    } // setupUi

    void retranslateUi(QDialog *CategoryBrowseDialog)
    {
        CategoryBrowseDialog->setWindowTitle(QApplication::translate("CategoryBrowseDialog", "Dialog", 0));
        categoryBrowseLabel->setText(QApplication::translate("CategoryBrowseDialog", "\345\210\206\347\261\273\346\265\217\350\247\210", 0));
        timeLabel->setText(QApplication::translate("CategoryBrowseDialog", "\346\227\266\351\227\264\346\256\265\357\274\232", 0));
        startTimeLabel->setText(QString());
        endTimeLabel->setText(QString());
        outputButton->setText(QApplication::translate("CategoryBrowseDialog", "\345\257\274\345\207\272", 0));
    } // retranslateUi

};

namespace Ui {
    class CategoryBrowseDialog: public Ui_CategoryBrowseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATEGORYBROWSEDIALOG_H
