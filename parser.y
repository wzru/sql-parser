%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <malloc.h>
#include "ast.h"
%}

%union {
    int intval;
    double floatval;
    char *strval;
    int subtok;
    struct SelectNode *select;
    struct DeleteNode *delete;
    struct InsertNode *insert;
    struct UpdateNode *update;
    struct ColumnNode *column;
    struct TableNode *table;
    struct LimitNode *limit;
    struct ExprNode *expr;
    struct ValueListNode *value_list;
    struct SetNode *assign;
}

    /* 名字和字面值 */
%token <strval> NAME
%token <strval> STRING
%token <intval> INTNUM
%token <floatval> APPROXNUM
    /* operator */
%right ASSIGN
%left OR
%left XOR
%left ANDOP
%nonassoc IN IS LIKE REGEXP
%left NOT '!'
%left BETWEEN
%left <subtok> COMPARISON /* = <> < > <= >= <=> */
%left '|'
%left '&'
%left '+' '-'
%left '*' '/' '%' MOD
%left '^'
%nonassoc UMINUS

%token AND
%token AS
%token ASC
%token BY
%token CASE
%token COUNT
%token DELETE
%token DESC
%token ELSE
%token END
%token EXIT
%token FROM
%token GROUP
%token IMPORT
%token IN
%token INSERT
%token INTO
%token LIKE
%token LIMIT
%token NOT
%token OR
%token ORDER
%token SAVE
%token SELECT
%token SET
%token SUM
%token THEN
%token UPDATE
%token VALUES
%token WHEN
%token WHERE

%token FCOUNT
%token FSUM

%type <expr> expr opt_where opt_groupby opt_orderby insert_vals select_expr_list select_expr val_list opt_val_list groupby_list orderby_list orderby_node case_list
%type <select> select_stmt table_subquery
%type <delete> delete_stmt
%type <insert> insert_stmt
%type <update> update_stmt
%type <limit> opt_limit
%type <strval> opt_as_alias
%type <table> table_references table_reference
%type <intval> opt_asc_desc
%type <column> opt_col_names column_list
%type <value_list> insert_vals_list
%type <assign> update_asgn_list
%start stmt_list
%%

stmt_list: stmt ';'
    | stmt_list stmt ';'
    ;

expr: NAME {
        $$ = calloc(1, sizeof(ExprNode));//一般来说就是列名
        $$->type = EXPR_NAME;
        $$->strval = strdup($1);
        sprintf_s($$->text, EXPR_LENGTH, "%s", $1);
        free($1);
    }
    | NAME '.' NAME {
        $$ = calloc(1, sizeof(ExprNode));//一般来说是表.列
        $$->type = EXPR_TABLE_COLUMN;
        $$->strval = strdup($3);
        $$->table = strdup($1);
        sprintf_s($$->text, EXPR_LENGTH, "%s.%s", $1, $3);
        free($1); free($3);
    }
    | STRING {
        $$ = calloc(1, sizeof(ExprNode));
        $$->type = EXPR_STRING;
        $$->strval = strdup($1);
        sprintf_s($$->text, EXPR_LENGTH, "%s", $1);
        free($1);
    }
    | INTNUM {
        $$ = calloc(1, sizeof(ExprNode));
        $$->type = EXPR_INTNUM;
        $$->intval = $1;
        sprintf_s($$->text, EXPR_LENGTH, "%d", $1);
    }
    | APPROXNUM {
        $$ = calloc(1, sizeof(ExprNode));
        $$->type = EXPR_APPROXNUM;
        $$->floatval = $1;
        sprintf_s($$->text, EXPR_LENGTH, "%f", $1);
    }
    ;

expr: expr '+' expr { 
        $$ = calloc(1, sizeof(ExprNode));
        $$->type = EXPR_ADD;
        $$->l = $1, $$->r=$3;
        sprintf_s($$->text, EXPR_LENGTH, "%s+%s", $1->text, $3->text);
    }
    | expr '-' expr {         
        $$ = calloc(1, sizeof(ExprNode));
        $$->type = EXPR_SUB;
        $$->l = $1, $$->r=$3; 
        sprintf_s($$->text, EXPR_LENGTH, "%s-%s", $1->text, $3->text);
    }
    | expr '*' expr {         
        $$ = calloc(1, sizeof(ExprNode));
        $$->type = EXPR_MUL;
        $$->l = $1, $$->r=$3; 
        sprintf_s($$->text, EXPR_LENGTH, "%s*%s", $1->text, $3->text);
    }
    | expr '/' expr {         
        $$ = calloc(1, sizeof(ExprNode));
        $$->type = EXPR_DIV;
        $$->l = $1, $$->r=$3; 
        sprintf_s($$->text, EXPR_LENGTH, "%s/%s", $1->text, $3->text);
    }
    | expr '%' expr {         
        $$ = calloc(1, sizeof(ExprNode));
        $$->type = EXPR_MOD;
        $$->l = $1, $$->r=$3;  
        sprintf_s($$->text, EXPR_LENGTH, "%s%%s", $1->text, $3->text);
    }
    | '-' expr %prec UMINUS { 
        $$ = calloc(1, sizeof(ExprNode));
        $$->type = EXPR_NEG;
        $$->r=$2; 
        sprintf_s($$->text, EXPR_LENGTH, "-%s", $2->text);
    }
    | expr ANDOP expr {         
        $$ = calloc(1, sizeof(ExprNode));
        $$->type = EXPR_AND;
        $$->l = $1, $$->r=$3;  
        sprintf_s($$->text, EXPR_LENGTH, "%s AND %s", $1->text, $3->text);
    }
    | expr OR expr {        
        $$ = calloc(1, sizeof(ExprNode));
        $$->type = EXPR_OR;
        $$->l = $1, $$->r=$3;   
        sprintf_s($$->text, EXPR_LENGTH, "%s OR %s", $1->text, $3->text);
    }
    | expr XOR expr {        
        $$ = calloc(1, sizeof(ExprNode));
        $$->type = EXPR_XOR;
        $$->l = $1, $$->r=$3;  
        sprintf_s($$->text, EXPR_LENGTH, "%s XOR %s", $1->text, $3->text);
    }
    | NOT expr {         
        $$ = calloc(1, sizeof(ExprNode));
        $$->type = EXPR_NOT;
        $$->r=$2;   
        sprintf_s($$->text, EXPR_LENGTH, "!%s", $2->text);
    }
    | '!' expr {         
        $$ = calloc(1, sizeof(ExprNode));
        $$->type = EXPR_NOT;
        $$->r=$2;   
        sprintf_s($$->text, EXPR_LENGTH, "!%s", $2->text);
    }
    | expr COMPARISON expr { 
        $$ = calloc(1, sizeof(ExprNode));
        $$->type = $2;
        $$->l = $1, $$->r = $3;
        sprintf_s($$->text, EXPR_LENGTH, "(%s %s %s)", $1->text, type_name[$2], $3->text);
    }
    | expr COMPARISON '(' select_stmt ')' { 
        $$ = calloc(1, sizeof(ExprNode));
        $$->type = EXPR_SELECT;
        $$->op = $2;
        $$->select = $4;
        sprintf_s($$->text, EXPR_LENGTH, "(%s %s %s)", $1->text, type_name[$2], "SUBQUERY");
    }
    ;

val_list: expr {
        $$ = $1;
        $$->op = $$->type;
        $$->type = EXPR_VAL_LIST;
        $$->next = NULL;
        sprintf_s($$->text, EXPR_LENGTH, "%s", $1->text);
    }
    | expr ',' val_list { 
        $$ = $1;
        $$->op = $1->type;
        $$->type = EXPR_VAL_LIST;
        $$->next = $3;
        sprintf_s($$->text, EXPR_LENGTH, "%s,%s", $1->text, $3->text);
    }
    ;

opt_val_list: /* nil */ { $$ = NULL; }
    | val_list {
        $$ = $1;
    }
    ;

expr: expr IN '(' val_list ')'       { 
        $$ = calloc(1, sizeof(ExprNode));
        $$->type = EXPR_IN_VAL_LIST;
        $$->l = $1, $$->r = $4;
    }   
    | expr NOT IN '(' val_list ')'    { 
        $$ = calloc(1, sizeof(ExprNode));
        $$->type = EXPR_NOT_IN_VAL_LIST;
        $$->l = $1, $$->r = $5;
    }   
    | expr IN '(' select_stmt ')'     { 
        $$ = calloc(1, sizeof(ExprNode));
        $$->type = EXPR_IN_SELECT;
        $$->l = $1, $$->select = $4;
    }
    | expr NOT IN '(' select_stmt ')' { 
        $$ = calloc(1, sizeof(ExprNode));
        $$->type = EXPR_NOT_IN_SELECT;
        $$->l = $1, $$->select = $5;
    }
    ;

  /* functions */
expr: NAME '(' opt_val_list ')' {  
        $$ = calloc(1, sizeof(ExprNode));
        $$->type = EXPR_FUNC;
        $$->strval = strdup($1);
        $$->r = $3;
        free($1);
        sprintf_s($$->text, EXPR_LENGTH, "%s(%s)", $1, $3->text);
    }
    ;

  /* functions with special syntax */
expr: FCOUNT '(' '*' ')' { 
        $$ = calloc(1, sizeof(ExprNode));
        $$->type = EXPR_COUNT_ALL;
        sprintf_s($$->text, EXPR_LENGTH, "COUNT(*)");
    }
    | FCOUNT '(' expr ')' { 
        $$ = calloc(1, sizeof(ExprNode));
        $$->type = EXPR_COUNT;
        $$->r = $3;
        sprintf_s($$->text, EXPR_LENGTH, "COUNT(%s)", $3->text);
    }
    | FSUM '(' '*' ')' { 
        $$ = calloc(1, sizeof(ExprNode));
        $$->type = EXPR_SUM_ALL;
        sprintf_s($$->text, EXPR_LENGTH, "SUM(*)");
    }
    | FSUM '(' expr ')' { 
        $$ = calloc(1, sizeof(ExprNode));
        $$->type = EXPR_SUM;
        $$->r = $3;
        sprintf_s($$->text, EXPR_LENGTH, "SUM(%s)", $3->text);
    }
    ;

expr: CASE expr case_list END {
        $$ = calloc(1, sizeof(ExprNode));
        $$->l = $2;
        $$->type = EXPR_CASE_EXPR;
        $$->case_head = $3;
        sprintf_s($$->text, EXPR_LENGTH, "CASE %s %s END", $2->text, $3->text);
    }
    |  CASE expr case_list ELSE expr END { 
        $$ = calloc(1, sizeof(ExprNode));
        $$->l = $2, $$->r = $5;
        $$->type = EXPR_CASE_EXPR_ELSE;
        $$->case_head = $3;
        sprintf_s($$->text, EXPR_LENGTH, "CASE %s %s ELSE %s END", $2->text, $3->text, $5->text);
    }
    |  CASE case_list END {
        $$ = calloc(1, sizeof(ExprNode));
        $$->type = EXPR_CASE;
        $$->case_head = $2;
        sprintf_s($$->text, EXPR_LENGTH, "CASE %s END", $2->text);
    }
    |  CASE case_list ELSE expr END { 
        $$ = calloc(1, sizeof(ExprNode));
        $$->type = EXPR_CASE_ELSE;
        $$->case_head = $2;
        $$->r = $4;
        sprintf_s($$->text, EXPR_LENGTH, "CASE %s ELSE %s END", $2->text, $4->text);
    }
    ;

case_list: WHEN expr THEN expr {
        $$ = calloc(1, sizeof(ExprNode));
        $$->type = EXPR_CASE_NODE;
        $$->l = $2, $$->r = $4;
        sprintf_s($$->text, EXPR_LENGTH, "WHEN %s THEN %s", $2->text, $4->text);
    }
    | WHEN expr THEN expr case_list {
        $$ = calloc(1, sizeof(ExprNode));
        $$->type = EXPR_CASE_NODE;
        $$->l = $2, $$->r = $4;
        $$->next = $5;
        sprintf_s($$->text, EXPR_LENGTH, "WHEN %s THEN %s %s", $2->text, $4->text, $5->text);
    }
    ;

expr: expr LIKE expr { 
        $$ = calloc(1, sizeof(ExprNode));
        $$->type = EXPR_LIKE;
        $$->l = $1, $$->r = $3;
        sprintf_s($$->text, EXPR_LENGTH, "(%s LIKE %s)", $1->text, $3->text);
    }
    | expr NOT LIKE expr { 
        $$ = calloc(1, sizeof(ExprNode));
        $$->type = EXPR_NOT_LIKE;
        $$->l = $1, $$->r = $4;
        sprintf_s($$->text, EXPR_LENGTH, "(%s NOT LIKE %s)", $1->text, $4->text);
    }
    ;

   /* statements: select statement */
stmt: select_stmt { 
#ifdef DEBUG
        emit("SELECT STMT");
#endif
        ast_root = malloc(sizeof(SqlAst));
        ast_root->type = SELECT_STMT;
        ast_root->select = $1;
    }
    ;

select_stmt: SELECT select_expr_list {
#ifdef DEBUG
        emit("SELECTNODATA!");
#endif
    }
    | SELECT select_expr_list FROM table_references opt_where opt_groupby opt_orderby opt_limit
    {
        $$ = calloc(1, sizeof(SelectNode));
        $$->column_head = $2;
        $$->table_head = $4;
        $$->where = $5;
        $$->group = $6;
        $$->order = $7;
        $$->limit = $8;
     }
    ;

opt_where: /* nil */ {
        $$ = NULL;
    }
    | WHERE expr {
        $$ = $2;
    }
    ;

opt_groupby: /* nil */ {
        $$ = NULL;
    }
    | GROUP BY groupby_list {
        $$ = $3;
    }
    ;

groupby_list: expr {
        $$ = $1;
    }
    | expr ',' groupby_list {
        $$ = $1;
        $$->op = $$->type;
        $$->type = GROUPBY;
        $$->next = $3;
    }
    ;

orderby_node: expr opt_asc_desc {
        $$ = $1;
        $$->op = $$->type;
        $$->type = ORDERBY;
        $$->sc = $2;
    }
    ;

orderby_list: orderby_node{
        $$ = $1;
        $$->next = NULL;
    }
    | orderby_node ',' groupby_list {
        $$ = $1;
        $$->next = $3;
    }
    ;

opt_asc_desc: /* nil */ { 
        $$ = 0; 
    }
    | ASC { 
        $$ = 0; 
    }
    | DESC { 
        $$ = 1; 
    }
    ;

opt_orderby: /* nil */ {
        $$ = NULL;
    }
    | ORDER BY orderby_list {
        $$ = $3;
    }
   ;

opt_limit: /* nil */ {
        $$ = NULL;
    }
    | LIMIT INTNUM {
        $$ = calloc(1, sizeof(LimitNode));
        $$->start = 0, $$->count = $2;
    }
    | LIMIT INTNUM ',' INTNUM {
        $$ = calloc(1, sizeof(LimitNode));
        $$->start = $2, $$->count = $4;
    }
    ;

column_list: NAME { 
        $$ = calloc(1, sizeof(ColumnNode));//update时候用
        $$->column = strdup($1);
        $$->next = NULL;
        free($1);
    }
    | NAME ',' column_list { 
        $$ = calloc(1, sizeof(ColumnNode));
        $$->column = strdup($1);
        $$->next = $3;
        free($1);
    }
    ;

select_expr_list: select_expr {
        $$ = $1;
        $$->next = NULL;
    }
    | select_expr ',' select_expr_list {
        $$ = $1;
        $$->next = $3;
    }
    | '*' {
        $$ = calloc(1, sizeof(ExprNode));
        $$->type = SELECT_ALL;
    }
    ;

select_expr: expr opt_as_alias {
        $$ = $1;
        $$->alias = $2;
    } 
    ;

opt_as_alias: AS NAME { 
        $$ = strdup($2);
        free($2);
    }
    | NAME { 
        $$ = strdup($1);
        free($1);
    }
    | AS STRING {
        $$ = strdup($2);
        free($2);
    }
    | STRING {
        $$ = strdup($1);
        free($1);
     }
    | {
        $$ = NULL;
    }
    ;

table_references: table_reference { 
        $$ = $1;
        $$->next = NULL;
    }
    | table_reference ',' table_references {
        $$ = $1;
        $$->next = $3;
    }
    ;

opt_as: AS
    |
    ;

table_reference: NAME opt_as_alias {
        $$ = calloc(1, sizeof(TableNode));
        $$->type = TABLE_DEFAULT;
        $$->alias = $2;
        $$->table = strdup($1);
        free($1);
    }
    | table_subquery opt_as NAME { 
        $$ = calloc(1, sizeof(TableNode));
        $$->type = TABLE_SUBQUERY;
        $$->select = $1;
        $$->alias = strdup($3);
        free($3); 
    }
    | '(' table_references ')' { 
        $$ = $2;
    }
    ;

table_subquery: '(' select_stmt ')' { 
        $$ = $2;
    }
    ;

   /* statements: delete statement */
stmt: delete_stmt { 
#ifdef DEBUG
        emit("DELETE STMT");
#endif
        ast_root = malloc(sizeof(SqlAst));
        ast_root->type = DELETE_STMT;
        ast_root->delete = $1;
    }
    ;

   /* single table delete */
delete_stmt: DELETE FROM NAME opt_where{ 
        $$ = calloc(1, sizeof(DeleteNode));
        $$->table = strdup($3);
        $$->where = $4;
        free($3); 
    }
    ;

   /* statements: insert statement */
stmt: insert_stmt { 
#ifdef DEBUG
        emit("INSERT STMT");
#endif
        ast_root = malloc(sizeof(SqlAst));
        ast_root->type = INSERT_STMT;
        ast_root->insert = $1;
    }
    ;

insert_stmt: INSERT opt_into NAME opt_col_names VALUES insert_vals_list {
        $$ = calloc(1, sizeof(InsertNode));
        $$->table = strdup($3);
        $$->column_head = $4;
        $$->value_list_head = $6;
        free($3);
    }
    ;

opt_into: INTO | /* nil */
    ;

opt_col_names: /* nil */ {
        $$ = NULL;
    }
    | '(' column_list ')' { 
        $$ = $2;
    }
    ;

insert_vals_list: '(' insert_vals ')' { 
        $$ = calloc(1, sizeof(ValueListNode));
        $$->head = $2;
        $$->next = NULL;
    }
    | '(' insert_vals ')' ',' insert_vals_list { 
        $$ = calloc(1, sizeof(ValueListNode));
        $$->head = $2;
        $$->next = $5;
    }
    ;

insert_vals: expr { 
        $$ = $1;
        $$->r = NULL;
    }
    | expr ',' insert_vals { 
        $$ = $1;
        $$->r = $3;
    }
    ;

   /* statements: update statement */
stmt: update_stmt { 
#ifdef DEBUG
        emit("UPDATE STMT");
#endif
        ast_root = malloc(sizeof(SqlAst));
        ast_root->type = UPDATE_STMT;
        ast_root->update = $1;
    }
    ;

update_stmt: UPDATE NAME
    SET update_asgn_list
    opt_where { 
        $$ = calloc(1, sizeof(UpdateNode));
        $$->table = strdup($2);
        $$->set_head = $4;
        $$->where = $5;
        free($2);
    }
    ;

update_asgn_list: NAME COMPARISON expr { 
        $$ = calloc(1, sizeof(SetNode));
        $$->column = strdup($1);
        free($1);
        $$->expr = $3;
        $$->op = $2;
        $$->next = NULL;
    }
    | NAME COMPARISON expr ',' update_asgn_list { 
        $$ = calloc(1, sizeof(SetNode));
        $$->column = strdup($1);
        free($1);
        $$->op = $2;
        $$->expr = $3;
        $$->next = $5;
    }
    ;

%%
void emit(char *s, ...)
{
    extern yylineno;
    va_list ap;
    va_start(ap, s);
    printf("rpn: ");
    vfprintf(stdout, s, ap);
    printf("\n");
}
void yyerror(char *s, ...)
{
    extern yylineno;
    va_list ap;
    va_start(ap, s);
    fprintf(stderr, "%d: error: ", yylineno);
    vfprintf(stderr, s, ap);
    fprintf(stderr, "\n");
}
#ifdef DEBUG
int main()
{
    char csql[1024];
    printf("Please input: ");
    while(1)
    {
        memset(csql, 0, sizeof(csql));
        fgets(csql, 1024, stdin);
        printf("Recv:'%s'\n", csql);
        parse_sql(csql);
        printf("Please input: ");
    }
    return 0;
} /* main */
#endif