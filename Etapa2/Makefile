#
# UFRGS - Compiladores B - Marcelo Johann - 2009/2 - Etapa 1
#
# Makefile for single compiler call
# All source files must be included from code embedded in scanner.l
# In our case, you probably need #include "hash.c" at the beginning
# and #include "main.c" in the last part of the scanner.l
#

etapa2: lex.yy.o y.tab.o
	gcc -o etapa2 lex.yy.o y.tab.o
lex.yy.o: lex.yy.c y.tab.c
	gcc -c lex.yy.c y.tab.c
lex.yy.c: scanner.l y.tab.h
	flex --header-file=lex.yy.h scanner.l
y.tab.h: parser.y
	yacc -d parser.y
clean:
	rm .o lex.yy. y.tab.* *.output etapa2