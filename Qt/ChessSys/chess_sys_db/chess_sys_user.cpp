#include "chess_sys_user.h"
#include <QVariant>
#include <QDebug>
#include <QSqlError>

ChessSysUser::ChessSysUser(QSqlDatabase db):
    _id(0), _level(Tourist), _boss(0), _query(db), _db(db){


//    _query = new QSqlQuery(db);
}

//ChessSysUser::ChessSysUser(const ChessSysUser & user) {

//    _id = user._id; // 用户编号
//    _name = user._name; // 用户名
//    _password = user._password; // 密码
//    _level = user._level; // 用户级别
//    _levelName = user._levelName; // 级别名称
//    _boss = user._boss; // 老板的用户编号

//    _query = new QSqlQuery(user._db);
//}

ChessSysUser::~ChessSysUser(){
//    if( _query != NULL) {
//        delete _query;
//        _query = NULL;
//    }
}

int ChessSysUser::setName(QString name){
    // 游客级别允许修改
    if(_level > Tourist){
        return -1;
    }
    _name = name;
    return 0;
}

int ChessSysUser::setPassword(QString password){
    // 游客级别允许修改
    if(_level > Tourist){
        return -1;
    }
    _password = password;
    return 0;
}

QString ChessSysUser::getName(){
    return _name;
}

ChessSysUserLevel ChessSysUser::getLevel(){
    return _level;
}

QString ChessSysUser::getLevelName(){
    return _levelName;
}

// 更新用户级别名称
int ChessSysUser::updateLevelName(){

    QString sql = "select name from UserLevel where level = " +
            QString::number(_level, 10) + ";";

    if(!_query.exec(sql)){
        return -1;
    }

    if(!_query.next()){
        return -2;
    }
    _levelName = _query.value(0).toString();
    return 0;
}

// 登录
int ChessSysUser::login(){

    // 判断用户是否存在,并获取用户级别
    QString sql = "select id, level, boss from User where name = '" +
            _name + "';";

    if(!_query.exec(sql)){
        // sql语句执行失败
        return -1;
    }

    if(!_query.next()){
        // 用户不存在
        return -101;
    }
    int id = _query.value("id").toInt();
    int level = _query.value("level").toInt();
    int boss = _query.value("boss").toInt();

    // 判断密码是否正确
    sql = "select level from User where name = '" +
                _name + "' and password = '" + _password + "';";
    if(!_query.exec(sql)){
        return -1;
    }

    if(!_query.next()){
        // 密码不正确
        return -102;
    }

    // 登录成功
    _id = id;
    _level = (ChessSysUserLevel)level;
    _boss = boss;
    updateLevelName();

    return 0;

}

// 退出
int ChessSysUser::exit(){

    if( _level == Tourist) {
        return 0;
    }

    _level = Tourist;
    _boss = 0;
    updateLevelName();

    return 0;
}

// 创建用户
int ChessSysUser::createUser(QString name, QString password, ChessSysUserLevel level, int boss){
    int id = queryUserId(name);
    if(id > 0){
        //用户已经存在
        return -101;
    }

    switch (level){
    case Tourist:
        // 不需要创建游客类型用户
        return -104;
        break;
    case Reception:
    case GodownKeeper:
        break;
    case SysAdmin:
        if(_level != SysAdmin){
            // 只有SysAdmin才能创建SysAdmin
            return -102;
        }
        break;
    case Boss:
        if(_level != SysAdmin && _level != Boss){
            // 只有SysAdmin和Boss才能创建Boss
            return -103;
        }
        break;
    default:
        break;
    }
    QString sql;
    sql = "LOCK TABLES User WRITE;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        return -1;
    }
    QString bossStr = boss<=0?"NULL":QString::number(boss, 10);
    sql = "insert into User (name, password, level, boss) values ('" +
            name + "', '" + password + "', " + QString::number(level, 10) + ", " +
            bossStr + ");";
    if(!_query.exec(sql)){
        // sql语句执行失败
        return -1;
    }
    sql = "UNLOCK TABLES;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        return -1;
    }
    return 0;
}

// 修改用户密码
int ChessSysUser::changePassword(QString password, QString oldPwd){
    if(_level <= Tourist){
        return -11;
    }

    QString sql;
    sql = "select level from User where id = " + QString::number(_id, 10) +
            " and password = '" + oldPwd + "';";
    if(!_query.exec(sql)){
        // sql语句执行失败
        return -1;
    }

    if(!_query.next()){
        // 旧密码不正确
        return -101;
    }

    if(oldPwd == password){
        // 新旧密码一致
        return -102;
    }

    sql = "LOCK TABLES User WRITE;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        return -1;
    }
    sql = "update User set password = '" + password +
            "' where id = " + QString::number(_id, 10) + ";";
    if(!_query.exec(sql)){
        // sql语句执行失败
        return -1;
    }
    sql = "UNLOCK TABLES;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        return -1;
    }

    _password = password;

    return 0;
}

// 查询商品类别id
int ChessSysUser::queryCommodityCategory(QString name){
    QString sql;
    name = "'" + name + "'";
    sql = "select id from CommodityCategory where name = " +
            name + ";";
    if(!_query.exec(sql)){
        // sql语句执行失败
        return -1;
    }
    if(!_query.next()){
        // 不存在改用户返回0
        return 0;
    }
    int id = _query.value("id").toInt();
    return id;
}

// 查询用户id
int ChessSysUser::queryUserId(QString name){
    QString sql;
    sql = "select id from User where name = '" +
            name + "';";
    if(!_query.exec(sql)){
        // sql语句执行失败
        return -1;
    }
    if(!_query.next()){
        // 不存在改用户返回0
        return 0;
    }
    int id = _query.value("id").toInt();
    return id;
}

// 查询用户名称,返回在name引用中
int ChessSysUser::queryUserName(int id, QString &name){
    QString sql;
    sql = "select name from User where id = " +
            QString::number(id, 10) + ";";
    if(!_query.exec(sql)){
        // sql语句执行失败
        name = "";
        return -1;
    }
    if(!_query.next()){
        // 不存在改用户返回0
        return 0;
    }
    name = _query.value("name").toString();
    return id;
}

// 查询用户级别
int ChessSysUser::queryUserLevel(int id){
    QString sql;
    sql = "select level from User where id = " +
            QString::number(id, 10) + ";";
    if(!_query.exec(sql)){
        // sql语句执行失败
        return -1;
    }
    if(!_query.next()){
        // 不存在改用户返回0
        return 0;
    }
    int level = _query.value("level").toInt();
    return level;
}

// 查询用户级别
int ChessSysUser::queryUserLevel(QString name){
    QString sql;
    sql = "select level from User where name = '" +
            name + "';";
    if(!_query.exec(sql)){
        // sql语句执行失败
        return -1;
    }
    if(!_query.next()){
        // 不存在改用户返回0
        return 0;
    }
    int level = _query.value("level").toInt();
    return level;
}

// 查询form表中target字段 = id的记录的数目
int ChessSysUser::queryUserRecordCount(QString form, QString target, int id){
    return 0;
}

// 查询form表中target字段 = id(userName的id)的记录的数目
int ChessSysUser::queryUserRecordCount(QString form, QString target, QString userName){
    return 0;
}

// 查询form表中target1字段或target2 = id的记录的数目
int ChessSysUser::queryUserRecordCount(QString form, QString target1, QString target2, int id){
    return 0;
}

// 查询form表中target1字段或target2 = id(userName的id)的记录的数目
int ChessSysUser::queryUserRecordCount(QString form, QString target1, QString target2, QString userName){
    return 0;
}

// 查询form表中target字段 = id的记录是否存在
int ChessSysUser::queryIfUserRecordExist(QString form, QString target, int id){
    QString sql;
    sql = "select id from " + form + " where " + target + " = " +
            QString::number(id, 10) + ";";

    if(!_query.exec(sql)){
        // sql语句执行失败
        return -1;
    }
    if(!_query.next()){
        // 不存记录
        return 0;
    }
    return 1;
}

// 查询form表中target字段 = id(userName的id)的记录是否存在
int ChessSysUser::queryIfUserRecordExist(QString form, QString target, QString userName){
    // 获取用户id
    int id = queryUserId(userName);
    if(id <= 0){
        // 不存在用户或出错
        return id;
    }

    return queryIfUserRecordExist(form, target, id);
}

// 查询form表中target1字段或target2 = id的记录是否存在
int ChessSysUser::queryIfUserRecordExist(QString form, QString target1, QString target2, int id){
    QString sql;
    QString idStr = QString::number(id, 10);
    sql = "select id from " + form + " where " + target1 + " = " +
            idStr + " or " + target2 + " = " + idStr + ";";
    if(!_query.exec(sql)){
        // sql语句执行失败
        return -1;
    }
    if(!_query.next()){
        // 不存记录
        return 0;
    }
    return 1;
}

// 查询form表中target1字段或target2 = id(userName的id)的记录是否存在
int ChessSysUser::queryIfUserRecordExist(QString form, QString target1, QString target2, QString userName){
    // 获取用户id
    int id = queryUserId(userName);
    if(id <= 0){
        // 不存在用户或出错
        return id;
    }

    return queryIfUserRecordExist(form, target1, target2, id);
}

// 查询form表中target字段 = id的记录是否存在
int ChessSysUser::queryIfRecordExist(QString form, QString target, int id){
    QString sql;
    sql = "select id from " + form + " where " + target + " = " +
            QString::number(id, 10) + ";";

    if(!_query.exec(sql)){
        // sql语句执行失败
        return -1;
    }
    if(!_query.next()){
        // 不存记录
        return 0;
    }
    return 1;
}

// 查询商品编号
int ChessSysUser::queryCommodityId(QString name){
    QString sql;
    sql = "select id from Commodity where name = '" + name + "';";
    if(!_query.exec(sql)){
        // sql语句执行失败
        return -1;
    }
    if(!_query.next()){
        // 不存记录
        return 0;
    }
    int id = _query.value("id").toInt();
    return id;
}

// 查询商品名称
int ChessSysUser::queryCommodityName(int commodityId, QString& name){
    QString sql;
    sql = "select name from Commodity where id = " + QString::number(commodityId, 10) + ";";
    if(!_query.exec(sql)){
        // sql语句执行失败
        return -1;
    }
    if(!_query.next()){
        // 不存记录
        return 0;
    }
    name = _query.value("name").toString();
    return commodityId;
}

// 查询商品价格
int ChessSysUser::queryCommodityPrice(int commodityId, double& price){
    QString sql;
    sql = "select price from Commodity where id = " + QString::number(commodityId, 10) + ";";
    if(!_query.exec(sql)){
        // sql语句执行失败
        return -1;
    }
    if(!_query.next()){
        // 不存记录
        return 0;
    }
    price = _query.value("price").toDouble();
    return commodityId;
}

// 查询商品库存
int ChessSysUser::queryCommodityStock(int commodityId, int& stock){
    QString sql;
    sql = "select stock from Commodity where id = " + QString::number(commodityId, 10) + ";";
    if(!_query.exec(sql)){
        // sql语句执行失败
        return -1;
    }
    if(!_query.next()){
        // 不存记录
        return 0;
    }
    stock = _query.value("stock").toInt();
    return commodityId;
}

// 查询存储记录中的数量
int ChessSysUser::queryStoreRecord(int id, int& num, int& commodityId){
    QString sql;
    sql = "select commodity_id, number from GodownEntry where id = " + QString::number(id, 10) + ";";
    if(!_query.exec(sql)){
        // sql语句执行失败
        return -1;
    }
    if(!_query.next()){
        // 不存记录
        return 0;
    }
    commodityId = _query.value("commodity_id").toInt();
    num = _query.value("number").toInt();
    return id;
}

// 判断房间记录是否已经关闭,返回值=id操作成功,0:id不存在,<0错误代码
int ChessSysUser::queryIfRoomRecordClosed(int id, int& ifClosed){
    QString sql;
    int ret = 0;
    ret = queryIfRecordExist("ChessRoomRecord", "id", id);
    if(ret <= 0){
        // id不存在
        return ret;
    }

    ret = id;

    // closing_user_id不为空交易关闭
    sql = "select id from ChessRoomRecord where id = " + QString::number(id, 10) +
            " and closing_user_id is not null;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        return -1;
    }
    ifClosed = 1;
    if(!_query.next()){
        // 不存记录
        ifClosed = 0;
    }
    return ret;
}

// 判断交易是否已经关闭,返回值=id操作成功,0:id不存在,<0错误代码
int ChessSysUser::queryIfTransactionClosed(int id, int& ifClosed){
    QString sql;
    int ret = 0;
    ret = queryIfRecordExist("TransactionList", "id", id);
    if(ret <= 0){
        // id不存在
        return ret;
    }

    ret = id;

    // closing_user_id不为空交易关闭
    sql = "select id from TransactionList where id = " + QString::number(id, 10) +
            " and closing_user_id is not null;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        return -1;
    }
    ifClosed = 1;
    if(!_query.next()){
        // 不存记录
        ifClosed = 0;
    }
    return ret;
}

// 查询棋牌房间id
int ChessSysUser::queryChessRoomId(QString name){
    QString sql;
    sql = "select id from ChessRoom where name = '" + name + "';";
    if(!_query.exec(sql)){
        // sql语句执行失败
        return -1;
    }
    if(!_query.next()){
        // 不存记录
        return 0;
    }
    int id = _query.value("id").toInt();
    return id;
}

// 查询商品记录金额
int ChessSysUser::queryCommodityRecordAmout(int recordId, double& amout){
    QString sql;
    sql = "select amout from AccountSales where id = " + QString::number(recordId, 10) + ";";
    if(!_query.exec(sql)){
        // sql语句执行失败
        return -1;
    }
    if(!_query.next()){
        // 不存记录
        return 0;
    }
    amout = _query.value("amout").toDouble();
    return recordId;
}

// 查询红利金额
int ChessSysUser::queryBonusAmout(int recordId, double& amout){
    QString sql;
    sql = "select amout from BonusList where id = " + QString::number(recordId, 10) + ";";
    if(!_query.exec(sql)){
        // sql语句执行失败
        return -1;
    }
    if(!_query.next()){
        // 不存记录
        return 0;
    }
    amout = _query.value("amout").toDouble();
    return recordId;
}

// 查询棋牌房间记录金额
int ChessSysUser::queryChessRoomRecordAmout(int recordId, double& amout){
    QString sql;
    sql = "select amout from ChessRoomRecord where id = " + QString::number(recordId, 10) + ";";
    if(!_query.exec(sql)){
        // sql语句执行失败
        return -1;
    }
    if(!_query.next()){
        // 不存记录
        return 0;
    }
    amout = _query.value("amout").toDouble();
    return recordId;
}

// 查询棋牌房间id(从房间记录中查询)
int ChessSysUser::queryChessRoomIdFromRecord(int recordId, int& roomId){
    QString sql;
    sql = "select room_id from ChessRoomRecord where id = " + QString::number(recordId, 10) + ";";
    if(!_query.exec(sql)){
        // sql语句执行失败
        return -1;
    }
    if(!_query.next()){
        // 不存记录
        return 0;
    }
    roomId = _query.value("room_id").toInt();
    return recordId;
}

// 查询棋牌房间名字
int ChessSysUser::queryChessRoomName(int id, QString& name){
    QString sql;
    sql = "select name from ChessRoom where id = " + QString::number(id, 10) + ";";
    if(!_query.exec(sql)){
        // sql语句执行失败
        return -1;
    }
    if(!_query.next()){
        // 不存记录
        return 0;
    }
    name = _query.value("name").toString();
    return id;
}

// 查询棋牌房间记录(通过交易记录)
// 返回值=transactionId操作成功,0:id不存在,<0错误代码
int ChessSysUser::queryChessRoomRecordIdFromTransaction(int transactionId, int& recordId){
    if(!queryIfRecordExist("TransactionList", "id", transactionId)){
        // 交易记录不存在
        return 0;
    }
    QString sql;
    sql = "select id from ChessRoomRecord where transaction_id = " +
            QString::number(transactionId, 10) + ";";
    if(!_query.exec(sql)){
        // sql语句执行失败
        return -1;
    }
    recordId = 0;
    if(_query.next()){
        recordId = _query.value("id").toInt();
    }

    return transactionId;
}

// 查询棋牌房间当前记录id
int ChessSysUser::queryChessRoomRecordId(int id, int& recordId){
    QString sql;
    sql = "select current_record_id from ChessRoom where id = " + QString::number(id, 10) + ";";
    if(!_query.exec(sql)){
        // sql语句执行失败
        return -1;
    }
    if(!_query.next()){
        // 不存记录
        return 0;
    }
    recordId = _query.value("current_record_id").toInt();
    return id;
}

// 查询棋牌房间计费公式
int ChessSysUser::queryChessRoomFormula(int id, QString& formula){
    QString sql;
    sql = "select charging_formula from ChessRoom where id = " + QString::number(id, 10) + ";";
    if(!_query.exec(sql)){
        // sql语句执行失败
        return -1;
    }
    if(!_query.next()){
        // 不存记录
        return 0;
    }
    formula = _query.value("charging_formula").toString();
    return id;
}

// 查询记录对应的交易id
int ChessSysUser::queryTransactionIdFromRecord(QString form, int recordId, int& transactionId){
    QString sql;
//    form = "'" + form + "'";
    sql = "select transaction_id from " +
          form + " where id = " + QString::number(recordId, 10) + ";";
    if(!_query.exec(sql)){
        // sql语句执行失败
        return -1;
    }
    if(!_query.next()){
        // 不存记录
        return 0;
    }
    transactionId = _query.value("transaction_id").toInt();
    return recordId;
}

// 查询销售记录对应的交易id
int ChessSysUser::queryTransactionIdFromSaleRecord(int recordId, int& transactionId){
    QString sql;
    sql = "select transaction_id from AccountSales where id = " + QString::number(recordId, 10) + ";";
    if(!_query.exec(sql)){
        // sql语句执行失败
        return -1;
    }
    if(!_query.next()){
        // 不存记录
        return 0;
    }
    transactionId = _query.value("transaction_id").toInt();
    return recordId;
}

// 查询棋牌房间当前交易id
int ChessSysUser::queryChessTransactionId(int id, int& transactionId){
    int recordId = 0;

    // 查询房间记录id
    id = queryChessRoomRecordId(id, recordId);
    if(id == 0){
        // 记录不存在
        return 0;
    } else if(id < 0){
        //错误代码
        return id;
    }

    QString sql;
    sql = "select transaction_id from ChessRoomRecord where id = " + QString::number(recordId, 10) + ";";
    if(!_query.exec(sql)){
        // sql语句执行失败
        return -1;
    }
    if(!_query.next()){
        // 不存记录
        return 0;
    }
    transactionId = _query.value("transaction_id").toInt();
    return id;
}

// 查询房间当前计费情况 id 为房间编号
int ChessSysUser::queryChessRoomCurrentCharging(int id, int& minutes, double& amout){

    // 获取房间计费公式
    QString formula;
    int recordId = 0;
    QString sql;
    id = queryChessRoomFormula(id, formula);
    if(id == 0){
        // 记录不存在
        return 0;
    } else if(id < 0){
        //错误代码
        return id;
    }

    id = queryChessRoomRecordId(id, recordId);
    if(id == 0){
        // 记录不存在
        return 0;
    } else if(id < 0){
        //错误代码
        return id;
    }

    sql = "select time, " + formula + " as amout from "
          "(select timestampdiff(MINUTE, entry_time, current_timestamp())"
          " as time, entry_time, current_timestamp() as closing_time from ChessRoomRecord where id = " + QString::number(recordId, 10) +
          " ) as duration";
    if(!_query.exec(sql)){
        // sql语句执行失败
        qDebug() << _query.lastError().text();
        return -1;
    }
    if(!_query.next()){
       return -1;
    }
    minutes = _query.value("time").toInt();
    amout = _query.value("amout").toDouble();
    return id;
}

// 查询棋牌房间状态
int ChessSysUser::queryChessRoomStatus(int id, ChessRoomState& status){
    QString sql;
    sql = "select status from ChessRoom where id = " + QString::number(id, 10) + ";";
    if(!_query.exec(sql)){
        // sql语句执行失败
        return -1;
    }
    if(!_query.next()){
        // 不存记录
        return 0;
    }
    status = (ChessRoomState)_query.value("status").toInt();
    return id;
}

// 删除用户
int ChessSysUser::deleteUser(int id){
    if(id == _id){
        // 不允许自我删除
        return -101;
    }
    ChessSysUserLevel level;
    level = (ChessSysUserLevel) queryUserLevel(id);
    if(level == 0){
        // 不存在该用户
        return -101;
    } else if( level < 0){
        return level;
    }

    // 判断当前this用户是否有权限删除该用户
    switch (_level){
    case Tourist:
    case Reception:
    case GodownKeeper:
        // 无权删除任何用户
        return -101;
        break;
    case SysAdmin:
        // 可以删除所有用户
        break;
    case Boss:
        if(level != Reception && level != GodownKeeper){
            // 只能删除Reception和GodownKeeper
            return -102;
        }
        break;
    default:
        break;
    }

    // 判断其他表中是否有该用户的记录
    if((queryIfUserRecordExist("CommodityPriceChanges", "user_id", id))
            || (queryIfUserRecordExist("GodownEntry", "user_id", id))
            || (queryIfUserRecordExist("TransactionList", "entry_user_id", "closing_user_id", id))
            || (queryIfUserRecordExist("BonusList", "entry_user_id", id))
            || (queryIfUserRecordExist("AccountSales", "entry_user_id", id))
            || (queryIfUserRecordExist("CommodityReturn", "entry_user_id", id))
            || (queryIfUserRecordExist("ChessRoomRecord", "entry_user_id", "closing_user_id", id))
            ) {
        // 存在记录则禁止删除该用户
        return -103;
    }

    QString sql;
    sql = "LOCK TABLES User WRITE;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        return -1;
    }
    sql = "delete from User where id = " +
            QString::number(id, 10) + ";";

    if(!_query.exec(sql)){
        // sql语句执行失败
        return -1;
    }
    sql = "UNLOCK TABLES;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        return -1;
    }
    return 0;
}

// 删除用户
int ChessSysUser::deleteUser(QString name){
    int id = queryUserId(name);
    if(id == 0){
        // 不存在该用户
        return -101;
    } else if( id < 0){
        return id;
    }
    return deleteUser(id);
}

// 添加商品类别
int ChessSysUser::addCommodityCategory(QString name){

    int ret = 0;
    int id = 0;
    QString sql;

    // 判断用户是否有权限添加商品
    switch (_level){
    case SysAdmin:
    case Boss:
    case GodownKeeper:
        break;
    default:
        // 无权限添加商品
        ret = -101;
        goto exit;
        break;
    }

    // 判断类别是否已经存在
    id = queryCommodityCategory(name);

    if(id > 0){
        // 类别已存在
        ret = -102;
        goto exit;
    }
    if(id < 0) {
        // sql语句执行失败
        ret = id;
        goto exit;
    }

    // 锁定CommodityCategory
    sql = "LOCK TABLES CommodityCategory WRITE;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

    // 向CommodityCategory中插入记录
    name = "'" + name + "'";
    sql = "insert into CommodityCategory (name) values ( " +
            name + " );";

    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

    // 获取记录的id
    sql = "select last_insert_id() as `id`;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }
    if(!_query.next()){
        // 获取失败
        ret = 0;
        goto sqlExit;
    }
    id = _query.value("id").toInt();
    ret = id;
sqlExit:
    sql = "UNLOCK TABLES;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto exit;
    }
exit:
    return ret;
}

// 添加商品
int ChessSysUser::addCommodity(QString name, CommodityState status,
                                QString categoryName, double price, int stock,
                                QString barCode, QString picPath){

    int ret = 0;
    int id = 0;
    int category = 0;
    QString barCodeStr, picPathStr;
    QString sql;

    // 判断用户是否有权限添加商品
    switch (_level){
    case SysAdmin:
    case Boss:
    case GodownKeeper:
        break;
    default:
        // 无权限添加商品
        ret = -101;
        goto exit;
        break;
    }

    // 判断商品是否已经存在
    id = queryCommodityId(name);

    if(id > 0){
        // 商品已存在
        ret = -102;
        goto exit;
    }
    if(id < 0) {
        // sql语句执行失败
        ret = id;
        goto exit;
    }

    // 获取类别id
    category = queryCommodityCategory(categoryName);
    if(category == 0){
        // 类别不存在
        ret = -103;
        goto exit;
    } else if(category < 0){
        // sql语句执行失败
        ret = category;
        goto exit;
    }

    // 锁定Commodity和CommodityPriceChanges
    sql = "LOCK TABLES Commodity WRITE, CommodityPriceChanges WRITE;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

    // 向Commodity中插入记录
    barCodeStr = barCode==""?"NULL":("'" + barCode + "'");
    picPathStr = picPath==""?"NULL":("'" + picPath + "'");
    sql = "insert into Commodity (name, status, category, price, stock, bar_code, pic_path) values ( '" +
            name + "', " + QString::number(status, 10) + ", " +
            QString::number(category, 10) + ", " +
            QString::number(price, 'f', 2) + ", " +
            QString::number(stock, 10) + ", " + barCodeStr + ", " + picPathStr + ");";

    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

    // 向CommodityPriceChanges中插入记录
    id = queryCommodityId(name);
    sql = "insert into CommodityPriceChanges (commodity_id, user_id, entry_time, new_price, old_price, remark) values (" +
            QString::number(id, 10) + ", " + QString::number(_id, 10) + ", current_timestamp(), " +
            QString::number(price, 'f', 2) + ", NULL, NULL);";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

sqlExit:
    sql = "UNLOCK TABLES;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto exit;
    }
exit:
    return ret;
}

// 修改商品价格
int ChessSysUser::changeCommodityPrice(int commodityId, double price, QString remark){

    int ret = 0;
    int id = 0;
    double oldPrice;
    QString sql;

    // 判断用户是否有权限添加商品
    switch (_level){
    case SysAdmin:
    case Boss:
    case GodownKeeper:
        break;
    default:
        // 无权限添加商品
        ret = -101;
        goto exit;
        break;
    }

    // 判断商品是否已经存在并获取商品过去的价格
    id = queryCommodityPrice(commodityId, oldPrice);

    if(id == 0){
        // 商品不存在
        ret = -101;
        goto exit;
    }
    if(id < 0) {
        // sql语句执行失败
        ret = id;
        goto exit;
    }

    if(price == oldPrice){
        // 前后价格一致
        ret = -102;
        goto exit;
    }

    // 锁定Commodity和CommodityPriceChanges
    sql = "LOCK TABLES Commodity WRITE, CommodityPriceChanges WRITE;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

    // 修改Commodity表中商品的价格
    sql = "update Commodity set price = " + QString::number(price, 'f', 2) + " where id = " +
            QString::number(commodityId, 10) + ";";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

    // 向CommodityPriceChanges中插入记录
    remark = remark==""?"NULL":("'" + remark + "'");
    sql = "insert into CommodityPriceChanges (commodity_id, user_id, entry_time, new_price, old_price, remark) values (" +
            QString::number(commodityId, 10) + ", " + QString::number(_id, 10) + ", current_timestamp(), " +
            QString::number(price, 'f', 2) + ", " + QString::number(oldPrice, 'f', 2) +
            ", " + remark + ");";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

sqlExit:
    sql = "UNLOCK TABLES;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto exit;
    }
exit:
    return ret;

}

int ChessSysUser::changeCommodityPrice(QString name, double price, QString remark){
    int id = queryCommodityId(name);
    if(id == 0){
        // 商品不存在
        return -101;
    } else if (id < 0) {
        // 错误代码
        return id;
    }
    return changeCommodityPrice(id, price, remark);
}

// 删除价格修改记录
int ChessSysUser::deleteCommodityPriceChangeRecord(int recordId){

    int ret = 0;
    QString sql;

    //判断是否有权限
    if(_level != SysAdmin){
        // 只有SysAdmin有权限删除记录
        ret = -101;
        goto exit;
    }

    // 判断记录是否存在
    sql = "select id from CommodityPriceChanges where id = " + QString::number(recordId, 10) + ";";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto exit;
    }
    if(!_query.next()){
        // 不存记录
        ret = 0;
        goto exit;
    }

    // 删除记录
    sql = "LOCK TABLES CommodityPriceChanges WRITE;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }
    sql = "delete from CommodityPriceChanges where id = " +
            QString::number(recordId, 10) + ";";

    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }
sqlExit:
    sql = "UNLOCK TABLES;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto exit;
    }
exit:
    return ret;
}

// 删除商品
int ChessSysUser::deleteCommodity(int id){

    int ret = 0;
    QString name;
    QString sql;
    // 判断权限
    switch(_level){
    case SysAdmin:
    case Boss:
    case GodownKeeper:
        break;
    default:
        // 只有SysAdmin,Boss,GodownKeeper又权限删除商品
        ret = -101;
        goto exit;
        break;
    }

    id = queryCommodityName(id, name);
    if(id == 0){
        // 商品不存在
        ret = -102;
        goto exit;
    } else if(id < 0){
        // 错误代码
        ret = id;
        goto exit;
    }

    // 判断CommodityPriceChanges中是否只存在初始记录
//    sql = "select id from CommodityPriceChanges where commodity_id = " +
//            QString::number(id, 10) + " and old_price is not NULL; ";
//    if(!_query.exec(sql)){
//        // sql语句执行失败
//        ret = -1;
//        goto sqlExit;
//    }
//    if(_query.next()){
//        // 除初始记录外还有其他记录
//        ret = -103;
//        goto exit;
//    }

    // 判断其他表中是否有该商品的记录
    if(queryIfRecordExist("GodownEntry", "commodity_id", id)
            || queryIfRecordExist("AccountSales", "commodity_id", id)
            || queryIfRecordExist("CommodityReturn", "commodity_id", id)
        ) {
        // 存在记录则禁止删除该用户

        ret = -103;
        goto exit;
    }

    // 删除商品及价格变化表中的记录
    sql = "LOCK TABLES Commodity WRITE, CommodityPriceChanges WRITE;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }
    sql = "delete from Commodity where id = " +
            QString::number(id, 10) + ";";

    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

//    sql = "delete from CommodityPriceChanges where commodity_id = " +
//            QString::number(id, 10) + " and old_price is NULL;";

    sql = "delete from CommodityPriceChanges where commodity_id = " +
            QString::number(id, 10) + ";";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

sqlExit:
    sql = "UNLOCK TABLES;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto exit;
    }
exit:
    return ret;
}

int ChessSysUser::deleteCommodity(QString name){
    int id = queryCommodityId(name);
    if(id == 0){
        // 商品不存在
        return -101;
    } else if (id < 0) {
        // 错误代码
        return id;
    }
    return deleteCommodity(id);
}

// 删除商品类别
int ChessSysUser::deleteCommodityCategory(QString name){
    int ret = 0;
    int id = 0;
    QString sql;
    // 判断权限
    switch(_level){
    case SysAdmin:
    case Boss:
    case GodownKeeper:
        break;
    default:
        // 只有SysAdmin,Boss,GodownKeeper又权限删除商品
        ret = -101;
        goto exit;
        break;
    }

    // 判断类别是否存在
    id = queryCommodityCategory(name);
    if(id == 0 ){
        // 类别不存在
        ret = -101;
        goto exit;
    }

    // 判断Commodity中是否存在类别的记录
    if(queryIfRecordExist("Commodity", "category", id)
        ) {
        // 存在记录则禁止删除该用户
        ret = -103;
        goto exit;
    }

    // 删除类别记录
    sql = "delete from CommodityCategory where id = " +
            QString::number(id, 10) + ";";

    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }
sqlExit:
    sql = "UNLOCK TABLES;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto exit;
    }
exit:
    return ret;
}

// 存储商品
int ChessSysUser::storeCommodity(int id, double purchasePrice, int num, int supplierId,
                           QString remark){

    int ret = 0;
    int stock = 0;
    QString sql, supplierIdStr;

    // 判断用户权限
    switch (_level){
    case SysAdmin:
    case Boss:
    case GodownKeeper:
        break;
    default:
        // 无权限
        ret = -101;
        goto exit;
        break;
    }

    // 判断商品id是否存在
    id = queryCommodityStock(id, stock);
    if(id == 0){
        // 商品不存在
        ret = 102;
        goto exit;
    } else if(id < 0){
        // 错误代码
        ret = id;
        goto exit;
    }

    // 锁定Commodity和GodownEntry
    sql = "LOCK TABLES Commodity WRITE, GodownEntry WRITE;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

    // 向GodownEntry中插入记录
    supplierIdStr = supplierId<=0?"NULL":QString::number(supplierId, 10);
    remark = remark==""?"NULL":("'" + remark + "'");
    sql = "insert into GodownEntry (commodity_id, user_id, purchase_price, number, entry_time, supplier_id, remark) values ( " +
            QString::number(id, 10) + ", " + QString::number(_id, 10) + ", " + QString::number(purchasePrice, 'f', 2) + ", " +
            QString::number(num, 10) + ", current_timestamp(), " + supplierIdStr + ", " + remark + ");";

    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

    // 修改Commodity中stock的值
    stock = stock + num;
    sql = "update Commodity set stock = " + QString::number(stock, 10) + " where id = " +
            QString::number(id, 10) + ";";

    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }
sqlExit:
    sql = "UNLOCK TABLES;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto exit;
    }
exit:
    return ret;
}

// 存储商品
int ChessSysUser::storeCommodity(QString name, double purchasePrice, int num, int supplierId,
                           QString remark){
    int id = queryCommodityId(name);
    if(id == 0){
        // 商品不存在
        return -102;
    } else if(id < 0){
        // 错误代码
        return id;
    }
    return storeCommodity(id, purchasePrice, num, supplierId, remark);
}

// 设置商品状态
int ChessSysUser::setCommodityStatus(QString name, CommodityState status){
    int ret = 0;
    int commodityId = 0;
    QString sql;

    // 判断用户权限
    switch (_level){
    case SysAdmin:
    case Boss:
    case GodownKeeper:
        break;
    default:
        // 无权限
        ret = -101;
        goto exit;
        break;
    }

    // 判断商品是否存在
    commodityId = queryCommodityId(name);
    if(commodityId == 0){
        // 商品不存在
        ret = -102;
        goto exit;
    } else if(commodityId < 0){
        // 错误代码
        ret = commodityId;
        goto exit;
    }

    // 锁定Commodity
    sql = "LOCK TABLES Commodity WRITE;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }
//    ForSale, // 待售
//    Active // 上架
    // 修改Commodity中status字段的值
    sql = "update Commodity set status = " + QString::number((int)status, 10) + " where id = " +
            QString::number(commodityId, 10) + ";";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

sqlExit:
    sql = "UNLOCK TABLES;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto exit;
    }

exit:
    return ret;

}

// 取消入库
int ChessSysUser::cancelStore(int id){

    int ret = 0;
    int num = 0;
    int stock = 0;
    int commodityId = 0;
    QString sql;

    // 判断用户权限
    switch (_level){
    case SysAdmin:
    case Boss:
    case GodownKeeper:
        break;
    default:
        // 无权限
        ret = -101;
        goto exit;
        break;
    }

    // 获取记录信息
    id = queryStoreRecord(id, num, commodityId);
    if(id == 0){
        // 记录不存在
        ret = -102;
        goto exit;
    } else if(id < 0){
        // 错误代码
        ret = id;
        goto exit;
    }

    // 获取商品库存
    commodityId = queryCommodityStock(commodityId, stock);
    if(commodityId == 0){
        // 记录不存在
        ret = -103;
        goto exit;
    } else if(commodityId < 0){
        // 错误代码
        ret = commodityId;
        goto exit;
    }

    sql = "LOCK TABLES Commodity WRITE, GodownEntry WRITE;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }
    // 删除GodownEntry中的记录
    sql = "delete from GodownEntry where id = " +
            QString::number(id, 10) + ";";

    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

    // 修改Commodity中stock字段的值
    stock -= num;
    sql = "update Commodity set stock = " + QString::number(stock, 10) + " where id = " +
            QString::number(commodityId, 10) + ";";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

sqlExit:
    sql = "UNLOCK TABLES;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto exit;
    }

exit:
    return ret;
}

// 创建交易清单,并返回创建的清单编号
int ChessSysUser::createTransaction(QString remark){
    int ret = 0;
    int id = 0;
    QString sql;

    // 判断用户权限
    switch (_level){
    case SysAdmin:
    case Boss:
    case Reception:
        break;
    default:
        // 用户无权创建棋牌房间
        ret = -101;
        goto exit;
        break;
    }

    // 锁定表TransactionList
    sql = "LOCK TABLES TransactionList WRITE;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

    // 向TransactionList中添加记录
    remark = remark==""?"NULL":("'" + remark + "'");
    sql = "insert into TransactionList (entry_user_id, entry_time, closing_user_id, closing_time, amout, remark) values ( " +
            QString::number(_id, 10) + ", current_timestamp(), NULL, NULL, NULL," + remark + ");";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

    // 获取记录的id
    sql = "select last_insert_id() as `id`;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }
    if(!_query.next()){
        // 获取失败
        ret = 0;
        goto sqlExit;
    }
    id = _query.value("id").toInt();
    ret = id;
sqlExit:
    sql = "UNLOCK TABLES;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }
exit:
    return ret;
}

// 结束交易清单(结账)
int ChessSysUser::closeTransaction(int id, QString remark){
    int ret = 0;
    QString sql;
    double recordAmout = 0.00;
    double amout = 0.00;//总金额
    int recordId = 0;

    // 判断用户权限
    switch (_level){
    case SysAdmin:
    case Boss:
    case Reception:
        break;
    default:
        // 用户无权关闭交易
        ret = -101;
        goto exit;
        break;
    }

    // 棋牌房间结算
    sql = "select id from ChessRoomRecord where transaction_id = " +
            QString::number(id, 10) + ";";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }
    if(_query.next()){
        recordId = _query.value("id").toInt();
        closeChessRoomRecord(recordId);
        recordAmout = 0;
        queryChessRoomRecordAmout(recordId, recordAmout);
        amout += recordAmout;
    }

    // 商品结算
    sql = "select id, amout from AccountSales where transaction_id = " +
            QString::number(id, 10) + ";";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }
    while(_query.next()){
        recordId = _query.value("id").toInt();
        recordAmout = _query.value("amout").toDouble();
//        queryCommodityRecordAmout(recordId, recordAmout);

        amout += recordAmout;
    }

    // 红利结算
    sql = "select id, amout from BonusList where transaction_id = " +
            QString::number(id, 10) + ";";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }
    while(_query.next()){
        recordId = _query.value("id").toInt();
        recordAmout = _query.value("amout").toDouble();
//        queryBonusAmout(recordId, recordAmout);
        amout -= recordAmout;
    }

    // 填写

    // 锁定表TransactionList
    sql = "LOCK TABLES TransactionList WRITE;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

    // 修改TransactionList中的closing_user_id,closing_time,amout,remark
    remark = remark==""?"NULL":("'" + remark + "'");
    sql = "update TransactionList set closing_user_id = " +
            QString::number(_id, 10) + ", closing_time = current_timestamp(), amout = " +
            QString::number(amout, 'f', 2) + ", remark =" + remark + " where id = " +
            QString::number(id, 10) + ";";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }
sqlExit:
    sql = "UNLOCK TABLES;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

exit:
    return ret;
}

// 销售商品
int ChessSysUser:: sellCommodity(int transactionId, int commodityId,
                           int num, QString remark){
    int ret = 0;
    int stock = 0;
    int salesId = 0;// 生成的id
    int ifClosed = 0;// 交易是否关闭
    QString sql;

    // 判断用户权限
    switch (_level){
    case SysAdmin:
    case Boss:
    case Reception:
        break;
    default:
        // 用户无权创建棋牌房间
        ret = -101;
        goto exit;
        break;
    }

    // 判断交易是否关闭
    transactionId = queryIfTransactionClosed(transactionId, ifClosed);
    if(transactionId == 0){
        // 记录不存在
        ret = -102;
        goto exit;
    } else if(transactionId < 0){
        // 错误代码
        ret = transactionId;
        goto exit;
    }
    if(ifClosed){
        // 交易已经关闭
        ret = -103;
        goto exit;
    }

    // 获取商品库存
    commodityId = queryCommodityStock(commodityId, stock);
    if(commodityId == 0){
        // 商品不存在
        ret = -104;
        goto exit;
    } else if(commodityId <0){
        // 错误代码
        ret = commodityId;
        goto exit;
    }

    // 锁定表Commodity和AccountSales
    sql = "LOCK TABLES Commodity WRITE, AccountSales WRITE;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

    // 向AccountSales添加销售记录
    remark = remark==""?"NULL":("'" + remark + "'");
    sql = "insert into AccountSales (transaction_id, entry_user_id, entry_time, commodity_id, number, amout, remark) values ( " +
            QString::number(transactionId, 10) + ", " + QString::number(_id, 10) +
            ", current_timestamp(), " + QString::number(commodityId, 10) + ", " + QString::number(num, 10) +
            ", (select price from Commodity where id = " + QString::number(commodityId, 10) + ") * " +
            QString::number(num, 10) + ", " + remark + ");";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

    // 获取记录的id
    sql = "select last_insert_id() as `id`;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }
    if(!_query.next()){
        // 获取失败
        ret = 0;
        goto sqlExit;
    }
    salesId = _query.value("id").toInt();
    ret = salesId;

    // 修改Commodity中的库存
//    stock -= num;
    sql = "update Commodity set stock = stock - (select number from AccountSales where id = " +
            QString::number(salesId, 10) + ") where id = " +
            QString::number(commodityId, 10) + ";";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }
sqlExit:
    sql = "UNLOCK TABLES;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }
exit:
    return ret;
}

// 删除交易记录
int ChessSysUser::deleteTransaction(int transactionId){
    int ret = 0;
    int roomId;
    int recordId;
    QString sql;
    QSqlQuery query(_db);
    QSqlQuery recordQuery(_db);
    // 判断权限
    switch(_level){
    case SysAdmin:
    case Boss:
        break;
    default:
        // 只有SysAdmin,Boss有权限删除销售记录
        ret = -101;
        goto exit;
        break;
    }

    // 获取开房记录,如果存在就删除
    transactionId = queryChessRoomRecordIdFromTransaction(transactionId, recordId);
    if(transactionId == 0){
        // 交易记录不存在
        ret = -102;
        goto exit;
    } else if(transactionId < 0){
        // 错误代码
        ret = transactionId;
        goto exit;
    }
    if(recordId > 0){
        // 强制删除房间记录
        this->deleteRoomRecord(recordId, 1);
    }



    // 删除交易中的所有销售记录
    sql = "select id from AccountSales where transaction_id = " +
            QString::number(transactionId, 10) + ";";
    if(!query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }
    while(query.next()){
        recordId = query.value("id").toInt();
//        sql = "delete from AccountSales where id = " +
//                QString::number(recordId, 10) + ";";
//        if(!query.exec(sql)){
//            // sql语句执行失败
//            ret = -1;
//            goto sqlExit;
//        }
        // 强制删除消除记录
        ret = deleteSaleRecord(recordId, 1);
        if(ret < 0){
            goto exit;
        }
    }

    // 锁定BonusList、TransactionList
    sql = "LOCK TABLES BonusList WRITE, TransactionList WRITE;";
    if(!query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

    // 删除交易中的红包记录
    sql = "select id from BonusList where transaction_id = " +
            QString::number(transactionId, 10) + ";";
    if(!query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }
    while(query.next()){
        recordId = query.value("id").toInt();
        sql = "delete from BonusList where id = " +
                QString::number(recordId, 10) + ";";
        if(!recordQuery.exec(sql)){
            // sql语句执行失败
            ret = -1;
            goto sqlExit;
        }
    }

    // 删除交易当前交易记录
    sql = "delete from TransactionList where id = " +
            QString::number(transactionId, 10) + ";";
    if(!query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

sqlExit:
    sql = "UNLOCK TABLES;";
    if(!query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto exit;
    }
exit:
    return ret;
}

// 删除房间记录
int ChessSysUser::deleteRoomRecord(int recordId, int force){
    int ret = 0;
    int transactionId = 0;
    int ifClosed = 1;
    int roomId;
    QString sql;
    // 判断权限
    switch(_level){
    case SysAdmin:
    case Boss:
    case Reception:
        break;
    default:
        // 只有SysAdmin,Boss,Reception有权限删除销售记录
        ret = -101;
        goto exit;
        break;
    }

    recordId = this->queryTransactionIdFromRecord("ChessRoomRecord", recordId, transactionId);
    if(recordId == 0){
        // 房间记录不存在
        ret = -102;
        goto exit;
    } else if(recordId < 0){
        // 错误代码
        ret = recordId;
        goto exit;
    }

    // 判断是否强行删除
    if(force == 0){
        // 判断交易是否关闭
        transactionId = queryIfTransactionClosed(transactionId, ifClosed);
        if(transactionId == 0) {
            // 交易记录不存在
            ret = -103;
            goto exit;
        }
        if(transactionId < 0){
            // 错误代码
            ret = transactionId;
            goto exit;
        }
        if(ifClosed > 0){
            // 交易关闭,不能删除开房记录
            ret = -104;
            goto exit;
        }
    }
    // 判断开房记录是否关闭
    recordId = queryIfRoomRecordClosed(recordId, ifClosed);
    if(recordId == 0) {
        // 开房记录不存在
        ret = -105;
        goto exit;
    }
    if(recordId < 0){
        // 错误代码
        ret = recordId;
        goto exit;
    }
    if(ifClosed == 0){
        // 开房记录未关闭,则将房间设置为Free状态
        recordId = queryChessRoomIdFromRecord(recordId, roomId);
        if(recordId == 0){
            // 开房记录不存在
            ret = -105;
            goto exit;
        } if(recordId < 0){
            // 错误代码
            ret = recordId;
            goto exit;
        }

        sql = "update ChessRoom set status = " + QString::number((int)Free, 10) +
                ", current_record_id = NULL, remark = NULL "
                "where id = " + QString::number(roomId, 10) + ";";
        if(!_query.exec(sql)){
            // sql语句执行失败
            ret = -1;
            goto sqlExit;
        }
    }


    // 删除ChessRoomRecord中的记录
    sql = "LOCK TABLES ChessRoomRecord WRITE;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }
    sql = "delete from ChessRoomRecord where id = " +
            QString::number(recordId, 10) + ";";

    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

//    // 交易已经被删空则删除交易记录
//    deleteTransactionAuto(transactionId);
sqlExit:
    sql = "UNLOCK TABLES;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto exit;
    }
exit:
    return ret;
}

// 删除销售记录
int ChessSysUser::deleteSaleRecord(int recordId, int force){

    int ret = 0;
    int transactionId = 0;
    int ifClosed = 1;
    int number = 0;
    int stock = 0;
    int commodityId = 0;
    QString name;
    QString sql;
    QSqlQuery query(_db);
    // 判断权限
    switch(_level){
    case SysAdmin:
    case Boss:
    case Reception:
        break;
    default:
        // 只有SysAdmin,Boss,Reception有权限删除销售记录
        ret = -101;
        goto exit;
        break;
    }

    recordId = this->queryTransactionIdFromSaleRecord(recordId, transactionId);
    if(recordId == 0){
        // 销售记录不存在
        ret = -102;
        goto exit;
    } else if(recordId < 0){
        // 错误代码
        ret = recordId;
        goto exit;
    }

    // 判断是否强行删除
    if(force == 0){
        // 判断交易是否关闭
        transactionId = queryIfTransactionClosed(transactionId, ifClosed);
        if(transactionId == 0) {
            // 交易记录不存在
            ret = -103;
            goto exit;
        }
        if(transactionId < 0){
            // 错误代码
            ret = transactionId;
            goto exit;
        }
        if(ifClosed > 0){
            // 交易关闭,不能删除销售记录
            ret = -104;
            goto exit;
        }
    }

    // 获取销售记录的commodity_id、number
    sql = "select commodity_id, number from AccountSales where id = " +
            QString::number(recordId, 10) + ";";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }
    if(!_query.next()){
        // 销售记录不存在
        ret = -102;
        goto sqlExit;
    }
    number = _query.value("number").toInt();
    commodityId = _query.value("commodity_id").toInt();

    // 获取商品记录的stock
    sql = "select stock from Commodity where id = " +
            QString::number(commodityId, 10) + ";";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }
    if(!_query.next()){
        // 商品记录不存在
        ret = -104;
        goto sqlExit;
    }
    stock = _query.value("stock").toInt();

    // 表格锁定
    sql = "LOCK TABLES AccountSales WRITE, Commodity WRITE;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

    // 修改Commodity中stock字段
    stock += number;
    sql = "update Commodity set stock = " + QString::number(stock, 10) +
            " where id = " + QString::number(commodityId, 10) + ";";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

    // 删除AccountSales中的记录
    sql = "delete from AccountSales where id = " +
            QString::number(recordId, 10) + ";";

    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

//    // 交易已经被删空则删除交易记录
//    deleteTransactionAuto(transactionId);
sqlExit:
    sql = "UNLOCK TABLES;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto exit;
    }
exit:
    return ret;
}

// 删除销售记录并执行deleteTransactionAuto (建议使用)
int ChessSysUser::deleteSaleRecordEx(int recordId, int force){
    int transactionId = 0;
    recordId = queryTransactionIdFromRecord("AccountSales", recordId, transactionId);
    if(recordId == 0){
        // 销售记录不存在
        return -101;
    } else if(recordId < 0){
        // 错误代码
        return recordId;
    }
    int ret = 0;
    // 删除销售记录
    ret = deleteSaleRecord(recordId, force);
    if(ret < 0){
        return ret;
    }
     // 自动删除交易记录
    deleteTransactionAuto(transactionId);
//    ret = deleteTransactionAuto(transactionId);
//    if(ret < 0){
//        return ret;
//    }
    return ret;
}

// 删除房间记录并执行deleteTransactionAuto (建议使用)
int ChessSysUser::deleteRoomRecordEx(int recordId){
    int transactionId = 0;
    recordId = queryTransactionIdFromRecord("ChessRoomRecord", recordId, transactionId);
    if(recordId == 0){
        // 销售记录不存在
        return -101;
    } else if(recordId < 0){
        // 错误代码
        return recordId;
    }
    int ret = 0;
    // 删除开房记录
    ret = deleteRoomRecord(recordId, 0);
    if(ret < 0){
        return ret;
    }
    // 自动删除交易记录
    deleteTransactionAuto(transactionId);
//    ret = deleteTransactionAuto(transactionId);
//    if(ret < 0){
//        return ret;
//    }
    return ret;
}

// 交易记录自动删除（删除空的交易记录）
int ChessSysUser::deleteTransactionAuto(int transactionId){
    int ret = 0;
    int ifClosed = 1;
    QString name;
    QString sql;
    // 判断权限
    switch(_level){
    case SysAdmin:
    case Boss:
    case Reception:
        break;
    default:
        // 只有SysAdmin,Boss,Reception有权限删除交易记录
        ret = -101;
        goto exit;
        break;
    }

    // 获取交易是或否关闭
    transactionId = queryIfTransactionClosed(transactionId, ifClosed);
    if(transactionId == 0) {
        // 交易记录不存在
        ret = -102;
        goto exit;
    }
    if(transactionId < 0){
        // 错误代码
        ret = transactionId;
        goto exit;
    }

    // 判断BonusList、AccountSales、ChessRoomRecord是否存在该交易记录
    if(queryIfRecordExist("BonusList", "transaction_id", transactionId)
            || queryIfRecordExist("AccountSales", "transaction_id", transactionId)
            || queryIfRecordExist("ChessRoomRecord", "transaction_id", transactionId)
        ) {
        // 存在记录则不会自动删除交易记录
        ret = -103;
        goto exit;
    }

    // 删除TransactionList中的记录
    sql = "LOCK TABLES TransactionList WRITE;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }
    sql = "delete from TransactionList where id = " +
            QString::number(transactionId, 10) + ";";

    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

sqlExit:
    sql = "UNLOCK TABLES;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto exit;
    }
exit:
    return ret;
}

// 发放红利
int ChessSysUser::shareBonus(int transactionId, double amout, QString remark){
    int ret = 0;
    int bonusId = 0;// 生成的id
    int ifClosed = 0;// 交易是否关闭
    QString sql;

    // 判断用户权限
    switch (_level){
    case SysAdmin:
    case Boss:
    case Reception:
        break;
    default:
        // 用户无权创建棋牌房间
        ret = -101;
        goto exit;
        break;
    }

    // 判断交易是否关闭
    transactionId = queryIfTransactionClosed(transactionId, ifClosed);
    if(transactionId == 0){
        // 记录不存在
        ret = -102;
        goto exit;
    } else if(transactionId < 0){
        // 错误代码
        ret = transactionId;
        goto exit;
    }
    if(ifClosed){
        // 交易已经关闭
        ret = -103;
        goto exit;
    }

    // 锁定表BonusList
    sql = "LOCK TABLES BonusList WRITE;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

    // 向BonusList添加红利记录
    remark = remark==""?"NULL":("'" + remark + "'");
    sql = "insert into BonusList (transaction_id, entry_user_id, entry_time, amout, remark) values ( " +
            QString::number(transactionId, 10) + ", " + QString::number(_id, 10) +
            ", current_timestamp(), " + QString::number(amout, 'f', 2) + ", " + remark + ");";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

    // 获取记录的id
    sql = "select last_insert_id() as `id`;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }
    if(!_query.next()){
        // 获取失败
        ret = 0;
        goto sqlExit;
    }
    bonusId = _query.value("id").toInt();
    ret = bonusId;

sqlExit:
    sql = "UNLOCK TABLES;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }
exit:
    return ret;
}


// 取消挂起棋牌房
int ChessSysUser::cancelSuspendChessRoom(int roomId, QString remark){
    int ret = 0;
    ChessRoomState roomStatus = (ChessRoomState)0;
    QString sql;

    // 判断用户权限
    switch (_level){
    case SysAdmin:
    case Boss:
    case Reception:
        break;
    default:
        // 用户无权创建棋牌房间
        ret = -101;
        goto exit;
        break;
    }

    // 判断房间状态
    roomId = queryChessRoomStatus(roomId, roomStatus);
    if(roomId == 0){
        // 房间不存在
        ret = -102;
        goto exit;
    } else if(roomId < 0){
        // 错误代码
        ret = roomId;
        goto exit;
    }
    if(roomStatus != Suspend){
        // 房间不是挂起状态
        ret = -103;
        goto exit;
    }
    // 锁定表ChessRoom
    sql = "LOCK TABLES ChessRoom WRITE;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

    // 修改ChessRoom的status
    remark = remark==""?"NULL":("'"+remark+"'");
    sql = "update ChessRoom set status = " + QString::number((int)Free, 10) +
            ", remark = " + remark + " where id = " + QString::number(roomId, 10) + ";";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }
sqlExit:
    sql = "UNLOCK TABLES;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

exit:
    return ret;
}


// 挂起棋牌房
int ChessSysUser::suspendChessRoom(int roomId, QString remark){
    int ret = 0;
    int transactionId = 0;
    int recordId = 0;
    ChessRoomState roomStatus = (ChessRoomState)0;
    QString sql;

    // 判断用户权限
    switch (_level){
    case SysAdmin:
    case Boss:
    case Reception:
        break;
    default:
        // 用户无权创建棋牌房间
        ret = -101;
        goto exit;
        break;
    }

    // 判断房间状态
    roomId = queryChessRoomStatus(roomId, roomStatus);
    if(roomId == 0){
        // 房间不存在
        ret = -102;
        goto exit;
    } else if(roomId < 0){
        // 错误代码
        ret = roomId;
        goto exit;
    }
    if(roomStatus != Free){
        // 房间不是空闲状态
        ret = -103;
        goto exit;
    }
    // 锁定表ChessRoom
    sql = "LOCK TABLES ChessRoom WRITE;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

    // 修改ChessRoom的status
    remark = remark==""?"NULL":("'"+remark+"'");
    sql = "update ChessRoom set status = " + QString::number((int)Suspend, 10) +
            ", remark = " + remark + " where id = " + QString::number(roomId, 10) + ";";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }
sqlExit:
    sql = "UNLOCK TABLES;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

exit:
    return ret;
}

// 预订棋牌房
int ChessSysUser::scheduleChessRoom(int roomId, QDateTime dateTime, QString remark){
    int ret = 0;
    int transactionId = 0;
    int recordId = 0;
    ChessRoomState roomStatus = (ChessRoomState)0;
    QString sql;
    QString dateTimeStr;

    // 判断用户权限
    switch (_level){
    case SysAdmin:
    case Boss:
    case Reception:
        break;
    default:
        // 用户无权创建棋牌房间
        ret = -101;
        goto exit;
        break;
    }

    // 判断房间状态
    roomId = queryChessRoomStatus(roomId, roomStatus);
    if(roomId == 0){
        // 房间不存在
        ret = -102;
        goto exit;
    } else if(roomId < 0){
        // 错误代码
        ret = roomId;
        goto exit;
    }
    if(roomStatus != Free){
        // 房间不是空闲状态
        ret = -103;
        goto exit;
    }

    // 创建交易
    transactionId = createTransaction();
    if(transactionId <=0 ){
        // 错误代码
        ret = transactionId;
        goto exit;
    }


    // 锁定表ChessRoom和ChessRoomRecord
    sql = "LOCK TABLES ChessRoom WRITE, ChessRoomRecord WRITE;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

    // 向ChessRoomRecord中添加记录
//    remark = remark==""?"NULL":("'" + remark + "'");
    sql = "insert into ChessRoomRecord (transaction_id, room_id, entry_user_id, entry_time, closing_user_id, closing_time, amout, remark) values ( " +
            QString::number(transactionId, 10) + ", " + QString::number(roomId, 10) +
            ", NULL, NULL, NULL, NULL, NULL, NULL);";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

    // 获取记录的id
    sql = "select last_insert_id() as `id`;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }
    if(!_query.next()){
        // 获取失败
        ret = 0;
        goto sqlExit;
    }
    recordId = _query.value("id").toInt();
    ret = recordId;

//    // 锁定表ChessRoom
//    sql = "LOCK TABLES ChessRoom WRITE;";
//    if(!_query.exec(sql)){
//        // sql语句执行失败
//        ret = -1;
//        goto sqlExit;
//    }

    // 修改ChessRoom的status
    remark = remark==""?"NULL":("'"+remark+"'");
    dateTimeStr = dateTime.toString("yyyy.MM.dd hh:mm");
    dateTimeStr = dateTimeStr==""?"NULL":("'"+dateTimeStr+"'");
    sql = "update ChessRoom set status = " + QString::number((int)Schedule, 10) +
            ", scheduled_time = " + dateTimeStr +
            ", current_record_id = " + QString::number(recordId, 10) +
            ", remark = " + remark +
            " where id = " + QString::number(roomId, 10) + ";";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }
sqlExit:
    sql = "UNLOCK TABLES;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

exit:
    return ret;
}

// 取消预订棋牌房
int ChessSysUser::cancelScheduleChessRoom(int roomId, QString remark){
    int ret = 0;
    int transactionId = 0;
    ChessRoomState roomStatus = (ChessRoomState)0;
    QString sql;
    QString dateTimeStr;

    // 判断用户权限
    switch (_level){
    case SysAdmin:
    case Boss:
    case Reception:
        break;
    default:
        // 用户无权创建棋牌房间
        ret = -101;
        goto exit;
        break;
    }

    // 判断房间状态
    roomId = queryChessRoomStatus(roomId, roomStatus);
    if(roomId == 0){
        // 房间不存在
        ret = -102;
        goto exit;
    } else if(roomId < 0){
        // 错误代码
        ret = roomId;
        goto exit;
    }
    if(roomStatus != Schedule){
        // 房间不是预订状态
        ret = -103;
        goto exit;
    }

    // 获取房间交易号
    roomId = queryChessTransactionId(roomId, transactionId);
    ret = this->deleteTransaction(transactionId);
    if(ret <= 0){
        goto exit;
    }

//    // 锁定表ChessRoom
//    sql = "LOCK TABLES ChessRoom WRITE;";
//    if(!_query.exec(sql)){
//        // sql语句执行失败
//        ret = -1;
//        goto sqlExit;
//    }

//    // 修改ChessRoom的status
//    remark = remark==""?"NULL":("'"+remark+"'");
//    sql = "update ChessRoom set status = " + QString::number((int)Free, 10) +
//            ", scheduled_time = " + "NULL" +
//            ", remark = " + remark + " where id = " + QString::number(roomId, 10) + ";";
//    if(!_query.exec(sql)){
//        // sql语句执行失败
//        ret = -1;
//        goto sqlExit;
//    }
//sqlExit:
//    sql = "UNLOCK TABLES;";
//    if(!_query.exec(sql)){
//        // sql语句执行失败
//        ret = -1;
//        goto sqlExit;
//    }

exit:
    return ret;
}

// 开设棋牌房
int ChessSysUser::openChessRoom(int roomId, QString remark){

    int ret = 0;
    int transactionId = 0;
    int recordId = 0;
    ChessRoomState roomStatus = (ChessRoomState)0;
    QString sql;

    // 判断用户权限
    switch (_level){
    case SysAdmin:
    case Boss:
    case Reception:
        break;
    default:
        // 用户无权创建棋牌房间
        ret = -101;
        goto exit;
        break;
    }

    // 判断房间状态
    roomId = queryChessRoomStatus(roomId, roomStatus);
    if(roomId == 0){
        // 房间不存在
        ret = -102;
        goto exit;
    } else if(roomId < 0){
        // 错误代码
        ret = roomId;
        goto exit;
    }
    if(roomStatus != Free && roomStatus != Schedule){
        // 房间不是空闲或预定状态
        ret = -103;
        goto exit;
    }

    if(roomStatus == Free){
        // 创建交易
        transactionId = createTransaction();
        if(transactionId <=0 ){
            // 错误代码
            ret = transactionId;
            goto exit;
        }


        // 锁定表ChessRoom和ChessRoomRecord
        sql = "LOCK TABLES ChessRoom WRITE, ChessRoomRecord WRITE;";
        if(!_query.exec(sql)){
            // sql语句执行失败
            ret = -1;
            goto sqlExit;
        }

        // 向ChessRoomRecord中添加记录
        remark = remark==""?"NULL":("'" + remark + "'");
        sql = "insert into ChessRoomRecord (transaction_id, room_id, entry_user_id, entry_time, closing_user_id, closing_time, amout, remark) values ( " +
                QString::number(transactionId, 10) + ", " + QString::number(roomId, 10) + ", " + QString::number(_id, 10) +
                ", current_timestamp(), NULL, NULL, NULL, NULL);";
        if(!_query.exec(sql)){
            // sql语句执行失败
            ret = -1;
            goto sqlExit;
        }

        // 获取记录的id
        sql = "select last_insert_id() as `id`;";
        if(!_query.exec(sql)){
            // sql语句执行失败
            ret = -1;
            goto sqlExit;
        }
        if(!_query.next()){
            // 获取失败
            ret = 0;
            goto sqlExit;
        }
        recordId = _query.value("id").toInt();
        ret = recordId;

        // 修改ChessRoom的status和current_record_id
        sql = "update ChessRoom set status = " + QString::number((int)Busy, 10) +
                ", current_record_id = " + QString::number(recordId, 10) + " where id = " +
                QString::number(roomId, 10) + ";";
        if(!_query.exec(sql)){
            // sql语句执行失败
            ret = -1;
            goto sqlExit;
        }
    } else if(roomStatus == Schedule){
        // 获取房间的当前记录编号
        roomId = queryChessRoomRecordId(roomId, recordId);
        if(roomId <= 0){
            // 记录获取失败
            ret = roomId;
            goto exit;
        }

        // 锁定表ChessRoom和ChessRoomRecord
        sql = "LOCK TABLES ChessRoom WRITE, ChessRoomRecord WRITE;";
        if(!_query.exec(sql)){
            // sql语句执行失败
            ret = -1;
            goto sqlExit;
        }
        // 修改ChessRoom的status和scheduled_time
        sql = "update ChessRoom set status = " + QString::number((int)Busy, 10) +
                ", scheduled_time = NULL" +
                " where id = " + QString::number(roomId, 10) + ";";
        if(!_query.exec(sql)){
            // sql语句执行失败
            ret = -1;
            goto sqlExit;
        }
        // 修改ChessRoomRecord的entry_user_id和entry_time,
        sql = "update ChessRoomRecord set entry_user_id = " + QString::number(_id, 10) +
                ", entry_time = current_timestamp() where id = " +
                QString::number(recordId, 10) + ";";
        if(!_query.exec(sql)){
            // sql语句执行失败
            ret = -1;
            goto sqlExit;
        }

    }
sqlExit:
    sql = "UNLOCK TABLES;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

exit:
    return ret;
}

// 开设棋牌房
int ChessSysUser::openChessRoom(int roomId, QDateTime dateTime, QString remark){
    int ret = 0;
    int transactionId = 0;
    int recordId = 0;
    ChessRoomState roomStatus = (ChessRoomState)0;
    QString sql;
    QString timeStr;

    // 判断用户权限
    switch (_level){
    case SysAdmin:
    case Boss:
    case Reception:
        break;
    default:
        // 用户无权创建棋牌房间
        ret = -101;
        goto exit;
        break;
    }

    // 判断房间状态
    roomId = queryChessRoomStatus(roomId, roomStatus);
    if(roomId == 0){
        // 房间不存在
        ret = -102;
        goto exit;
    } else if(roomId < 0){
        // 错误代码
        ret = roomId;
        goto exit;
    }
    if(roomStatus != Free && roomStatus != Schedule){
        // 房间不是空闲或预定状态
        ret = -103;
        goto exit;
    }

    if(roomStatus == Free){
        // 创建交易
        transactionId = createTransaction();
        if(transactionId <=0 ){
            // 错误代码
            ret = transactionId;
            goto exit;
        }


        // 锁定表ChessRoom和ChessRoomRecord
        sql = "LOCK TABLES ChessRoom WRITE, ChessRoomRecord WRITE;";
        if(!_query.exec(sql)){
            // sql语句执行失败
            ret = -1;
            goto sqlExit;
        }

        // 向ChessRoomRecord中添加记录
        timeStr = (!dateTime.isValid())?"NULL":("'" + dateTime.toString("yyyy-MM-dd hh:mm:ss") + "'");
        remark = remark==""?"NULL":("'" + remark + "'");
        sql = "insert into ChessRoomRecord (transaction_id, room_id, entry_user_id, entry_time, closing_user_id, closing_time, amout, remark) values ( " +
                QString::number(transactionId, 10) + ", " + QString::number(roomId, 10) + ", " + QString::number(_id, 10) +
                ", " + timeStr + ", NULL, NULL, NULL, NULL);";
        if(!_query.exec(sql)){
            // sql语句执行失败
            ret = -1;
            goto sqlExit;
        }

        // 获取记录的id
        sql = "select last_insert_id() as `id`;";
        if(!_query.exec(sql)){
            // sql语句执行失败
            ret = -1;
            goto sqlExit;
        }
        if(!_query.next()){
            // 获取失败
            ret = 0;
            goto sqlExit;
        }
        recordId = _query.value("id").toInt();
        ret = recordId;

        // 修改ChessRoom的status和current_record_id
        sql = "update ChessRoom set status = " + QString::number((int)Busy, 10) +
                ", current_record_id = " + QString::number(recordId, 10) + " where id = " +
                QString::number(roomId, 10) + ";";
        if(!_query.exec(sql)){
            // sql语句执行失败
            ret = -1;
            goto sqlExit;
        }
    } else if(roomStatus == Schedule){
        // 获取房间的当前记录编号
        roomId = queryChessRoomRecordId(roomId, recordId);
        if(roomId <= 0){
            // 记录获取失败
            ret = roomId;
            goto exit;
        }

        // 锁定表ChessRoom和ChessRoomRecord
        sql = "LOCK TABLES ChessRoom WRITE, ChessRoomRecord WRITE;";
        if(!_query.exec(sql)){
            // sql语句执行失败
            ret = -1;
            goto sqlExit;
        }
        // 修改ChessRoom的status和scheduled_time
        sql = "update ChessRoom set status = " + QString::number((int)Busy, 10) +
                ", scheduled_time = NULL" +
                " where id = " + QString::number(roomId, 10) + ";";
        if(!_query.exec(sql)){
            // sql语句执行失败
            ret = -1;
            goto sqlExit;
        }
        // 修改ChessRoomRecord的entry_user_id和entry_time,
        timeStr = (!dateTime.isValid())?"NULL":("'" + dateTime.toString("yyyy-MM-dd hh:mm:ss") + "'");
        sql = "update ChessRoomRecord set entry_user_id = " + QString::number(_id, 10) +
                ", entry_time = " + timeStr + " where id = " +
                QString::number(recordId, 10) + ";";
        if(!_query.exec(sql)){
            // sql语句执行失败
            ret = -1;
            goto sqlExit;
        }

    }
sqlExit:
    sql = "UNLOCK TABLES;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

exit:
    return ret;
}

// 结束棋牌房记录
int ChessSysUser::closeChessRoomRecord(int recordId, QString remark){
    int ret = 0;
    QString formula;
    int roomId = 0;
    QString sql;
    ChessRoomState status;

    // 判断用户权限
    switch (_level){
    case SysAdmin:
    case Boss:
    case Reception:
        break;
    default:
        // 用户无权结束房间记录
        ret = -101;
        goto exit;
        break;
    }

    // 获取房间编号
    recordId = queryChessRoomIdFromRecord(recordId, roomId);
    if(recordId == 0){
        // 记录不存在
        ret = -102;
        goto exit;
    } else if(recordId < 0){
        // 错误代码
        ret = recordId;
        goto exit;
    }

    // 获取房间状态
    roomId = queryChessRoomStatus(roomId, status);

    if(status == Busy){ // 计费状态

        sql = "LOCK TABLES ChessRoomRecord WRITE, ChessRoom WRITE;";
        if(!_query.exec(sql)){
            // sql语句执行失败
            ret = -1;
            goto sqlExit;
        }

        // 修改ChessRoom的status和current_record_id
        sql = "update ChessRoom set status = " + QString::number((int)Free, 10) +
              ", current_record_id = NULL, remark = NULL "
              "where id = " + QString::number(roomId, 10) + ";";
        if(!_query.exec(sql)){
            // sql语句执行失败
            ret = -1;
            goto sqlExit;
        }

        // 录入ChessRoomRecord的closing_user_id,closing_time和remark
        remark = remark==""?"NULL":("'" + remark + "'");
        sql = "update ChessRoomRecord set closing_user_id = " + QString::number(_id, 10) +
               ", closing_time = current_timestamp(), remark  = " + remark + " where id = " +
                QString::number(recordId, 10) + ";";
        if(!_query.exec(sql)){
            // sql语句执行失败
            ret = -1;
            goto sqlExit;
        }

        // 获取公式
        roomId = queryChessRoomFormula(roomId, formula);
        if(roomId == 0){
            // 房间不存在
            ret = -103;
            goto sqlExit;
        } else if(roomId < 0){
            // 错误代码
            ret = roomId;
            goto sqlExit;
        }

        sql = "UNLOCK TABLES;";
        if(!_query.exec(sql)){
            // sql语句执行失败
            ret = -1;
            goto sqlExit;
        }

        // 录入ChessRoomRecord的amout
        sql = "update ChessRoomRecord, "
              "(select timestampdiff(MINUTE, entry_time, closing_time) as time from ChessRoomRecord where id = " +
              QString::number(recordId, 10) + ") as duration set amout = " + formula +
              " where id = " + QString::number(recordId, 10) + ";";
        if(!_query.exec(sql)){
            // sql语句执行失败
            qDebug() << _query.lastError().text();
            ret = -1;
            goto sqlExit;
        }
    } else if(status == Schedule){ // 预定状态

        // 删除记录
        this->deleteRoomRecord(recordId, 1);
    }

sqlExit:
    sql = "UNLOCK TABLES;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }
exit:
    return ret;
}

// 创建棋牌房
int ChessSysUser::createChessRoom(QString name, ChessRoomState status, QString formula,
                          int recordId, QDateTime scheduledTime, int scheduledMemberId, QString remark){

    int ret = 0;
    int id = 0;
    QString sql, recordIdStr, scheduledTimeStr, scheduledMemberIdStr;

    // 判断用户权限
    switch (_level){
    case SysAdmin:
    case Boss:
    case Reception:
        break;
    default:
        // 用户无权创建棋牌房间
        ret = -101;
        goto exit;
        break;
    }

    // 判断房间名是否存在
    id = queryChessRoomId(name);
    if(id > 0){
        // 房间已经存在
        ret = -102;
        goto exit;
    } else if(id < 0){
        // 错误代码
        ret = id;
        goto exit;
    }

    // 锁定表ChessRoom和ChessFormulaChanges
    sql = "LOCK TABLES ChessRoom WRITE, ChessFormulaChanges WRITE;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

    // 向ChessRoom中添加记录
    scheduledTimeStr = (!scheduledTime.isValid())?"NULL":("'" + scheduledTime.toString("yyyy-MM-dd hh:mm:ss") + "'");
    remark = remark==""?"NULL":("'" + remark + "'");
    scheduledMemberIdStr = scheduledMemberIdStr<=0?"NULL":QString::number(scheduledMemberId, 10);
    recordIdStr = recordIdStr<=0?"NULL":QString::number(recordId, 10);
    sql = "insert into ChessRoom (name, status, charging_formula, scheduled_time, scheduled_member_id, current_record_id, remark) values ( '" +
            name + "', " + QString::number(status, 10) + ", '" + formula + "', " +
            scheduledTimeStr + ", " + scheduledMemberIdStr + ", " + recordIdStr + ", " + remark + ");";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

    // 获取添加的room的id
    id = queryChessRoomId(name);

    // 向ChessFormulaChanges中添加记录
    sql = "insert into ChessFormulaChanges (room_id, entry_user_id, entry_time, new_formula, old_formula, remark) values ( " +
            QString::number(id, 10) + ", " + QString::number(_id, 10) + ", current_timestamp(), '" + formula +
            "', NULL, NULL);";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }
sqlExit:
    // 解锁ChessRoom和ChessFormulaChanges
    sql = "UNLOCK TABLES;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }
exit:
    return ret;
}

// 删除棋牌房间
int ChessSysUser::deleteChessRoom(int id){

    int ret = 0;
    QString name;
    QString sql;
    // 判断权限
    switch(_level){
    case SysAdmin:
    case Boss:
    case Reception:
        break;
    default:
        // 只有SysAdmin,Boss,Reception有权限删除棋牌房间
        ret = -101;
        goto exit;
        break;
    }

    id = queryChessRoomName(id, name);
    if(id == 0){
        // 房间不存在
        ret = -102;
        goto exit;
    } else if(id < 0){
        // 错误代码
        ret = id;
        goto exit;
    }

    // 判断ChessRoomRecord中是否有该房间的记录
    if(queryIfRecordExist("ChessRoomRecord", "room_id", id)
        ) {
        // 存在记录则禁止删除该房间

        ret = -103;
        goto exit;
    }

    // 删除ChessRoom及ChessFormulaChanges中的记录
    sql = "LOCK TABLES ChessRoom WRITE, ChessFormulaChanges WRITE;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }
    sql = "delete from ChessRoom where id = " +
            QString::number(id, 10) + ";";

    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

    sql = "delete from ChessFormulaChanges where room_id = " +
            QString::number(id, 10) + ";";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

sqlExit:
    sql = "UNLOCK TABLES;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto exit;
    }
exit:
    return ret;

}

// 修改房间计费公式
int ChessSysUser::changeChessRoomFormula(int id, QString formula, QString remark){
    int ret = 0;
    QString oldFormula;
    QString sql;
    ChessRoomState status;// 房间当前状态

    // 判断用户是否有权限添加商品
    switch (_level){
    case SysAdmin:
    case Boss:
    case Reception:
        break;
    default:
        // 无权限修改计费公式
        ret = -101;
        goto exit;
        break;
    }

    // 判断商品是否已经存在并获取商品过去的价格
    id = queryChessRoomFormula(id, oldFormula);

    if(id == 0){
        // 房间不存在
        ret = -102;
        goto exit;
    }
    if(id < 0) {
        // sql语句执行失败
        ret = id;
        goto exit;
    }

    if(formula == oldFormula){
        // 前后公式一致
        ret = -103;
        goto exit;
    }

    // 判断房间状态是否空闲
    id = queryChessRoomStatus(id, status);
    if(id == 0){
        // 房间不存在
        ret = -102;
        goto exit;
    }
    if(id < 0) {
        // sql语句执行失败
        ret = id;
        goto exit;
    }
    if( status != Free && status != Schedule){
        // 只有空闲和预定状态才允许修改计费公式
        ret = -104;
        goto exit;
    }

    // 锁定ChessRoom和ChessFormulaChanges
    sql = "LOCK TABLES ChessRoom WRITE, ChessFormulaChanges WRITE;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

    formula = formula==""?"NULL":("'"+formula+"'");
    oldFormula = oldFormula==""?"NULL":("'"+oldFormula+"'");

    // 修改ChessRoom表中charging_formula
    sql = "update ChessRoom set charging_formula = " + formula + " where id = " +
            QString::number(id, 10) + ";";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

    // 向ChessFormulaChanges中插入记录
    remark = remark==""?"NULL":("'" + remark + "'");
    sql = "insert into ChessFormulaChanges (room_id, entry_user_id, entry_time, new_formula, old_formula, remark) values (" +
            QString::number(id, 10) + ", " + QString::number(_id, 10) + ", current_timestamp(), " +
            formula + ", " + oldFormula + ", " + remark + ");";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto sqlExit;
    }

sqlExit:
    sql = "UNLOCK TABLES;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        ret = -1;
        goto exit;
    }
exit:
    return ret;
}

// 查询命令执行
QSqlQuery* ChessSysUser::queryCommand(QString cmd){
    if(!_query.exec(cmd)){
        // sql语句执行失败
        return NULL;
    }
    return &_query;
}

// 查询命令执行,并产生新的QSqlQuery*
QSqlQuery* ChessSysUser::queryNewCommand(QString cmd){
    QSqlQuery* query = new QSqlQuery(_db);

    if(!query->exec(cmd)){
        // sql语句执行失败
        if(query != NULL){
            delete query;
        }
        return NULL;
    }
    return query;
}

QSqlQuery* ChessSysUser::queryChessRoomInfo(){
    QString sql;
    sql = "select * from ChessRoom order by name;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        return NULL;
    }
    return &_query;
}

QSqlQuery* ChessSysUser::queryChessRoomInfo(QString name){
    QString sql;
    sql = "select * from ChessRoom where name = '" + name + "' order by name;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        return NULL;
    }
    return &_query;
}

// 通过交易清单查询房间记录
QSqlQuery* ChessSysUser::queryChessRoomRecordFromTransaction(int transactionId){
    QString sql;
    sql = "select * from ChessRoomRecord where transaction_id = " +
            QString::number(transactionId, 10) + " order by id;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        return NULL;
    }
    return &_query;
}

// 通过交易清单查询商品记录
QSqlQuery* ChessSysUser::queryCommodityFromTransaction(int transactionId){
    QString sql;
    sql = "select * from AccountSales where transaction_id = " +
            QString::number(transactionId, 10) + " order by id;";
    if(!_query.exec(sql)){
        // sql语句执行失败
        return NULL;
    }
    return &_query;

}
