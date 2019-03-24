#include <QApplication>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSettings>
#include <QDebug>
#include "chess_sys_db/chess_sys_user.h"
#include "ui/logindialog.h"
#include "ui/mainwindow.h"
#include "chessroomform.h"
#include "chessroomadddialog.h"
#include "stockmanageform.h"
#include "commodityadddialog.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

//    a.setWindowIcon(1);

    // 添加MySql数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    // 读取ini文件中的数据库链接信息
    QSettings settings("../settings/sys_config.ini", QSettings::IniFormat);

    QString hostIp = settings.value("Database/hostIp").toString();
    int port = settings.value("Database/port").toInt();
    QString userName = settings.value("Database/userName").toString();
    QString password = settings.value("Database/password").toString();
    QString databaseName = settings.value("Database/databaseName").toString();

    // 链接到数据库
    db.setHostName(hostIp);
    db.setPort(port);
    db.setUserName(userName);
    db.setPassword(password);
    db.setDatabaseName(databaseName);

    // 打开数据库
    if(! db.open()){
        QMessageBox::warning(NULL, "警告", db.lastError().text());
        return 0;
    }

    ChessSysUser user(db);

    // 开启登录
    LoginDialog d(&user);
    d.exec();

    // 判断是否登录成功
    if(user.getLevel() == Tourist){
        // 不成功
        return 0;
    }

//    QString formula = "greatest( (floor(time/6) + 1)*1.00, 50.00) + 20";
//    int k = user.changeChessRoomFormula(1, formula);
//    qDebug() << "ret = " + QString::number(k, 10);

//    ChessRoomForm crf(&user);
//    crf.show();

//    ChessRoomAddDialog crad(&user);
//    crad.exec();

//    StockManageForm smf(&user);
//    smf.show();

//    CommodityAddDialog cad(&user);
//    cad.exec();

    MainWindow w(&user);
    w.show();

    int ret = a.exec();

    // 关闭数据库链接
    db.close();

    return ret;
}
