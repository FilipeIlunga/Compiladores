#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"

//lex.yy.h
int yylex();
extern char *yytext;
extern FILE *yyin;


int isRunning(void);
void initMe(void);

int yyparse();

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        exit(1);
    }

    FILE *input_file = fopen(argv[1], "r");

    if (!input_file) {
        perror("Error opening input file");
        exit(2);
    }

    yyin = input_file;

    int result = yyparse();

    fclose(input_file);

    return result;
}