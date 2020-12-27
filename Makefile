ifeq ($(OS),Windows_NT)
 #echo "Build on Windows"
 SHELL := cmd.exe
 LIB := parser.lib
else
 UNAME_S := $(shell uname -s)
 ifeq ($(UNAME_S),Linux)
 SHELL := /bin/bash
 LIB := libparser.a
 endif
 ifeq ($(UNAME_S),Darwin)
 SHELL := zsh
 endif
endif
# SHELL = cmd.exe
CC := gcc -g
LEX := flex
YACC := bison
CFLAGS := -w -std=c11
DEBUG_CFLAGS := $(CFLAGS) -DDEBUG
LDCFLAGS := -w -std=c11 -fPIC
OBJS := lexer.o ast.o parser.tab.o
# LIB = parser.lib
PROGRAMS := sql_parser

# all: ${PROGRAMS}

static: parser.tab.o lexer.o ast.o 
		ar -rc $(LIB) $(OBJS)

dynamic: parser.tab.o lexer.o ast.o 
		${CC} ${LDCFLAGS} -shared $(OBJS) -o $(LIB)

parser: parser.tab.o lexer.o ast.o 
		$(CC) $(CFLAGS) -o $@ lexer.o ast.o parser.o

lexer.o: lexer.c
		$(CC) $(CFLAGS) -c $< -o $@

ast.o: ast.c ast.h
		${CC} ${CFLAGS} -c $< -o $@

parser.tab.o: parser.tab.c parser.tab.h
		${CC} ${CFLAGS} -c parser.tab.c -o $@

parser.tab.c parser.tab.h: parser.y
		${YACC} -vd parser.y

lexer.c: lexer.l
		${LEX} -o $*.c $<

# .SUFFIXES: .l .y
.PHONY: clean debug

clean:
		rm -f *.o *.tab.* *.output *.exe *.lib lib*.a *.so

debug:
		$(CC) $(DEBUG_CFLAGS) -c parser.tab.c -o parser.o