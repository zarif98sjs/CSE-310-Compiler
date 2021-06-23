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


; sum=0;
MOV WORD PTR[bp-30],0
MOV AX,[bp-30]

MOV WORD PTR[bp-26],AX
; chk=0;
MOV WORD PTR[bp-32],0
MOV AX,[bp-32]

MOV WORD PTR[bp-28],AX
; for(i=1;i<=10;i++){ara[i]=i;sum=sum+i;chk=chk+ara[i];}
MOV WORD PTR[bp-34],1
MOV AX,[bp-34]

MOV WORD PTR[bp-24],AX
L2:
; i<=10;

MOV WORD PTR[bp-36],10
MOV AX,[bp-24]
CMP AX,[bp-36]
jle L0
MOV WORD PTR[bp-38],0
JMP L1
L0:
MOV WORD PTR[bp-38],1
L1:

; check for loop condition
CMP [bp-38],0
JE L3
; ara[i]=i;

MOV AX,[bp-24]

MOV SI,[bp-24]
ADD SI,SI
MOV WORD PTR[bp-22+SI],AX
; sum=sum+i;


MOV AX,[bp-26]
ADD AX,[bp-24]
MOV WORD PTR[bp-40],AX
MOV AX,[bp-40]

MOV WORD PTR[bp-26],AX
; chk=chk+ara[i];


MOV SI,[bp-24]
ADD SI,SI
MOV AX,[bp-28]
ADD AX,[bp-22+SI]
MOV WORD PTR[bp-42],AX
MOV AX,[bp-42]

MOV WORD PTR[bp-28],AX
; i++
INC WORD PTR[bp-24]
JMP L2
L3:


; printf(sum);
MOV AX,[bp-26]
MOV FOR_PRINT,AX
CALL OUTPUT

; printf(chk);
MOV AX,[bp-28]
MOV FOR_PRINT,AX
CALL OUTPUT
MOV AH,4ch
INT 21h
main ENDP



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
