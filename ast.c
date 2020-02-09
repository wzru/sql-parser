#include "ast.h"

SqlAst *ast_root;

SqlAst* parse_sql(char *sql)
{
    void* bp = yy_scan_string(sql);
    yy_switch_to_buffer(bp);
    yyparse();
    yy_flush_buffer(bp);
    yy_delete_buffer(bp);
    return ast_root;
}