/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <malloc.h>
#include "ast.h"

/* Line 371 of yacc.c  */
#line 77 "parser.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
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
/* Line 387 of yacc.c  */
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


/* Line 387 of yacc.c  */
#line 187 "parser.tab.c"
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

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 215 "parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  29
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   521

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNRULES -- Number of states.  */
#define YYNSTATES  187

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    15,     2,     2,     2,    25,    20,     2,
      60,    61,    23,    21,    62,    22,    59,    24,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    58,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    27,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    19,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      16,    17,    18,    26,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,    10,    12,    16,    18,    20,    22,
      26,    30,    34,    38,    42,    45,    49,    53,    57,    60,
      63,    67,    73,    75,    79,    80,    82,    88,    95,   101,
     108,   113,   118,   123,   128,   133,   138,   145,   149,   155,
     160,   166,   170,   175,   177,   180,   189,   190,   193,   194,
     198,   200,   204,   207,   209,   213,   214,   216,   218,   219,
     223,   224,   227,   232,   234,   238,   240,   244,   246,   249,
     252,   254,   257,   259,   260,   262,   266,   268,   269,   272,
     276,   280,   284,   286,   291,   293,   300,   302,   303,   304,
     308,   312,   318,   320,   324,   326,   332,   336
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      64,     0,    -1,    69,    58,    -1,    64,    69,    58,    -1,
       3,    -1,     3,    59,     3,    -1,     4,    -1,     5,    -1,
       6,    -1,    65,    21,    65,    -1,    65,    22,    65,    -1,
      65,    23,    65,    -1,    65,    24,    65,    -1,    65,    25,
      65,    -1,    22,    65,    -1,    65,    10,    65,    -1,    65,
       8,    65,    -1,    65,     9,    65,    -1,    16,    65,    -1,
      15,    65,    -1,    65,    18,    65,    -1,    65,    18,    60,
      70,    61,    -1,    65,    -1,    65,    62,    66,    -1,    -1,
      66,    -1,    65,    14,    60,    66,    61,    -1,    65,    16,
      14,    60,    66,    61,    -1,    65,    14,    60,    70,    61,
      -1,    65,    16,    14,    60,    70,    61,    -1,     3,    60,
      67,    61,    -1,    56,    60,    23,    61,    -1,    56,    60,
      65,    61,    -1,    57,    60,    23,    61,    -1,    57,    60,
      65,    61,    -1,    33,    65,    68,    38,    -1,    33,    65,
      68,    37,    65,    38,    -1,    33,    68,    38,    -1,    33,
      68,    37,    65,    38,    -1,    54,    65,    51,    65,    -1,
      54,    65,    51,    65,    68,    -1,    65,    12,    65,    -1,
      65,    16,    12,    65,    -1,    70,    -1,    48,    80,    -1,
      48,    80,    40,    83,    71,    72,    77,    78,    -1,    -1,
      55,    65,    -1,    -1,    41,    32,    73,    -1,    65,    -1,
      65,    62,    73,    -1,    65,    76,    -1,    74,    -1,    74,
      62,    73,    -1,    -1,    31,    -1,    36,    -1,    -1,    46,
      32,    75,    -1,    -1,    45,     5,    -1,    45,     5,    62,
       5,    -1,     3,    -1,     3,    62,    79,    -1,    81,    -1,
      81,    62,    80,    -1,    23,    -1,    65,    82,    -1,    30,
       3,    -1,     3,    -1,    30,     4,    -1,     4,    -1,    -1,
      85,    -1,    85,    62,    83,    -1,    30,    -1,    -1,     3,
      82,    -1,    86,    84,     3,    -1,    60,    83,    61,    -1,
      60,    70,    61,    -1,    87,    -1,    35,    40,     3,    71,
      -1,    88,    -1,    43,    89,     3,    90,    53,    91,    -1,
      44,    -1,    -1,    -1,    60,    79,    61,    -1,    60,    92,
      61,    -1,    60,    92,    61,    62,    91,    -1,    65,    -1,
      65,    62,    92,    -1,    93,    -1,    52,     3,    49,    94,
      71,    -1,     3,    18,    65,    -1,     3,    18,    65,    62,
      94,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   100,   100,   101,   104,   110,   117,   123,   128,   135,
     140,   145,   150,   155,   160,   165,   170,   175,   180,   185,
     190,   195,   203,   209,   217,   218,   223,   229,   235,   241,
     250,   260,   264,   269,   273,   280,   286,   292,   297,   305,
     309,   316,   321,   329,   339,   344,   356,   359,   364,   367,
     372,   375,   382,   390,   394,   400,   403,   406,   411,   414,
     419,   422,   426,   432,   438,   446,   450,   454,   460,   466,
     470,   474,   478,   482,   487,   491,   497,   498,   501,   508,
     515,   520,   526,   537,   546,   556,   565,   565,   568,   571,
     576,   581,   588,   592,   599,   609,   620,   628
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NAME", "STRING", "INTNUM", "APPROXNUM",
  "ASSIGN", "OR", "XOR", "ANDOP", "REGEXP", "LIKE", "IS", "IN", "'!'",
  "NOT", "BETWEEN", "COMPARISON", "'|'", "'&'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "MOD", "'^'", "UMINUS", "AND", "AS", "ASC", "BY", "CASE", "COUNT",
  "DELETE", "DESC", "ELSE", "END", "EXIT", "FROM", "GROUP", "IMPORT",
  "INSERT", "INTO", "LIMIT", "ORDER", "SAVE", "SELECT", "SET", "SUM",
  "THEN", "UPDATE", "VALUES", "WHEN", "WHERE", "FCOUNT", "FSUM", "';'",
  "'.'", "'('", "')'", "','", "$accept", "stmt_list", "expr", "val_list",
  "opt_val_list", "case_list", "stmt", "select_stmt", "opt_where",
  "opt_groupby", "groupby_list", "orderby_node", "orderby_list",
  "opt_asc_desc", "opt_orderby", "opt_limit", "column_list",
  "select_expr_list", "select_expr", "opt_as_alias", "table_references",
  "opt_as", "table_reference", "table_subquery", "delete_stmt",
  "insert_stmt", "opt_into", "opt_col_names", "insert_vals_list",
  "insert_vals", "update_stmt", "update_asgn_list", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,    33,   270,   271,   272,   124,
      38,    43,    45,    42,    47,    37,   273,    94,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,    59,    46,
      40,    41,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    64,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    66,    66,    67,    67,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    68,
      68,    65,    65,    69,    70,    70,    71,    71,    72,    72,
      73,    73,    74,    75,    75,    76,    76,    76,    77,    77,
      78,    78,    78,    79,    79,    80,    80,    80,    81,    82,
      82,    82,    82,    82,    83,    83,    84,    84,    85,    85,
      85,    86,    69,    87,    69,    88,    89,    89,    90,    90,
      91,    91,    92,    92,    69,    93,    94,    94
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     1,     3,     1,     1,     1,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     2,     2,
       3,     5,     1,     3,     0,     1,     5,     6,     5,     6,
       4,     4,     4,     4,     4,     4,     6,     3,     5,     4,
       5,     3,     4,     1,     2,     8,     0,     2,     0,     3,
       1,     3,     2,     1,     3,     0,     1,     1,     0,     3,
       0,     2,     4,     1,     3,     1,     3,     1,     2,     2,
       1,     2,     1,     0,     1,     3,     1,     0,     2,     3,
       3,     3,     1,     4,     1,     6,     1,     0,     0,     3,
       3,     5,     1,     3,     1,     5,     3,     5
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    87,     0,     0,     0,     0,    43,    82,    84,
      94,     0,    86,     0,     4,     6,     7,     8,     0,     0,
       0,    67,     0,     0,     0,    73,    44,    65,     0,     1,
       0,     2,    46,    88,     0,    24,    19,    18,    14,     0,
       0,     0,     0,     0,    70,    72,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    68,
       0,     0,     0,     3,     0,    83,     0,     0,     5,    22,
      25,     0,     0,     0,     0,    37,     0,     0,     0,     0,
      16,    17,    15,    41,     0,     0,     0,     0,    20,     9,
      10,    11,    12,    13,    69,    71,    73,     0,    46,    74,
      77,    66,     0,    46,    47,    63,     0,     0,     0,    30,
       0,     0,    35,     0,    31,    32,    33,    34,     0,     0,
      42,     0,     0,    78,     0,     0,    48,     0,    76,     0,
       0,    95,     0,    89,     0,    85,    23,    39,     0,    38,
      26,    28,     0,     0,    21,    81,    80,     0,    58,    75,
      79,    96,    64,    92,     0,    40,    36,    27,    29,     0,
       0,    60,     0,     0,    90,    50,    49,     0,     0,    45,
      97,    93,     0,     0,    55,    53,    59,    61,    91,    51,
      56,    57,    52,     0,     0,    54,    62
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,    69,    70,    71,    41,     6,     7,    65,   148,
     166,   175,   176,   182,   161,   169,   106,    26,    27,    59,
      98,   129,    99,   100,     8,     9,    13,    67,   135,   154,
      10,   103
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -164
static const yytype_int16 yypact[] =
{
      51,   -31,   -23,   190,    28,   130,   -20,  -164,  -164,  -164,
    -164,    45,  -164,    52,     7,  -164,  -164,  -164,   273,   273,
     273,  -164,   194,    10,    18,   430,    40,     1,    35,  -164,
      29,  -164,    38,    37,    99,   273,     4,     4,  -164,   273,
     330,    58,   216,   237,  -164,  -164,   273,   273,   273,   273,
      44,    23,     8,   273,   273,   273,   273,   273,    97,  -164,
       0,   190,   109,  -164,   273,  -164,   111,    63,  -164,    67,
    -164,    57,   351,    68,   273,  -164,    59,   289,    60,   310,
     466,   482,   212,   496,   252,   273,    75,    80,   129,    49,
      49,  -164,  -164,  -164,  -164,  -164,     3,    -1,    38,    77,
     107,  -164,   123,    38,   449,    81,    83,    95,   273,  -164,
     273,   273,  -164,   369,  -164,  -164,  -164,  -164,    96,    98,
     496,   252,   100,  -164,   105,   106,   117,     0,  -164,   159,
     273,  -164,   111,  -164,   273,  -164,  -164,   330,   387,  -164,
    -164,  -164,   108,   110,  -164,  -164,  -164,   136,   126,  -164,
    -164,   101,  -164,   124,   113,  -164,  -164,  -164,  -164,   273,
     152,   142,   109,   273,   139,   167,  -164,   273,   197,  -164,
    -164,  -164,    95,   273,   405,   141,  -164,   145,  -164,  -164,
    -164,  -164,  -164,   273,   199,  -164,  -164
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -164,  -164,    -3,   -52,  -164,   -39,   203,   -79,   -41,  -164,
    -163,  -164,  -164,  -164,  -164,  -164,    79,   153,  -164,   119,
     -93,  -164,  -164,  -164,  -164,  -164,  -164,  -164,    46,    54,
    -164,    82
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_int16 yytable[] =
{
      25,    73,    96,    96,   125,   119,    44,    45,   122,    11,
     179,    14,    15,    16,    17,    36,    37,    38,   124,    40,
     185,    12,    52,    18,    19,    53,    54,    55,    56,    57,
      20,    28,   118,    58,   149,    85,    72,    86,    31,    77,
      79,    22,   143,    80,    81,    82,    83,     3,    32,    88,
      89,    90,    91,    92,    93,    33,   136,   126,    25,    97,
      97,   104,   131,    61,    23,    24,    34,    35,    87,   142,
      42,   113,    55,    56,    57,    46,    47,    48,    43,    49,
      60,    50,   120,    51,    62,    52,     1,    63,    53,    54,
      55,    56,    57,    64,     2,    74,    75,    66,   155,     3,
      94,    95,    68,     4,    84,   111,   112,   137,   138,    46,
      47,    48,   102,    49,   105,    50,   107,    51,   109,    52,
     114,   116,    53,    54,    55,    56,    57,   151,     3,   108,
      29,   153,    46,    47,    48,   121,    49,   128,    50,   127,
      51,   130,    52,   132,   133,    53,    54,    55,    56,    57,
      53,    54,    55,    56,    57,   134,   165,   140,   147,   141,
     153,   144,   150,   162,   174,     1,   145,   146,   159,   157,
     165,   158,   160,     2,   164,    46,    47,    48,     3,    49,
     165,    50,     4,    51,   167,    52,   163,   168,    53,    54,
      55,    56,    57,    14,    15,    16,    17,    14,    15,    16,
      17,   172,   177,   183,   186,    18,    19,   184,    30,    18,
      19,   152,    20,    21,   101,   123,    20,   171,   178,    14,
      15,    16,    17,    22,    49,     0,    50,    22,    51,   173,
      52,    18,    19,    53,    54,    55,    56,    57,    20,    76,
      14,    15,    16,    17,   170,     0,    23,    24,    39,    22,
      23,    24,    18,    19,     0,    14,    15,    16,    17,    20,
      78,     0,     0,     0,     0,     0,     0,    18,    19,     0,
      22,     0,    23,    24,    20,     0,    14,    15,    16,    17,
       0,     0,     0,     0,     0,    22,     0,     0,    18,    19,
       0,     0,     0,    23,    24,    20,     0,    46,    47,    48,
       3,    49,     0,    50,     0,    51,    22,    52,    23,    24,
      53,    54,    55,    56,    57,     0,     0,     0,    46,    47,
      48,     0,    49,     0,    50,     0,    51,     0,    52,    23,
      24,    53,    54,    55,    56,    57,     0,     0,    46,    47,
      48,     0,    49,     0,    50,     0,    51,     0,    52,     0,
     115,    53,    54,    55,    56,    57,     0,     0,     0,    46,
      47,    48,     0,    49,     0,    50,     0,    51,     0,    52,
       0,   117,    53,    54,    55,    56,    57,    46,    47,    48,
       0,    49,     0,    50,    39,    51,     0,    52,     0,     0,
      53,    54,    55,    56,    57,    46,    47,    48,     0,    49,
       0,    50,   110,    51,     0,    52,     0,   139,    53,    54,
      55,    56,    57,    46,    47,    48,     0,    49,     0,    50,
       0,    51,     0,    52,     0,   156,    53,    54,    55,    56,
      57,     0,     0,    44,    45,     0,   180,     0,    46,    47,
      48,   181,    49,     0,    50,     0,    51,     0,    52,     0,
       0,    53,    54,    55,    56,    57,     0,    46,    47,    48,
      58,    49,     0,    50,     0,    51,     0,    52,     0,     0,
      53,    54,    55,    56,    57,    47,    48,     0,    49,     0,
      50,     0,    51,     0,    52,     0,     0,    53,    54,    55,
      56,    57,    48,     0,    49,     0,    50,     0,    51,     0,
      52,     0,     0,    53,    54,    55,    56,    57,    -1,     0,
      -1,     0,    51,     0,    52,     0,     0,    53,    54,    55,
      56,    57
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-164)))

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

static const yytype_int16 yycheck[] =
{
       3,    40,     3,     3,    97,    84,     3,     4,    87,    40,
     173,     3,     4,     5,     6,    18,    19,    20,    97,    22,
     183,    44,    18,    15,    16,    21,    22,    23,    24,    25,
      22,     3,    84,    30,   127,    12,    39,    14,    58,    42,
      43,    33,   121,    46,    47,    48,    49,    48,     3,    52,
      53,    54,    55,    56,    57,     3,   108,    98,    61,    60,
      60,    64,   103,    62,    56,    57,    59,    60,    60,   121,
      60,    74,    23,    24,    25,     8,     9,    10,    60,    12,
      40,    14,    85,    16,    49,    18,    35,    58,    21,    22,
      23,    24,    25,    55,    43,    37,    38,    60,   137,    48,
       3,     4,     3,    52,    60,    37,    38,   110,   111,     8,
       9,    10,     3,    12,     3,    14,    53,    16,    61,    18,
      61,    61,    21,    22,    23,    24,    25,   130,    48,    62,
       0,   134,     8,     9,    10,    60,    12,    30,    14,    62,
      16,    18,    18,    62,    61,    21,    22,    23,    24,    25,
      21,    22,    23,    24,    25,    60,   159,    61,    41,    61,
     163,    61,     3,    62,   167,    35,    61,    61,    32,    61,
     173,    61,    46,    43,    61,     8,     9,    10,    48,    12,
     183,    14,    52,    16,    32,    18,    62,    45,    21,    22,
      23,    24,    25,     3,     4,     5,     6,     3,     4,     5,
       6,    62,     5,    62,     5,    15,    16,    62,     5,    15,
      16,   132,    22,    23,    61,    96,    22,   163,   172,     3,
       4,     5,     6,    33,    12,    -1,    14,    33,    16,    62,
      18,    15,    16,    21,    22,    23,    24,    25,    22,    23,
       3,     4,     5,     6,   162,    -1,    56,    57,    54,    33,
      56,    57,    15,    16,    -1,     3,     4,     5,     6,    22,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    -1,
      33,    -1,    56,    57,    22,    -1,     3,     4,     5,     6,
      -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    15,    16,
      -1,    -1,    -1,    56,    57,    22,    -1,     8,     9,    10,
      48,    12,    -1,    14,    -1,    16,    33,    18,    56,    57,
      21,    22,    23,    24,    25,    -1,    -1,    -1,     8,     9,
      10,    -1,    12,    -1,    14,    -1,    16,    -1,    18,    56,
      57,    21,    22,    23,    24,    25,    -1,    -1,     8,     9,
      10,    -1,    12,    -1,    14,    -1,    16,    -1,    18,    -1,
      61,    21,    22,    23,    24,    25,    -1,    -1,    -1,     8,
       9,    10,    -1,    12,    -1,    14,    -1,    16,    -1,    18,
      -1,    61,    21,    22,    23,    24,    25,     8,     9,    10,
      -1,    12,    -1,    14,    54,    16,    -1,    18,    -1,    -1,
      21,    22,    23,    24,    25,     8,     9,    10,    -1,    12,
      -1,    14,    51,    16,    -1,    18,    -1,    38,    21,    22,
      23,    24,    25,     8,     9,    10,    -1,    12,    -1,    14,
      -1,    16,    -1,    18,    -1,    38,    21,    22,    23,    24,
      25,    -1,    -1,     3,     4,    -1,    31,    -1,     8,     9,
      10,    36,    12,    -1,    14,    -1,    16,    -1,    18,    -1,
      -1,    21,    22,    23,    24,    25,    -1,     8,     9,    10,
      30,    12,    -1,    14,    -1,    16,    -1,    18,    -1,    -1,
      21,    22,    23,    24,    25,     9,    10,    -1,    12,    -1,
      14,    -1,    16,    -1,    18,    -1,    -1,    21,    22,    23,
      24,    25,    10,    -1,    12,    -1,    14,    -1,    16,    -1,
      18,    -1,    -1,    21,    22,    23,    24,    25,    12,    -1,
      14,    -1,    16,    -1,    18,    -1,    -1,    21,    22,    23,
      24,    25
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    35,    43,    48,    52,    64,    69,    70,    87,    88,
      93,    40,    44,    89,     3,     4,     5,     6,    15,    16,
      22,    23,    33,    56,    57,    65,    80,    81,     3,     0,
      69,    58,     3,     3,    59,    60,    65,    65,    65,    54,
      65,    68,    60,    60,     3,     4,     8,     9,    10,    12,
      14,    16,    18,    21,    22,    23,    24,    25,    30,    82,
      40,    62,    49,    58,    55,    71,    60,    90,     3,    65,
      66,    67,    65,    68,    37,    38,    23,    65,    23,    65,
      65,    65,    65,    65,    60,    12,    14,    60,    65,    65,
      65,    65,    65,    65,     3,     4,     3,    60,    83,    85,
      86,    80,     3,    94,    65,     3,    79,    53,    62,    61,
      51,    37,    38,    65,    61,    61,    61,    61,    66,    70,
      65,    60,    70,    82,    70,    83,    71,    62,    30,    84,
      18,    71,    62,    61,    60,    91,    66,    65,    65,    38,
      61,    61,    66,    70,    61,    61,    61,    41,    72,    83,
       3,    65,    79,    65,    92,    68,    38,    61,    61,    32,
      46,    77,    62,    62,    61,    65,    73,    32,    45,    78,
      94,    92,    62,    62,    65,    74,    75,     5,    91,    73,
      31,    36,    76,    62,    62,    73,     5
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:
/* Line 1792 of yacc.c  */
#line 104 "parser.y"
    {
        (yyval.expr) = calloc(1, sizeof(ExprNode));//一般来说就是列名
        (yyval.expr)->type = EXPR_NAME;
        (yyval.expr)->strval = strdup((yyvsp[(1) - (1)].strval));
        free((yyvsp[(1) - (1)].strval));
    }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 110 "parser.y"
    {
        (yyval.expr) = calloc(1, sizeof(ExprNode));//一般来说是表.列
        (yyval.expr)->type = EXPR_TABLE_COLUMN;
        (yyval.expr)->strval = strdup((yyvsp[(3) - (3)].strval));
        (yyval.expr)->table = strdup((yyvsp[(1) - (3)].strval));
        free((yyvsp[(1) - (3)].strval)); free((yyvsp[(3) - (3)].strval));
    }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 117 "parser.y"
    {
        (yyval.expr) = calloc(1, sizeof(ExprNode));
        (yyval.expr)->type = EXPR_STRING;
        (yyval.expr)->strval = strdup((yyvsp[(1) - (1)].strval));
        free((yyvsp[(1) - (1)].strval));
    }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 123 "parser.y"
    {
        (yyval.expr) = calloc(1, sizeof(ExprNode));
        (yyval.expr)->type = EXPR_INTNUM;
        (yyval.expr)->intval = (yyvsp[(1) - (1)].intval);
    }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 128 "parser.y"
    {
        (yyval.expr) = calloc(1, sizeof(ExprNode));
        (yyval.expr)->type = EXPR_APPROXNUM;
        (yyval.expr)->floatval = (yyvsp[(1) - (1)].floatval);
    }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 135 "parser.y"
    { 
        (yyval.expr) = calloc(1, sizeof(ExprNode));
        (yyval.expr)->type = EXPR_ADD;
        (yyval.expr)->l = (yyvsp[(1) - (3)].expr), (yyval.expr)->r=(yyvsp[(3) - (3)].expr);
    }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 140 "parser.y"
    {         
        (yyval.expr) = calloc(1, sizeof(ExprNode));
        (yyval.expr)->type = EXPR_SUB;
        (yyval.expr)->l = (yyvsp[(1) - (3)].expr), (yyval.expr)->r=(yyvsp[(3) - (3)].expr); 
    }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 145 "parser.y"
    {         
        (yyval.expr) = calloc(1, sizeof(ExprNode));
        (yyval.expr)->type = EXPR_MUL;
        (yyval.expr)->l = (yyvsp[(1) - (3)].expr), (yyval.expr)->r=(yyvsp[(3) - (3)].expr); 
    }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 150 "parser.y"
    {         
        (yyval.expr) = calloc(1, sizeof(ExprNode));
        (yyval.expr)->type = EXPR_DIV;
        (yyval.expr)->l = (yyvsp[(1) - (3)].expr), (yyval.expr)->r=(yyvsp[(3) - (3)].expr); 
    }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 155 "parser.y"
    {         
        (yyval.expr) = calloc(1, sizeof(ExprNode));
        (yyval.expr)->type = EXPR_MOD;
        (yyval.expr)->l = (yyvsp[(1) - (3)].expr), (yyval.expr)->r=(yyvsp[(3) - (3)].expr);  
    }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 160 "parser.y"
    { 
        (yyval.expr) = calloc(1, sizeof(ExprNode));
        (yyval.expr)->type = EXPR_NEG;
        (yyval.expr)->r=(yyvsp[(2) - (2)].expr); 
    }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 165 "parser.y"
    {         
        (yyval.expr) = calloc(1, sizeof(ExprNode));
        (yyval.expr)->type = EXPR_AND;
        (yyval.expr)->l = (yyvsp[(1) - (3)].expr), (yyval.expr)->r=(yyvsp[(3) - (3)].expr);  
    }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 170 "parser.y"
    {        
        (yyval.expr) = calloc(1, sizeof(ExprNode));
        (yyval.expr)->type = EXPR_OR;
        (yyval.expr)->l = (yyvsp[(1) - (3)].expr), (yyval.expr)->r=(yyvsp[(3) - (3)].expr);   
    }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 175 "parser.y"
    {        
        (yyval.expr) = calloc(1, sizeof(ExprNode));
        (yyval.expr)->type = EXPR_XOR;
        (yyval.expr)->l = (yyvsp[(1) - (3)].expr), (yyval.expr)->r=(yyvsp[(3) - (3)].expr);  
    }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 180 "parser.y"
    {         
        (yyval.expr) = calloc(1, sizeof(ExprNode));
        (yyval.expr)->type = EXPR_NOT;
        (yyval.expr)->r=(yyvsp[(2) - (2)].expr);   
    }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 185 "parser.y"
    {         
        (yyval.expr) = calloc(1, sizeof(ExprNode));
        (yyval.expr)->type = EXPR_NOT;
        (yyval.expr)->r=(yyvsp[(2) - (2)].expr);   
    }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 190 "parser.y"
    { 
        (yyval.expr) = calloc(1, sizeof(ExprNode));
        (yyval.expr)->type = (yyvsp[(2) - (3)].subtok);
        (yyval.expr)->l = (yyvsp[(1) - (3)].expr), (yyval.expr)->r = (yyvsp[(3) - (3)].expr);
    }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 195 "parser.y"
    { 
        (yyval.expr) = calloc(1, sizeof(ExprNode));
        (yyval.expr)->type = EXPR_SELECT;
        (yyval.expr)->op = (yyvsp[(2) - (5)].subtok);
        (yyval.expr)->select = (yyvsp[(4) - (5)].select);
    }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 203 "parser.y"
    {
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
        (yyval.expr)->op = (yyval.expr)->type;
        (yyval.expr)->type = EXPR_VAL_LIST;
        (yyval.expr)->next = NULL;
    }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 209 "parser.y"
    { 
        (yyval.expr) = (yyvsp[(1) - (3)].expr);
        (yyval.expr)->op = (yyvsp[(1) - (3)].expr)->type;
        (yyval.expr)->type = EXPR_VAL_LIST;
        (yyval.expr)->next = (yyvsp[(3) - (3)].expr);
    }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 217 "parser.y"
    { (yyval.expr) = NULL; }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 218 "parser.y"
    {
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
    }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 223 "parser.y"
    { 
        (yyval.expr) = calloc(1, sizeof(ExprNode));
        (yyval.expr)->type = EXPR_IN_VAL_LIST;
        (yyval.expr)->l = (yyvsp[(1) - (5)].expr);
        (yyval.expr)->r = (yyvsp[(4) - (5)].expr);
    }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 229 "parser.y"
    { 
        (yyval.expr) = calloc(1, sizeof(ExprNode));
        (yyval.expr)->type = EXPR_NOT_IN_VAL_LIST;
        (yyval.expr)->l = (yyvsp[(1) - (6)].expr);
        (yyval.expr)->r = (yyvsp[(5) - (6)].expr);
    }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 235 "parser.y"
    { 
        (yyval.expr) = calloc(1, sizeof(ExprNode));
        (yyval.expr)->type = EXPR_IN_SELECT;
        (yyval.expr)->l = (yyvsp[(1) - (5)].expr);
        (yyval.expr)->select = (yyvsp[(4) - (5)].select);
    }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 241 "parser.y"
    { 
        (yyval.expr) = calloc(1, sizeof(ExprNode));
        (yyval.expr)->type = EXPR_NOT_IN_SELECT;
        (yyval.expr)->l = (yyvsp[(1) - (6)].expr);
        (yyval.expr)->select = (yyvsp[(5) - (6)].select);
    }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 250 "parser.y"
    {  
        (yyval.expr) = calloc(1, sizeof(ExprNode));
        (yyval.expr)->type = EXPR_FUNC;
        (yyval.expr)->strval = strdup((yyvsp[(1) - (4)].strval));
        (yyval.expr)->r = (yyvsp[(3) - (4)].expr);
        free((yyvsp[(1) - (4)].strval));
    }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 260 "parser.y"
    { 
        (yyval.expr) = calloc(1, sizeof(ExprNode));
        (yyval.expr)->type = EXPR_COUNT_ALL;
    }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 264 "parser.y"
    { 
        (yyval.expr) = calloc(1, sizeof(ExprNode));
        (yyval.expr)->type = EXPR_COUNT;
        (yyval.expr)->r = (yyvsp[(3) - (4)].expr);
    }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 269 "parser.y"
    { 
        (yyval.expr) = calloc(1, sizeof(ExprNode));
        (yyval.expr)->type = EXPR_SUM_ALL;
    }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 273 "parser.y"
    { 
        (yyval.expr) = calloc(1, sizeof(ExprNode));
        (yyval.expr)->type = EXPR_SUM;
        (yyval.expr)->r = (yyvsp[(3) - (4)].expr);
    }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 280 "parser.y"
    {
        (yyval.expr) = calloc(1, sizeof(ExprNode));
        (yyval.expr)->l = (yyvsp[(2) - (4)].expr);
        (yyval.expr)->type = EXPR_CASE_EXPR;
        (yyval.expr)->case_head = (yyvsp[(3) - (4)].cas);
    }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 286 "parser.y"
    { 
        (yyval.expr) = calloc(1, sizeof(ExprNode));
        (yyval.expr)->l = (yyvsp[(2) - (6)].expr), (yyval.expr)->r = (yyvsp[(5) - (6)].expr);
        (yyval.expr)->type = EXPR_CASE_EXPR_ELSE;
        (yyval.expr)->case_head = (yyvsp[(3) - (6)].cas);
    }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 292 "parser.y"
    {
        (yyval.expr) = calloc(1, sizeof(ExprNode));
        (yyval.expr)->type = EXPR_CASE;
        (yyval.expr)->case_head = (yyvsp[(2) - (3)].cas);
    }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 297 "parser.y"
    { 
        (yyval.expr) = calloc(1, sizeof(ExprNode));
        (yyval.expr)->type = EXPR_CASE_ELSE;
        (yyval.expr)->case_head = (yyvsp[(2) - (5)].cas);
        (yyval.expr)->r = (yyvsp[(4) - (5)].expr);
    }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 305 "parser.y"
    {
        (yyval.cas) = calloc(1, sizeof(CaseNode));
        (yyval.cas)->cond = (yyvsp[(2) - (4)].expr), (yyval.cas)->then = (yyvsp[(4) - (4)].expr);
    }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 309 "parser.y"
    {
        (yyval.cas) = calloc(1, sizeof(CaseNode));
        (yyval.cas)->cond = (yyvsp[(2) - (5)].expr), (yyval.cas)->then = (yyvsp[(4) - (5)].expr);
        (yyval.cas)->next = (yyvsp[(5) - (5)].cas);
    }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 316 "parser.y"
    { 
        (yyval.expr) = calloc(1, sizeof(ExprNode));
        (yyval.expr)->type = EXPR_LIKE;
        (yyval.expr)->l = (yyvsp[(1) - (3)].expr), (yyval.expr)->r = (yyvsp[(3) - (3)].expr);
    }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 321 "parser.y"
    { 
        (yyval.expr) = calloc(1, sizeof(ExprNode));
        (yyval.expr)->type = EXPR_NOT_LIKE;
        (yyval.expr)->l = (yyvsp[(1) - (4)].expr), (yyval.expr)->r = (yyvsp[(4) - (4)].expr);
    }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 329 "parser.y"
    { 
#ifdef DEBUG
        emit("SELECT STMT");
#endif
        ast_root = malloc(sizeof(SqlAst));
        ast_root->type = SELECT_STMT;
        ast_root->select = (yyvsp[(1) - (1)].select);
    }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 339 "parser.y"
    {
#ifdef DEBUG
        emit("SELECTNODATA!");
#endif
    }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 345 "parser.y"
    {
        (yyval.select) = calloc(1, sizeof(SelectNode));
        (yyval.select)->column_head = (yyvsp[(2) - (8)].expr);
        (yyval.select)->table_head = (yyvsp[(4) - (8)].table);
        (yyval.select)->where = (yyvsp[(5) - (8)].expr);
        (yyval.select)->group = (yyvsp[(6) - (8)].expr);
        (yyval.select)->order = (yyvsp[(7) - (8)].expr);
        (yyval.select)->limit = (yyvsp[(8) - (8)].limit);
     }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 356 "parser.y"
    {
        (yyval.expr) = NULL;
    }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 359 "parser.y"
    {
        (yyval.expr) = (yyvsp[(2) - (2)].expr);
    }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 364 "parser.y"
    {
        (yyval.expr) = NULL;
    }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 367 "parser.y"
    {
        (yyval.expr) = (yyvsp[(3) - (3)].expr);
    }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 372 "parser.y"
    {
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
    }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 375 "parser.y"
    {
        (yyval.expr) = (yyvsp[(1) - (3)].expr);
        (yyval.expr)->type = GROUPBY;
        (yyval.expr)->next = (yyvsp[(3) - (3)].expr);
    }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 382 "parser.y"
    {
        (yyval.expr) = (yyvsp[(1) - (2)].expr);
        (yyval.expr)->op = (yyval.expr)->type;
        (yyval.expr)->type = ORDERBY;
        (yyval.expr)->sc = (yyvsp[(2) - (2)].intval);
    }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 390 "parser.y"
    {
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
        (yyval.expr)->next = NULL;
    }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 394 "parser.y"
    {
        (yyval.expr) = (yyvsp[(1) - (3)].expr);
        (yyval.expr)->next = (yyvsp[(3) - (3)].expr);
    }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 400 "parser.y"
    { 
        (yyval.intval) = 0; 
    }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 403 "parser.y"
    { 
        (yyval.intval) = 0; 
    }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 406 "parser.y"
    { 
        (yyval.intval) = 1; 
    }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 411 "parser.y"
    {
        (yyval.expr) = NULL;
    }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 414 "parser.y"
    {
        (yyval.expr) = (yyvsp[(3) - (3)].expr);
    }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 419 "parser.y"
    {
        (yyval.limit) = NULL;
    }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 422 "parser.y"
    {
        (yyval.limit) = calloc(1, sizeof(LimitNode));
        (yyval.limit)->start = 0, (yyval.limit)->count = (yyvsp[(2) - (2)].intval);
    }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 426 "parser.y"
    {
        (yyval.limit) = calloc(1, sizeof(LimitNode));
        (yyval.limit)->start = (yyvsp[(2) - (4)].intval), (yyval.limit)->count = (yyvsp[(4) - (4)].intval);
    }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 432 "parser.y"
    { 
        (yyval.column) = calloc(1, sizeof(ColumnNode));//update时候用
        (yyval.column)->column = strdup((yyvsp[(1) - (1)].strval));
        (yyval.column)->next = NULL;
        free((yyvsp[(1) - (1)].strval));
    }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 438 "parser.y"
    { 
        (yyval.column) = calloc(1, sizeof(ColumnNode));
        (yyval.column)->column = strdup((yyvsp[(1) - (3)].strval));
        (yyval.column)->next = (yyvsp[(3) - (3)].column);
        free((yyvsp[(1) - (3)].strval));
    }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 446 "parser.y"
    {
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
        (yyval.expr)->next = NULL;
    }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 450 "parser.y"
    {
        (yyval.expr) = (yyvsp[(1) - (3)].expr);
        (yyval.expr)->next = (yyvsp[(3) - (3)].expr);
    }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 454 "parser.y"
    {
        (yyval.expr) = calloc(1, sizeof(ExprNode));
        (yyval.expr)->type = SELECT_ALL;
    }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 460 "parser.y"
    {
        (yyval.expr) = (yyvsp[(1) - (2)].expr);
        (yyval.expr)->alias = (yyvsp[(2) - (2)].strval);
    }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 466 "parser.y"
    { 
        (yyval.strval) = strdup((yyvsp[(2) - (2)].strval));
        free((yyvsp[(2) - (2)].strval));
    }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 470 "parser.y"
    { 
        (yyval.strval) = strdup((yyvsp[(1) - (1)].strval));
        free((yyvsp[(1) - (1)].strval));
    }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 474 "parser.y"
    {
        (yyval.strval) = strdup((yyvsp[(2) - (2)].strval));
        free((yyvsp[(2) - (2)].strval));
    }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 478 "parser.y"
    {
        (yyval.strval) = strdup((yyvsp[(1) - (1)].strval));
        free((yyvsp[(1) - (1)].strval));
     }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 482 "parser.y"
    {
        (yyval.strval) = NULL;
    }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 487 "parser.y"
    { 
        (yyval.table) = (yyvsp[(1) - (1)].table);
        (yyval.table)->next = NULL;
    }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 491 "parser.y"
    {
        (yyval.table) = (yyvsp[(1) - (3)].table);
        (yyval.table)->next = (yyvsp[(3) - (3)].table);
    }
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 501 "parser.y"
    {
        (yyval.table) = calloc(1, sizeof(TableNode));
        (yyval.table)->type = TABLE_DEFAULT;
        (yyval.table)->alias = (yyvsp[(2) - (2)].strval);
        (yyval.table)->table = strdup((yyvsp[(1) - (2)].strval));
        free((yyvsp[(1) - (2)].strval));
    }
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 508 "parser.y"
    { 
        (yyval.table) = calloc(1, sizeof(TableNode));
        (yyval.table)->type = TABLE_SUBQUERY;
        (yyval.table)->select = (yyvsp[(1) - (3)].select);
        (yyval.table)->alias = strdup((yyvsp[(3) - (3)].strval));
        free((yyvsp[(3) - (3)].strval)); 
    }
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 515 "parser.y"
    { 
        (yyval.table) = (yyvsp[(2) - (3)].table);
    }
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 520 "parser.y"
    { 
        (yyval.select) = (yyvsp[(2) - (3)].select);
    }
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 526 "parser.y"
    { 
#ifdef DEBUG
        emit("DELETE STMT");
#endif
        ast_root = malloc(sizeof(SqlAst));
        ast_root->type = DELETE_STMT;
        ast_root->delete = (yyvsp[(1) - (1)].delete);
    }
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 537 "parser.y"
    { 
        (yyval.delete) = calloc(1, sizeof(DeleteNode));
        (yyval.delete)->table = strdup((yyvsp[(3) - (4)].strval));
        (yyval.delete)->where = (yyvsp[(4) - (4)].expr);
        free((yyvsp[(3) - (4)].strval)); 
    }
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 546 "parser.y"
    { 
#ifdef DEBUG
        emit("INSERT STMT");
#endif
        ast_root = malloc(sizeof(SqlAst));
        ast_root->type = INSERT_STMT;
        ast_root->insert = (yyvsp[(1) - (1)].insert);
    }
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 556 "parser.y"
    {
        (yyval.insert) = calloc(1, sizeof(InsertNode));
        (yyval.insert)->table = strdup((yyvsp[(3) - (6)].strval));
        (yyval.insert)->column_head = (yyvsp[(4) - (6)].column);
        (yyval.insert)->value_list_head = (yyvsp[(6) - (6)].value_list);
        free((yyvsp[(3) - (6)].strval));
    }
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 568 "parser.y"
    {
        (yyval.column) = NULL;
    }
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 571 "parser.y"
    { 
        (yyval.column) = (yyvsp[(2) - (3)].column);
    }
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 576 "parser.y"
    { 
        (yyval.value_list) = calloc(1, sizeof(ValueListNode));
        (yyval.value_list)->head = (yyvsp[(2) - (3)].expr);
        (yyval.value_list)->next = NULL;
    }
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 581 "parser.y"
    { 
        (yyval.value_list) = calloc(1, sizeof(ValueListNode));
        (yyval.value_list)->head = (yyvsp[(2) - (5)].expr);
        (yyval.value_list)->next = (yyvsp[(5) - (5)].value_list);
    }
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 588 "parser.y"
    { 
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
        (yyval.expr)->r = NULL;
    }
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 592 "parser.y"
    { 
        (yyval.expr) = (yyvsp[(1) - (3)].expr);
        (yyval.expr)->r = (yyvsp[(3) - (3)].expr);
    }
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 599 "parser.y"
    { 
#ifdef DEBUG
        emit("UPDATE STMT");
#endif
        ast_root = malloc(sizeof(SqlAst));
        ast_root->type = UPDATE_STMT;
        ast_root->update = (yyvsp[(1) - (1)].update);
    }
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 611 "parser.y"
    { 
        (yyval.update) = calloc(1, sizeof(UpdateNode));
        (yyval.update)->table = strdup((yyvsp[(2) - (5)].strval));
        (yyval.update)->set_head = (yyvsp[(4) - (5)].assign);
        (yyval.update)->where = (yyvsp[(5) - (5)].expr);
        free((yyvsp[(2) - (5)].strval));
    }
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 620 "parser.y"
    { 
        (yyval.assign) = calloc(1, sizeof(SetNode));
        (yyval.assign)->column = strdup((yyvsp[(1) - (3)].strval));
        free((yyvsp[(1) - (3)].strval));
        (yyval.assign)->expr = (yyvsp[(3) - (3)].expr);
        (yyval.assign)->op = (yyvsp[(2) - (3)].subtok);
        (yyval.assign)->next = NULL;
    }
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 628 "parser.y"
    { 
        (yyval.assign) = calloc(1, sizeof(SetNode));
        (yyval.assign)->column = strdup((yyvsp[(1) - (5)].strval));
        free((yyvsp[(1) - (5)].strval));
        (yyval.assign)->op = (yyvsp[(2) - (5)].subtok);
        (yyval.assign)->expr = (yyvsp[(3) - (5)].expr);
        (yyval.assign)->next = (yyvsp[(5) - (5)].assign);
    }
    break;


/* Line 1792 of yacc.c  */
#line 2541 "parser.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 638 "parser.y"

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