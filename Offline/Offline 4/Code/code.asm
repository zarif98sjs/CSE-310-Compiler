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
SUB SP,74

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

; a=10;
MOV WORD PTR [bp-24],10
MOV CX,[bp-24]
MOV WORD PTR [bp-18],CX
; b=14;
MOV WORD PTR [bp-26],14
MOV CX,[bp-26]
MOV WORD PTR [bp-20],CX
; c=16;
MOV WORD PTR [bp-28],16
MOV CX,[bp-28]
MOV WORD PTR [bp-22],CX

; x=d[0]-d[1];
MOV WORD PTR [bp-32],0
MOV SI,[bp-32]
ADD SI,SI
MOV AX,[bp-8+SI]
MOV WORD PTR [bp-36],AX
MOV WORD PTR [bp-34],1
MOV SI,[bp-34]
ADD SI,SI
MOV AX,[bp-36]
SUB AX,[bp-8+SI]
MOV WORD PTR [bp-38],AX
MOV CX,[bp-38]
MOV WORD PTR [bp-30],CX

; printf(x);
MOV AX,[bp-30]
MOV FOR_PRINT,AX
CALL OUTPUT
; x=d[0]-d[1]+c;
MOV WORD PTR [bp-40],0
MOV SI,[bp-40]
ADD SI,SI
MOV AX,[bp-8+SI]
MOV WORD PTR [bp-44],AX
MOV WORD PTR [bp-42],1
MOV SI,[bp-42]
ADD SI,SI
MOV AX,[bp-44]
SUB AX,[bp-8+SI]
MOV WORD PTR [bp-46],AX
MOV AX,[bp-46]
MOV WORD PTR [bp-48],AX

MOV AX,[bp-48]
ADD AX,[bp-22]
MOV WORD PTR [bp-46],AX
MOV CX,[bp-46]
MOV WORD PTR [bp-30],CX

; printf(x);
MOV AX,[bp-30]
MOV FOR_PRINT,AX
CALL OUTPUT
; x=a+b+c;

MOV AX,[bp-18]
MOV WORD PTR [bp-50],AX

MOV AX,[bp-50]
ADD AX,[bp-20]
MOV WORD PTR [bp-52],AX
MOV AX,[bp-52]
MOV WORD PTR [bp-54],AX

MOV AX,[bp-54]
ADD AX,[bp-22]
MOV WORD PTR [bp-52],AX
MOV CX,[bp-52]
MOV WORD PTR [bp-30],CX

; printf(x);
MOV AX,[bp-30]
MOV FOR_PRINT,AX
CALL OUTPUT
; x=d[0]-c-d[1];
MOV WORD PTR [bp-56],0
MOV SI,[bp-56]
ADD SI,SI
MOV AX,[bp-8+SI]
MOV WORD PTR [bp-58],AX

MOV AX,[bp-58]
SUB AX,[bp-22]
MOV WORD PTR [bp-60],AX
MOV AX,[bp-60]
MOV WORD PTR [bp-64],AX
MOV WORD PTR [bp-62],1
MOV SI,[bp-62]
ADD SI,SI
MOV AX,[bp-64]
SUB AX,[bp-8+SI]
MOV WORD PTR [bp-60],AX
MOV CX,[bp-60]
MOV WORD PTR [bp-30],CX

; printf(x);
MOV AX,[bp-30]
MOV FOR_PRINT,AX
CALL OUTPUT
; x=d[0]-d[1];
MOV WORD PTR [bp-66],0
MOV SI,[bp-66]
ADD SI,SI
MOV AX,[bp-8+SI]
MOV WORD PTR [bp-70],AX
MOV WORD PTR [bp-68],1
MOV SI,[bp-68]
ADD SI,SI
MOV AX,[bp-70]
SUB AX,[bp-8+SI]
MOV WORD PTR [bp-72],AX
MOV CX,[bp-72]
MOV WORD PTR [bp-30],CX

; printf(x);
MOV AX,[bp-30]
MOV FOR_PRINT,AX
CALL OUTPUT
; return 0;
MOV WORD PTR [bp-74],0
MOV AX,[bp-74]
JMP L_main

L_main:
ADD SP,74
POP BP

;DOS EXIT
MOV AH,4ch
INT 21h
main ENDP
END MAIN


