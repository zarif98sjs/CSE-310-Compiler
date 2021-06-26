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
x_global dw ?
ara dw 10 dup ($)

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

main PROC
MOV AX, @DATA
MOV DS, AX
PUSH BP
MOV BP,SP
SUB SP,36

; x=31;
MOV WORD PTR[bp-8],31
MOV AX,[bp-8]
MOV WORD PTR[bp-2],AX
; y=55;
MOV WORD PTR[bp-10],55
MOV AX,[bp-10]
MOV WORD PTR[bp-4],AX
; x_global=3;
MOV WORD PTR[bp-12],3
MOV AX,[bp-12]
MOV x_global,AX
; ara[2]=12;
MOV WORD PTR[bp-16],12
MOV AX,[bp-16]
MOV WORD PTR[bp-14],2
MOV BX,[bp-14]
ADD BX,BX
MOV ara[BX],AX

MOV WORD PTR[bp-18],2
MOV BX,[bp-18]
ADD BX,BX
MOV AX,x_global
CMP AX,ara[BX]
jg L0
MOV WORD PTR[bp-20],0
JMP L1
L0:
MOV WORD PTR[bp-20],1
L1:

CMP [bp-20],0
JE L2
; x_global=x_global-1;

MOV WORD PTR[bp-22],1
MOV AX,x_global
SUB AX,[bp-22]
MOV WORD PTR[bp-24],AX
MOV AX,[bp-24]
MOV x_global,AX
JMP L3
L2:; ara[2]=ara[2]-1;
MOV WORD PTR[bp-28],2
MOV BX,[bp-28]
ADD BX,BX
MOV WORD PTR[bp-30],1
MOV AX,ara[BX]
SUB AX,[bp-30]
MOV WORD PTR[bp-32],AX
MOV AX,[bp-32]
MOV WORD PTR[bp-26],2
MOV BX,[bp-26]
ADD BX,BX
MOV ara[BX],AX
L3:

; printf(x_global);
MOV AX,x_global
MOV FOR_PRINT,AX
CALL OUTPUT

; printf(ara[2]);
MOV WORD PTR[bp-34],2
MOV BX,[bp-34]
ADD BX,BX
MOV AX,ara[BX]
MOV FOR_PRINT,AX
CALL OUTPUT
MOV WORD PTR[bp-36],0
MOV AX,[bp-36]
JMP L_main

L_main:
ADD SP,36
POP BP

;DOS EXIT
MOV AH,4ch
INT 21h
main ENDP
END MAIN


