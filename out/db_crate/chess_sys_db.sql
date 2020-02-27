--
-- 创建数据库chess_sys_db
--

create database chess_sys_db character set utf8 collate utf8_general_ci;
use chess_sys_db;

--
-- UserLevel用户级别结构
--
DROP TABLE IF EXISTS UserLevel;

CREATE TABLE UserLevel (
level int primary key auto_increment, -- 用户级别(主键)
name varchar(20) not null -- 级别名称
);

-- 插入初始内容
LOCK TABLES UserLevel WRITE;
insert into UserLevel values
(1, '游客'),
(2, '系统管理员'),
(3, '老板'),
(4, '前台'),
(5, '库存管理员');
UNLOCK TABLES;

--
-- User用户结构
--
DROP TABLE IF EXISTS User;

CREATE TABLE User (
id int primary key auto_increment, -- 用户编号(主键)
name varchar(50) not null unique, -- 用户名称
password varchar(20) not null, -- 密码
level int not null, -- 用户级别(必须是UserLevel表中的主键值)
boss int -- 老板编号
);

-- 插入初始管理员用户名及密码
insert into User values
(1, 'Admin', 'yaocc118', 2, null);

--
-- CommodityState商品状态表
--
DROP TABLE IF EXISTS CommodityState;

CREATE TABLE CommodityState (
id int primary key auto_increment, -- 商品状态id
name varchar(20) not null unique -- 商品状态名称
);

-- 插入商品状态类型
LOCK TABLES CommodityState WRITE;
insert into CommodityState values
(1, '待检'),
(2, '库存'),
(3, '下架'),
(4, '上架');
UNLOCK TABLES;

--
-- Commodity商品表结构
--
DROP TABLE IF EXISTS Commodity;

CREATE TABLE Commodity (
id int primary key auto_increment, -- 商品id
name varchar(50) not null unique, -- 商品名称
status int not null, -- 状态
category int not null, -- 类别
price decimal(12, 2) not null, -- 价格
stock int not null, -- 库存
bar_code varchar(50), -- 条形码
pic_path varchar(260) -- 图片路径
);

--
-- CommodityCategory商品表结构
--
DROP TABLE IF EXISTS CommodityCategory;

CREATE TABLE CommodityCategory (
id int primary key auto_increment, -- 类别编号
name varchar(20) not null unique -- 类别名称
);

--
-- CommodityPriceChanges商品价格变化表
--
DROP TABLE IF EXISTS CommodityPriceChanges;

CREATE TABLE CommodityPriceChanges (
id int primary key auto_increment, -- 商品价格变化记录编号
commodity_id int not null, -- 商品id
user_id int not null, -- 录入用户编号
entry_time datetime not null, -- 录入时间
new_price decimal(12, 2) not null, -- 新价格
old_price decimal(12, 2), -- 原价格
remark varchar(260) -- 备注
);

--
-- Supplier供应商表结构
--
DROP TABLE IF EXISTS Supplier;

CREATE TABLE Supplier (
id int primary key auto_increment, -- 供应商编号
name varchar(50) not null unique, -- 商品名称
cellphone varchar(20), -- 手机
telephone varchar(20), -- 电话
remark varchar(260) -- 备注
);

--
-- GodownEntry入库单结构
--
DROP TABLE IF EXISTS GodownEntry;

CREATE TABLE GodownEntry (
id int primary key auto_increment, -- 入库单编号
commodity_id int not null, -- 入库商品id
user_id int not null, -- 录入用户编号
purchase_price decimal(12, 2) not null, -- 进货价格
number int not null, -- 入库数量
entry_time datetime not null, -- 录入时间
supplier_id int, -- 供应商id
remark varchar(260) -- 备注
);

--
-- TransactionList交易清单清单结构
--
DROP TABLE IF EXISTS TransactionList;

CREATE TABLE TransactionList (
id int primary key auto_increment, -- 交易清单编号
entry_user_id int not null, -- 录入用户编号
entry_time datetime not null, -- 录入时间
closing_user_id int, -- 结束交易用户编号
closing_time datetime, -- 结束交易时间
amout decimal(12, 2), -- 交易金额
remark varchar(260) -- 备注
);

--
-- BonusList红利清单结构
--
DROP TABLE IF EXISTS BonusList;

CREATE TABLE BonusList (
id int primary key auto_increment, -- 红利清单编号
transaction_id int not null, -- 交易清单编号
entry_user_id int not null, -- 录入用户编号
entry_time datetime not null, -- 录入时间
amout decimal(12, 2) not null, -- 红利金额
remark varchar(260) -- 备注
);

--
-- AccountSales商品销售清单结构
--
DROP TABLE IF EXISTS AccountSales;

CREATE TABLE AccountSales (
id int primary key auto_increment, -- 销售清单编号
transaction_id int not null, -- 交易清单编号
entry_user_id int not null, -- 录入用户编号
entry_time datetime not null, -- 录入时间
commodity_id int not null, -- 商品编号
number int not null, -- 商品数量
amout decimal(12, 2) not null, -- 总金额
remark varchar(260) -- 备注
);

--
-- CommodityReturn退货清单
--
DROP TABLE IF EXISTS CommodityReturn;

CREATE TABLE CommodityReturn (
id int primary key auto_increment, -- 销售清单编号
account_id int not null, -- 销售清单编号
entry_user_id int not null, -- 录入用户编号
entry_time datetime not null, -- 录入时间
commodity_id int not null, -- 商品编号
number int not null, -- 退回商品数量
amout decimal(12, 2) not null, -- 总金额
remark varchar(260) -- 备注
);

--
-- ChessRoomState棋牌房间状态表数据结构
--
DROP TABLE IF EXISTS ChessRoomState;

CREATE TABLE ChessRoomState (
id int primary key auto_increment, -- 棋牌房间状态id
name varchar(20) not null unique -- 房间状态名称
);

-- 插入房间状态内容
LOCK TABLES ChessRoomState WRITE;
insert into ChessRoomState values
(1, '空闲'),
(2, '预定'),
(3, '计费'),
(4, '挂起');
UNLOCK TABLES;
--
-- ChessMember棋牌会员
--
DROP TABLE IF EXISTS ChessMember;

CREATE TABLE ChessMember (
id int primary key auto_increment, -- 会员id
name varchar(20) not null unique, -- 会员名称
cellphone varchar(20), -- 手机
telephone varchar(20), -- 电话
remark varchar(260) -- 备注
);

--
-- ChessRoom棋牌房间数据结构
--
DROP TABLE IF EXISTS ChessRoom;

CREATE TABLE ChessRoom (
id int primary key auto_increment, -- 棋牌房间id
name varchar(20) not null unique, -- 房间名称
status int not null, -- 房间当前状态id
charging_formula TEXT, -- 计费公式
scheduled_time datetime, -- 预定时间(可以为空)
scheduled_member_id int, -- 预定会员id
current_record_id int, -- 当前ChessRoomRecord记录id
remark varchar(260) -- 备注
);

--
-- ChessFormulaChanges棋牌房间计费公式修改记录
--
DROP TABLE IF EXISTS ChessFormulaChanges;

CREATE TABLE ChessFormulaChanges (
id int primary key auto_increment, -- 棋牌房间计费公式修改记录id
room_id int not null, -- 房间编号
entry_user_id int not null, -- 录入用户编号
entry_time datetime not null, -- 录入时间
new_formula TEXT, -- 新计费公式
old_formula TEXT, -- 旧计费公式
remark varchar(260) -- 备注
);

--
-- ChessRoomRecord棋牌房间开房记录
--
DROP TABLE IF EXISTS ChessRoomRecord;

CREATE TABLE ChessRoomRecord (
id int primary key auto_increment, -- 棋牌房间开房记录id
transaction_id int not null, -- 交易清单编号
room_id int not null, -- 房间编号
entry_user_id int, -- 录入用户编号
entry_time datetime, -- 录入时间
closing_user_id int, -- 结束交易用户编号
closing_time datetime, -- 结束交易时间
amout decimal(12, 2), -- 房费金额
remark varchar(260) -- 备注
);
