#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "chess_sys_db/chess_sys_user.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(ChessSysUser *user, QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_chessRoomAction_triggered();

    void on_stockManageAction_triggered();

    void on_userInfoAction_triggered();

    void on_saleManageAction_triggered();

    void on_benefitAnalyAction_triggered();

private:
    Ui::MainWindow *ui;

    ChessSysUser *_user;
};

#endif // MAINWINDOW_H
