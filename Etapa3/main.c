#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

extern int yyparse();
extern char* yytext;
extern FILE* yyin;
extern FILE* file();

extern AST* getRoot();
extern int getLineNumber(void);
extern int isRunning(void);
extern void initMe(void);

int main(int argc, char* argv[]) {
  int token;
  int ret;
  FILE* output;

  if (argc < 3) {
    printf("call: ./etapa3 <input_file> <output_file>\n");
    exit(1);
  }
  if (!(file(argv[1]))) {
    printf("Cannot open file %s...\n",argv[1]);
    exit(1);
  }
  if (!(output = fopen(argv[2], "w"))) {
    printf("Cannot open file %s...\n",argv[1]);
    exit(1);
  }

  initMe();
  
  yyparse();

  printf("\n\nInit uncompilation\n\n");

  uncompileAST(getRoot(), output);

fprintf(stderr, "Uncompiling done!\n");

  fclose(output);

  exit(0);
}