#include "commoditypricechangedialog.h"
#include "ui_commoditypricechangedialog.h"
#include <QMessageBox>

CommodityPriceChangeDialog::CommodityPriceChangeDialog(ChessSysUser* user, QString name, QWidget *parent) :
    _user(user),
    _name(name),
    QDialog(parent),
    ui(new Ui::CommodityPriceChangeDialog)
{
    ui->setupUi(this);
    ui->nameEdit->setText(_name);
}

CommodityPriceChangeDialog::~CommodityPriceChangeDialog()
{
    delete ui;
}

void CommodityPriceChangeDialog::on_sureButton_clicked()
{
    int ret = QMessageBox::question(
                this,
                "", "确实要修改价格吗?",
                QMessageBox::Ok|
                QMessageBox::Cancel
                );

    switch(ret){
    case QMessageBox::Ok:
//        qDebug() << "i am ok";
        break;
    case QMessageBox::Cancel:
//        qDebug() << "i am bad";
        return;
        break;
    default:
        break;
    }

    double price = ui->newPriceEdit->text().toDouble();
    ret = _user->changeCommodityPrice(_name, price);
    if(ret < 0){
        QMessageBox::warning(this, "警告", "价格修改异常！");
        return;
    }
    QMessageBox::information(this, "通知", "价格修改成功！");
}
