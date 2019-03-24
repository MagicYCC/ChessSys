#include "commoditycategoryadddialog.h"
#include "ui_commoditycategoryadddialog.h"
#include <QSqlQuery>
#include <QMessageBox>

CommodityCategoryAddDialog::CommodityCategoryAddDialog(ChessSysUser *user, QWidget *parent) :
    _user(user),
    QDialog(parent),
    ui(new Ui::CommodityCategoryAddDialog)
{
    ui->setupUi(this);

    setWindowTitle("商品类别添加");
}

CommodityCategoryAddDialog::~CommodityCategoryAddDialog()
{
    delete ui;
}

void CommodityCategoryAddDialog::on_sureButton_clicked()
{
    QString name = ui->nameEdit->text();
    if(name == "") {
        QMessageBox::warning(this, "警告", "类别名称不可为空！");
    }

    int ret = _user->addCommodityCategory(name);
    if(ret == -101){
        QMessageBox::warning(this, "警告", "用户无权限！");
        return;
    } else if(ret == -102){
        QMessageBox::warning(this, "警告", "类别名称已经存在！");
        return;
    }
    if(ret < 0){
        QMessageBox::warning(this, "警告", "数据库通信异常！");
        return;
    }

    QMessageBox::information(this, "通知", "商品类别添加成功！");
}
