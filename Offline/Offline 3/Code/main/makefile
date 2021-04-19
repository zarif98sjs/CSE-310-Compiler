CC = g++
LEX = flex
YACC = yacc
CPPFLAGS = -w
COMMON_HEADER_FILES = SymbolInfo.h ScopeTable.h SymbolTable.h Helper.h
COMMON_HEADER_OBJECT_FILES = SymbolInfo.o ScopeTable.o SymbolTable.o Helper.o

all: y.o l.o a.out run
	
y.o: demo.y ${COMMON_HEADER_FILES}
	${YACC} -d -y demo.y
	${CC} ${CPPFLAGS} -c -o y.o y.tab.c

l.o : demo.l y.tab.h ${COMMON_HEADER_FILES}
	${LEX} demo.l
	${CC} ${CPPFLAGS} -c -o l.o lex.yy.c

SymbolInfo.o 	: SymbolInfo.cpp
				${CC} ${CPPFLAGS} -c SymbolInfo.cpp

ScopeTable.o 	: ScopeTable.cpp
				${CC} ${CPPFLAGS} -c ScopeTable.cpp

SymbolTable.o 	: SymbolTable.cpp
				${CC} ${CPPFLAGS} -c SymbolTable.cpp

Helper.o 		: Helper.cpp
				${CC} ${CPPFLAGS} -c Helper.cpp

a.out: l.o y.o ${COMMON_HEADER_OBJECT_FILES}
	${CC} ${CPPFLAGS} y.o l.o ${COMMON_HEADER_OBJECT_FILES} -lfl

run:
#valgrind --leak-check=full -s --show-leak-kinds=all ./a.out input.txt log.txt error.txt
	./a.out demo.txt > demo_out.txt

clean: 
	rm -f *.out
	rm -f *.o
	rm -f lex.yy.c
	rm -f y.tab.c
	rm -f y.tab.h
	rm -f y.output