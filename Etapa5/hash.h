#ifndef HASH_HEADER
#define HASH_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 997

#define SYMBOL_LIT_INT 1
#define SYMBOL_LIT_FLOAT 2
#define SYMBOL_LIT_CHAR 3
#define SYMBOL_LIT_STRING 4

#define SYMBOL_IDENTIFIER 5

#define SYMBOL_VAR 6
#define SYMBOL_VEC 7
#define SYMBOL_FUN 8
#define SYMBOL_PARAM 9

#define DATATYPE_INT 10
#define DATATYPE_FLOAT 11
#define DATATYPE_CHAR 12
#define DATATYPE_BOOL 13

typedef struct hash_node
{
    int type;
    int datatype;
    int lineNumber;
    int wasImplemented;
    char *text;
    struct hash_node *next;
} HASH_NODE;

void hashInit(void);
int hashAddress(char *text);
HASH_NODE *hashInsert(int type, char *text);
void hashPrint(void);
HASH_NODE *hashFind(char* text);
int checkUndeclaredHash(void);
HASH_NODE *createTemp();
HASH_NODE *createLabel();

#endif