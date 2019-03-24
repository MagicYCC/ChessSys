#ifndef CHESSROOMFORMULACHANGEDIALOG_H
#define CHESSROOMFORMULACHANGEDIALOG_H

#include <QDialog>
#include "chess_sys_user.h"

namespace Ui {
class ChessRoomFormulaChangeDialog;
}

class ChessRoomFormulaChangeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChessRoomFormulaChangeDialog(ChessSysUser* user, int roomId, QWidget *parent = 0);
    ~ChessRoomFormulaChangeDialog();

private slots:
    void on_sureButton_clicked();

private:
    Ui::ChessRoomFormulaChangeDialog *ui;
    ChessSysUser* _user;
    int _roomId;
};

#endif // CHESSROOMFORMULACHANGEDIALOG_H
