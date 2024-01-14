#include "hash.h"
extern int getLineNumber();


HASH_NODE* Table[HASH_SIZE];

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
    newNode->type = type;
    newNode->lineNumber = getLineNumber();
    newNode->implemented = 0;
    newNode->dataType = NO_DATATYPE;


    newNode->text = (char*) calloc(strlen(text) + 1, sizeof(char));
    strcpy(newNode->text, text);
    newNode->next = 0;
    
    address = hashAddress(text);
    newNode->next = Table[address];
    Table[address] = newNode;
    return newNode;
}

int checkUndeclaredIdentifiers(void) {
    int undeclaredVariables = 0;

    for (int i = 0; i < HASH_SIZE; i++) {
        HASH_NODE *node = Table[i];

        while (node != NULL) {
            if (node->type == SYMBOL_IDENTIFIER) {
                fprintf(stderr, "Semantic ERROR Line %d: Undeclared identifier %s\n", node->lineNumber, node->text);
                undeclaredVariables++;
            }

            node = node->next;
        }
    }

    return undeclaredVariables;
}