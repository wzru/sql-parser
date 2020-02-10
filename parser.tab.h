/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NAME = 258,
     STRING = 259,
     INTNUM = 260,
     APPROXNUM = 261,
     ASSIGN = 262,
     OR = 263,
     XOR = 264,
     ANDOP = 265,
     REGEXP = 266,
     LIKE = 267,
     IS = 268,
     IN = 269,
     NOT = 270,
     BETWEEN = 271,
     COMPARISON = 272,
     MOD = 273,
     UMINUS = 274,
     AND = 275,
     AS = 276,
     ASC = 277,
     BY = 278,
     CASE = 279,
     COUNT = 280,
     DELETE = 281,
     DESC = 282,
     ELSE = 283,
     END = 284,
     EXIT = 285,
     FROM = 286,
     GROUP = 287,
     IMPORT = 288,
     INSERT = 289,
     INTO = 290,
     LIMIT = 291,
     ORDER = 292,
     SAVE = 293,
     SELECT = 294,
     SET = 295,
     SUM = 296,
     THEN = 297,
     UPDATE = 298,
     VALUES = 299,
     WHEN = 300,
     WHERE = 301,
     FCOUNT = 302,
     FSUM = 303
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 10 "parser.y"

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
    struct CaseNode *cas;
    struct ValueListNode *value_list;
    struct SetNode *assign;


/* Line 2058 of yacc.c  */
#line 124 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
