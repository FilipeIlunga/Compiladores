%{
/* ETAPA 3 - Compiladores - 2023/2
   Aluno: Filipe Ilunga Xindanhi
*/

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "ast.h"

int yylex();
int yyerror();
AST* getRoot();
extern int getLineNumber();

AST* root; 

%}

%union
{
struct hash_node* symbol;
struct ast_node* ast;
}

%token KW_INT
%token KW_FLOAT
%token KW_CHAR
%token KW_CODE
%token KW_IF
%token KW_ELSE
%token KW_WHILE
%token KW_PRINT
%token KW_RETURN
%token KW_INPUT
%token OPERATOR_LE      
%token OPERATOR_GE      
%token OPERATOR_EQ      
%token OPERATOR_DIF

%token <symbol> TK_IDENTIFIER
%token <symbol> LIT_INT
%token <symbol> LIT_REAL 
%token <symbol> LIT_CHAR
%token <symbol> LIT_STRING

%token TOKEN_ERROR

%left '<' '>' OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_DIF
%left '+' '-'
%left '*' '/'

%type <ast> programa
%type <ast> declaracoes_inicial 
%type <ast> declaracoes_globais 
%type <ast> declaracao_global 
%type <ast> inicializacao_vetor_opcional 
%type <ast> parametros_formais 
%type <ast> parametros_formais_fim 
%type <ast> parametro_formal 
%type <ast> lista_codigo 
%type <ast> bloco 
%type <ast> lista_comandos 
%type <ast> comando 
%type <ast> expressao 
%type <ast> lista_argumentos 
%type <ast> lista_argumentos_fim 
%type <ast> tipo
%type <ast> literal 

%start programa

%%

programa : declaracoes_inicial                                                                  {root=$$; astPrint(root,0);}
         ;


declaracoes_inicial: declaracoes_globais lista_codigo                                           {$$=astCreate(AST_LDECGLOBAL, 0, $1, $2, 0, 0);}
                  ;

declaracoes_globais : declaracao_global declaracoes_globais                                     {$$=astCreate(AST_LSTDEC, 0, $1, $2, 0, 0);}
                   |                                                                            {$$=0;}
                   ;

declaracao_global : tipo TK_IDENTIFIER '=' literal ';'                                          {$$=astCreate(AST_DECVAR, $2, $1, $4, 0, 0);}
                  | tipo TK_IDENTIFIER '[' LIT_INT ']' inicializacao_vetor_opcional ';'         {$$=astCreate(AST_DECVEC, $2, $1, astCreate(AST_SYMBOL, $4, 0, 0, 0, 0), $6, 0);} 
                  | tipo TK_IDENTIFIER '(' parametros_formais ')' ';'                           {$$=astCreate(AST_DECFUNC, $2, $1, $4, 0, 0);} 
                  ;

inicializacao_vetor_opcional :  literal inicializacao_vetor_opcional                             {$$=astCreate(AST_LSTVEC, 0, $1, $2, 0, 0);}
                   |                                                                             {$$=0;}
                   ;

parametros_formais : parametro_formal parametros_formais_fim                                    {$$=astCreate(AST_PARAMINIT, 0, $1, $2, 0, 0);}
                  |                                                                             {$$=0;}
                  ;

parametros_formais_fim : ',' parametro_formal parametros_formais_fim                            {$$=astCreate(AST_LSTPARAM, 0, $2, $3, 0, 0);}
                      |                                                                         {$$=0;}
                      ;

parametro_formal : tipo TK_IDENTIFIER                                                           {$$=astCreate(AST_PARAM, $2, $1, 0, 0, 0);}
                ;               

lista_codigo : KW_CODE TK_IDENTIFIER comando lista_codigo                                       {$$=astCreate(AST_LSTCODIGO, $2, $3, $4, 0, 0);}
            |                                                                                   {$$=0;}
            ;           

bloco : '{' lista_comandos '}'                                                                  {$$=astCreate(AST_BLOCO, 0, $2, 0, 0, 0);}
      ;         

lista_comandos : comando lista_comandos                                                         {$$=astCreate(AST_LSTCOMANDO, 0, $1, $2, 0, 0);}
              |                                                                                 {$$=0;}
              ;         

comando : bloco                                                                                 {$$=$1;}
        | TK_IDENTIFIER '=' expressao ';'                                                       {$$=astCreate(AST_ATTREXPR, $1, $3, 0, 0, 0);}
        | TK_IDENTIFIER '[' expressao ']' '=' expressao ';'                                     {$$=astCreate(AST_ATTRVEC, $1, $3, $6, 0, 0);}
        | KW_PRINT LIT_STRING ';'                                                               {$$=astCreate(AST_PRINT, 0, astCreate(AST_SYMBOL, $2, 0, 0, 0 ,0), 0, 0, 0);}                
        | KW_PRINT expressao ';'                                                                {$$=astCreate(AST_PRINTEXP, 0, $2, 0, 0, 0);}     
        | KW_IF '(' expressao ')' comando                                                       {$$=astCreate(AST_IF, 0, $3, $5, 0, 0);}
        | KW_IF '(' expressao ')' comando KW_ELSE comando                                       {$$=astCreate(AST_ELSE, 0, $3, $5, $7, 0);}
        | KW_WHILE '(' expressao ')' comando                                                    {$$=astCreate(AST_WHILE, 0, $3, $5, 0, 0);}
        | KW_RETURN expressao ';'                                                               {$$=astCreate(AST_RETURN, 0, $2, 0, 0, 0);}
        | ';'                                                                                   {$$=0;}
        ;
 
expressao : TK_IDENTIFIER                                                                       {$$=astCreate(AST_SYMBOL, $1, 0, 0, 0, 0);}
          | TK_IDENTIFIER '[' expressao ']'                                                     {$$=astCreate(AST_VEC, $1, $3, 0, 0, 0);}
          | TK_IDENTIFIER '(' lista_argumentos ')'                                              {$$=astCreate(AST_FUNC, $1, $3, 0, 0, 0);}
          | LIT_INT                                                                             {$$=astCreate(AST_SYMBOL, $1, 0, 0, 0, 0);}   
          | LIT_REAL                                                                            {$$=astCreate(AST_SYMBOL, $1, 0, 0, 0, 0);}
          | LIT_CHAR                                                                            {$$=astCreate(AST_SYMBOL, $1, 0, 0, 0, 0);}
          | LIT_STRING                                                                          {$$=astCreate(AST_SYMBOL, $1, 0, 0, 0, 0);}
          | KW_INPUT '(' tipo ')'                                                               {$$=astCreate(AST_INPUT, 0, $3, 0, 0 ,0);} 
          | expressao '+' expressao                                                             {$$=astCreate(AST_ADD, 0, $1, $3, 0, 0);}
          | expressao '-' expressao                                                             {$$=astCreate(AST_SUB, 0, $1, $3, 0, 0);}
          | expressao '*' expressao                                                             {$$=astCreate(AST_MUL, 0, $1, $3, 0, 0);}
          | expressao '/' expressao                                                             {$$=astCreate(AST_DIV, 0, $1, $3, 0, 0);}
          | expressao '<' expressao                                                             {$$=astCreate(AST_LESS, 0, $1, $3, 0, 0);}
          | expressao '>' expressao                                                             {$$=astCreate(AST_GREATER, 0, $1, $3, 0, 0);}
          | expressao OPERATOR_LE expressao                                                     {$$=astCreate(AST_LE, 0, $1, $3, 0, 0);} 
          | expressao OPERATOR_GE expressao                                                     {$$=astCreate(AST_GE, 0, $1, $3, 0, 0);}   
          | expressao OPERATOR_EQ expressao                                                     {$$=astCreate(AST_EQ, 0, $1, $3, 0, 0);}  
          | expressao OPERATOR_DIF expressao                                                    {$$=astCreate(AST_DIF, 0, $1, $3, 0, 0);} 
          | '(' expressao ')'                                                                   {$$=astCreate(AST_PAREN, 0, $2, 0, 0, 0);}
          ;

lista_argumentos :                                                                              {$$=0;}
                | expressao lista_argumentos_fim                                                {$$=astCreate(AST_LSTARG, 0, $1, $2, 0, 0);}
                ;               

lista_argumentos_fim :                                                                          {$$=0;}
                | ',' expressao lista_argumentos_fim                                            {$$=astCreate(AST_LSTARGFIM, 0, $2, $3, 0, 0);}
                ;               

literal : LIT_INT                                                                               {$$=astCreate(AST_SYMBOL, $1, 0, 0, 0, 0);}
        | LIT_REAL                                                                              {$$=astCreate(AST_SYMBOL, $1, 0, 0, 0, 0);}
        | LIT_CHAR                                                                              {$$=astCreate(AST_SYMBOL, $1, 0, 0, 0, 0);}
        | LIT_STRING                                                                            {$$=astCreate(AST_SYMBOL, $1, 0, 0, 0, 0);}
        ;               

tipo : KW_INT                                                                                   {$$=astCreate(AST_INT, 0, 0, 0, 0, 0);}
     | KW_FLOAT                                                                                 {$$=astCreate(AST_FLOAT, 0, 0, 0, 0, 0);}
     | KW_CHAR                                                                                  {$$=astCreate(AST_CHAR, 0, 0, 0, 0, 0);}
     ;

%%

AST* getRoot() {
    return root;
}

int yyerror() {
    fprintf(stderr, "ERRO na linha = %d\n", getLineNumber());
    exit(3);
}
