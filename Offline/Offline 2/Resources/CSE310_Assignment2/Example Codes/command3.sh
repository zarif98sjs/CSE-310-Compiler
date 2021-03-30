flex -o scannerCPP.c scannerCPP.l
g++ scannerCPP.c -lfl -o scannerCPP.out
./scannerCPP.out scannerCPP.txt
