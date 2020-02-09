#ifndef AST_H
#define AST_H

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char byte;

// struct ValueNode;
// struct TableNode;
// struct SelectNode;
// struct ColumnNode;
// struct ConditionNode;
// struct ExprNode;
// struct LimitNode;
// struct DeleteNode;
// struct InsertNode;
// struct ValueListNode;
// struct UpdateNode;
// struct CaseNode;
// struct SetNode;

// typedef struct ValueNode ValueNode;
// typedef struct TableNode TableNode;
// typedef struct SelectNode SelectNode;
// typedef struct ColumnNode ColumnNode;
// typedef struct ConditionNode ConditionNode;
// typedef struct ExprNode ExprNode;
// typedef struct LimitNode LimitNode;
// typedef struct DeleteNode DeleteNode;
// typedef struct InsertNode InsertNode;
// typedef struct ValueListNode ValueListNode;
// typedef struct UpdateNode UpdateNode;
// typedef struct CaseNode CaseNode;
// typedef struct SetNode SetNode;

enum
{
    EXPR_NAME = 1024,
    EXPR_TABLE_COLUMN,
    EXPR_STRING,
    EXPR_INTNUM,
    EXPR_APPROXNUM,
    EXPR_ADD,
    EXPR_SUB,
    EXPR_MUL,
    EXPR_DIV,
    EXPR_MOD,
    EXPR_NEG,
    EXPR_AND,
    EXPR_OR,
    EXPR_XOR,
    EXPR_NOT,
    EXPR_EQ,
    EXPR_NE,
    EXPR_LT,
    EXPR_GT,
    EXPR_LE,
    EXPR_GE,
    EXPR_SELECT,
    EXPR_IN_VAL_LIST,
    EXPR_NOT_IN_VAL_LIST,
    EXPR_IN_SELECT,
    EXPR_NOT_IN_SELECT,
    EXPR_VAL_LIST,
    EXPR_FUNC,
    EXPR_COUNT_ALL,
    EXPR_COUNT,
    EXPR_SUM_ALL,
    EXPR_SUM,
    EXPR_CASE,
    EXPR_CASE_ELSE,
    EXPR_CASE_EXPR,
    EXPR_CASE_EXPR_ELSE,
    EXPR_LIKE,
    EXPR_NOT_LIKE,
    EXPR_COLUMN,
    EXPR_COLUMN_ALL,
    TABLE_DEFAULT,
    TABLE_SUBQUERY,
    ORDERBY,
    SELECT_ALL,
    SELECT_STMT,
    DELETE_STMT,
    INSERT_STMT,
    UPDATE_STMT
};

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
} ExprNode;

typedef struct ValueNode
{
    struct ExprNode *value;
    struct ValueNode *next;
} ValueNode;

typedef struct ValueListNode
{
    struct ValueNode *head;
    struct ValueListNode *next;
} ValueListNode;

typedef struct CaseNode
{
    struct ExprNode *cond, *then;
    struct CaseNode *next;
} CaseNode;

typedef struct TableNode
{
    u16 type;
    union
    {
        char *table;
        struct SelectNode *select;//子查询
    };
    char *alias;
    struct TableNode *next;
} TableNode;

typedef struct SetNode
{
    char *column;
    struct ExprNode *expr;
    struct SetNode *next;
} SetNode;

typedef struct ColumnNode
{
    char *column;
    struct ColumnNode* next;
} ColumnNode;

typedef struct LimitNode
{
    u32 start, count;
} LimitNode;

typedef struct SelectNode
{
    struct ExprNode *column_head;
    struct TableNode *table_head;
    struct ExprNode *where;
    struct ExprNode *group;
    struct ExprNode *order;
    struct LimitNode *limit;
} SelectNode;

typedef struct DeleteNode
{//简易版
    struct ColumnNode *column_head;
    char *table;
    struct ExprNode *where;
} DeleteNode;

typedef struct InsertNode
{
    struct ColumnNode *column_head;
    char *table;
    struct ValueListNode *value_list_head;
} InsertNode;

typedef struct UpdateNode
{
    struct ColumnNode *column_head;
    char *table;
    struct TableNode *table_head;
    struct ValueNode *value_head;
    struct ExprNode *where;
} UpdateNode;

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

void yyerror(char *s, ...);
void emit(char *s, ...);
SqlAst* parse_sql(char *sql);

#endif