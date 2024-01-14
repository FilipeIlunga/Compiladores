#ifndef HASH_HEADER
#define HASH_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 997

typedef enum {
    SYMBOL_LIT_INT = 1,
    SYMBOL_LIT_FLOAT,
    SYMBOL_LIT_CHAR,
    SYMBOL_LIT_STRING,
    SYMBOL_IDENTIFIER,
    SYMBOL_VAR,
    SYMBOL_VEC,
    SYMBOL_FUNC,
    SYMBOL_PARAM
} SymbolType;

typedef enum {
    DATATYPE_INT = 10,
    DATATYPE_FLOAT,
    DATATYPE_CHAR,
    DATATYPE_BOOL,
    NO_DATATYPE,
} DataType;

typedef struct hash_node {
    int type;
    int dataType;
    int lineNumber;
    int implemented;
    char *text;
    struct hash_node *next;
} HASH_NODE;

void hashInit(void);
int hashAddress(char *text);
int checkUndeclaredIdentifiers(void);
HASH_NODE *hashInsert(int type, char *text);
HASH_NODE *hashFind(char* text);

#endif