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

sum_1 PROC
PUSH BP
MOV BP,SP

MOV AX,[bp+4]
MOV WORD PTR[bp-2],AX
MOV AX,[bp+6]
MOV WORD PTR[bp-4],AX

; s=a+b;


MOV AX,[bp-2]
ADD AX,[bp-4]
MOV WORD PTR[bp-8],AX
MOV AX,[bp-8]
MOV WORD PTR[bp-6],AX

MOV AX,[bp-6]
POP BP
RET
sum_1 ENDP

main PROC
MOV AX, @DATA
MOV DS, AX

; x=10;
MOV WORD PTR[bp-6],10
MOV AX,[bp-6]
MOV WORD PTR[bp-2],AX
; y=12;
MOV WORD PTR[bp-8],12
MOV AX,[bp-8]
MOV WORD PTR[bp-4],AX

; s=sum_1(2*x,y)+sum_1(x,2*y);

PUSH [bp-4]
MOV WORD PTR[bp-12],2

MOV AX,[bp-12]
IMUL WORD PTR[bp-2]
MOV WORD PTR[bp-14],AX
PUSH [bp-14]
CALL sum_1
ADD SP,4
MOV WORD PTR[bp-16],AX
MOV WORD PTR[bp-18],2

MOV AX,[bp-18]
IMUL WORD PTR[bp-4]
MOV WORD PTR[bp-20],AX
PUSH [bp-20]

PUSH [bp-2]
CALL sum_1
ADD SP,4
MOV WORD PTR[bp-22],AX
MOV AX,[bp-16]
ADD AX,[bp-22]
MOV WORD PTR[bp-24],AX
MOV AX,[bp-24]
MOV WORD PTR[bp-10],AX

; printf(s);
MOV AX,[bp-10]
MOV FOR_PRINT,AX
CALL OUTPUT

;DOS EXIT
MOV AH,4ch
INT 21h
main ENDP
END MAIN



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
