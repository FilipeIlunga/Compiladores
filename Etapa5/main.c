#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include "tac.h"


extern int yyparse();
extern char* yytext;
extern FILE* yyin;

extern TAC* getTACs();
extern AST* getRoot();
extern int getLineNumber(void);
extern int isRunning(void);
extern void initMe(void);
extern void hashPrint();


int main(int argc, char* argv[]) {
    FILE* output;
    if (argc <= 2) {
        fprintf(stderr, "Call: ./etapa3 input.txt output.txt\n");
        exit(1);
    }
    if (0 == (yyin = fopen(argv[1],"r"))) {
        fprintf(stderr, "Cannot open file %s\n", argv[1]);
        exit(2);
    }
    if (0 == (output = fopen(argv[2],"w"))) {
        fprintf(stderr, "Cannot open file %s\n", argv[2]);
        exit(2);
    }
  initMe();
  
  yyparse();

  printf("\n\nInit uncompilation\n\n");

  uncompileAST(getRoot(), output);

  fprintf(stderr, "Uncompiling done!\n");

  fclose(output);

  printf("Done!\n");

  generatedTac(getTACs());

  exit(0);
}