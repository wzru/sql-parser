# SQL Parser
A concise SQL parser using Flex &amp; Bison

一个使用Flex&Bison构建的简单SQL解析器，可以作为一些组件的编译前端。

## Usage

### Compile

Just `make`. Also need flex & bison.

这个项目使用Makefile。Windows平台可以选择WSL/MinGW/Cygwin。构建这个项目也需要Flex和Bison。

Makefile有多种编译目标，建议可以编译为静态库/动态库的方式调用。

### Quick Start
Create main.c in sql-parser folder:
```c
#include "ast.h"
int main()
{
    char *sql = "SELECT * FROM TABLE;";
    SqlAst *ast = parse_sql(sql);
    print_ast(ast, 0);
    return 0;
}
```
Run:
```bash
gcc main.c -o main -L. -lparser
./main
```
It will output like:
```bash
{
        type: SELECT,
        columns: [
        {
                type: *
        }
        ],
}
```

## Background

因为最近在写[课设]( https://github.com/WangZhengru/Crims )，但课设本身太无聊了，又由于课设是跟数据库操作相关，所以便想写一个SQL解释器。

又由于课设仅限C语言，很自然地只能使用Flex&Bison，这里参考了动物书系列的[flex & bison]( http://shop.oreilly.com/product/9780596155988.do )。原书上有一个SQL解释器的实现（不过给出的源码并没有构建出AST），这个项目参考了这个实现并进行了一些修改，增加了构建AST的实现，减少了一些功能（所以也许并不能叫SQL解释器，得叫CSQL[Concise SQL]解释器）。

## Features

### Keywords

目前有且仅有如下关键字：

```sql
AND
AS
ASC
BY
CASE
DELETE
DESC
ELSE
END
FROM
GROUP
IN
INSERT
INTO
LIKE
LIMIT
NOT
OR
ORDER
SELECT
SET
THEN
UPDATE
VALUES
WHEN
WHERE
```

目前不支持的功能有`HAVING`, `JOIN`, `DISTINCT`等。

### Statements

目前支持4种语句：`SELECT`, `DELETE`, `INSERT`, `UPDATE`。

**支持子查询，支持CASE**。

### Functions

目前支持3个函数：`COUNT()`, `SUM()`, `TIMESTAMPDIFF()`。

## Test

以下语句已测试通过（由于Bison的原因，标识符暂不支持中文，但字符串支持中文）：

- [x] SELECT A, B, C FROM E, F, G;
- [x] SELECT A.B, C.D FROM A, C;
- [x] SELECT A.B AS B, C.D AS D FROM A, C;
- [x] SELECT COUNT(*) FROM SQL;
- [x] SELECT COUNT(A.B) FROM SQL;
- [x] INSERT INTO CAR_INFO VALUES("鄂A3S880", "1", "大众朗逸", "1.6自动", "135", "y");
- [x] UPDATE RENT_ORDER
  SET name="李四", phone_number="13388888888"
   	WHERE oid="2019021505";
- [x] DELETE FROM CAR_TYPE WHERE code='5';
- [x] SELECT code, cname, gear, daily_rent 
  FROM CAR_INFO
   	WHERE rent='n' 
   	AND code IN (SELECT code 
                  FROM CAR_TYPE 
         	     WHERE tname="经济型");
- [x] SELECT code, cname, gear, daily_rent 
  FROM CAR_INFO
   	WHERE rent='n'
   	AND code IN (SELECT code 
                  FROM CAR_TYPE
                  WHERE tname="经济型" 
                  OR tname="商务型");
- [x] SELECT *
  FROM CAR_INFO	
   	WHERE plate LIKE "%鄂A%";
- [x] SELECT *
  FROM RENT_ORDER
   	WHERE pickup_time >= '2019/02/11'
   	AND pickup_time <= '2019/05/12';
- [x] SELECT COUNT(CASE WHEN CAR_INFO.rent='y' THEN 1 END)      
  		
  AS ASDF FROM CAR_TYPE, CAR_INFO
  WHERE CAR_TYPE.code=CAR_INFO.code;
- [x] SELECT COUNT(CASE WHEN CAR_INFO.rent='y' THEN 1 END) AS rent, 
  	   COUNT(CASE WHEN CAR_INFO.rent='n' THEN 1 END) AS notrent
  	FROM CAR_TYPE, CAR_INFO
      WHERE CAR_TYPE.code=CAR_INFO.code;
- [x] SELECT CAR_INFO.plate, 
  	   CAR_INFO.cname, 
  	   SUM(RENT_ORDER.actual_fee) AS turnover
         FROM CAR_INFO, RENT_ORDER
         WHERE CAR_INFO.cid=RENT_ORDER.cid
         GROUP BY CAR_INFO.plate;
- [x] SELECT CAR_INFO.plate, 
  	   CAR_INFO.cname, 
  	   SUM(RENT_ORDER.actual_fee) AS "营业额", 
         SUM(TIMESTAMPDIFF(DAY, RENT_ORDER.pickup_time, RENT_ORDER.actual_dropoff_time))/365 AS "租用率"
         FROM CAR_INFO, RENT_ORDER
         WHERE CAR_INFO.cid=RENT_ORDER.cid
         GROUP BY CAR_INFO.plate;

## Implementation

> Think twice, code once.

如果你不介意浪费一些内存，你可以去掉以下所有的`union`

### Top

首先是顶层的AST节点，这里将4类语句的指针放在了`union`里面：

```c
typedef struct SqlAst
{
    u16 type;
    union
    {
        SelectNode *select;
        DeleteNode *delete;
        InsertNode *insert;
        UpdateNode *update;
    };
} SqlAst;
extern SqlAst *ast_root;
```

Bison有一个缺点，就是使用了一些全局变量。~~（所以这里我也使用了）~~

我这里定义了一个全局变量，当调用`parse_sql()`时，会暂时存在`ast_root`里面，然后返回。

### Insert

从最简单的`INSERT`语句开始

```c
typedef struct InsertNode
{
    struct ColumnNode *column_head;
    char *table;
    struct ValueListNode *value_list_head;
} InsertNode;
```

每个`INSERT`语句会有一张插入表的名称（不考虑多表插入，考虑的话也很好改），插入的列名列表和插入的值的**列表的列表**。

```c
typedef struct ValueListNode
{
    struct ExprNode *head;
    struct ValueListNode *next;
} ValueListNode;
```

这里的`head`即为单个值列表的列表头。具体的`ExprNode`类型见后。

### Delete

```c
typedef struct DeleteNode
{//简易版
    struct ColumnNode *column_head;
    char *table;
    struct ExprNode *where;
} DeleteNode;
```

`DELETE`多了一个条件`WHERE`，这里的`WHERE`是表达式类型`ExprNode*`, 这个是比较显然的。（一般）就是一些表达式的复合。

### Update

```c
typedef struct UpdateNode
{
    char *table;
    SetNode *set_head;
    struct ExprNode *where;
} UpdateNode;

typedef struct SetNode
{
    char *column;
    u16 op;
    struct ExprNode *expr;
    struct SetNode *next;
} SetNode;
```

`UPDATE`相对不同的地方在于存在一个**列名和值的二元组的链表**，所以设计了`SetNode`。

### Select

`SELECT`相对而言最复杂，也是最常用的操作。

```c
typedef struct SelectNode
{
    struct ExprNode *column_head;
    struct TableNode *table_head;
    struct ExprNode *where;
    struct ExprNode *group;
    struct ExprNode *order;
    struct LimitNode *limit;
} SelectNode;
```

`SELECT 「列」的列表 FROM 「表」的列表 [WHERE条件] [GROUP] [ORDER] [LIMIT]`

又考虑到这里的「列」不一定是简单列，所以也**抽象**为了`Expr`。`ORDER`等同理。

### Expression

表达式是最「多变」的类型

```c
typedef struct ExprNode
{
    u16 type;
    union
    {
        int intval;
        float floatval;
        char *strval;
        struct SelectNode *select;
        struct CaseNode *case_head;
        byte sc;
    };
    char *table, *alias;
    u16 op;
    struct ExprNode *l, *r;
    struct ExprNode *next;
} ExprNode;
```

`ExprNode`通过`type`参数和`op`参数来标识类型

`ExprNode`可以表示的类型有：

+ 列名/字符串——strval
+ 表名.列名——表名存在table，列名存在strval
+ 整数——intval
+ 浮点数——floatval
+ 表达式之间的各种算数运算和逻辑运算，其中`LHS`存在`l`，`RHS`存在`r` 
+ 子表达式是否存在/不存在于一个值列表中，其中子表达式存在`l`，值列表头指针为`r`
+ 含有`COUNT`, `SUM`等的表达式，参数列表头存在`r`
+ CASE子句
+ LIKE表达式
+ SELECT子查询
+ ORDER BY子句

## Maintainers

[wzru](https://github.com/wzru)

## License

[GPL-3.0](https://github.com/wzru/Crims/blob/master/LICENSE) © wzru
