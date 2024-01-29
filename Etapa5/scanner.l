%{
#include "y.tab.h"
#include "hash.h"
#include "ast.h"
#include <stdio.h>

int token;
int running=1;
int lineNumber=1;

int getLineNumber() {
  return lineNumber;
}

void initMe(void){
	hashInit();
}

int isRunning(void) {
  return running;
}

%}

%x COMMENT_LINE
%x COMMENT

%%

"char"        {return KW_CHAR;}       
"int"         {return KW_INT;}       
"float"       {return KW_FLOAT;}        
"code"        {return KW_CODE;}       
"if"          {return KW_IF;}       
"else"        {return KW_ELSE;}       
"while"       {return KW_WHILE;}        
"input"       {return KW_INPUT;}        
"print"       {return KW_PRINT;}       
"return"      {return KW_RETURN;}   

[,;()[\]{}=+\-*/%<>&|~] { return yytext[0]; }

[0-9]+							       {yylval.symbol = hashInsert(SYMBOL_LIT_INT, yytext);return LIT_INT;}
[0-9]+"."[0-9]+						 {yylval.symbol = hashInsert(SYMBOL_LIT_FLOAT, yytext);return LIT_REAL;}
(\'.\')|(\'\')						 {yylval.symbol = hashInsert(SYMBOL_LIT_CHAR, yytext);return LIT_CHAR;}
\"(\\.|[^\"\n])*\"				 {yylval.symbol = hashInsert(SYMBOL_LIT_STRING, yytext);return LIT_STRING;}   

"<="          return OPERATOR_LE;       
">="          return OPERATOR_GE;       
"=="          return OPERATOR_EQ;      
"!="          return OPERATOR_DIF;

[a-zA-Z0-9_]+		 {yylval.symbol = hashInsert(SYMBOL_IDENTIFIER, yytext);return TK_IDENTIFIER;}

\n								{lineNumber++;}
[ "\t"]               {}

"///" {BEGIN(COMMENT);}
"//" {BEGIN(COMMENT_LINE);}

.								{printf("tokenError %c\n", yytext[0]); return TOKEN_ERROR;}

<COMMENT_LINE>"\n" {lineNumber++; BEGIN(INITIAL);}
<COMMENT_LINE>. {}

<COMMENT>"\n"    { lineNumber++;   }
<COMMENT>.       {}
<COMMENT>"\\\\\\"   { BEGIN(INITIAL); }

%%

#include "main.c" 

int yywrap(){
	running = 0;
	return 1;
}