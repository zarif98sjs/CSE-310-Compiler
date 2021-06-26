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
SUB SP,54

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
; ara[2]=3;
MOV WORD PTR[bp-16],3
MOV AX,[bp-16]
MOV WORD PTR[bp-14],2
MOV BX,[bp-14]
ADD BX,BX
MOV ara[BX],AX
; z=x%x_global;


MOV AX,[bp-2]
CWD
IDIV x_global
MOV WORD PTR[bp-18],DX
MOV AX,[bp-18]
MOV WORD PTR[bp-6],AX

; printf(z);
MOV AX,[bp-6]
MOV FOR_PRINT,AX
CALL OUTPUT
; z=x_global%y;


MOV AX,x_global
CWD
IDIV WORD PTR[bp-4]
MOV WORD PTR[bp-20],DX
MOV AX,[bp-20]
MOV WORD PTR[bp-6],AX

; printf(z);
MOV AX,[bp-6]
MOV FOR_PRINT,AX
CALL OUTPUT
; z=x%ara[2];

MOV WORD PTR[bp-22],2
MOV BX,[bp-22]
ADD BX,BX
MOV AX,[bp-2]
CWD
IDIV ara[BX]
MOV WORD PTR[bp-24],DX
MOV AX,[bp-24]
MOV WORD PTR[bp-6],AX

; printf(z);
MOV AX,[bp-6]
MOV FOR_PRINT,AX
CALL OUTPUT
; z=ara[2]%y;
MOV WORD PTR[bp-26],2
MOV BX,[bp-26]
ADD BX,BX

MOV AX,ara[BX]
CWD
IDIV WORD PTR[bp-4]
MOV WORD PTR[bp-28],DX
MOV AX,[bp-28]
MOV WORD PTR[bp-6],AX

; printf(z);
MOV AX,[bp-6]
MOV FOR_PRINT,AX
CALL OUTPUT
; z=x*x_global;


MOV AX,[bp-2]
IMUL x_global
MOV WORD PTR[bp-30],AX
MOV AX,[bp-30]
MOV WORD PTR[bp-6],AX

; printf(z);
MOV AX,[bp-6]
MOV FOR_PRINT,AX
CALL OUTPUT
; z=x_global*y;


MOV AX,x_global
IMUL WORD PTR[bp-4]
MOV WORD PTR[bp-32],AX
MOV AX,[bp-32]
MOV WORD PTR[bp-6],AX

; printf(z);
MOV AX,[bp-6]
MOV FOR_PRINT,AX
CALL OUTPUT
; z=x*ara[2];

MOV WORD PTR[bp-34],2
MOV BX,[bp-34]
ADD BX,BX
MOV AX,[bp-2]
IMUL ara[BX]
MOV WORD PTR[bp-36],AX
MOV AX,[bp-36]
MOV WORD PTR[bp-6],AX

; printf(z);
MOV AX,[bp-6]
MOV FOR_PRINT,AX
CALL OUTPUT
; z=ara[2]*y;
MOV WORD PTR[bp-38],2
MOV BX,[bp-38]
ADD BX,BX

MOV AX,ara[BX]
IMUL WORD PTR[bp-4]
MOV WORD PTR[bp-40],AX
MOV AX,[bp-40]
MOV WORD PTR[bp-6],AX

; printf(z);
MOV AX,[bp-6]
MOV FOR_PRINT,AX
CALL OUTPUT
; z=x/x_global;


MOV AX,[bp-2]
CWD
IDIV x_global
MOV WORD PTR[bp-42],AX
MOV AX,[bp-42]
MOV WORD PTR[bp-6],AX

; printf(z);
MOV AX,[bp-6]
MOV FOR_PRINT,AX
CALL OUTPUT
; z=x_global/y;


MOV AX,x_global
CWD
IDIV WORD PTR[bp-4]
MOV WORD PTR[bp-44],AX
MOV AX,[bp-44]
MOV WORD PTR[bp-6],AX

; printf(z);
MOV AX,[bp-6]
MOV FOR_PRINT,AX
CALL OUTPUT
; z=x/ara[2];

MOV WORD PTR[bp-46],2
MOV BX,[bp-46]
ADD BX,BX
MOV AX,[bp-2]
CWD
IDIV ara[BX]
MOV WORD PTR[bp-48],AX
MOV AX,[bp-48]
MOV WORD PTR[bp-6],AX

; printf(z);
MOV AX,[bp-6]
MOV FOR_PRINT,AX
CALL OUTPUT
; z=ara[2]/y;
MOV WORD PTR[bp-50],2
MOV BX,[bp-50]
ADD BX,BX

MOV AX,ara[BX]
CWD
IDIV WORD PTR[bp-4]
MOV WORD PTR[bp-52],AX
MOV AX,[bp-52]
MOV WORD PTR[bp-6],AX

; printf(z);
MOV AX,[bp-6]
MOV FOR_PRINT,AX
CALL OUTPUT
MOV WORD PTR[bp-54],0
MOV AX,[bp-54]
JMP L_main

L_main:
ADD SP,54
POP BP

;DOS EXIT
MOV AH,4ch
INT 21h
main ENDP
END MAIN


