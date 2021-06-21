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

main PROC
MOV AX, @DATA
MOV DS, AX

; b=0;
MOV WORD PTR[bp-10],0
MOV AX,[bp-10]
MOV WORD PTR[bp-4],AX
; c=1;
MOV WORD PTR[bp-12],1
MOV AX,[bp-12]
MOV WORD PTR[bp-6],AX
; for(i=0;i<4;i++){a=3;while(a--){b++;}}
MOV WORD PTR[bp-14],0
MOV AX,[bp-14]
MOV WORD PTR[bp-8],AX
L4:
; i<4;

MOV WORD PTR[bp-16],4
MOV AX,[bp-8]
CMP AX,[bp-16]
jl L0
MOV WORD PTR[bp-18],0
JMP L1
L0:
MOV WORD PTR[bp-18],1
L1:

; check for loop condition
CMP [bp-18],0
JE L5
; a=3;
MOV WORD PTR[bp-20],3
MOV AX,[bp-20]
MOV WORD PTR[bp-2],AX
; while(a--){b++;}
L2:
; a--
DEC WORD PTR[bp-2]
; check while loop condition
CMP [bp-2],0
JE L3
; b++;
INC WORD PTR[bp-4]
JMP L2
L3:

; i++
INC WORD PTR[bp-8]
JMP L4
L5:


; printf(a);
MOV AX,[bp-2]
MOV FOR_PRINT,AX
CALL OUTPUT

; printf(b);
MOV AX,[bp-4]
MOV FOR_PRINT,AX
CALL OUTPUT

; printf(c);
MOV AX,[bp-6]
MOV FOR_PRINT,AX
CALL OUTPUT
MOV AH,4ch
INT 21h
main ENDP


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

        LEA DX, NEWLINE
        MOV AH, 9 
        INT 21H
    
        RET     
      
OUTPUT ENDP
