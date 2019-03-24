/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *chessRoomAction;
    QAction *stockManageAction;
    QAction *userInfoAction;
    QAction *saleManageAction;
    QAction *benefitAnalyAction;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *chessRoomPage;
    QWidget *stockManagePage;
    QWidget *saleManagePage;
    QWidget *userInfoPage;
    QWidget *benefitAnalyPage;
    QMenuBar *menubar;
    QMenu *startMenu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(544, 339);
        chessRoomAction = new QAction(MainWindow);
        chessRoomAction->setObjectName(QStringLiteral("chessRoomAction"));
        stockManageAction = new QAction(MainWindow);
        stockManageAction->setObjectName(QStringLiteral("stockManageAction"));
        userInfoAction = new QAction(MainWindow);
        userInfoAction->setObjectName(QStringLiteral("userInfoAction"));
        saleManageAction = new QAction(MainWindow);
        saleManageAction->setObjectName(QStringLiteral("saleManageAction"));
        benefitAnalyAction = new QAction(MainWindow);
        benefitAnalyAction->setObjectName(QStringLiteral("benefitAnalyAction"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        chessRoomPage = new QWidget();
        chessRoomPage->setObjectName(QStringLiteral("chessRoomPage"));
        stackedWidget->addWidget(chessRoomPage);
        stockManagePage = new QWidget();
        stockManagePage->setObjectName(QStringLiteral("stockManagePage"));
        stackedWidget->addWidget(stockManagePage);
        saleManagePage = new QWidget();
        saleManagePage->setObjectName(QStringLiteral("saleManagePage"));
        stackedWidget->addWidget(saleManagePage);
        userInfoPage = new QWidget();
        userInfoPage->setObjectName(QStringLiteral("userInfoPage"));
        stackedWidget->addWidget(userInfoPage);
        benefitAnalyPage = new QWidget();
        benefitAnalyPage->setObjectName(QStringLiteral("benefitAnalyPage"));
        stackedWidget->addWidget(benefitAnalyPage);

        verticalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 544, 23));
        startMenu = new QMenu(menubar);
        startMenu->setObjectName(QStringLiteral("startMenu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(startMenu->menuAction());
        startMenu->addAction(chessRoomAction);
        startMenu->addAction(stockManageAction);
        startMenu->addAction(userInfoAction);
        startMenu->addAction(saleManageAction);
        startMenu->addAction(benefitAnalyAction);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        chessRoomAction->setText(QApplication::translate("MainWindow", "\346\243\213\347\211\214\346\210\277\351\227\264\347\256\241\347\220\206", 0));
        stockManageAction->setText(QApplication::translate("MainWindow", "\345\225\206\345\223\201\345\272\223\345\255\230\347\256\241\347\220\206", 0));
        userInfoAction->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\344\277\241\346\201\257", 0));
        saleManageAction->setText(QApplication::translate("MainWindow", "\351\224\200\345\224\256\347\256\241\347\220\206", 0));
        benefitAnalyAction->setText(QApplication::translate("MainWindow", "\346\224\266\347\233\212\345\210\206\346\236\220", 0));
        startMenu->setTitle(QApplication::translate("MainWindow", "\345\274\200\345\247\213", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
