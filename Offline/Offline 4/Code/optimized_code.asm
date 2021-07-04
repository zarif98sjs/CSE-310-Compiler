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



main PROC
MOV AX, @DATA
MOV DS, AX
PUSH BP
MOV BP,SP
SUB SP,60
; d[0]=20;
MOV WORD PTR [bp-12],20
MOV CX,[bp-12]
MOV WORD PTR [bp-10],0
MOV SI,[bp-10]
ADD SI,SI
MOV WORD PTR [bp-8+SI],CX
; d[1]=40;
MOV WORD PTR [bp-16],40
MOV CX,[bp-16]
MOV WORD PTR [bp-14],1
MOV SI,[bp-14]
ADD SI,SI
MOV WORD PTR [bp-8+SI],CX
; x=d[0]+d[1];
MOV WORD PTR [bp-20],0
MOV SI,[bp-20]
ADD SI,SI
MOV AX,[bp-8+SI]
MOV WORD PTR [bp-24],AX
MOV WORD PTR [bp-22],1
MOV SI,[bp-22]
ADD SI,SI
MOV AX,[bp-24]
ADD AX,[bp-8+SI]
MOV WORD PTR [bp-26],AX
MOV CX,[bp-26]
MOV WORD PTR [bp-18],CX
; printf(x);
MOV AX,[bp-18]
MOV FOR_PRINT,AX
CALL OUTPUT
; x=d[0]-d[1];
MOV WORD PTR [bp-28],0
MOV SI,[bp-28]
ADD SI,SI
MOV AX,[bp-8+SI]
MOV WORD PTR [bp-32],AX
MOV WORD PTR [bp-30],1
MOV SI,[bp-30]
ADD SI,SI
MOV AX,[bp-32]
SUB AX,[bp-8+SI]
MOV WORD PTR [bp-34],AX
MOV CX,[bp-34]
MOV WORD PTR [bp-18],CX
; printf(x);
MOV AX,[bp-18]
MOV FOR_PRINT,AX
CALL OUTPUT
; x=d[0]*d[1];
MOV WORD PTR [bp-36],0
MOV SI,[bp-36]
ADD SI,SI
MOV CX,[bp-8+SI]
MOV WORD PTR [bp-40],CX
MOV WORD PTR [bp-38],1
MOV SI,[bp-38]
ADD SI,SI
MOV CX,[bp-40]
MOV AX,CX
IMUL WORD PTR [bp-8+SI]
MOV WORD PTR [bp-42],AX
MOV CX,[bp-42]
MOV WORD PTR [bp-18],CX
; printf(x);
MOV AX,[bp-18]
MOV FOR_PRINT,AX
CALL OUTPUT
; x=d[0]/d[1];
MOV WORD PTR [bp-44],0
MOV SI,[bp-44]
ADD SI,SI
MOV CX,[bp-8+SI]
CWD
MOV WORD PTR [bp-48],CX
MOV WORD PTR [bp-46],1
MOV SI,[bp-46]
ADD SI,SI
MOV CX,[bp-48]
MOV AX,CX
IDIV WORD PTR [bp-8+SI]
MOV WORD PTR [bp-50],AX
MOV CX,[bp-50]
MOV WORD PTR [bp-18],CX
; printf(x);
MOV AX,[bp-18]
MOV FOR_PRINT,AX
CALL OUTPUT
; x=d[0]%d[1];
MOV WORD PTR [bp-52],0
MOV SI,[bp-52]
ADD SI,SI
MOV CX,[bp-8+SI]
CWD
MOV WORD PTR [bp-56],CX
MOV WORD PTR [bp-54],1
MOV SI,[bp-54]
ADD SI,SI
MOV CX,[bp-56]
MOV AX,CX
IDIV WORD PTR [bp-8+SI]
MOV WORD PTR [bp-58],DX
MOV CX,[bp-58]
MOV WORD PTR [bp-18],CX
; printf(x);
MOV AX,[bp-18]
MOV FOR_PRINT,AX
CALL OUTPUT
; return 0;
MOV WORD PTR [bp-60],0
MOV AX,[bp-60]
JMP L_main
L_main:
ADD SP,60
POP BP
;DOS EXIT
MOV AH,4ch
INT 21h
main ENDP
END MAIN
