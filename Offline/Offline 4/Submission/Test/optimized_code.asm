.MODEL SMALL

.STACK 100H
.DATA
IS_NEG DB ?
FOR_PRINT DW ?
CR EQU 0DH
LF EQU 0AH
NEWLINE DB CR, LF , '$'
save dw 7 dup ($)

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



fibo PROC
PUSH BP
MOV BP,SP
SUB SP,36
MOV AX,[bp+4]
MOV WORD PTR [bp-2],AX
; if(save[n]!=-1){return save[n];}else if(n<=1){save[n]=n;return save[n];}else {save[n]=fibo(n-1)+fibo(n-2);return save[n];}
MOV BX,[bp-2]
ADD BX,BX
MOV WORD PTR [bp-4],1
NEG WORD PTR [bp-4]
MOV AX,save[BX]
CMP AX,[bp-4]
jne L0
MOV WORD PTR [bp-6],0
JMP L1
L0:
MOV WORD PTR [bp-6],1
L1:
CMP [bp-6],0
JE L6
MOV AX,[bp+4]
MOV WORD PTR [bp-8],AX
; return save[n];
MOV BX,[bp-8]
ADD BX,BX
MOV AX,save[BX]
JMP L_fibo
JMP L7
L6:
; if(n<=1){save[n]=n;return save[n];}else {save[n]=fibo(n-1)+fibo(n-2);return save[n];}
MOV WORD PTR [bp-10],1
MOV AX,[bp-2]
CMP AX,[bp-10]
jle L2
MOV WORD PTR [bp-12],0
JMP L3
L2:
MOV WORD PTR [bp-12],1
L3:
CMP [bp-12],0
JE L4
MOV AX,[bp+4]
MOV WORD PTR [bp-14],AX
; save[n]=n;
MOV CX,[bp-14]
MOV BX,[bp-14]
ADD BX,BX
MOV save[BX],CX
; return save[n];
MOV BX,[bp-14]
ADD BX,BX
MOV AX,save[BX]
JMP L_fibo
JMP L5
L4:
MOV AX,[bp+4]
MOV WORD PTR [bp-16],AX
; save[n]=fibo(n-1)+fibo(n-2);
MOV WORD PTR [bp-20],AX
MOV WORD PTR [bp-18],1
MOV AX,[bp-20]
SUB AX,[bp-18]
MOV WORD PTR [bp-22],AX
PUSH [bp-22]
CALL fibo
ADD SP,2
MOV WORD PTR [bp-24],AX
MOV WORD PTR [bp-34],AX
MOV AX,[bp-16]
MOV WORD PTR [bp-28],AX
MOV WORD PTR [bp-26],2
MOV AX,[bp-28]
SUB AX,[bp-26]
MOV WORD PTR [bp-30],AX
PUSH [bp-30]
CALL fibo
ADD SP,2
MOV WORD PTR [bp-32],AX
MOV AX,[bp-34]
ADD AX,[bp-32]
MOV WORD PTR [bp-36],AX
MOV CX,[bp-36]
MOV BX,[bp-16]
ADD BX,BX
MOV save[BX],CX
; return save[n];
MOV BX,[bp-16]
ADD BX,BX
MOV AX,save[BX]
JMP L_fibo
L5:
L7:
L_fibo:
ADD SP,36
POP BP
RET
fibo ENDP

main PROC
MOV AX, @DATA
MOV DS, AX
PUSH BP
MOV BP,SP
SUB SP,28
; i=0;
MOV WORD PTR [bp-4],0
MOV CX,[bp-4]
MOV WORD PTR [bp-2],CX
; for(i=0;i<=6;i++){save[i]=-1;}
MOV WORD PTR [bp-6],0
MOV CX,[bp-6]
MOV WORD PTR [bp-2],CX
L10:
; i<=6;
MOV WORD PTR [bp-8],6
MOV AX,[bp-2]
CMP AX,[bp-8]
jle L8
MOV WORD PTR [bp-10],0
JMP L9
L8:
MOV WORD PTR [bp-10],1
L9:
; check for loop condition
CMP [bp-10],0
JE L11
; save[i]=-1;
MOV WORD PTR [bp-14],1
NEG WORD PTR [bp-14]
MOV CX,[bp-14]
MOV BX,[bp-2]
ADD BX,BX
MOV save[BX],CX
; i++
MOV AX,[bp-2]
MOV WORD PTR [bp-12],AX
INC WORD PTR [bp-2]
JMP L10
L11:
; for(i=6;i>-1;i--){pr=fibo(i);printf(pr);}
MOV WORD PTR [bp-18],6
MOV CX,[bp-18]
MOV WORD PTR [bp-2],CX
L14:
; i>-1;
MOV WORD PTR [bp-20],1
NEG WORD PTR [bp-20]
MOV AX,[bp-2]
CMP AX,[bp-20]
jg L12
MOV WORD PTR [bp-22],0
JMP L13
L12:
MOV WORD PTR [bp-22],1
L13:
; check for loop condition
CMP [bp-22],0
JE L15
; pr=fibo(i);
PUSH [bp-2]
CALL fibo
ADD SP,2
MOV WORD PTR [bp-26],AX
MOV CX,[bp-26]
MOV WORD PTR [bp-16],CX
; printf(pr);
MOV AX,[bp-16]
MOV FOR_PRINT,AX
CALL OUTPUT
; i--
MOV AX,[bp-2]
MOV WORD PTR [bp-24],AX
DEC WORD PTR [bp-2]
JMP L14
L15:
; return 0;
MOV WORD PTR [bp-28],0
MOV AX,[bp-28]
JMP L_main
L_main:
ADD SP,28
POP BP
;DOS EXIT
MOV AH,4ch
INT 21h
main ENDP
END MAIN
