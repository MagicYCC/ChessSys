#ifndef CHESSROOMFORM_H
#define CHESSROOMFORM_H

#include <QWidget>
#include <QListWidgetItem>
#include "chess_sys_user.h"

namespace Ui {
class ChessRoomForm;
}

class ChessRoomForm : public QWidget
{
    Q_OBJECT

public:
    explicit ChessRoomForm(ChessSysUser *user, QWidget *parent = 0);
    ~ChessRoomForm();

    int updateRoomInfo();
    void clearLayout(QLayout *layout);
    void enableRoomButtons(ChessRoomState status = (ChessRoomState) 0);
    void openRoom();
    void closeRoom();
private slots:

    void on_addRoomButton_clicked();

    void on_updateButton_clicked();

    void on_openButton_clicked();

//    void on_chessRoomList_itemChanged(QListWidgetItem *item);

    void on_chessRoomList_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

//    void on_chessRoomList_currentRowChanged(int currentRow);

//    void on_chessRoomList_itemSelectionChanged();

    void on_commoditySaleButton_clicked();

    void on_suspendButton_clicked();

    void on_scheduleButton_clicked();

    void on_closeRoomButton_clicked();

    void on_changeFormulaButton_clicked();

    void on_deletRoomButton_clicked();

    void on_chessRoomList_itemDoubleClicked(QListWidgetItem *item);

protected:
    static const QString StatusStrings[];
    static const QString ImageFileDir;
    static const QString ImageFileName[];

    ChessRoomState _statusFlag = Free;

private:
    Ui::ChessRoomForm *ui;

    ChessSysUser * _user;
};

#endif // CHESSROOMFORM_H
