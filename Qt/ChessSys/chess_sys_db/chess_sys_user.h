#ifndef CHESSSYSUSER_H
#define CHESSSYSUSER_H

#include <QString>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDateTime>

// 棋牌系统用户类级别
typedef enum ChessSysUserLevel {
    Tourist = 1,
    SysAdmin,
    Boss,
    Reception,
    GodownKeeper
}ChessSysUserLevel_t;

// 棋牌系统用户类级别
typedef enum CommodityState {
    WaitCheck = 1, // 待检
    Stock, // 库存
    ForSale, // 待售
    Active // 上架
}CommodityState_t;

// 棋牌房间状态
typedef enum ChessRoomState {
    Free = 1, // 空闲
    Schedule, // 预定
    Busy, // 计费
    Suspend //挂起
}ChessRoomState_t;

// 棋牌系统用户类
// 对于棋牌数据库的所有操作都是由ChessSysUser的实例实现
class ChessSysUser
{
public:
    ChessSysUser(QSqlDatabase db);
//    ChessSysUser(const ChessSysUser& user);
    virtual ~ChessSysUser();

    virtual int setName(QString name);
    virtual int setPassword(QString password);

    virtual QString getName();
    virtual ChessSysUserLevel getLevel();
    virtual QString getLevelName();

    virtual int updateLevelName(); // 更新级别名称
    virtual int login(); // 登录
    virtual int exit(); // 退出
    // 创建用户
    virtual int createUser(QString name, QString password,
                   ChessSysUserLevel level, int boss = 0);
    // 修改用户密码
    virtual int changePassword(QString password, QString oldPwd);


    // 查询用户id
    virtual int queryUserId(QString name);
    // 查询用户名称,返回在name引用中
    virtual int queryUserName(int id, QString &name);
    // 查询用户级别
    virtual int queryUserLevel(int id);
    virtual int queryUserLevel(QString name);
    // 查询商品类别id
    virtual int queryCommodityCategory(QString name);
    // 查询用户记录数量
    // 查询form表中target字段 = id的记录的数目
    virtual int queryUserRecordCount(QString form, QString target, int id);
    // 查询form表中target字段 = id(userName的id)的记录的数目
    virtual int queryUserRecordCount(QString form, QString target, QString userName);
    // 查询form表中target1字段或target2 = id的记录的数目
    virtual int queryUserRecordCount(QString form, QString target1, QString target2, int id);
    // 查询form表中target1字段或target2 = id(userName的id)的记录的数目
    virtual int queryUserRecordCount(QString form, QString target1, QString target2, QString userName);
    // 查询用户记录是否存在
    // 查询form表中target字段 = id的记录是否存在
    virtual int queryIfUserRecordExist(QString form, QString target, int id);
    // 查询form表中target字段 = id(userName的id)的记录是否存在
    virtual int queryIfUserRecordExist(QString form, QString target, QString userName);
    // 查询form表中target1字段或target2 = id的记录是否存在
    virtual int queryIfUserRecordExist(QString form, QString target1, QString target2, int id);
    // 查询form表中target1字段或target2 = id(userName的id)的记录是否存在
    virtual int queryIfUserRecordExist(QString form, QString target1, QString target2, QString userName);
    // 查询记录是否存在
    // 查询form表中target字段 = id的记录是否存在
    virtual int queryIfRecordExist(QString form, QString target, int id);
    // 查询商品编号
    virtual int queryCommodityId(QString name);
    // 查询商品名称
    virtual int queryCommodityName(int commodityId, QString& name);
    // 查询商品价格
    virtual int queryCommodityPrice(int commodityId, double& price);
    // 查询商品库存
    virtual int queryCommodityStock(int commodityId, int& stock);
    // 查询商品记录金额
    virtual int queryCommodityRecordAmout(int recordId, double& amout);
    // 查询红利金额
    virtual int queryBonusAmout(int recordId, double& amout);
    // 查询存储记录中的数量
    virtual int queryStoreRecord(int id, int& num, int& commodityId);
    // 判断房间记录是否已经关闭,返回值=id操作成功,0:id不存在,<0错误代码
    virtual int queryIfRoomRecordClosed(int id, int& ifClosed);
    // 判断交易是否已经关闭,返回值=id操作成功,0:id不存在,<0错误代码
    virtual int queryIfTransactionClosed(int id, int& ifClosed);
    // 查询棋牌房间id
    virtual int queryChessRoomId(QString name);
    // 查询记录对应的交易id
    virtual int queryTransactionIdFromRecord(QString form, int recordId, int& transactionId);
    // 查询销售记录对应的交易id
    virtual int queryTransactionIdFromSaleRecord(int recordId, int& transactionId);
    // 查询棋牌房间id(从房间记录中查询)
    virtual int queryChessRoomIdFromRecord(int recordId, int& roomId);
    // 查询棋牌房间记录金额
    virtual int queryChessRoomRecordAmout(int recordId, double& amout);
    // 查询棋牌房间状态
    virtual int queryChessRoomStatus(int id, ChessRoomState& status);
    // 查询棋牌房间名字
    virtual int queryChessRoomName(int id, QString& name);
    // 查询棋牌房间记录(通过交易记录)
    // 返回值=transactionId操作成功,0:id不存在,<0错误代码
    virtual int queryChessRoomRecordIdFromTransaction(int transactionId, int& recordId);
    // 查询棋牌房间当前记录id
    virtual int queryChessRoomRecordId(int id, int& recordId);
    // 查询棋牌房间计费公式
    virtual int queryChessRoomFormula(int id, QString& formula);
    // 查询棋牌房间当前交易id
    virtual int queryChessTransactionId(int id, int& transactionId);
    // 查询房间当前计费情况 id 为房间编号
    virtual int queryChessRoomCurrentCharging(int id, int& minutes, double& amout);

    // 删除用户
    virtual int deleteUser(int id);
    virtual int deleteUser(QString name);

    // 添加商品类别
    virtual int addCommodityCategory(QString name);

    // 添加商品
    virtual int addCommodity(QString name, CommodityState status, QString categoryName, double price, int stock = 0,
                             QString barCode = "", QString picPath = "");
    // 修改商品价格
    virtual int changeCommodityPrice(int commodityId, double price, QString remark = "");
    virtual int changeCommodityPrice(QString name, double price, QString remark = "");
    // 删除价格修改记录
    virtual int deleteCommodityPriceChangeRecord(int recordId);
    // 删除商品
    virtual int deleteCommodity(int id);
    virtual int deleteCommodity(QString name);
    // 删除商品类别
    virtual int deleteCommodityCategory(QString name);

    // 存储商品
    virtual int storeCommodity(int id, double purchasePrice, int num, int supplierId = 0,
                               QString remark = "");
    virtual int storeCommodity(QString name, double purchasePrice, int num, int supplierId = 0,
                               QString remark = "");
    // 设置商品状态
    virtual int setCommodityStatus(QString name, CommodityState status);

    // 取消入库
    virtual int cancelStore(int id);

    // 创建交易清单,并返回创建的清单编号
    virtual int createTransaction(QString remark = "");
    // 结束交易清单
    virtual int closeTransaction(int id, QString remark = "");
    // 销售商品
    virtual int sellCommodity(int transactionId, int commodityId,
                               int num, QString remark = "");
    // 删除销售记录
    virtual int deleteSaleRecord(int recordId, int force);
    // 删除销售记录并执行deleteTransactionAuto (建议使用)
    virtual int deleteSaleRecordEx(int recordId, int force);
    // 删除房间记录
    virtual int deleteRoomRecord(int recordId, int force);
    // 删除房间记录并执行deleteTransactionAuto (建议使用)
    virtual int deleteRoomRecordEx(int recordId);
    // 交易记录自动删除（删除空的交易记录）
    virtual int deleteTransactionAuto(int transactionId);
    // 删除交易记录
    virtual int deleteTransaction(int transactionId);
    // 发放红利
    virtual int shareBonus(int transactionId, double amout, QString remark = "");
    // 挂起棋牌房
    virtual int suspendChessRoom(int roomId, QString remark = "");
    // 取消挂起棋牌房
    virtual int cancelSuspendChessRoom(int roomId, QString remark = "");
    // 预订棋牌房
    virtual int scheduleChessRoom(int roomId, QDateTime dateTime, QString remark = "");
    // 取消预订棋牌房
    virtual int cancelScheduleChessRoom(int roomId, QString remark = "");
    // 开设棋牌房
    virtual int openChessRoom(int roomId, QString remark = "");
    // 开设棋牌房
    virtual int openChessRoom(int roomId, QDateTime dateTime, QString remark = "");
    // 结束棋牌房记录
    virtual int closeChessRoomRecord(int recordId, QString remark = "");
    // 创建棋牌房
    virtual int createChessRoom(QString name, ChessRoomState status, QString formula,
                                int recordId = 0, QDateTime scheduledTime = *(new QDateTime),
                                int scheduledMemberId = 0, QString remark = "");
    // 删除棋牌房间
    virtual int deleteChessRoom(int id);
    // 修改房间计费公式
    virtual int changeChessRoomFormula(int id, QString formula, QString remark = "");

    // 查询命令执行
    virtual QSqlQuery* queryCommand(QString cmd);
    // 查询命令执行,并产生新的QSqlQuery*
    virtual QSqlQuery* queryNewCommand(QString cmd);
    virtual QSqlQuery* queryChessRoomInfo();
    virtual QSqlQuery* queryChessRoomInfo(QString name);
    // 通过交易清单查询房间记录
    virtual QSqlQuery* queryChessRoomRecordFromTransaction(int transactionId);
    // 通过交易清单查询商品记录
    virtual QSqlQuery* queryCommodityFromTransaction(int transactionId);
protected:
    QSqlDatabase _db;
    QSqlQuery _query; // 查询

    int _id; // 用户编号
    QString _name; // 用户名
    QString _password; // 密码
    ChessSysUserLevel _level; // 用户级别
    QString _levelName; // 级别名称
    int _boss; // 老板的用户编号
};

#endif // CHESSSYSUSER_H
