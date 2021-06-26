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

; x=12;
MOV WORD PTR[bp-6],12
MOV AX,[bp-6]
MOV WORD PTR[bp-2],AX
; y=13;
MOV WORD PTR[bp-8],13
MOV AX,[bp-8]
MOV WORD PTR[bp-4],AX

; ara[2]=7;
MOV WORD PTR[bp-14],7
MOV AX,[bp-14]
MOV WORD PTR[bp-12],2
MOV BX,[bp-12]
ADD BX,BX
MOV ara[BX],AX
; x_global=x+ara[2]+y+ara[2];

MOV WORD PTR[bp-16],2
MOV BX,[bp-16]
ADD BX,BX
MOV AX,[bp-2]
ADD AX,ara[BX]
MOV WORD PTR[bp-18],AX

MOV AX,[bp-18]
ADD AX,[bp-4]
MOV WORD PTR[bp-20],AX
MOV WORD PTR[bp-22],2
MOV BX,[bp-22]
ADD BX,BX
MOV AX,[bp-20]
ADD AX,ara[BX]
MOV WORD PTR[bp-24],AX
MOV AX,[bp-24]
MOV x_global,AX

; printf(x_global);
MOV AX,x_global
MOV FOR_PRINT,AX
CALL OUTPUT
; ara[3]=12+2;
MOV WORD PTR[bp-28],12
MOV WORD PTR[bp-30],2
MOV AX,[bp-28]
ADD AX,[bp-30]
MOV WORD PTR[bp-32],AX
MOV AX,[bp-32]
MOV WORD PTR[bp-26],3
MOV BX,[bp-26]
ADD BX,BX
MOV ara[BX],AX

; printf(ara[3]);
MOV WORD PTR[bp-34],3
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


