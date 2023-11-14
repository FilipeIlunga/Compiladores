/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
     OPERATOR_LE = 267,
     OPERATOR_GE = 268,
     OPERATOR_EQ = 269,
     OPERATOR_DIF = 270,
     TK_IDENTIFIER = 271,
     LIT_INT = 272,
     LIT_REAL = 273,
     LIT_CHAR = 274,
     LIT_STRING = 275,
     KW_INPUT = 276,
     TOKEN_ERROR = 277
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
#define OPERATOR_LE 267
#define OPERATOR_GE 268
#define OPERATOR_EQ 269
#define OPERATOR_DIF 270
#define TK_IDENTIFIER 271
#define LIT_INT 272
#define LIT_REAL 273
#define LIT_CHAR 274
#define LIT_STRING 275
#define KW_INPUT 276
#define TOKEN_ERROR 277




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

