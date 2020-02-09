CC = gcc -g
LEX = flex
YACC = bison
CFLAGS = -w -DYYDEBUG=1 -std=c11
LIB_CFLAGS = -std=c11 -fPIC

PROGRAMS = csql_parser

# all: ${PROGRAMS}

slib: parser.tab.o lexer.o ast.o
		ar -rc parser.lib $^

dlib: parser.tab.c lexer.c ast.c
		${CC} ${LIB_CFLAGS} -shared $^ -o parser.lib

parser: parser.tab.o lexer.o ast.o
		${CC} ${CFLAGS} -o $@ parser.tab.o lexer.o ast.o

parser.tab.c parser.tab.h: parser.y
		${YACC} -vd parser.y

lexer.c: lexer.l
		${LEX} -o $*.c $<

lexer.o: lexer.c parser.tab.h

ast.o:
		${CC} ${CFLAGS} -c ast.c

.SUFFIXES: .l .y .c .h

.PHONY: clean

clean:
		-rm *.o *.tab.* *.output *.exe *.lib