etapa3: y.tab.o lex.yy.o hash.o ast.o
	gcc -o etapa3 y.tab.o lex.yy.o hash.o ast.o

hash.o: hash.c
	gcc -c hash.c

ast.o: ast.c
	gcc -c ast.c

y.tab.o: y.tab.c
	gcc -c y.tab.c

y.tab.c: parser.y
	yacc -d -v parser.y

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

lex.yy.c: scanner.l
	flex --header-file=lex.yy.h scanner.l

clean:
	rm -f *.o etapa3 lex.yy.c lex.yy.h y.tab.c y.tab.h y.output