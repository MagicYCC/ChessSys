#include "chessroomadddialog.h"
#include "ui_chessroomadddialog.h"
#include <QMessageBox>

ChessRoomAddDialog::ChessRoomAddDialog(ChessSysUser *user, QWidget *parent) :
    _user(user),
    QDialog(parent),
    ui(new Ui::ChessRoomAddDialog)
{
    ui->setupUi(this);
    setWindowTitle("棋牌房间添加");
}

ChessRoomAddDialog::~ChessRoomAddDialog()
{
    delete ui;
}

void ChessRoomAddDialog::on_sureButton_clicked()
{
    QString name = ui->nameEdit->text();
//    QString formula = ui->formulaEdit->text();
    QString formula = ui->formulaWidget->getFormula();
    int ret = _user->createChessRoom(name, Free, formula);

    if(ret < 0){
        QMessageBox::warning(this, "警告", "房间添加失败！");
        return;
    }

    QMessageBox::information(this, "通知", "房间添加成功！");

    close();
}
