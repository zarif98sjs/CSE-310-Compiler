flex -o 1705010.c 1705010.l
g++ SymbolInfo.cpp ScopeTable.cpp SymbolTable.cpp 1705010.c -lfl -o 1705010.out
./1705010.out sample_input1.txt