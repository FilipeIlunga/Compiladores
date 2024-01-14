#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

extern int yyparse();
extern char* yytext;
extern FILE* yyin;
extern AST* getRoot();
extern int getLineNumber(void);
extern int isRunning(void);
extern void initMe(void);
extern int checkSemantic();



int main(int argc, char* argv[]) {
  int token;
  int ret;
  FILE* output;

  if (argc < 3) {
    printf("call: ./etapa4 <input_file> <output_file>\n");
    exit(1);
  }
  if (0 == (yyin = fopen(argv[1], "r"))) {
    printf("Cannot open file %s...\n",argv[1]);
    exit(1);
  }
  if (0 == (output = fopen(argv[2],"w"))) {
    printf("Cannot open file %s...\n",argv[1]);
    exit(1);
  }

  initMe();
  
  yyparse();

  printf("\n\nStart uncompilation\n\n");

  uncompileAST(getRoot(), output);

  fclose(output);

  printf("\n\nChecking Semantic\n\n");

  checkSemantic();

  exit(0);
}