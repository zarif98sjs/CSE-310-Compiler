.MODEL SMALL

.STACK 100H   

.DATA
IS_NEG DB ?
FOR_PRINT DW ?
MARKER DW 0DH
DIV_RES DW ? 
DIV_REM DW ?
a dw ?
b dw ?
c dw ?
i dw ?
t0 dw ?
t1 dw ?
t2 dw ?
t3 dw ?
t4 dw ?
t5 dw ?

.CODE
MAIN PROC
MOV AX, @DATA 
MOV DS, AX


; b=0;
MOV t0,0
MOV AX,t0
MOV b,AX
; c=1;
MOV t1,1
MOV AX,t1
MOV c,AX
; for(i=0;i<4;i++){a=3;while(a--){b++;}}
MOV t2,0
MOV AX,t2
MOV i,AX
L4:
; i<4;

MOV t3,4
MOV AX,i
CMP AX,t3
jl L0
MOV t4,0
JMP L1
L0:
MOV t4,1
L1:

; check for loop condition
CMP t4,0
JE L5
; a=3;
MOV t5,3
MOV AX,t5
MOV a,AX
; while(a--){b++;}
L2:
; a--
DEC a
; check while loop condition
CMP a,0
JE L3
; b++;
INC b
JMP L2
L3:

; i++
INC i
JMP L4
L5:


; printf(a);
MOV AX,a
MOV FOR_PRINT,AX
CALL OUTPUT

; printf(b);
MOV AX,b
MOV FOR_PRINT,AX
CALL OUTPUT

; printf(c);
MOV AX,c
MOV FOR_PRINT,AX
CALL OUTPUT

MOV AH,4ch 
INT 21h
MAIN ENDP

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
    
        RET     
      
OUTPUT ENDP
