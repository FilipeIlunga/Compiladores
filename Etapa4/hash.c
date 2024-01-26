#include "hash.h"
extern int getLineNumber();


HASH_NODE* Table[HASH_SIZE];

void printToken(int index, char *text, int token) {
 /*    
    switch (token) {
        case KW_CHAR:
            printf("TABLE[%d] has %s - KW_CHAR\n", index, text);
            break;
        case KW_INT:
            printf("TABLE[%d] has %s - KW_INT\n", index, text);
            break;
        case KW_FLOAT:
            printf("TABLE[%d] has %s - KW_FLOAT\n", index, text);
            break;
        case KW_CODE:
            printf("TABLE[%d] has %s - KW_CODE\n", index, text);
            break;
        case KW_IF:
            printf("TABLE[%d] has %s - KW_IF\n", index, text);
            break;
        case KW_ELSE:
            printf("TABLE[%d] has %s - KW_ELSE", index, text);
            break;
        case KW_WHILE:
            printf("TABLE[%d] has %s - KW_WHILE\n", index, text);
            break;
        case KW_INPUT:
            printf("TABLE[%d] has %s - KW_INPUT\n", index, text);
            break;
        case KW_PRINT:
            printf("TABLE[%d] has %s - KW_PRINT\n", index, text);
            break;
        case KW_RETURN:
            printf("TABLE[%d] has %s - KW_RETURN\n", index, text);
            break;
        case OPERATOR_LE:
            printf("TABLE[%d] has %s - OPERATOR_LE\n", index, text);
            break;
        case OPERATOR_GE:
            printf("TABLE[%d] has %s - OPERATOR_GE\n", index, text);
            break;
        case OPERATOR_EQ:
            printf("TABLE[%d] has %s - OPERATOR_EQ\n", index, text);
            break;
        case OPERATOR_DIF:
            printf("TABLE[%d] has %s - OPERATOR_DIF\n", index, text);
            break;
        case TK_IDENTIFIER:
            printf("TABLE[%d] has %s - TK_IDENTIFIER\n", index, text);
            break;
        case LIT_INT:
            printf("TABLE[%d] has %s - LIT_INT\n", index, text);
            break;
        case LIT_REAL:
            printf("TABLE[%d] has %s - LIT_REAL\n", index, text);
            break;
        case LIT_CHAR:
            printf("TABLE[%d] has %s - LIT_CHAR\n", index, text);
            break;
        case LIT_STRING:
            printf("TABLE[%d] has %s - LIT_STRING\n", index, text);
            break;
        case TOKEN_ERROR:
            printf("TABLE[%d] has %s - TOKEN_ERROR\n", index, text);
            break;
        default:
            printf("Token unkown index: %d - text: %s\n", index, text);
            break;
    }
    */
}



void hashInit(void) {
    int i;
    for( i = 0; i < HASH_SIZE; ++i )
        Table[i] = 0;
}

HASH_NODE *hashFind(char* text) {
  HASH_NODE *node;
  int address = hashAddress(text);

  for(node = Table[address]; node; node = node->next) {
    if(strcmp(node->text, text) == 0)
      return node;
  }

  return 0;
}

int hashAddress(char *text) {
    int address = 1;
    int i;
    
    for (i=0; i<strlen(text); i++)
        address = (address * text[i]) % HASH_SIZE + 1;
    
    return address - 1;
}

HASH_NODE *hashInsert(int type, char *text) {
    HASH_NODE *newNode;
    int address;
    
    if ((newNode = hashFind(text)) != 0)
        return newNode;
    
    newNode = (HASH_NODE*) calloc(1,sizeof(HASH_NODE));
    newNode->lineNumber = getLineNumber();
    newNode->wasImplemented = 0;
    newNode->type = type;

    if(newNode->type == SYMBOL_LIT_CHAR) newNode->datatype = DATATYPE_CHAR; 
    else if(newNode->type == SYMBOL_LIT_FLOAT) newNode->datatype = DATATYPE_FLOAT;
    else if(newNode->type == SYMBOL_LIT_INT) newNode->datatype = DATATYPE_INT;

    newNode->text = (char*) calloc(strlen(text) + 1, sizeof(char));
    strcpy(newNode->text, text);
    newNode->next = 0;
    
    address = hashAddress(text);
    newNode->next = Table[address];
    Table[address] = newNode;
    return newNode;
}

void hashPrint(void) {
    int i;
    HASH_NODE *node;
    
    for (i = 0; i<HASH_SIZE; ++i) {
        for (node=Table[i]; node; node = node->next) {
            printf("Table[%d] has %s, type: %d, dataType: %d\n", i, node->text, node->type, node->datatype);
        }
    }
}

int checkUndeclaredHash(void) {
    HASH_NODE *node;
    int undeclaredVariables = 0;
    for (int i = 0; i < HASH_SIZE; i++) {
        if (Table[i] == 0) continue;
        for (node = Table[i]; node; node = node->next) {
            if (node->type == SYMBOL_IDENTIFIER) {
                fprintf(stderr, "Semantic ERROR Line %d: Undeclared identifier %s\n", node->lineNumber, node->text);
                undeclaredVariables++;
            }
        }
    }
    return undeclaredVariables;
}
