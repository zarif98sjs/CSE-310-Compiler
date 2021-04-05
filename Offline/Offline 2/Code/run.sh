flex -o main.c main.l
g++ SymbolInfo.cpp ScopeTable.cpp SymbolTable.cpp main.c -lfl -o main.out
./main.out scannerCPP.txt