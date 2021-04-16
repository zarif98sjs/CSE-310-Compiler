#!/bin/bash

yacc -d -y simplecalcmodified.y
echo 'Generated the parser C file as well the header file'
gcc -w -c -o y.o y.tab.c
echo 'Generated the parser object file'
flex simplecalcmodified.l
echo 'Generated the scanner C file'
gcc -w -c -o l.o lex.yy.c
# if the above command doesn't work try g++ -fpermissive -w -c -o l.o lex.yy.c
echo 'Generated the scanner object file'
gcc y.o l.o -lfl 
echo 'All ready, running'
./a.out
