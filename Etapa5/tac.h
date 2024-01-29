#ifndef TAC_H
#define TAC_H

#include <stdlib.h>
#include "ast.h"
#include "hash.h"

enum TAC_ENUM {
  TAC_SYMBOL,
  TAC_MOVE,
  TAC_BEGINFUN,
  TAC_ENDFUN,
  TAC_CALL,
  TAC_JUMP,
  TAC_LABEL,
  TAC_PARAMPOP,
  TAC_ADD,
  TAC_SUB,
  TAC_MUL,
  TAC_DIV,
  TAC_GT,
  TAC_LT,
  TAC_GE,
  TAC_LE,
  TAC_EQ,
  TAC_DIF,
  TAC_AND,
  TAC_OR,
  TAC_NOT,
  TAC_RET,
  TAC_ARGPUSH,
  TAC_IF,
  TAC_ARG,
  TAC_PRINT,
  TAC_INPUT,
  TAC_VECATTR,
  TAC_VEC
};

typedef struct tac {
  int type;
  HASH_NODE* res;
  HASH_NODE* op1;
  HASH_NODE* op2;
  struct tac* prev;
  struct tac* next;
} TAC;

TAC* makeBinop(int type, TAC* children[]);
TAC* makeWhile(TAC* children[], HASH_NODE* label);
TAC* makeIf(TAC* children[]);
TAC* createFunction(TAC* symbol, TAC* params, TAC* code);
TAC* tacUnion(TAC* list1, TAC* list2);
TAC* newTac(int type, HASH_NODE* res, HASH_NODE* op1, HASH_NODE* op2);
TAC* rewindTac(TAC* list);
void printTac(TAC* list);
TAC* buildTac(AST* node, HASH_NODE* label);
void generatedTac(TAC* list);

#endif