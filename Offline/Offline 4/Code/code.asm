.MODEL SMALL

.STACK 100H   

.DATA
IS_NEG DB ?
FOR_PRINT DW ?
MARKER DW 0DH
DIV_RES DW ? 
DIV_REM DW ?
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
    
        MOV DIV_RES , AX
        MOV DIV_REM , DX 
        
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

f PROC
PUSH BP
MOV BP,SP
SUB SP,8

MOV AX,[bp+4]
MOV WORD PTR[bp-2],AX
MOV WORD PTR[bp-4],2

MOV AX,[bp-4]
IMUL WORD PTR[bp-2]
MOV WORD PTR[bp-6],AX
MOV AX,[bp-6]
JMP L_f

; a=9;
MOV WORD PTR[bp-8],9
MOV AX,[bp-8]
MOV WORD PTR[bp-2],AX
L_f:
ADD SP,8
POP BP
RET
f ENDP

g PROC
PUSH BP
MOV BP,SP
SUB SP,12

MOV AX,[bp+4]
MOV WORD PTR[bp-2],AX
MOV AX,[bp+6]
MOV WORD PTR[bp-4],AX

; x=f(a)+a+b;

PUSH [bp-2]
CALL f
ADD SP,2
MOV WORD PTR[bp-8],AX

MOV AX,[bp-8]
ADD AX,[bp-2]
MOV WORD PTR[bp-10],AX

MOV AX,[bp-10]
ADD AX,[bp-4]
MOV WORD PTR[bp-12],AX
MOV AX,[bp-12]
MOV WORD PTR[bp-6],AX

MOV AX,[bp-6]
JMP L_g

L_g:
ADD SP,12
POP BP
RET
g ENDP

main PROC
MOV AX, @DATA
MOV DS, AX
PUSH BP
MOV BP,SP
SUB SP,12

; a=1;
MOV WORD PTR[bp-6],1
MOV AX,[bp-6]
MOV WORD PTR[bp-2],AX
; b=2;
MOV WORD PTR[bp-8],2
MOV AX,[bp-8]
MOV WORD PTR[bp-4],AX
; a=g(a,b);

PUSH [bp-4]

PUSH [bp-2]
CALL g
ADD SP,4
MOV WORD PTR[bp-10],AX
MOV AX,[bp-10]
MOV WORD PTR[bp-2],AX

; printf(a);
MOV AX,[bp-2]
MOV FOR_PRINT,AX
CALL OUTPUT
MOV WORD PTR[bp-12],0
MOV AX,[bp-12]
JMP L_main

L_main:
ADD SP,12
POP BP

;DOS EXIT
MOV AH,4ch
INT 21h
main ENDP
END MAIN


