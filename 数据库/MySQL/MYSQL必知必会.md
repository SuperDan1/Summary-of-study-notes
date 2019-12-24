typora-copy-images-to: pic
[TOC]

# SQL简介

## 数据库基础

- 数据库（DataBase——DB）：按照数据结构来组织、存储和管理数据的容器
- RDBMS（Relational Database Management System）：关系型数据库管理系统
  - `RDBMS` 是 SQL 的基础，同样也是所有现代数据库系统的基础，比如 `MS SQL Server`、`IBM DB2`、`Oracle`、`MySQL` 以及 `Microsoft Access`。
  - RDBMS 中的数据存储在被称为**表**的数据库对象中。
    - 表（table）：某种特定类型数据的结构化清单
    - 表是相关的数据项的集合，它由列和行组成。
      - 数据类型（datatype）：每个表的列都有相应的数据类型，限制（或容许）该列中存储的数据
      - 列（column）：表中的一个字段——所有表都是由一个或多个列组成的
      - 行（row）：表中的一个记录
        - 表中的数据是**按行存储**的
        - 所保存的每个记录存储在自己的行内
      - 主键（primary key）：一列（或一组列），其值能够唯一区分表中每个行——订单ID、编号等
        - 任意两行都不具有相同的主键值
        - 每个行都必须具有一个主键值（主键值不允许NULL值）
        - 可以使用多个列作为主键——所有列值的组合必须是唯一的（但单个列的值可以不唯一）
- 模式（schema）：关于数据库和表的布局及特性的信息，例如
  - 数据在表中如何存储
  - 数据如何分解
  - 各部分信息如何命名

## SQL

- SQL是用于**访问和处理数据库**的标准的计算机语言
  - SQL（Structured Query Language）：结构化查询语言
  - SQL可以访问和处理数据库
  - SQL 是一种 ANSI（American National Standards Institute 美国国家标准化组织）标准的计算机语言
- SQL的优点
  - 几乎所有重要的DBMS都支持SQL
  - 简单易学
  - 灵活使用，可以进行非常复杂和高级的数据库操作

## MySQL

> 数据的所有存储、检索、管理和处理实际上是由数据库软件——DBMS（数据库管理系统）完成的。MySQL是一种DBMS——一种数据库软件

* MySQL的优点
  * 成本：MySQL是开放源代码的，一般可以免费使用（甚至可以免费修改）
  * 性能：MySQL执行很快
  * 可信赖：很多大公司使用MySQL
  * 简单：MySQL容易安装和使用
* DBMS
  * 基于共享文件系统的DBMS：桌面用途，通常不用于高端或者更关键的应用
    * Microsoft Acess
    * FileMaker
  * 基于客户机-服务器的DBMS
    * 服务器部分：负责所有数据访问和处理的一个软件，运行在**数据库服务器**上
    * 客户机：用户通过客户机向服务器提出请求

# 使用MySQL

## 连接

* MySQL是客户机-服务器DBMS，要求在能执行命令之前能登陆到DBMS；MySQL在内部保存自己的用户列表，并且把每个用户与各种权限关联起来
* 为了连接到MySQL，需要以下信息
  * 主机名（计算机名）——如果连接到本地MySQL服务器，`localhost`
  * 端口：如果使用默认端口3306之外的端口需要指明，否则省略
  * 一个合法的用户名
  * 用户命令

## 选择数据库——USE

```mysql
USE DATABASE;
```

## 了解数据库和表——SHOW

* 数据库、表、列、用户、权限等的信息被存储在数据库和表中；不过，内部的表一般不直接访问，可以使用命令`SHOW`来显示这些信息

  * 自动增量：主键（订单编号、雇员ID等）需要唯一值，在每行添加到表中时，MySQL可以自动地为每个行分配下一个可用编号

  * 显示可用数据库的列表

    ```mysql
    SHOW DATABASES;
    ```

  * 显示一个数据库内的表的列表

    ```mysql
    SHOW TABLES;
    ```

  * 显示表内的列——字段名、数据类型、是否允许NULL、键信息、默认值（缺省值）以及其他信息（如字段ID是auto_increment）

    ```mysql
    SHOW COLUMNS FROM table_name;
    # 同上
    DESCRIBE table_name;
    ```
    
  * 显示广泛的服务器状态信息
  
    ```mysql
    SHOW STATUS;
    ```
  
  * 显示创建特定数据库或表的MySQL语句
  
    ```mysql
    SHOW CREATE DATABASE;
    SHOW CREATE TABLE;
    ```
  
  * 显示授权用户（所有用户或特定用户）的安全权限
  
    ```mysql
    SHOW GRANTS;
    ```
  
  * 显示服务器错误或警告信息
  
    ```mysql
    SHOW ERRORS;
    SHOW WARNINGS;
    ```
  
  * 进一步了解`SHOW`
  
    ```mysql
    HELP SHOW;
    ```


# 创建和操纵表

## 创建表——CREATE TABLE

* 创建表，必须给出下列2种信息

  * 新表的名字
  * 列的名字和定义，用逗号分隔

* 创建表实例

  ```MYSQL
  CREATE TABLE table_name IF NOT EXISTS
  (
  	column_name1 int      NOT NULL AUTO_INCREMENT,
  	column_name2 char(50) NOT NULL,
  	column_name3 char(50) NULL,
  	column_name4 int      NOT NULL DEAULT 1,
  	PRIMARY KEY (column_name1)
   )ENGINE=InnoDB;
  ```
  
  * 在创建新表时，指定的表名必须不存在，否则将出错；`IF NOT EXISTS`表示在一个表不存在时创建
  
  * 表名紧跟在`CREATE TABLE`关键字后面；实际表定义括在**圆括号之中**，各列之间用逗号分隔
  
  * `PRIMARY KEY`关键字指定表的主键：主键值必须唯一，只能使用`NOT NULL`的列
    
    * 主键使用单个列，则它的值必须唯一
    * 主键使用多个列，则这些列的组合值必须唯一
    
  * `NULL`和`NOT NULL`
    
    * `NULL`为默认设置，如果不指定，**默认该列允许没有值**
    * `NOT NULL`指该列不接受没有值的行——在插入或更新行时，该列必须有值
    
  * `AUTO_INCREMENT`：本列每当增加一行时自动增量
    
    * 每个表只允许一个`AUTO_INCREMENT`列
    
    * 本列必须被索引（通过使它成为主键）
    
    * `last_insert_id()`函数可以获得最后一个`AUTO_INCREMENT`的值
    
      ```mysql
      SELECT last_insert_id();
      ```
    
  * 如果在插入行时没有给出值，MYSQL使用`DEFAULT`关键字指定此时使用的默认值
    * 与大多数DBMS不一样，MYSQL不允许使用函数作为默认值，只支持常量
    * 大多数情况下应使用默认值，而不是`NULL`列，特别是对于计算或数据分组的列
    
  * 引擎类型：具体管理和处理数据的内部引擎——`CREATE TABLE`时该引擎具体创建表，而在使用`SELECT`语句或进行其他数据库处理时，该引擎在内部处理你的请求，多数情况下，此引擎都隐藏在`DBMS`内
    
    * MySQL具有多种引擎，全都能执行建表、查询等命令，但具有不同的功能和特性
      * 如果忽略`ENGINE=`语句，则使用默认引擎（很可能是`MyISAM`）
      * `InnoDB`是一个**可靠**的**事物处理引擎**，**不支持全文本搜索**
      * `MEMORY`在功能上等同于`MyISAM`，但由于数据存储在内存（不是磁盘）中，速度很快（特别**适合于临时表**）
      * `MyISAM`是一个**性能极高**的引擎，**支持全文本搜索**，但**不支持事物处理**
    * 引擎类型可以混用，但是**外键不能跨外键**——使用一个引擎的表不能引用具有使用不同引擎的表的外键
  
* 数据类型

  * 数值类型
  
    |     类型      | 大小  |   范围（有符号）   | 范围（无符号） |      用途      |
    | :-----------: | :---: | :----------------: | :------------: | :------------: |
    |    TINYINT    | 1字节 |     (-128,127)     |    (0,255)     |    小整数值    |
    |   SMALLINT    | 2字节 |   (-32768,32767)   |   (0,65535)    |    大整数值    |
    |   MEDIUMINT   | 3字节 | (-8388608,8388607) |  (0,16777215)  |    大整数值    |
    | INT或INTERGER | 4字节 |                    |                |    大整数值    |
    |    BIGINT     | 8字节 |                    |                |   极大整数值   |
    |     FLOAT     | 4字节 |                    |                | 单精度浮点数值 |
    |    DOUBLE     | 8字节 |                    |                | 双精度浮点数值 |
    |    DECIMAL    |       |                    |                |     小数值     |
  
  * 日期和时间类型
  
    |   类型    | 大小  |                  范围                   |        格式         |           用途           |
    | :-------: | :---: | :-------------------------------------: | :-----------------: | :----------------------: |
    |   DATE    | 3字节 |          1000-01-01~9999-12-31          |     YYYY-MM-DD      |          日期值          |
    |   TIME    | 3字节 |        '-838:59:59'~'838:59:59'         |      HH:MM::SS      |     时间值或持续时间     |
    |   YEAR    | 1字节 |                1901~2155                |        YYYY         |          年份值          |
    | DATATIME  | 8字节 | 1000-01-01 00:00:00~9999-12-31 23:59:59 | YYYY-MM-DD HH:MM:SS |      混合日期和时间      |
    | TIMESTAMP | 4字节 | 1970-01-01 00:00:00/2038-1-19 11:14:07  |   YYYYMMDD HHMMSS   | 混合日期和时间值，时间戳 |
  
  * 字符串类型
  
    |    类型     |       大小       |             用途              |
    | :---------: | :--------------: | :---------------------------: |
    |    CHAR     |    0-255字节     |          定长字符串           |
    |   VARCHAR   |   0-65535字节    |          变长字符串           |
    |  TINYBLOB   |    0-255字节     | 不超过255个字符的二进制字符串 |
    | MEDIUMBLOB  |  0-16777215字节  | 二进制形式的中等长度文本数据  |
    |    BLOB     |   0-65535字节    |    二进制形式的长文本shuju    |
    |  LONGBLOG   | 0-4294967295字节 |   二进制形式的极大文本数据    |
    |  TINYTEXT   |    0-255字节     |         短文本字符串          |
    | MEDIUMBTEXT |  0-16777215字节  |       中等长度文本数据        |
    |    TEXT     |   0-65535字节    |          长文本字节           |
    |  LONGTEXT   | 0-4294967295字节 |         极大文本数据          |
  

## 更新——ALTER

> 理想状态下，当表中存储数据以后，该表就不应该再被更新。在表的设计过程中需要花费大量时间来考虑，以便后期不对该表进行大的改动

* 为了更改表结构，必须给出下面的信息

  * 在`ALTER TABLE`之后给出要更改的表名（该表必须存在）

  * 所做更改的列表

* 更新表：使用`ALTER TABLE`语句

  * 给表添加一个列

    ```mysql
    ALTER TABLE table_name ADD column_name data_type
    ```

  * 删除表的一列

    ```mysql
    ALTER TABLE table_name DROP column column_name
    ```

* 使用`ALTER TABLE`要极为小心，应该在进行改动前做一个完整的备份（模式和数据的备份）

  * 数据库的更改不能撤销
  * 增加了不需要的列，可能不能删除它们
  * 删除了不应该删除的列，可能会丢失该列中的所有数据

## 删除表——DROP

* 删除表：使用`DROP TABLE`语句删除整个表

  * 删除表没有确认，也不能撤销

  * 执行删除表操作将永久删除该表

    ```mysql
    DROP TABLE table_name
    ```

## 重命名表——RENAME
* 重命名表：使用`RENAME TABLE`语句可以重命名一个表

  ```mysql
  RENAME TABLE table_name1 TO new_table_name1,
               table_name2 TO new_table_name2,
               table_name3 TO new_table_name3
  ```

# 数据插入——INSERT

## 插入完整的行

* 指定表名和被插入到新行中的值使用INSERT插入一个完整的行

  ```mysql
  INSERT INTO       table_name(column_name1,column_name2,column_name3,...)
  VALUES (value1, value2, value3,...)
  ```

* 在表名后的括号里明确给出列名，省略时默认插入所有列名数值
  
  * VALUES以指定的次序匹配指定的列名，不一定按各个列出现在实际表中的次序——优点是即使表的结构改变，`INSERT`依然能正确运行
* `INSERT LOW_PRIORITY INTO`指示降低`INSERT`的优先级，同样适用于`UPDATE`和`DELETE`语句
  
  * 数据库经常被多个客户访问，对处理什么请求以及用什么次序处理进行管理是MySQL的任务
  * `INSERT`操作可能很耗时（特别是有很多索引需要更新时），而且可能降低等待处理的SELECT语句的性能

## 插入多个行

* 单条`INSERT`语句处理多个插入比使用多条`INSERT`语句快

  ```mysql
  INSERT INTO table_name(column_name1,column_name2,column_name3,...)
  VALUES (value1, value2, value3,...),
	   (value1, value2, value3,...),
       ....;
  ```

## 插入检索出的数据

* 将一条`SELECT`语句的结果插入表中

```mysql
INSERT INTO table_name1(column_name1,column_name2,column_name3,...)
SELECT column_name1,column_name2,column_name3,... from table_name2;
```

* 两个表的列名不要求相同，Mysql使用的是列的位置

# 更新和删除数据

## 更新数据——UPDATE

* 更新数据：使用`UPDATE`语句更新特定行

  ```mysql
  UPDATE IGNORE table_name SET column_name1=value1, column2_name2=value2,... WHERE...;
  ```

  * `SET`命令：将新值赋给被更新的列

  * WHERE子句限制更新哪行

  * IGNORE关键字（可不填）
    * `UPDATE`语句更新多行，并在更新这些行中的一行或多行时出现一个错误，则整个`UPDATE`操作取消（错误发生前更新的所有行被恢复到它们原来的值）
    * 使用`IGNORE`关键字即使发生错误也继续进行更新
    
  * 为了删除某个列的值，可设置它为`NULL`（假如表定义允许`NULL`值）

## 删除数据——DELETE

* 删除数据：使用`DELETE`语句删除特定行

  ```mysql
  DELETE FROM table_name WHERE condition;
  ```

  * `DELETE`语句从表中删除行，甚至是删除表中所有行，但是不删除表本身
  * 更快的删除：如果想从表中删除所有行，不要使用`DELETE`，可以使用`TRUNCATE TABLE`语句，它完成相同的工作，但速度更快（`TRUNCATE` 实际是删除原来的表并重新创建一个表，而不是逐行删除表中的数据）

# 检索数据

## 检索——SELECT

> SELECT：从数据库中选取数据，结果被存储在一个结果表中（称为结果集）
>
> * 想选择什么
> * 从什么地方选择

- 语法：

  - 从表中检索单个列

    ```mysql
    SELECT column_name FROM table_name
    ```

  - 从表中检索某几列：列名之间必须以逗号分隔

    ```mysql
    SELECT column_name1, column_name2.... FROM table_name
    ```

  - 检索表中所有列：虽然使用通配符使自己省事，但检索不需要的列通常会**降低**检索和应用程序的**性能**

    ```mysql
    SELECT * FROM table_name
    ```

- 注意：

  - 查询结果的**数据顺序**没有特殊意义
  - 多条SQL语句最好以**分号**分隔
  - SQL语句不区分大小写，但习惯——`SQL`关键字使用大写，而对所有列和表名使用小写
  - 处理SQL语句时，其中所有空格都被忽略，所以SQL语句可以分成多行

## 检索不同的行——SELECT DISTINCT

> SELECT DISTINCT：返回唯一不同的值

- 语法

  - `Distinct`关键字**应用于所有列**而不仅是前置它的列
  - 如下，必须两个列不同才视为两行不同

  ```mysql
  SELECT DISTINCT column_name1, column_name2
  FROM table_name;
  ```

- DISTINCT关键字应用于**选择的所有列**，而不是紧跟的列（与后面的`DESC`相反）

## 限制结果——LIMIT

> LIMIT子句：返回前几行

* 返回前几行

  ```mysql
  SELECT column_name from table_name LIMIT num;
  ```

* 指定要检索的开始行和行数

  ```mysql
  SELECT column_name from table_name LIMIT num offset num_start;
  ```

  * 检索出来的第一行为行0——计数从0开始
  * 行数不够时返回能返回的那么多行

## 排序检索数据——ORDER BY

> ORDER BY子句：取一个或多个列的名字，据此对输出进行排序

* 按照单列进行排序：默认**升序**

  ```mysql
  SELECT columns_name1, column_name2 from table ORDER BY column_name
  ```

* 按照多个列排序：先根据`column_name1`进行排序，在`column_name1`相同的情况下，再根据`column_name2`进行排序

* 指定排序方向`DESC`、`ASC`

  * 单列降序排序

    ```mysql
  SELECT columns_name1, column_name2 from table ORDER BY column_name DESC
    ```
    
  * 多列排序，`DESC`只应用到直接位于其前面的列名；如果想在多个列上进行降序排序，必须对每个列指定`DESC`关键字
  
* `ORDER BY`子句的位置

  * `ORDER BY`子句应该位于`FROM`子句之后
  * `ORDER BY`子句应该位于`LIMIT`子句之前

## 使用完全限定的表名

> 完全限定的名字来引用列——同时使用表名和列字
>
> 完全限定的名字来引用表——同时使用库名和表名

# 过滤数据

## WHERE子句

- `WHERE`子句：提取那些满足指定的搜索条件的记录

  ```mysql
  SELECT column_name, column_name
  FROM table_name
  WHERE column_name operator value;
  ```

  - SQL使用**单引号**来环绕文本值（大部分数据库系统也接受双引号）
  - MySQL在执行匹配时默认**不区分大小写**
  - 在同时使用`ORDER BY`和`WHERE`子句时，应该让`ORDER BY`位于`WHERE`之后，否则将会产生错误
  - `IS NULL`：检查具有`NULL`值的列——`NULL`与字段包含0、空字符串或仅仅包含空格不同

- `WHERE`子句中的运算符

  |           运算符           |            描述            |
  | :------------------------: | :------------------------: |
  |             =              |            等于            |
  |           <>, !=           |           不等于           |
  |            >, <            |         大于和小于         |
  |           >=, <=           |     大于等于和小于等于     |
  |        BETWEEN  AND        |        在某个范围内        |
  |            LIKE            |        搜索某种模式        |
  | IN(value1, value2, value3) | 指定针对某个列的多个可能值 |

  - `BETWEEN`匹配范围中所有的值，包括指定的**开始值**和**结束值**
  - MySQL在执行字符匹配时默认**不区分大小写**

## 组合WHERE子句

> 操作符（operator）用来联结或改变WHERE子句中的子句的关键字，也称为逻辑操作符（logistical operator）

* `AND`操作符：指示检索满足所有给定条件的行

  ```mysql
  SELECT columns_name1, column_name2, column_name3 
  FROM table_name
  WHERE conditon1 AND condition2
  ```

* `OR`操作符：指示检索满足任一条件的行

  ```mysql
  SELECT columns_name1, column_name2
  FROM table_name
  WHERE conditon1 OR condition2
  ```

* 计算次序 ：`AND`操作符优先级高，最好使用**圆括号**明确地分组对应的操作符

* `IN`操作符：可以完成与`OR`相同的功能

  * `IN`计算的次序更容易管理
  * `IN`操作符一般比`OR`操作符清单**执行更快**
  * `IN`可以包含其他`SELECT`语句

* `NOT`操作符：否定它之后所跟的任何条件

## 用通配符进行过滤

### LIKE操作符

* 通配符（wildcard）：用来匹配值的一部分的特殊字符
* 百分号（%）通配符：表示任何字符出现任意次数（**包括0次**）——不能匹配`NULL`
  * M%：模糊查询信息为M开头的
  * %M%：表示查询包含M的所有内容
* 下划线（_）通配符：只匹配单个字符
  * %M_：表示查询以M在倒数第二位的所有内容

### 使用通配符的技巧

> MySQL的通配符很有用，但通配符搜索的处理一般时间更长

* 不要过度使用通配符——如果其他操作符能达到相同目的，应该使用其他操作符
* 尽量不要把通配符用在搜索模式的开始处，这样是最慢的

## 用正则表达式进行搜索

> 正则表达式：用来匹配文本的特殊的串——可以看正则表达式必知必会

### 基本字符匹配

* `REGEXP ‘zxc’`：告诉MySQL：REGEXP后面跟的东西作为正则表达式

* `.`表示一个字符的占位符

* MySQL中的正则表达匹配不区分大小写，为区分大小写，可使用`BINARY`关键字

  ```mysql
  WHERE column_name REGEXP BINARY 'abc';
  ```

### 进行OR匹配——|

* |为正则表达式的OR操作符：满足两个匹配之一即可

  ```mysql
  SELECT column_name 
  FROM table_name
  WHERE column_name1 REGEXP '1000|2000';
  ```

### 匹配几个字符之一

* 通过指定一组用`[]`括起来的字符来完成：`[]`中字符只占一位

  * `[123]`匹配1、2、3中的任一字符
  * `[^123]`匹配除1、2、3之外的字符

  ```mysql
  SELECT column_name FROM table_name WHERE column_name1 REGEXP '[123] TON'
  ```

### 匹配范围

* 简化数字`[123456789]`为`[1-9]`
* 简化字符`[abcdef]`为`[a-f]`

### 匹配特殊字符（TODO）



### 匹配字符类（TODO）

### 匹配多个实例（TODO）

### 定位符（TODO）

# 创建计算字段（TODO）

> 计算字段：并不实际存在于数据库表中，是运行时在SELECT语句内创建的

# 使用数据处理函数（TODO）

# 汇总数据

## 聚集函数

* 聚集函数（aggregate function）：运行在行组上，计算和返回单个值的函数

  |  函数   |       说明       |
  | :-----: | :--------------: |
  |  AVG()  | 返回某列的平均值 |
  | COUNT() |  返回某列的行数  |
  |  MAX()  | 返回某列的最大值 |
  |  MIN()  | 返回某列的最小值 |
  |  SUM()  |  返回某列值之和  |

  > MySQL还支持一系列的标准偏差聚集函数，可以自行查阅

## AVG()函数

* `AVG()`通过对表中行数技术并计算特定列值之和，求得该列的平均值

  * `AVG()`只能用来确定特定数值列的平均值

  * `AVG()`函数忽略列值为`NULL`的值

    ```mysql
    SELECT AVG(column_name) AS alias FROM TABLE_NAME
    ```

## COUNT()函数

* `COUNT()`函数进行计数，确定表中行的数目

  * `COUNT(*)`对表中行的数目进行计数，不管表列中包含的是空值（`NULL`）还是非空值

  * `COUNT(column)`对特定列中具有值的行进行计数，忽略`NULL`值

    ```mysql
    SELECT COUNT(*) AS column_name 
    FROM table_name;
    ```

## MAX()、MIN()函数

* `MAX()、MIN()`返回指定列中的最大值、最小值，忽略`NULL`值

## SUM()函数

* `SUM()`返回指定列值的和，忽略`NULL`值

# 分组数据——GROUP BY

## 创建分组

* 分组：允许把数据分为多个逻辑组，以便对每个组进行聚集计算
* `GROUP BY`：指示MySQL分组数据，然后对每个组而不是整个结果集进行聚集
  * `GROUP BY`子句可以包含任意数目的列——能对分组进行嵌套，为数据分组提供更细致的控制
  * 如果在`SELECT`中使用表达式，则必须在`GROUP BY`子句中指定相同的表达式，不能使用别名
  * `GROUP BY`子句中的每个列都必须在`SELECT`的列中
  * `GROUP BY`子句必须出现在`WHERE`子句之后，`ORDER BY`子句之前

## 过滤分组

* 过滤分组：规定包括哪些分组，排除哪些分组
  * 不能使用`WHERE`，因为`WHERE`过滤指定的是行而不是分组
  * 使用`HAVING`子句——非常类似于`WHERE`，唯一的差别是`HAVING`过滤组，`WHERE`过滤行

## 分组和排序

## SELECT子句顺序

|   子句   |        说明        |
| :------: | :----------------: |
|  SELECT  | 要返回的列或表达式 |
|   FROM   |  从中检索数据的表  |
|  WHERE   |      行级过滤      |
| GROUP BY |        分组        |
|  HAVING  |      组级过滤      |
| ORDER BY |    输出排序顺序    |
|  LIMIT   |    要检索的行数    |

# 使用子查询

> 子查询（subquery）：嵌套在其他查询中的查询

* 利用子查询进行过滤
  * 子查询总是从内向外处理
  * 在`WHERE`子句中使用子查询能够编写出功能很强并且很灵活的SQL语句
  * 对于能嵌套的子查询的数目没有限制，不过在实际使用时由于性能的限制，不能嵌套太多的子查询
* 使用子查询作为计算字段

# 联结表

## 关系表

* 例子——假如有一个包含产品目录的数据库表，其中每种类别的物品占一行，对于每种物品要存储的信息包括产品描述和价格，以及生产该产品的供应商信息；假如有由同一供应商生产的多种物品
  * 建立两个表，一个存储供应商信息，另一个存储产品信息
    * 供应商信息不重复，从而不浪费时间和空间
    * 如果供应商信息变动，可以只更新供应商表中的单个记录，相关表中的数据不用改动
    * 由于数据无重复，显然数据是一致的，使得处理数据更简单
* 外键（foreign key）：外键为某个表中的一列，包含另一个表的主键值，定义了两个表之间的关系
* 可伸缩性（scale）：能够适应不断增加的工作量而不失败。设计良好的数据库或应用程序称之为可伸缩性好

## 为什么要使用联结（join）

* 分解数据为多个表能更有效地存储，更方便地处理，并且具有更大的可伸缩性，需要使用联结检索出数据
* 联结是一种机制，可以联结多个表返回一组输出，联结在运行时关联表中正确的行
* 维护引用完整性
  * 联结不是物理实体，它在实际的数据库表中不存在，由MySQL根据需要建立，存在于查询的执行当中
  * 在使用关系表时，仅在关系列中插入合法的数据非常重要

## 创建联结

* 规定要联结的所有表以及它们如何关联即可

  ```mysql
  SELECT column_name1, column_name2, column_name3 
  FROM table_name1, table_name2
  WHERE table_name1.column_name1 = table_name2.column_name1
  ```

* 完全限定列名：在引用的列可能出现二义性时，必须使用完全限定列名

## 内部联结

* 上述的联结称为等值联结（equijoin），基于两个表之间的相等测试，可以使用稍微不同的语法

  * `INNER JOIN`联结两个表
  * `ON`表示联结条件

  ```mysql
  SELECT column_name1, column_name2, column_name3 
  FROM table_name1 INNER JOIN table_name2
  ON table_name1.column_name1 = table_name2.column_name1
  ```

* MySQL在运行时关联指定的每个表以处理联结，这种处理可能是非常耗费资源的，因此应该仔细，不要联结不必要的表。联结的表越多，性能下降约厉害

## 外部联结

* 联结包含了那些在相关表中没有关联行的行，称为外部联结
* `LEFT OUTER JOIN`
* `RIGHT OUTER JOIN`



# 创建高级连结

* 使用表别名
  * 缩短SQL语句
  * 允许在单条SELECT语句中多次使用相同的表

# 组合查询

# 全文本搜索 

> 并非所有引擎都支持全文本搜索，`MyISAM`支持全文本搜索，而`InnoDB`不支持全文本搜索



# 使用视图

# 使用存储过程

# 使用游标

# 管理事物处理

# 改善性能

> 位于https://dev.mysql.com/doc/的MySQL文档有许多提示和技巧（甚至有用户提供的评论和反馈），可以时常进行查看

* MySQL是用一系列的默认设置预先配置的，这些设置开始通常是很好的。但过一段时间可能需要**调整内存分配**、**缓冲区大小**，为查看当前设置，可使用命令

  ```mysql
  SHOW VARIABLES;
  SHOW STATUS;
  ```

* MySQL是一个多用户多线程，即经常同时执行多个任务；如果这些任务中的某一个执行缓慢，则所有请求都会执行缓慢

  * 如果遇到显著的性能不良，可使用命令显示所有活动进程（以及它们的线程ID和执行时间）

    ```mysql
    SHOW PROCESSLIST;
    ```

  * 用`KILL`命令终结某个特定的进程（需要管理员登录）

* 应该尝试联结、并、子查询等，找出最佳的方法

* 使用`EXPLAIN`语句让MySQL解释它将如何执行一条`SELECT`语句

* 使用正确的数据类型

* 存储过程执行比一条一条执行MySQL语句快

* 不要检索比需求还多的数据

* 
