.MODEL SMALL

.STACK 100H
.DATA
IS_NEG DB ?
FOR_PRINT DW ?
CR EQU 0DH
LF EQU 0AH
NEWLINE DB CR, LF , '$'
ar dw 10 dup ($)

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



f PROC
PUSH BP
MOV BP,SP
SUB SP,26
; x[2]=20;
MOV WORD PTR [bp-24],20
MOV CX,[bp-24]
MOV WORD PTR [bp-22],2
MOV SI,[bp-22]
ADD SI,SI
MOV WORD PTR [bp-20+SI],CX
MOV WORD PTR [bp-26],2
MOV SI,[bp-26]
ADD SI,SI
MOV AX,[bp-20+SI]
JMP L_f
L_f:
ADD SP,26
POP BP
RET
f ENDP

main PROC
MOV AX, @DATA
MOV DS, AX
PUSH BP
MOV BP,SP
SUB SP,12
; ar[2]=3;
MOV WORD PTR [bp-4],3
MOV CX,[bp-4]
MOV WORD PTR [bp-2],2
MOV BX,[bp-2]
ADD BX,BX
MOV ar[BX],CX
; printf(ar[2]);
MOV WORD PTR [bp-6],2
MOV BX,[bp-6]
ADD BX,BX
MOV AX,ar[BX]
MOV FOR_PRINT,AX
CALL OUTPUT
; re=f();
CALL f
ADD SP,0
MOV WORD PTR [bp-10],AX
MOV CX,[bp-10]
MOV WORD PTR [bp-8],CX
; printf(re);
MOV AX,[bp-8]
MOV FOR_PRINT,AX
CALL OUTPUT
MOV WORD PTR [bp-12],0
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
