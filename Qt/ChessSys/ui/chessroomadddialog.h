#ifndef CHESSROOMADDDIALOG_H
#define CHESSROOMADDDIALOG_H

#include <QDialog>
#include "chess_sys_user.h"

namespace Ui {
class ChessRoomAddDialog;
}

class ChessRoomAddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChessRoomAddDialog(ChessSysUser *user, QWidget *parent = 0);
    ~ChessRoomAddDialog();

private slots:

    void on_sureButton_clicked();

private:
    Ui::ChessRoomAddDialog *ui;

    ChessSysUser *_user;
};

#endif // CHESSROOMADDDIALOG_H
