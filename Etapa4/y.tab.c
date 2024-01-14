/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     KW_INT = 258,
     KW_FLOAT = 259,
     KW_CHAR = 260,
     KW_CODE = 261,
     KW_IF = 262,
     KW_ELSE = 263,
     KW_WHILE = 264,
     KW_PRINT = 265,
     KW_RETURN = 266,
     KW_INPUT = 267,
     OPERATOR_LE = 268,
     OPERATOR_GE = 269,
     OPERATOR_EQ = 270,
     OPERATOR_NOT = 271,
     OPERATOR_OR = 272,
     OPERATOR_AND = 273,
     OPERATOR_DIF = 274,
     TK_IDENTIFIER = 275,
     LIT_INT = 276,
     LIT_REAL = 277,
     LIT_CHAR = 278,
     LIT_STRING = 279,
     TOKEN_ERROR = 280
   };
#endif
/* Tokens.  */
#define KW_INT 258
#define KW_FLOAT 259
#define KW_CHAR 260
#define KW_CODE 261
#define KW_IF 262
#define KW_ELSE 263
#define KW_WHILE 264
#define KW_PRINT 265
#define KW_RETURN 266
#define KW_INPUT 267
#define OPERATOR_LE 268
#define OPERATOR_GE 269
#define OPERATOR_EQ 270
#define OPERATOR_NOT 271
#define OPERATOR_OR 272
#define OPERATOR_AND 273
#define OPERATOR_DIF 274
#define TK_IDENTIFIER 275
#define LIT_INT 276
#define LIT_REAL 277
#define LIT_CHAR 278
#define LIT_STRING 279
#define TOKEN_ERROR 280




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

/* ETAPA 3 - Compiladores - 2023/2
   Aluno: Filipe Ilunga Xindanhi
*/

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "ast.h"
#include "semantic.h"


int yylex();
int yyerror();
AST* getRoot();
extern int getLineNumber();
void checkSemantic(void);

AST* root; 



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 24 "parser.y"
{
struct hash_node* symbol;
struct ast_node* ast;
}
/* Line 193 of yacc.c.  */
#line 173 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 186 "y.tab.c"

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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   316

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNRULES -- Number of states.  */
#define YYNSTATES  139

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   280

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      36,    37,    30,    28,    38,    29,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    33,
      26,    32,    27,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    34,     2,    35,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    11,    14,    17,    18,    24,
      32,    39,    42,    43,    46,    47,    51,    52,    55,    58,
      59,    63,    67,    70,    71,    73,    75,    77,    79,    81,
      83,    85,    91,    98,   101,   102,   106,   111,   119,   123,
     125,   127,   129,   134,   139,   141,   143,   145,   147,   152,
     156,   160,   164,   168,   172,   176,   180,   184,   187,   191,
     195,   199,   203,   207,   208,   211,   212,   216,   218,   220,
     222,   224,   226,   228
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,    43,    -1,    44,    52,    -1,    45,    44,
      -1,    46,    44,    -1,    47,    44,    -1,    -1,    68,    20,
      32,    67,    33,    -1,    68,    20,    34,    21,    35,    48,
      33,    -1,    68,    20,    36,    49,    37,    33,    -1,    67,
      48,    -1,    -1,    51,    50,    -1,    -1,    38,    51,    50,
      -1,    -1,    68,    20,    -1,    53,    52,    -1,    -1,     6,
      20,    56,    -1,    39,    55,    40,    -1,    56,    55,    -1,
      -1,    54,    -1,    61,    -1,    62,    -1,    57,    -1,    60,
      -1,    33,    -1,    58,    -1,     9,    36,    64,    37,    56,
      -1,     7,    36,    64,    37,    56,    59,    -1,     8,    56,
      -1,    -1,    11,    64,    33,    -1,    20,    32,    64,    33,
      -1,    20,    34,    64,    35,    32,    64,    33,    -1,    10,
      63,    33,    -1,    24,    -1,    64,    -1,    20,    -1,    20,
      34,    64,    35,    -1,    20,    36,    65,    37,    -1,    21,
      -1,    22,    -1,    23,    -1,    24,    -1,    12,    36,    68,
      37,    -1,    64,    28,    64,    -1,    64,    29,    64,    -1,
      64,    30,    64,    -1,    64,    31,    64,    -1,    64,    26,
      64,    -1,    64,    27,    64,    -1,    64,    18,    64,    -1,
      64,    17,    64,    -1,    16,    64,    -1,    64,    13,    64,
      -1,    64,    14,    64,    -1,    64,    15,    64,    -1,    64,
      19,    64,    -1,    36,    64,    37,    -1,    -1,    64,    66,
      -1,    -1,    38,    64,    66,    -1,    21,    -1,    22,    -1,
      23,    -1,    24,    -1,     3,    -1,     4,    -1,     5,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    92,    92,   105,   108,   109,   110,   111,   114,   117,
     120,   123,   124,   127,   128,   131,   132,   135,   138,   139,
     142,   145,   148,   149,   152,   153,   154,   155,   156,   157,
     160,   161,   164,   167,   168,   171,   174,   175,   178,   181,
     182,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   209,   210,   213,   214,   217,   218,   219,
     220,   223,   224,   225
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "KW_INT", "KW_FLOAT", "KW_CHAR",
  "KW_CODE", "KW_IF", "KW_ELSE", "KW_WHILE", "KW_PRINT", "KW_RETURN",
  "KW_INPUT", "OPERATOR_LE", "OPERATOR_GE", "OPERATOR_EQ", "OPERATOR_NOT",
  "OPERATOR_OR", "OPERATOR_AND", "OPERATOR_DIF", "TK_IDENTIFIER",
  "LIT_INT", "LIT_REAL", "LIT_CHAR", "LIT_STRING", "TOKEN_ERROR", "'<'",
  "'>'", "'+'", "'-'", "'*'", "'/'", "'='", "';'", "'['", "']'", "'('",
  "')'", "','", "'{'", "'}'", "$accept", "programa", "declaracoes_globais",
  "lista_decl", "decl_var", "decl_vetor", "decl_proto", "opcional",
  "parametros_formais", "parametros_formais_fim", "parametro_formal",
  "lista_codigo", "decl_func", "bloco", "lista_comandos", "comando",
  "comando_fluxo", "comando_if", "comando_else", "comando_return",
  "comando_atribuicao", "comando_print", "comando_printResto", "expressao",
  "lista_argumentos", "lista_argumentos_fim", "literal", "tipo", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,    60,    62,    43,    45,
      42,    47,    61,    59,    91,    93,    40,    41,    44,   123,
     125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    44,    44,    44,    44,    45,    46,
      47,    48,    48,    49,    49,    50,    50,    51,    52,    52,
      53,    54,    55,    55,    56,    56,    56,    56,    56,    56,
      57,    57,    58,    59,    59,    60,    61,    61,    62,    63,
      63,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    65,    65,    66,    66,    67,    67,    67,
      67,    68,    68,    68
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     2,     0,     5,     7,
       6,     2,     0,     2,     0,     3,     0,     2,     2,     0,
       3,     3,     2,     0,     1,     1,     1,     1,     1,     1,
       1,     5,     6,     2,     0,     3,     4,     7,     3,     1,
       1,     1,     4,     4,     1,     1,     1,     1,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     3,     0,     2,     0,     3,     1,     1,     1,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,    71,    72,    73,     0,     2,    19,     7,     7,     7,
       0,     1,     0,     3,    19,     4,     5,     6,     0,     0,
      18,     0,     0,    14,     0,     0,     0,     0,     0,    29,
      23,    24,    20,    27,    30,    28,    25,    26,    67,    68,
      69,    70,     0,     0,     0,    16,     0,     0,     0,     0,
       0,    41,    44,    45,    46,    47,     0,     0,    40,    47,
       0,     0,     0,     0,    23,     8,    12,     0,     0,    13,
      17,     0,     0,     0,    57,     0,    63,     0,    38,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    35,     0,     0,    21,    22,     0,    12,    10,    16,
       0,     0,     0,     0,    65,     0,    62,    58,    59,    60,
      56,    55,    61,    53,    54,    49,    50,    51,    52,    36,
       0,     9,    11,    15,    34,    31,    48,    42,     0,    64,
      43,     0,     0,    32,    65,     0,    33,    66,    37
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,     9,    96,    44,    69,
      45,    13,    14,    31,    63,    64,    33,    34,   133,    35,
      36,    37,    57,    58,   105,   129,    97,    10
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -29
static const yytype_int16 yypact[] =
{
      12,   -29,   -29,   -29,     3,   -29,    17,    12,    12,    12,
       5,   -29,     9,   -29,    17,   -29,   -29,   -29,   -22,    -2,
     -29,    44,    24,    12,    -3,     2,   155,   172,   -28,   -29,
      -2,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
     -29,   -29,     1,    11,    14,    10,    53,   172,   172,    33,
     172,   -23,   -29,   -29,   -29,    59,   172,    60,   285,   -29,
     222,   172,   172,    54,    -2,   -29,    44,    63,    12,   -29,
     -29,    93,   114,    12,    13,   172,   172,   135,   -29,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   -29,   243,   184,   -29,   -29,    64,    44,   -29,    10,
      -2,    -2,    61,   203,    57,    62,   -29,    49,    49,    49,
      13,    13,    49,    49,    49,   -11,   -11,   -29,   -29,   -29,
      68,   -29,   -29,   -29,    95,   -29,   -29,   -29,   172,   -29,
     -29,   172,    -2,   -29,    57,   264,   -29,   -29,   -29
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -29,   -29,   -29,    82,   -29,   -29,   -29,     4,   -29,    15,
      36,   101,   -29,   -29,    45,   -19,   -29,   -29,   -29,   -29,
     -29,   -29,   -29,   -26,   -29,   -18,    96,   -21
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -40
static const yytype_int16 yytable[] =
{
      32,    60,    46,    11,    61,    24,    62,    25,    26,    27,
      21,    75,    22,    76,    23,     1,     2,     3,    28,    89,
      90,    71,    72,    12,    74,    18,    79,    80,    81,    19,
      77,    29,    84,    47,    65,    92,    93,    30,    48,    85,
      86,    87,    88,    89,    90,    43,    66,    46,    68,   103,
     104,    67,   102,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,    38,    39,    40,    41,    73,
      79,    80,    81,    70,    82,    83,    84,    87,    88,    89,
      90,   124,   125,    85,    86,    87,    88,    89,    90,    15,
      16,    17,   -39,    78,    94,   128,    98,   121,   126,   130,
     131,   122,   134,   132,    99,   135,    79,    80,    81,    95,
      82,    83,    84,   136,   123,    20,   137,    42,     0,    85,
      86,    87,    88,    89,    90,     0,     0,    79,    80,    81,
     100,    82,    83,    84,     0,     0,     0,     0,     0,     0,
      85,    86,    87,    88,    89,    90,     0,     0,    79,    80,
      81,   101,    82,    83,    84,     0,     0,     0,     0,     0,
       0,    85,    86,    87,    88,    89,    90,    49,     0,     0,
       0,    50,   106,     0,     0,    51,    52,    53,    54,    55,
       0,     0,     0,     0,    49,     0,     0,     0,    50,     0,
       0,    56,    51,    52,    53,    54,    59,    79,    80,    81,
       0,    82,    83,    84,     0,     0,     0,     0,    56,     0,
      85,    86,    87,    88,    89,    90,    79,    80,    81,   120,
      82,    83,    84,     0,     0,     0,     0,     0,     0,    85,
      86,    87,    88,    89,    90,    79,    80,    81,   127,    82,
      83,    84,     0,     0,     0,     0,     0,     0,    85,    86,
      87,    88,    89,    90,     0,    91,    79,    80,    81,     0,
      82,    83,    84,     0,     0,     0,     0,     0,     0,    85,
      86,    87,    88,    89,    90,     0,   119,    79,    80,    81,
       0,    82,    83,    84,     0,     0,     0,     0,     0,     0,
      85,    86,    87,    88,    89,    90,     0,   138,    79,    80,
      81,     0,    82,    83,    84,     0,     0,     0,     0,     0,
       0,    85,    86,    87,    88,    89,    90
};

static const yytype_int16 yycheck[] =
{
      19,    27,    23,     0,    32,     7,    34,     9,    10,    11,
      32,    34,    34,    36,    36,     3,     4,     5,    20,    30,
      31,    47,    48,     6,    50,    20,    13,    14,    15,    20,
      56,    33,    19,    36,    33,    61,    62,    39,    36,    26,
      27,    28,    29,    30,    31,    21,    35,    68,    38,    75,
      76,    37,    73,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    21,    22,    23,    24,    36,
      13,    14,    15,    20,    17,    18,    19,    28,    29,    30,
      31,   100,   101,    26,    27,    28,    29,    30,    31,     7,
       8,     9,    33,    33,    40,    38,    33,    33,    37,    37,
      32,    97,   128,     8,    68,   131,    13,    14,    15,    64,
      17,    18,    19,   132,    99,    14,   134,    21,    -1,    26,
      27,    28,    29,    30,    31,    -1,    -1,    13,    14,    15,
      37,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    27,    28,    29,    30,    31,    -1,    -1,    13,    14,
      15,    37,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    31,    12,    -1,    -1,
      -1,    16,    37,    -1,    -1,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    16,    -1,
      -1,    36,    20,    21,    22,    23,    24,    13,    14,    15,
      -1,    17,    18,    19,    -1,    -1,    -1,    -1,    36,    -1,
      26,    27,    28,    29,    30,    31,    13,    14,    15,    35,
      17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    29,    30,    31,    13,    14,    15,    35,    17,
      18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,
      28,    29,    30,    31,    -1,    33,    13,    14,    15,    -1,
      17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    29,    30,    31,    -1,    33,    13,    14,    15,
      -1,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    27,    28,    29,    30,    31,    -1,    33,    13,    14,
      15,    -1,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    31
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    42,    43,    44,    45,    46,    47,
      68,     0,     6,    52,    53,    44,    44,    44,    20,    20,
      52,    32,    34,    36,     7,     9,    10,    11,    20,    33,
      39,    54,    56,    57,    58,    60,    61,    62,    21,    22,
      23,    24,    67,    21,    49,    51,    68,    36,    36,    12,
      16,    20,    21,    22,    23,    24,    36,    63,    64,    24,
      64,    32,    34,    55,    56,    33,    35,    37,    38,    50,
      20,    64,    64,    36,    64,    34,    36,    64,    33,    13,
      14,    15,    17,    18,    19,    26,    27,    28,    29,    30,
      31,    33,    64,    64,    40,    55,    48,    67,    33,    51,
      37,    37,    68,    64,    64,    65,    37,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    33,
      35,    33,    48,    50,    56,    56,    37,    35,    38,    66,
      37,    32,     8,    59,    64,    64,    56,    66,    33
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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


/* Prevent warnings from -Wmissing-prototypes.  */

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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
        case 2:
#line 92 "parser.y"
    {
                                                                                        astPrint(root,0);
                                                                                        root=(yyval.ast); 
                                                                                        setDeclaration(root);
                                                                                        setNodeType(root);
                                                                                        checkUndeclared();
                                                                                        checkUsage(root);
                                                                                        checkReturns(root);
                                                                                        checkSemantic();
                                                                                     }
    break;

  case 3:
#line 105 "parser.y"
    {(yyval.ast)=astCreate(AST_LDECGLOBAL, 0, (yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast), 0, 0);}
    break;

  case 4:
#line 108 "parser.y"
    {(yyval.ast)=astCreate(AST_LSTDEC, 0, (yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast), 0, 0);}
    break;

  case 5:
#line 109 "parser.y"
    {(yyval.ast)=astCreate(AST_LSTDEC, 0, (yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast), 0, 0);}
    break;

  case 6:
#line 110 "parser.y"
    {(yyval.ast)=astCreate(AST_LSTDEC, 0, (yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast), 0, 0);}
    break;

  case 7:
#line 111 "parser.y"
    {(yyval.ast)=0;}
    break;

  case 8:
#line 114 "parser.y"
    {(yyval.ast)=astCreate(AST_DECVAR, (yyvsp[(2) - (5)].symbol), (yyvsp[(1) - (5)].ast), (yyvsp[(4) - (5)].ast), 0, 0);}
    break;

  case 9:
#line 117 "parser.y"
    {(yyval.ast)=astCreate(AST_DECVEC, (yyvsp[(2) - (7)].symbol), (yyvsp[(1) - (7)].ast), astCreate(AST_SYMBOL, (yyvsp[(4) - (7)].symbol), 0, 0, 0, 0), (yyvsp[(6) - (7)].ast), 0);}
    break;

  case 10:
#line 120 "parser.y"
    {(yyval.ast)=astCreate(AST_DECPROTO, (yyvsp[(2) - (6)].symbol), (yyvsp[(1) - (6)].ast), (yyvsp[(4) - (6)].ast), 0, 0);}
    break;

  case 11:
#line 123 "parser.y"
    {(yyval.ast)=astCreate(AST_OPT, 0, (yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast), 0, 0);}
    break;

  case 12:
#line 124 "parser.y"
    {(yyval.ast)=0;}
    break;

  case 13:
#line 127 "parser.y"
    {(yyval.ast)=astCreate(AST_PARAMINIT, 0, (yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast), 0, 0);}
    break;

  case 14:
#line 128 "parser.y"
    {(yyval.ast)=0;}
    break;

  case 15:
#line 131 "parser.y"
    {(yyval.ast)=astCreate(AST_LSTPARAM, 0, (yyvsp[(2) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0);}
    break;

  case 16:
#line 132 "parser.y"
    {(yyval.ast)=0;}
    break;

  case 17:
#line 135 "parser.y"
    {(yyval.ast)=astCreate(AST_PARAM, (yyvsp[(2) - (2)].symbol), (yyvsp[(1) - (2)].ast), 0, 0, 0);}
    break;

  case 18:
#line 138 "parser.y"
    {(yyval.ast)=astCreate(AST_LSTCODIGO, 0, (yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast), 0, 0);}
    break;

  case 19:
#line 139 "parser.y"
    {(yyval.ast)=0;}
    break;

  case 20:
#line 142 "parser.y"
    {(yyval.ast)=astCreate(AST_CODE, (yyvsp[(2) - (3)].symbol), (yyvsp[(3) - (3)].ast), 0, 0, 0);}
    break;

  case 21:
#line 145 "parser.y"
    {(yyval.ast)=astCreate(AST_BLOCO, 0, (yyvsp[(2) - (3)].ast), 0, 0, 0);}
    break;

  case 22:
#line 148 "parser.y"
    {(yyval.ast)=astCreate(AST_LSTCOMANDO, 0, (yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast), 0, 0);}
    break;

  case 23:
#line 149 "parser.y"
    {(yyval.ast)=0;}
    break;

  case 24:
#line 152 "parser.y"
    {(yyval.ast)=(yyvsp[(1) - (1)].ast);}
    break;

  case 25:
#line 153 "parser.y"
    {(yyval.ast)=(yyvsp[(1) - (1)].ast);}
    break;

  case 26:
#line 154 "parser.y"
    {(yyval.ast)=(yyvsp[(1) - (1)].ast);}
    break;

  case 27:
#line 155 "parser.y"
    {(yyval.ast)=(yyvsp[(1) - (1)].ast);}
    break;

  case 28:
#line 156 "parser.y"
    {(yyval.ast)=(yyvsp[(1) - (1)].ast);}
    break;

  case 29:
#line 157 "parser.y"
    {(yyval.ast)=0;}
    break;

  case 30:
#line 160 "parser.y"
    {(yyval.ast)=(yyvsp[(1) - (1)].ast);}
    break;

  case 31:
#line 161 "parser.y"
    {(yyval.ast)=astCreate(AST_WHILE, 0, (yyvsp[(3) - (5)].ast), (yyvsp[(5) - (5)].ast), 0, 0);}
    break;

  case 32:
#line 164 "parser.y"
    {(yyval.ast)=astCreate(AST_IF, 0, (yyvsp[(3) - (6)].ast), (yyvsp[(5) - (6)].ast), (yyvsp[(6) - (6)].ast), 0);}
    break;

  case 33:
#line 167 "parser.y"
    {(yyval.ast)=astCreate(AST_ELSE, 0, (yyvsp[(2) - (2)].ast), 0, 0, 0);}
    break;

  case 34:
#line 168 "parser.y"
    {(yyval.ast)=0;}
    break;

  case 35:
#line 171 "parser.y"
    {(yyval.ast)=astCreate(AST_RETURN, 0, (yyvsp[(2) - (3)].ast), 0, 0, 0);}
    break;

  case 36:
#line 174 "parser.y"
    {(yyval.ast)=astCreate(AST_ATTREXPR, (yyvsp[(1) - (4)].symbol), (yyvsp[(3) - (4)].ast), 0, 0, 0);}
    break;

  case 37:
#line 175 "parser.y"
    {(yyval.ast)=astCreate(AST_ATTRVEC, (yyvsp[(1) - (7)].symbol), (yyvsp[(3) - (7)].ast), (yyvsp[(6) - (7)].ast), 0, 0);}
    break;

  case 38:
#line 178 "parser.y"
    {(yyval.ast)=astCreate(AST_PRINT, 0, (yyvsp[(2) - (3)].ast), 0, 0, 0);}
    break;

  case 39:
#line 181 "parser.y"
    {(yyval.ast)=astCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0);}
    break;

  case 40:
#line 182 "parser.y"
    {(yyval.ast)=(yyvsp[(1) - (1)].ast);}
    break;

  case 41:
#line 185 "parser.y"
    {(yyval.ast)=astCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0);}
    break;

  case 42:
#line 186 "parser.y"
    {(yyval.ast)=astCreate(AST_VEC, (yyvsp[(1) - (4)].symbol), (yyvsp[(3) - (4)].ast), 0, 0, 0);}
    break;

  case 43:
#line 187 "parser.y"
    {(yyval.ast)=astCreate(AST_FUNC, (yyvsp[(1) - (4)].symbol), (yyvsp[(3) - (4)].ast), 0, 0, 0);}
    break;

  case 44:
#line 188 "parser.y"
    {(yyval.ast)=astCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0);}
    break;

  case 45:
#line 189 "parser.y"
    {(yyval.ast)=astCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0);}
    break;

  case 46:
#line 190 "parser.y"
    {(yyval.ast)=astCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0);}
    break;

  case 47:
#line 191 "parser.y"
    {(yyval.ast)=astCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0);}
    break;

  case 48:
#line 192 "parser.y"
    {(yyval.ast)=astCreate(AST_INPUT, 0, (yyvsp[(3) - (4)].ast), 0, 0, 0);}
    break;

  case 49:
#line 193 "parser.y"
    {(yyval.ast)=astCreate(AST_ADD, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0);}
    break;

  case 50:
#line 194 "parser.y"
    {(yyval.ast)=astCreate(AST_SUB, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0);}
    break;

  case 51:
#line 195 "parser.y"
    {(yyval.ast)=astCreate(AST_MUL, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0);}
    break;

  case 52:
#line 196 "parser.y"
    {(yyval.ast)=astCreate(AST_DIV, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0);}
    break;

  case 53:
#line 197 "parser.y"
    {(yyval.ast)=astCreate(AST_LESS, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0);}
    break;

  case 54:
#line 198 "parser.y"
    {(yyval.ast)=astCreate(AST_GREATER, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0);}
    break;

  case 55:
#line 199 "parser.y"
    {(yyval.ast)=astCreate(AST_AND, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0);}
    break;

  case 56:
#line 200 "parser.y"
    {(yyval.ast)=astCreate(AST_OR, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0);}
    break;

  case 57:
#line 201 "parser.y"
    {(yyval.ast)=astCreate(AST_NOT, 0, (yyvsp[(2) - (2)].ast), 0, 0, 0);}
    break;

  case 58:
#line 202 "parser.y"
    {(yyval.ast)=astCreate(AST_LE, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0);}
    break;

  case 59:
#line 203 "parser.y"
    {(yyval.ast)=astCreate(AST_GE, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0);}
    break;

  case 60:
#line 204 "parser.y"
    {(yyval.ast)=astCreate(AST_EQ, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0);}
    break;

  case 61:
#line 205 "parser.y"
    {(yyval.ast)=astCreate(AST_DIF, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0);}
    break;

  case 62:
#line 206 "parser.y"
    {(yyval.ast)=astCreate(AST_PAREN, 0, (yyvsp[(2) - (3)].ast), 0, 0, 0);}
    break;

  case 63:
#line 209 "parser.y"
    {(yyval.ast)=0;}
    break;

  case 64:
#line 210 "parser.y"
    {(yyval.ast)=astCreate(AST_LSTARG, 0, (yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast), 0, 0);}
    break;

  case 65:
#line 213 "parser.y"
    {(yyval.ast)=0;}
    break;

  case 66:
#line 214 "parser.y"
    {(yyval.ast)=astCreate(AST_LSTARGFIM, 0, (yyvsp[(2) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0);}
    break;

  case 67:
#line 217 "parser.y"
    {(yyval.ast)=astCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0);}
    break;

  case 68:
#line 218 "parser.y"
    {(yyval.ast)=astCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0);}
    break;

  case 69:
#line 219 "parser.y"
    {(yyval.ast)=astCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0);}
    break;

  case 70:
#line 220 "parser.y"
    {(yyval.ast)=astCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0);}
    break;

  case 71:
#line 223 "parser.y"
    {(yyval.ast)=astCreate(AST_INT, 0, 0, 0, 0, 0);}
    break;

  case 72:
#line 224 "parser.y"
    {(yyval.ast)=astCreate(AST_FLOAT, 0, 0, 0, 0, 0);}
    break;

  case 73:
#line 225 "parser.y"
    {(yyval.ast)=astCreate(AST_CHAR, 0, 0, 0, 0, 0);}
    break;


/* Line 1267 of yacc.c.  */
#line 1907 "y.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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


#line 228 "parser.y"


AST* getRoot() {
    return root;
}

void checkSemantic() {
    if(totalSemanticErrors() > 0) {
        fprintf(stderr, "%d, Semantic Errors.\n", totalSemanticErrors());
        exit(4);
    }
}

int yyerror() {
    fprintf(stderr, "ERRO na linha = %d\n", getLineNumber());
    exit(3);
}

