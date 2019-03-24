#ifndef CHESSROOMOPENDIALOG_H
#define CHESSROOMOPENDIALOG_H

#include <QDialog>
#include "chess_sys_user.h"

namespace Ui {
class ChessRoomOpenDialog;
}

class ChessRoomOpenDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChessRoomOpenDialog(ChessSysUser *user, QString name, QWidget *parent = 0);
    ~ChessRoomOpenDialog();

    void openRoom();
    void initTime();

private slots:
    void on_sureButton_clicked();

public:
    const static int RoomOpened;

private:
    Ui::ChessRoomOpenDialog *ui;
    ChessSysUser *_user;
    QString _name; // 房间名称
};

#endif // CHESSROOMOPENDIALOG_H
