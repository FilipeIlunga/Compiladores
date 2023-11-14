%{
#include "tokens.h"
#include "hash.c"

int token;
int running=1;
int lineNumber=1;

int getLineNumber() {
  return lineNumber;
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

[0-9]+							      {hashInsert(LIT_INT, yytext);return LIT_INT;}
[0-9]+"."[0-9]+						{hashInsert(LIT_REAL, yytext);return LIT_REAL;}
(\'.\')|(\'\')						{hashInsert(LIT_CHAR, yytext);return LIT_CHAR;}
\"(\\.|[^\"\n])*\"				{hashInsert(LIT_STRING, yytext);return LIT_STRING;}   

"<="          return OPERATOR_LE;       
">="          return OPERATOR_GE;       
"=="          return OPERATOR_EQ;      
"!="          return OPERATOR_DIF;

[a-zA-Z0-9_]+		{hashInsert(TK_IDENTIFIER, yytext);return TK_IDENTIFIER;}

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

void initMe(void){
	hashInit();
}

#include "main.c" 

int yywrap(){
	running = 0;
	return 1;
}
