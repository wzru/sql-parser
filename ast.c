#include <stdio.h>

#include "ast.h"
#include "parser.tab.h"

SqlAst *ast_root;
int dbg = 0;
ExprNode *exp;

char *type_name[1024] =
{
    [EXPR_ADD] = "+",
    [EXPR_SUB] = "-",
    [EXPR_MUL] = "*",
    [EXPR_DIV] = "/",
    [EXPR_MOD] = "%",
    [EXPR_AND] = "AND",
    [EXPR_OR] = "OR",
    [EXPR_XOR] = "XOR",
    [EXPR_EQ] = "==",
    [EXPR_NE] = "!=",
    [EXPR_LT] = "<",
    [EXPR_GT] = ">",
    [EXPR_LE] = "<=",
    [EXPR_GE] = ">=",
    [EXPR_NEG] = "-",
    [EXPR_NOT] = "!"
};

// SqlAst *parse_sql (char *sql)
// {
//     void* bp = yy_scan_string (sql);
//     yy_switch_to_buffer (bp);
//     yyparse();
//     yy_flush_buffer (bp);
//     yy_delete_buffer (bp);
//     return ast_root;
// }

inline void repeat (char c, int cnt)
{
    while (cnt--)
    {
        putchar (c);
    }
}

void print_ast (SqlAst *node, int d)
{
    repeat ('\t', d);
    printf ("{\n");
    repeat ('\t', d + 1);
    printf ("type: ");
    if (node == NULL)
    {
        printf ("NULL\n");
    }
    else
    {
        switch (node->type)
        {
        case SELECT_STMT:
            printf ("SELECT,\n");
            print_select (node->select, d);
            break;
        case DELETE_STMT:
            printf ("DELETE,\n");
            print_select (node->delete, d);
            break;
        case INSERT_STMT:
            printf ("INSERT,\n");
            print_select (node->insert, d);
            break;
        case UPDATE_STMT:
            printf ("UPDATE,\n");
            print_select (node->update, d);
            break;
        default:
            printf ("UNKNOWN,\n");
        }
    }
    repeat ('\t', d);
    printf ("}\n");
}

void print_select (SelectNode *node, int d)
{
    if (node != NULL)
    {
        repeat ('\t', d + 1);
        printf ("columns: [\n");
        if (node->column_head != NULL)
        {
            print_column (node->column_head, d + 1);
        }
        repeat ('\t', d + 1);
        printf ("],\n");
    }
}

void print_delete (DeleteNode *node, int d);
void print_insert (InsertNode *node, int d);
void print_update (UpdateNode *node, int d);

void print_column (ExprNode *node, int d)
{
    if (node != NULL)
    {
        repeat ('\t', d);
        printf ("{\n");
        repeat ('\t', d + 1);
        printf ("type: ");
        if (node->type == NULL)
        {
            printf ("NULL\n");
        }
        else
        {
            switch (node->type)
            {
            case SELECT_ALL:
                printf ("*\n");
                break;
            case EXPR_NAME:
                printf ("column,\n");
                repeat ('\t', d + 1);
                printf ("column: %s\n", node->strval);
                break;
            case EXPR_TABLE_COLUMN:
                printf ("table.column,\n");
                repeat ('\t', d + 1);
                printf ("table: %s\n", node->table);
                repeat ('\t', d + 1);
                printf ("column: %s\n", node->strval);
                break;
            case EXPR_COUNT_ALL:
                printf ("count(*)\n");
                break;
            case EXPR_COUNT:
                printf ("count,\n");
                print_val_list (node->l, d + 1);
                break;
            case EXPR_SUM_ALL:
                printf ("sum(*)\n");
                break;
            case EXPR_SUM:
                printf ("sum,\n");
                print_val_list (node->l, d + 1);
                break;
            }
        }
        repeat ('\t', d);
        printf ("}");
        if (node->r != NULL)
        {
            printf (",\n");
            print_column (node->r, d + 1);
        }
        else
        {
            printf ("\n");
        }
    }
}

void print_val_list (ExprNode *node, int d)
{
    repeat ('\t', d);
    printf ("values: [\n");
    if (node != NULL)
    {
        repeat ('\t', d);
        printf ("{\n");
        print_expr (node, d + 1);
        repeat ('\t', d);
        printf ("}\n");
    }
    repeat ('\t', d);
    printf ("],\n");
}

void print_expr (ExprNode *node, int d)
{
    if (node != NULL)
    {
        repeat ('\t', d);
        printf ("type: ");
        switch (node->type)
        {
        case EXPR_NAME:
            printf ("name,\n");
            repeat ('\t', d);
            printf ("name: %s,\n", node->strval);
            break;
        case EXPR_TABLE_COLUMN:
            printf ("table.column,\n");
            repeat ('\t', d);
            printf ("table: %s,\n", node->table);
            repeat ('\t', d);
            printf ("column: %s,\n", node->strval);
            break;
        case EXPR_STRING:
            printf ("\"%s\",\n", node->strval);
            break;
        case EXPR_INTNUM:
            printf ("%d,\n", node->intval);
            break;
        case EXPR_APPROXNUM:
            printf ("%f,\n", node->floatval);
            break;
        case EXPR_ADD:
        case EXPR_SUB:
        case EXPR_MUL:
        case EXPR_DIV:
        case EXPR_MOD:
        case EXPR_AND:
        case EXPR_OR:
        case EXPR_XOR:
        case EXPR_EQ:
        case EXPR_NE:
        case EXPR_LT:
        case EXPR_GT:
        case EXPR_LE:
        case EXPR_GE:
        case EXPR_NEG:
        case EXPR_NOT:
            printf ("%s,\n", type_name[node->type]);
            repeat ('\t', d);
            printf ("lhs: {");
            print_expr (node->l, d + 1);
            repeat ('\t', d);
            printf ("},");
            repeat ('\t', d);
            printf ("rhs: {");
            print_expr (node->r, d + 1);
            repeat ('\t', d);
            printf ("},");
            break;
        }
    }
}

char *my_strdup(const char *s)
{
    if(s==NULL) return NULL;
    size_t len = strlen(s);
    char *t = malloc(len+1);
    memcpy(t, s, len);
    t[len]='\0';
    return t;
}