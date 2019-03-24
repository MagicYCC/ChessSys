#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chessroomform.h"
#include "stockmanageform.h"
#include "userinfoform.h"
#include "salemanageform.h"
#include "benefitanalysisform.h"
#include <QMessageBox>
#include <QAction>

MainWindow::MainWindow(ChessSysUser *user, QWidget *parent) :
    _user(user),
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 设置页面
    delete ui->chessRoomPage;
    ui->chessRoomPage = new ChessRoomForm(_user);
    ui->chessRoomPage->setObjectName(QStringLiteral("chessRoomPage"));
    ui->stackedWidget->addWidget(ui->chessRoomPage);

    delete ui->stockManagePage;
    ui->stockManagePage = new StockManageForm(_user);
    ui->stockManagePage->setObjectName(QStringLiteral("stockManagePage"));
    ui->stackedWidget->addWidget(ui->stockManagePage);

    delete ui->userInfoPage;
    ui->userInfoPage = new UserInfoForm(_user);
    ui->userInfoPage->setObjectName(QStringLiteral("userInfoPage"));
    ui->stackedWidget->addWidget(ui->userInfoPage);

    delete ui->saleManagePage;
    ui->saleManagePage = new SaleManageForm(_user);
    ui->saleManagePage->setObjectName(QStringLiteral("saleManagePage"));
    ui->stackedWidget->addWidget(ui->saleManagePage);

    delete ui->benefitAnalyPage;
    ui->benefitAnalyPage = new BenefitAnalysisForm(_user);
    ui->benefitAnalyPage->setObjectName(QStringLiteral("benefitAnalyPage"));
    ui->stackedWidget->addWidget(ui->benefitAnalyPage);

    // 设置标题
    setWindowTitle(_user->getName() + " - " + _user->getLevelName());

    // 页面选择
    switch (_user->getLevel()){
    case SysAdmin:
    case Boss:
    case Reception:
        ui->stackedWidget->setCurrentWidget(ui->chessRoomPage);
        break;
    default:
        ui->stackedWidget->setCurrentWidget(ui->userInfoPage);
        break;
    }



}

MainWindow::~MainWindow()
{
    delete ui;
}

// 棋牌房间切换
void MainWindow::on_chessRoomAction_triggered()
{
    ChessSysUserLevel level = _user->getLevel();
    switch (level){
    case SysAdmin:
    case Boss:
    case Reception:
        break;
    default:
        QMessageBox::warning(this, "警告", "用户无权限！");
        return;
        break;
    }
    ui->stackedWidget->setCurrentWidget(ui->chessRoomPage);
}

// 库存管理切换
void MainWindow::on_stockManageAction_triggered()
{
    ChessSysUserLevel level = _user->getLevel();
    switch (level){
    case SysAdmin:
    case Boss:
    case GodownKeeper:
        break;
    default:
        QMessageBox::warning(this, "警告", "用户无权限！");
        return;
        break;
    }
    ui->stackedWidget->setCurrentWidget(ui->stockManagePage);
}

void MainWindow::on_userInfoAction_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->userInfoPage);
}

void MainWindow::on_saleManageAction_triggered()
{
    ChessSysUserLevel level = _user->getLevel();
    switch (level){
    case SysAdmin:
    case Boss:
    case Reception:
        break;
    default:
        QMessageBox::warning(this, "警告", "用户无权限！");
        return;
        break;
    }
    ui->stackedWidget->setCurrentWidget(ui->saleManagePage);
}

void MainWindow::on_benefitAnalyAction_triggered()
{
    ChessSysUserLevel level = _user->getLevel();
    switch (level){
    case SysAdmin:
    case Boss:
        break;
    default:
        QMessageBox::warning(this, "警告", "用户无权限！");
        return;
        break;
    }
    ui->stackedWidget->setCurrentWidget(ui->benefitAnalyPage);
}
