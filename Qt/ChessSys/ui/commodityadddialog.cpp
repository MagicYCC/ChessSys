#include "commodityadddialog.h"
#include "ui_commodityadddialog.h"
#include "commoditycategoryadddialog.h"
#include <QSqlQuery>
#include <QMessageBox>

CommodityAddDialog::CommodityAddDialog(ChessSysUser* user, QWidget *parent) :
    _user(user),
    QDialog(parent),
    ui(new Ui::CommodityAddDialog)
{
    ui->setupUi(this);

    setWindowTitle("添加商品");

    // 更新类型
    updateCategory();

    // 清空输入
    clearInput();
}

void CommodityAddDialog::clearInput(){

    ui->categoryCombo->setCurrentIndex(0);
    ui->nameEdit->clear();
    ui->priceEdit->clear();

}

void CommodityAddDialog::updateCategory(){
    ui->categoryCombo->clear();
    QString sql;
    sql = "select * from CommodityCategory";
    QSqlQuery* query = _user->queryCommand(sql);
    if(query == NULL){
        QMessageBox::warning(this, "警告", "类别添加失败！");
        return;
    }
    // 添加到categoryCombo中
    while(query->next()){
        QString name = query->value("name").toString();
        ui->categoryCombo->addItem(name);
    }
}

CommodityAddDialog::~CommodityAddDialog()
{
    delete ui;
}

void CommodityAddDialog::on_clearButton_clicked()
{
    clearInput();
}

void CommodityAddDialog::on_categoryAddButton_clicked()
{
    // 打开类别添加对话框
    CommodityCategoryAddDialog ccad(_user);
    ccad.exec();

    // 更新类别显示
    updateCategory();
}

void CommodityAddDialog::on_updateCategoryButton_clicked()
{
    updateCategory();
}

void CommodityAddDialog::on_sureButton_clicked()
{
    QString name = ui->nameEdit->text();
    if(name == ""){
        QMessageBox::warning(this, "警告", "商品名称不可为空！");
        return;
    }
    double price = ui->priceEdit->text().toDouble();
    QString categoryName = ui->categoryCombo->currentText();
    int ret = _user->addCommodity(name, ForSale, categoryName, price);
    if(ret == -101){
        QMessageBox::warning(this, "警告", "用户无权限！");
        return;
    } else if(ret == -102){
        QMessageBox::warning(this, "警告", "商品名称已经存在！");
        return;
    } else if(ret == -103){
        QMessageBox::warning(this, "警告", "类别有误！");
        return;
    }

    if(ret < 0){
        QMessageBox::warning(this, "警告", "数据库通信异常！");
        return;
    }
    QMessageBox::information(this, "通知", "商品添加成功！");
}
