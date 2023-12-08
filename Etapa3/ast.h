#ifndef AST_HEADER 
#define AST_HEADER

#include "hash.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_SONS 4

#define AST_SYMBOL        0 
#define AST_ADD           1  
#define AST_SUB           2 
#define AST_MUL           3 
#define AST_DIV           4
#define AST_LESS          5 
#define AST_GREATER       6 
#define AST_INT           7
#define AST_FLOAT         8
#define AST_CHAR          9 
#define AST_LE            10 
#define AST_GE            11
#define AST_EQ            12
#define AST_DIF           13 
#define AST_NOT           14 
#define AST_IF            15
#define AST_ELSE          16
#define AST_WHILE         17
#define AST_INPUT         18
#define AST_CODE          19
#define AST_PRINT         20
#define AST_RETURN        21
#define AST_LSTDEC        22
#define AST_DECVAR        23
#define AST_DECVEC        24 
#define AST_DECFUNC       25
#define AST_PARAM         26
#define AST_BLOCO         27 
#define AST_LSTCOMANDO    28
#define AST_VEC           29  
#define AST_FUNC          30  
#define AST_VECFIM        31 
#define AST_LSTVEC        32
#define AST_PARAMINIT     33
#define AST_LSTPARAM      34
#define AST_LSTCODIGO     35 
#define AST_ATTR          36 
#define AST_ATTREXPR      37
#define AST_ATTRVEC       38
#define AST_PAREN         39
#define AST_LSTARG        40
#define AST_LSTARGFIM     41 
#define AST_PROG          42    
#define AST_LDECGLOBAL    43
#define AST_PRINTEXP      44

typedef struct ast_node {
    int type;
    HASH_NODE* symbol;
    struct ast_node* son[MAX_SONS];
} AST;

AST* astCreate(int type, HASH_NODE* symbol, AST* son0, AST* son1, AST* son2, AST* son3);
void astPrint(AST* node, int level);
void uncompileAST(AST* node, FILE* file);

#endif