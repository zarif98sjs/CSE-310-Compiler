flex -o scanner.c scanner.l
g++ scanner.c -lfl -o scanner.out
./scanner.out scanner.txt
