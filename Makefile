ifeq ($(OS),Windows_NT)
 SHELL := cmd.exe
 LIB := parser.lib
else
 UNAME_S := $(shell uname -s)
 ifeq ($(UNAME_S),Linux)
 SHELL := bash
 LIB := libparser.a
 endif
 ifeq ($(UNAME_S),Darwin)
 SHELL := zsh
 LIB := libparser.a
 endif
endif

CC := gcc -g
LEX := flex
YACC := bison
CFLAGS := -w -std=c11
DEBUG_CFLAGS := $(CFLAGS) -DDEBUG
LDCFLAGS := -w -std=c11 -fPIC
OBJS := lexer.o ast.o parser.tab.o
PROGRAMS := sql_parser

.SUFFIXES: .l .y .c .h
.PHONY: clean debug

# all: ${PROGRAMS}

static: parser.tab.o lexer.o ast.o 
		ar -rc $(LIB) $(OBJS)

dynamic: parser.tab.o lexer.o ast.o 
		${CC} ${LDCFLAGS} -shared $(OBJS) -o $(LIB)

parser: parser.tab.o lexer.o ast.o 
		$(CC) $(CFLAGS) -o $@ lexer.o ast.o parser.tab.o

lexer.o: lexer.c
		$(CC) $(CFLAGS) -c $< -o $@

ast.o: ast.c ast.h
		${CC} ${CFLAGS} -c $< -o $@

parser.tab.o: parser.tab.c
		${CC} ${CFLAGS} -c parser.tab.c -o $@

parser.tab.c: parser.y lexer.c
		${YACC} -vd parser.y

lexer.c: lexer.l
		${LEX} -o $*.c $<

clean:
		rm -f lexer.c *.o parser.tab.c parser.tab.h *.output lib*

debug:
		$(CC) $(DEBUG_CFLAGS) -c parser.tab.c -o parser.o