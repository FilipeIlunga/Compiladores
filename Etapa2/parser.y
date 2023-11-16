%{
/* ETAPA 2 - Compiladores - 2023/2
   Aluno: Filipe Ilunga Xindanhi
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

int yylex();
int yyerror(char *mensagem);
extern int getLineNumber();

%}

%token KW_INT
%token KW_FLOAT
%token KW_CHAR
%token KW_CODE
%token KW_IF
%token KW_ELSE
%token KW_WHILE
%token KW_PRINT
%token KW_RETURN
%token OPERATOR_LE      
%token OPERATOR_GE      
%token OPERATOR_EQ      
%token OPERATOR_DIF
%token TK_IDENTIFIER
%token LIT_INT
%token LIT_REAL
%token LIT_CHAR
%token LIT_STRING
%token KW_INPUT

%token TOKEN_ERROR

%left '<' '>' OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_DIF
%left '+' '-'
%left '*' '/'

%start programa

%%

programa : declaracoes_globais lista_codigo
        ;

declaracoes_globais : declaracao_global declaracoes_globais
                   |
                   ;

declaracao_global : declaracao_variavel
                  | declaracao_vetor
                  | declaracao_funcao
                  ;

declaracao_variavel : tipo TK_IDENTIFIER '=' literal ';'
                    ;

declaracao_vetor : tipo TK_IDENTIFIER '[' LIT_INT ']' inicializacao_vetor_opcional ';'
                ;

inicializacao_vetor_opcional :  literal inicializacao_vetor_opcional
                   | 
                   ;

declaracao_funcao : tipo TK_IDENTIFIER '(' parametros_formais ')' ';'
                 ;

parametros_formais : parametro_formal parametros_formais_fim
                  |
                  ;

parametros_formais_fim : ',' parametro_formal parametros_formais_fim
                      |
                      ;

parametro_formal : tipo TK_IDENTIFIER
                ;

lista_codigo : KW_CODE TK_IDENTIFIER bloco lista_codigo
            |
            ;

bloco : '{' lista_comandos '}' 
      ;

lista_comandos : comando lista_comandos
              |
              ;

comando : comando_vazio
        | comando_atribuicao
        | comando_print
        | comando_return
        | comando_if
        | comando_if_else
        | comando_while
        | bloco
        ;

comando_vazio : ';'
             ;

comando_atribuicao : TK_IDENTIFIER '=' expressao
                 | TK_IDENTIFIER '[' expressao ']' '=' expressao
                 ;

comando_print : KW_PRINT elementos_print ';'
              ;

elementos_print : LIT_STRING
                | expressao 
                ;

comando_return : KW_RETURN expressao ';'
               ;

comando_if : KW_IF '(' expressao ')' comando
          ;

comando_if_else : KW_IF '(' expressao ')' comando KW_ELSE comando
               ;

comando_while : KW_WHILE '(' expressao ')' comando
             ;

expressao : TK_IDENTIFIER
          | TK_IDENTIFIER '[' expressao ']'
          | TK_IDENTIFIER '(' lista_argumentos ')'
          | LIT_INT
          | LIT_REAL
          | LIT_CHAR
          | LIT_STRING
          | KW_INPUT '(' tipo ')'
          | expressao '+' expressao
          | expressao '-' expressao
          | expressao '*' expressao
          | expressao '/' expressao
          | expressao '<' expressao
          | expressao '>' expressao
          | expressao OPERATOR_LE expressao
          | expressao OPERATOR_GE expressao
          | expressao OPERATOR_EQ expressao
          | expressao OPERATOR_DIF expressao
          | '(' expressao ')'
          ;

lista_argumentos : 
                | expressao lista_argumentos_fim
                ;

lista_argumentos_fim : ',' expressao lista_argumentos_fim
                 |
                 ;

literal : LIT_INT
        | LIT_REAL
        | LIT_CHAR
        | LIT_STRING
        ;

tipo : KW_INT
     | KW_FLOAT
     | KW_CHAR
     ;

%%

int yyerror(char *err) {
    fprintf(stderr, "ERRO na linha = %d\n", getLineNumber());
    exit(3);
}
