--
-- �������ݿ�chess_sys_db
--

create database chess_sys_db character set utf8 collate utf8_general_ci;
use chess_sys_db;

--
-- UserLevel�û�����ṹ
--
DROP TABLE IF EXISTS UserLevel;

CREATE TABLE UserLevel (
level int primary key auto_increment, -- �û�����(����)
name varchar(20) not null -- ��������
);

-- �����ʼ����
LOCK TABLES UserLevel WRITE;
insert into UserLevel values
(1, '�ο�'),
(2, 'ϵͳ����Ա'),
(3, '�ϰ�'),
(4, 'ǰ̨'),
(5, '������Ա');
UNLOCK TABLES;

--
-- User�û��ṹ
--
DROP TABLE IF EXISTS User;

CREATE TABLE User (
id int primary key auto_increment, -- �û����(����)
name varchar(50) not null unique, -- �û�����
password varchar(20) not null, -- ����
level int not null, -- �û�����(������UserLevel���е�����ֵ)
boss int -- �ϰ���
);

-- �����ʼ����Ա�û���������
insert into User values
(1, 'Admin', 'yaocc118', 2, null);

--
-- CommodityState��Ʒ״̬��
--
DROP TABLE IF EXISTS CommodityState;

CREATE TABLE CommodityState (
id int primary key auto_increment, -- ��Ʒ״̬id
name varchar(20) not null unique -- ��Ʒ״̬����
);

-- ������Ʒ״̬����
LOCK TABLES CommodityState WRITE;
insert into CommodityState values
(1, '����'),
(2, '���'),
(3, '�¼�'),
(4, '�ϼ�');
UNLOCK TABLES;

--
-- Commodity��Ʒ��ṹ
--
DROP TABLE IF EXISTS Commodity;

CREATE TABLE Commodity (
id int primary key auto_increment, -- ��Ʒid
name varchar(50) not null unique, -- ��Ʒ����
status int not null, -- ״̬
category int not null, -- ���
price decimal(12, 2) not null, -- �۸�
stock int not null, -- ���
bar_code varchar(50), -- ������
pic_path varchar(260) -- ͼƬ·��
);

--
-- CommodityCategory��Ʒ��ṹ
--
DROP TABLE IF EXISTS CommodityCategory;

CREATE TABLE CommodityCategory (
id int primary key auto_increment, -- �����
name varchar(20) not null unique -- �������
);

--
-- CommodityPriceChanges��Ʒ�۸�仯��
--
DROP TABLE IF EXISTS CommodityPriceChanges;

CREATE TABLE CommodityPriceChanges (
id int primary key auto_increment, -- ��Ʒ�۸�仯��¼���
commodity_id int not null, -- ��Ʒid
user_id int not null, -- ¼���û����
entry_time datetime not null, -- ¼��ʱ��
new_price decimal(12, 2) not null, -- �¼۸�
old_price decimal(12, 2), -- ԭ�۸�
remark varchar(260) -- ��ע
);

--
-- Supplier��Ӧ�̱�ṹ
--
DROP TABLE IF EXISTS Supplier;

CREATE TABLE Supplier (
id int primary key auto_increment, -- ��Ӧ�̱��
name varchar(50) not null unique, -- ��Ʒ����
cellphone varchar(20), -- �ֻ�
telephone varchar(20), -- �绰
remark varchar(260) -- ��ע
);

--
-- GodownEntry��ⵥ�ṹ
--
DROP TABLE IF EXISTS GodownEntry;

CREATE TABLE GodownEntry (
id int primary key auto_increment, -- ��ⵥ���
commodity_id int not null, -- �����Ʒid
user_id int not null, -- ¼���û����
purchase_price decimal(12, 2) not null, -- �����۸�
number int not null, -- �������
entry_time datetime not null, -- ¼��ʱ��
supplier_id int, -- ��Ӧ��id
remark varchar(260) -- ��ע
);

--
-- TransactionList�����嵥�嵥�ṹ
--
DROP TABLE IF EXISTS TransactionList;

CREATE TABLE TransactionList (
id int primary key auto_increment, -- �����嵥���
entry_user_id int not null, -- ¼���û����
entry_time datetime not null, -- ¼��ʱ��
closing_user_id int, -- ���������û����
closing_time datetime, -- ��������ʱ��
amout decimal(12, 2), -- ���׽��
remark varchar(260) -- ��ע
);

--
-- BonusList�����嵥�ṹ
--
DROP TABLE IF EXISTS BonusList;

CREATE TABLE BonusList (
id int primary key auto_increment, -- �����嵥���
transaction_id int not null, -- �����嵥���
entry_user_id int not null, -- ¼���û����
entry_time datetime not null, -- ¼��ʱ��
amout decimal(12, 2) not null, -- �������
remark varchar(260) -- ��ע
);

--
-- AccountSales��Ʒ�����嵥�ṹ
--
DROP TABLE IF EXISTS AccountSales;

CREATE TABLE AccountSales (
id int primary key auto_increment, -- �����嵥���
transaction_id int not null, -- �����嵥���
entry_user_id int not null, -- ¼���û����
entry_time datetime not null, -- ¼��ʱ��
commodity_id int not null, -- ��Ʒ���
number int not null, -- ��Ʒ����
amout decimal(12, 2) not null, -- �ܽ��
remark varchar(260) -- ��ע
);

--
-- CommodityReturn�˻��嵥
--
DROP TABLE IF EXISTS CommodityReturn;

CREATE TABLE CommodityReturn (
id int primary key auto_increment, -- �����嵥���
account_id int not null, -- �����嵥���
entry_user_id int not null, -- ¼���û����
entry_time datetime not null, -- ¼��ʱ��
commodity_id int not null, -- ��Ʒ���
number int not null, -- �˻���Ʒ����
amout decimal(12, 2) not null, -- �ܽ��
remark varchar(260) -- ��ע
);

--
-- ChessRoomState���Ʒ���״̬�����ݽṹ
--
DROP TABLE IF EXISTS ChessRoomState;

CREATE TABLE ChessRoomState (
id int primary key auto_increment, -- ���Ʒ���״̬id
name varchar(20) not null unique -- ����״̬����
);

-- ���뷿��״̬����
LOCK TABLES ChessRoomState WRITE;
insert into ChessRoomState values
(1, '����'),
(2, 'Ԥ��'),
(3, '�Ʒ�'),
(4, '����');
UNLOCK TABLES;
--
-- ChessMember���ƻ�Ա
--
DROP TABLE IF EXISTS ChessMember;

CREATE TABLE ChessMember (
id int primary key auto_increment, -- ��Աid
name varchar(20) not null unique, -- ��Ա����
cellphone varchar(20), -- �ֻ�
telephone varchar(20), -- �绰
remark varchar(260) -- ��ע
);

--
-- ChessRoom���Ʒ������ݽṹ
--
DROP TABLE IF EXISTS ChessRoom;

CREATE TABLE ChessRoom (
id int primary key auto_increment, -- ���Ʒ���id
name varchar(20) not null unique, -- ��������
status int not null, -- ���䵱ǰ״̬id
charging_formula TEXT, -- �Ʒѹ�ʽ
scheduled_time datetime, -- Ԥ��ʱ��(����Ϊ��)
scheduled_member_id int, -- Ԥ����Աid
current_record_id int, -- ��ǰChessRoomRecord��¼id
remark varchar(260) -- ��ע
);

--
-- ChessFormulaChanges���Ʒ���Ʒѹ�ʽ�޸ļ�¼
--
DROP TABLE IF EXISTS ChessFormulaChanges;

CREATE TABLE ChessFormulaChanges (
id int primary key auto_increment, -- ���Ʒ���Ʒѹ�ʽ�޸ļ�¼id
room_id int not null, -- ������
entry_user_id int not null, -- ¼���û����
entry_time datetime not null, -- ¼��ʱ��
new_formula TEXT, -- �¼Ʒѹ�ʽ
old_formula TEXT, -- �ɼƷѹ�ʽ
remark varchar(260) -- ��ע
);

--
-- ChessRoomRecord���Ʒ��俪����¼
--
DROP TABLE IF EXISTS ChessRoomRecord;

CREATE TABLE ChessRoomRecord (
id int primary key auto_increment, -- ���Ʒ��俪����¼id
transaction_id int not null, -- �����嵥���
room_id int not null, -- ������
entry_user_id int, -- ¼���û����
entry_time datetime, -- ¼��ʱ��
closing_user_id int, -- ���������û����
closing_time datetime, -- ��������ʱ��
amout decimal(12, 2), -- ���ѽ��
remark varchar(260) -- ��ע
);
