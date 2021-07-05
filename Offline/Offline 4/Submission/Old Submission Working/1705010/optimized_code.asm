.MODEL SMALL

.STACK 100H
.DATA
IS_NEG DB ?
FOR_PRINT DW ?
CR EQU 0DH
LF EQU 0AH
NEWLINE DB CR, LF , '$'
count dw ?

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



f2 PROC
PUSH BP
MOV BP,SP
SUB SP,8
MOV AX,[bp+4]
MOV WORD PTR [bp-2],AX
MOV AX,[bp+6]
MOV WORD PTR [bp-4],AX
; return a*b;
MOV CX,[bp-2]
MOV WORD PTR [bp-6],CX
MOV AX,CX
IMUL WORD PTR [bp-4]
MOV WORD PTR [bp-8],AX
JMP L_f2
L_f2:
ADD SP,8
POP BP
RET
f2 ENDP

f4 PROC
PUSH BP
MOV BP,SP
SUB SP,14
MOV AX,[bp+4]
MOV WORD PTR [bp-2],AX
MOV AX,[bp+6]
MOV WORD PTR [bp-4],AX
MOV AX,[bp+8]
MOV WORD PTR [bp-6],AX
MOV AX,[bp+10]
MOV WORD PTR [bp-8],AX
; return f2(f2(a,b),f2(c,d));
PUSH [bp-8]
PUSH [bp-6]
CALL f2
ADD SP,4
MOV WORD PTR [bp-12],AX
PUSH [bp-12]
PUSH [bp-4]
PUSH [bp-2]
CALL f2
ADD SP,4
MOV WORD PTR [bp-10],AX
PUSH [bp-10]
CALL f2
ADD SP,4
MOV WORD PTR [bp-14],AX
JMP L_f4
L_f4:
ADD SP,14
POP BP
RET
f4 ENDP

show PROC
PUSH BP
MOV BP,SP
SUB SP,4
MOV AX,[bp+4]
MOV WORD PTR [bp-2],AX
; count++;
MOV AX,count
MOV WORD PTR [bp-4],AX
INC count
; printf(n);
MOV AX,[bp-2]
MOV FOR_PRINT,AX
CALL OUTPUT
L_show:
ADD SP,4
POP BP
RET
show ENDP

main PROC
MOV AX, @DATA
MOV DS, AX
PUSH BP
MOV BP,SP
SUB SP,76
; i=0;
MOV WORD PTR [bp-12],0
MOV CX,[bp-12]
MOV WORD PTR [bp-10],CX
; for(i=0;i<4;i++){d[3-i]=(i+1)*10;}
MOV WORD PTR [bp-14],0
MOV CX,[bp-14]
MOV WORD PTR [bp-10],CX
L2:
; i<4;
MOV WORD PTR [bp-16],4
MOV AX,[bp-10]
CMP AX,[bp-16]
jl L0
MOV WORD PTR [bp-18],0
JMP L1
L0:
MOV WORD PTR [bp-18],1
L1:
; check for loop condition
CMP [bp-18],0
JE L3
; d[3-i]=(i+1)*10;
MOV AX,[bp-10]
MOV WORD PTR [bp-30],AX
MOV WORD PTR [bp-28],1
MOV AX,[bp-30]
ADD AX,[bp-28]
MOV WORD PTR [bp-32],AX
MOV CX,[bp-32]
MOV WORD PTR [bp-36],CX
MOV WORD PTR [bp-34],10
MOV CX,[bp-36]
MOV AX,CX
IMUL WORD PTR [bp-34]
MOV WORD PTR [bp-38],AX
MOV CX,[bp-38]
MOV WORD PTR [bp-22],3
MOV AX,[bp-22]
MOV WORD PTR [bp-24],AX
SUB AX,[bp-10]
MOV WORD PTR [bp-26],AX
MOV SI,[bp-26]
ADD SI,SI
MOV WORD PTR [bp-8+SI],CX
; i++
MOV AX,[bp-10]
MOV WORD PTR [bp-20],AX
INC WORD PTR [bp-10]
JMP L2
L3:
; i=0;
MOV WORD PTR [bp-40],0
MOV CX,[bp-40]
MOV WORD PTR [bp-10],CX
; while(i<4){show(d[i]/5);i++;}
L6:
; i<4
MOV WORD PTR [bp-42],4
MOV AX,[bp-10]
CMP AX,[bp-42]
jl L4
MOV WORD PTR [bp-44],0
JMP L5
L4:
MOV WORD PTR [bp-44],1
L5:
; check while loop condition
CMP [bp-44],0
JE L7
; show(d[i]/5);
MOV SI,[bp-10]
ADD SI,SI
MOV CX,[bp-8+SI]
CWD
MOV WORD PTR [bp-48],CX
MOV WORD PTR [bp-46],5
MOV CX,[bp-48]
MOV AX,CX
IDIV WORD PTR [bp-46]
MOV WORD PTR [bp-50],AX
PUSH [bp-50]
CALL show
ADD SP,2
; i++;
MOV AX,[bp-10]
MOV WORD PTR [bp-52],AX
INC WORD PTR [bp-10]
JMP L6
L7:
; md=d[0]%d[1];
MOV WORD PTR [bp-56],0
MOV SI,[bp-56]
ADD SI,SI
MOV CX,[bp-8+SI]
CWD
MOV WORD PTR [bp-60],CX
MOV WORD PTR [bp-58],1
MOV SI,[bp-58]
ADD SI,SI
MOV CX,[bp-60]
MOV AX,CX
IDIV WORD PTR [bp-8+SI]
MOV WORD PTR [bp-62],DX
MOV CX,[bp-62]
MOV WORD PTR [bp-54],CX
; show(md);
PUSH [bp-54]
CALL show
ADD SP,2
; show(count);
PUSH count
CALL show
ADD SP,2
; g=f4(2,3,4,5);
MOV WORD PTR [bp-72],5
PUSH [bp-72]
MOV WORD PTR [bp-70],4
PUSH [bp-70]
MOV WORD PTR [bp-68],3
PUSH [bp-68]
MOV WORD PTR [bp-66],2
PUSH [bp-66]
CALL f4
ADD SP,8
MOV WORD PTR [bp-74],AX
MOV CX,[bp-74]
MOV WORD PTR [bp-64],CX
; printf(g);
MOV AX,[bp-64]
MOV FOR_PRINT,AX
CALL OUTPUT
; return 0;
MOV WORD PTR [bp-76],0
MOV AX,[bp-76]
JMP L_main
L_main:
ADD SP,76
POP BP
;DOS EXIT
MOV AH,4ch
INT 21h
main ENDP
END MAIN
