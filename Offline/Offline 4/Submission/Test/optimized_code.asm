.MODEL SMALL

.STACK 100H
.DATA
IS_NEG DB ?
FOR_PRINT DW ?
CR EQU 0DH
LF EQU 0AH
NEWLINE DB CR, LF , '$'

.CODE

OUTPUT PROC
               
        MOV CX , 0FH     
        PUSH CX ; marker
        
        MOV IS_NEG, 0H
        MOV AX , FOR_PRINT
        TEST AX , 8000H
        JE OUTPUT_LOOP
                    
        MOV IS_NEG, 1H
        MOV AX , 0FFFFH
        SUB AX , FOR_PRINT
        ADD AX , 1H
        MOV FOR_PRINT , AX

    OUTPUT_LOOP:
    
        ;MOV AH, 1
        ;INT 21H
        
        MOV AX , FOR_PRINT
        XOR DX,DX
        MOV BX , 10D
        DIV BX ; QUOTIENT : AX  , REMAINDER : DX     
        
        MOV FOR_PRINT , AX
        
        PUSH DX
        
        CMP AX , 0H
        JNE OUTPUT_LOOP
        
        ;LEA DX, NEWLINE ; DX : USED IN IO and MUL,DIV
        ;MOV AH, 9 ; AH,9 used for character string output
        ;INT 21H;

        MOV AL , IS_NEG
        CMP AL , 1H
        JNE OP_STACK_PRINT
        
        MOV AH, 2
        MOV DX, '-' ; stored in DL for display 
        INT 21H
            
        
    OP_STACK_PRINT:
    
        ;MOV AH, 1
        ;INT 21H
    
        POP BX
        
        CMP BX , 0FH
        JE EXIT_OUTPUT
        
       
        MOV AH, 2
        MOV DX, BX ; stored in DL for display 
        ADD DX , 30H
        INT 21H
        
        JMP OP_STACK_PRINT

    EXIT_OUTPUT:
    
        ;POP CX 

        LEA DX, NEWLINE
        MOV AH, 9 
        INT 21H
    
        RET     
      
OUTPUT ENDP



fib PROC
PUSH BP
MOV BP,SP
SUB SP,20
MOV AX,[bp+4]
MOV WORD PTR [bp-2],AX
MOV WORD PTR [bp-4],1
MOV AX,[bp-2]
CMP AX,[bp-4]
jle L0
MOV WORD PTR [bp-6],0
JMP L1
L0:
MOV WORD PTR [bp-6],1
L1:
CMP [bp-6],0
JE L2
MOV AX,[bp-2]
JMP L_fib
L2:
MOV AX,[bp-2]
MOV WORD PTR [bp-8],1
SUB AX,[bp-8]
MOV WORD PTR [bp-10],AX
PUSH [bp-10]
CALL fib
ADD SP,2
MOV WORD PTR [bp-12],AX
MOV AX,[bp-2]
MOV WORD PTR [bp-14],2
SUB AX,[bp-14]
MOV WORD PTR [bp-16],AX
PUSH [bp-16]
CALL fib
ADD SP,2
MOV WORD PTR [bp-18],AX
ADD AX,[bp-18]
MOV WORD PTR [bp-20],AX
JMP L_fib
L_fib:
ADD SP,20
POP BP
RET
fib ENDP

main PROC
MOV AX, @DATA
MOV DS, AX
PUSH BP
MOV BP,SP
SUB SP,10
; n=5;
MOV WORD PTR [bp-4],5
MOV CX,[bp-4]
MOV WORD PTR [bp-2],CX
; s=fib(n);
PUSH [bp-2]
CALL fib
ADD SP,2
MOV WORD PTR [bp-8],AX
MOV CX,[bp-8]
MOV WORD PTR [bp-6],CX
; printf(s);
MOV AX,[bp-6]
MOV FOR_PRINT,AX
CALL OUTPUT
MOV WORD PTR [bp-10],0
MOV AX,[bp-10]
JMP L_main
L_main:
ADD SP,10
POP BP
;DOS EXIT
MOV AH,4ch
INT 21h
main ENDP
END MAIN