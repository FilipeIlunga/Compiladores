#include "stdio.h"
#include "stdlib.h"
extern FILE *yyin;

void   initMe(void);

int main(int argc, char **argv) {
  int token = 0;

  hashInit();
if (argc <= 2) {
        fprintf(stderr, "Call: ./a.out file_name\n");
        exit(1);
    }
    if (0 == (yyin = fopen(argv[1],"r"))) {
        fprintf(stderr, "Cannot open file %s\n", argv[1]);
        exit(2);
    }
    
    initMe();
    while(isRunning()) {
        token = yylex();
        if (!isRunning()) {
            break;
        }
    }
    
  printf("Foram encotradas %d linhas\n", getLineNumber());
  hashPrint();
  exit(0);
}

