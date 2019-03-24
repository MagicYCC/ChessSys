#include "stockadddialog.h"
#include "ui_stockadddialog.h"
#include <QMessageBox>

StockAddDialog::StockAddDialog(ChessSysUser* user, QWidget *parent) :
    _user(user),
    QDialog(parent),
    ui(new Ui::StockAddDialog)
{
    ui->setupUi(this);
    setWindowTitle("库存添加");

    // 更新商品信息
    updateCommodityInfo();
}

StockAddDialog::~StockAddDialog()
{
    delete ui;
}

// 更新商品信息
void StockAddDialog::updateCommodityInfo(){
    ui->nameCombo->clear();
    QString sql;
    sql = "select name from Commodity";
    QSqlQuery* query = _user->queryCommand(sql);
    if(query == NULL){
        QMessageBox::warning(this, "警告", "商品名称添加失败！");
        return;
    }
    // 添加到nameCombo中
    while(query->next()){
        QString name = query->value("name").toString();
        ui->nameCombo->addItem(name);
    }
}

void StockAddDialog::on_sureButton_clicked()
{
    QString name = ui->nameCombo->currentText();
    double price = ui->purchasePriceEdit->text().toDouble();
    int number = ui->numberEdit->text().toInt();
    if(name == ""){
        QMessageBox::warning(this, "警告", "商品名称错误不可为空！");
        return;
    }
    int ret = _user->storeCommodity(name, price, number);
    if(ret == -101 ){
        QMessageBox::warning(this, "警告", "用户无操作权限！");
        return;
    } else if(ret == -102){
        QMessageBox::warning(this, "警告", "商品不存在！");
        return;
    }
    if(ret < 0){
        QMessageBox::warning(this, "警告", "数据库异常！");
        return;
    }
    QMessageBox::information(this, "通知", name + "入库成功！");
}
