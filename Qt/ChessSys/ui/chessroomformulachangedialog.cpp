#include "chessroomformulachangedialog.h"
#include "ui_chessroomformulachangedialog.h"
#include <QMessageBox>

ChessRoomFormulaChangeDialog::ChessRoomFormulaChangeDialog(ChessSysUser* user,
                                                           int roomId, QWidget *parent) :
    _user(user),
    _roomId(roomId),
    QDialog(parent),
    ui(new Ui::ChessRoomFormulaChangeDialog)
{
    ui->setupUi(this);

    this->setWindowTitle("房间计费公式修改");
}

ChessRoomFormulaChangeDialog::~ChessRoomFormulaChangeDialog()
{
    delete ui;
}

// 修改公式
void ChessRoomFormulaChangeDialog::on_sureButton_clicked()
{
    QString formula = ui->formulaWidget->getFormula();

    int ret = _user->changeChessRoomFormula(_roomId, formula);

    if(ret == -101){
        QMessageBox::warning(this, "警告", "用户无权限！");
        return;
    } else if(ret == -102){
        QMessageBox::warning(this, "警告", "房间id不存在！");
        return;
    } else if(ret == -103){
        QMessageBox::warning(this, "警告", "前后公式一致！");
        return;
    }  else if(ret == -104){
        QMessageBox::warning(this, "警告", "房间未处于空闲或预定状态！");
        return;
    }
    if(ret < 0){
       QMessageBox::warning(this, "警告", "sql执行错误！");
       return;
    }
    QMessageBox::information(this, "通知", "计费公式修改成功！");
    close();
}
