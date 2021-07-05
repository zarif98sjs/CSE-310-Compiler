.MODEL SMALL

.STACK 100H
.DATA
IS_NEG DB ?
FOR_PRINT DW ?
CR EQU 0DH
LF EQU 0AH
NEWLINE DB CR, LF , '$'
arr dw 6 dup ($)
leftArr dw 6 dup ($)
rightArr dw 6 dup ($)

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

merge PROC
PUSH BP
MOV BP,SP
SUB SP,116

MOV AX,[bp+4]
MOV WORD PTR [bp-2],AX
MOV AX,[bp+6]
MOV WORD PTR [bp-4],AX
MOV AX,[bp+8]
MOV WORD PTR [bp-6],AX

; len1=mid-start+1;

MOV AX,[bp-4]
MOV WORD PTR [bp-10],AX

MOV AX,[bp-10]
SUB AX,[bp-2]
MOV WORD PTR [bp-12],AX
MOV AX,[bp-12]
MOV WORD PTR [bp-16],AX
MOV WORD PTR [bp-14],1
MOV AX,[bp-16]
ADD AX,[bp-14]
MOV WORD PTR [bp-18],AX
MOV CX,[bp-18]
MOV WORD PTR [bp-8],CX

; len2=end-mid;

MOV AX,[bp-6]
MOV WORD PTR [bp-22],AX

MOV AX,[bp-22]
SUB AX,[bp-4]
MOV WORD PTR [bp-24],AX
MOV CX,[bp-24]
MOV WORD PTR [bp-20],CX

; for(i=0;i<len1;i++)leftArr[i]=arr[start+i];
MOV WORD PTR [bp-28],0
MOV CX,[bp-28]
MOV WORD PTR [bp-26],CX
L2:
; i<len1;


MOV AX,[bp-26]
CMP AX,[bp-8]
jl L0
MOV WORD PTR [bp-30],0
JMP L1
L0:
MOV WORD PTR [bp-30],1
L1:

; check for loop condition
CMP [bp-30],0
JE L3
; leftArr[i]=arr[start+i];

MOV AX,[bp-2]
MOV WORD PTR [bp-34],AX

MOV AX,[bp-34]
ADD AX,[bp-26]
MOV WORD PTR [bp-36],AX
MOV BX,[bp-36]
ADD BX,BX
MOV CX,arr[BX]

MOV BX,[bp-26]
ADD BX,BX
MOV leftArr[BX],CX
; i++

MOV AX,[bp-26]
MOV WORD PTR [bp-32],AX
INC WORD PTR [bp-26]
JMP L2
L3:


; for(j=0;j<len2;j++)rightArr[j]=arr[mid+1+j];
MOV WORD PTR [bp-40],0
MOV CX,[bp-40]
MOV WORD PTR [bp-38],CX
L6:
; j<len2;


MOV AX,[bp-38]
CMP AX,[bp-20]
jl L4
MOV WORD PTR [bp-42],0
JMP L5
L4:
MOV WORD PTR [bp-42],1
L5:

; check for loop condition
CMP [bp-42],0
JE L7
; rightArr[j]=arr[mid+1+j];

MOV AX,[bp-4]
MOV WORD PTR [bp-48],AX
MOV WORD PTR [bp-46],1
MOV AX,[bp-48]
ADD AX,[bp-46]
MOV WORD PTR [bp-50],AX
MOV AX,[bp-50]
MOV WORD PTR [bp-52],AX

MOV AX,[bp-52]
ADD AX,[bp-38]
MOV WORD PTR [bp-54],AX
MOV BX,[bp-54]
ADD BX,BX
MOV CX,arr[BX]

MOV BX,[bp-38]
ADD BX,BX
MOV rightArr[BX],CX
; j++

MOV AX,[bp-38]
MOV WORD PTR [bp-44],AX
INC WORD PTR [bp-38]
JMP L6
L7:


; i=0;
MOV WORD PTR [bp-58],0
MOV CX,[bp-58]
MOV WORD PTR [bp-26],CX
; j=0;
MOV WORD PTR [bp-60],0
MOV CX,[bp-60]
MOV WORD PTR [bp-38],CX
; k=start;

MOV CX,[bp-2]
MOV WORD PTR [bp-56],CX
; while(i<len1&&j<len2){if(leftArr[i]<=rightArr[j]){arr[k]=leftArr[i];i++;}else {arr[k]=rightArr[j];j++;}k++;}
L18:
; i<len1&&j<len2


MOV AX,[bp-26]
CMP AX,[bp-8]
jl L8
MOV WORD PTR [bp-62],0
JMP L9
L8:
MOV WORD PTR [bp-62],1
L9:



MOV AX,[bp-38]
CMP AX,[bp-20]
jl L10
MOV WORD PTR [bp-64],0
JMP L11
L10:
MOV WORD PTR [bp-64],1
L11:

CMP [bp-62],0
JE L12
CMP [bp-64],0
JE L12
MOV WORD PTR [bp-66],1
JMP L13
L12:
MOV WORD PTR [bp-66],0
L13:

; check while loop condition
CMP [bp-66],0
JE L19
MOV AX,[bp+4]
MOV WORD PTR [bp-68],AX
MOV AX,[bp+6]
MOV WORD PTR [bp-70],AX
MOV AX,[bp+8]
MOV WORD PTR [bp-72],AX
; if(leftArr[i]<=rightArr[j]){arr[k]=leftArr[i];i++;}else {arr[k]=rightArr[j];j++;}

MOV BX,[bp-26]
ADD BX,BX

MOV BX,[bp-38]
ADD BX,BX
MOV AX,leftArr[BX]
CMP AX,rightArr[BX]
jle L14
MOV WORD PTR [bp-74],0
JMP L15
L14:
MOV WORD PTR [bp-74],1
L15:

CMP [bp-74],0
JE L16
MOV AX,[bp+4]
MOV WORD PTR [bp-76],AX
MOV AX,[bp+6]
MOV WORD PTR [bp-78],AX
MOV AX,[bp+8]
MOV WORD PTR [bp-80],AX
; arr[k]=leftArr[i];

MOV BX,[bp-26]
ADD BX,BX
MOV CX,leftArr[BX]

MOV BX,[bp-56]
ADD BX,BX
MOV arr[BX],CX
; i++;

MOV AX,[bp-26]
MOV WORD PTR [bp-82],AX
INC WORD PTR [bp-26]
JMP L17
L16:
MOV AX,[bp+4]
MOV WORD PTR [bp-84],AX
MOV AX,[bp+6]
MOV WORD PTR [bp-86],AX
MOV AX,[bp+8]
MOV WORD PTR [bp-88],AX
; arr[k]=rightArr[j];

MOV BX,[bp-38]
ADD BX,BX
MOV CX,rightArr[BX]

MOV BX,[bp-56]
ADD BX,BX
MOV arr[BX],CX
; j++;

MOV AX,[bp-38]
MOV WORD PTR [bp-90],AX
INC WORD PTR [bp-38]
L17:

; k++;

MOV AX,[bp-56]
MOV WORD PTR [bp-92],AX
INC WORD PTR [bp-56]
JMP L18
L19:

; while(i<len1){arr[k]=leftArr[i];i++;k++;}
L22:
; i<len1


MOV AX,[bp-26]
CMP AX,[bp-8]
jl L20
MOV WORD PTR [bp-94],0
JMP L21
L20:
MOV WORD PTR [bp-94],1
L21:

; check while loop condition
CMP [bp-94],0
JE L23
MOV AX,[bp+4]
MOV WORD PTR [bp-96],AX
MOV AX,[bp+6]
MOV WORD PTR [bp-98],AX
MOV AX,[bp+8]
MOV WORD PTR [bp-100],AX
; arr[k]=leftArr[i];

MOV BX,[bp-26]
ADD BX,BX
MOV CX,leftArr[BX]

MOV BX,[bp-56]
ADD BX,BX
MOV arr[BX],CX
; i++;

MOV AX,[bp-26]
MOV WORD PTR [bp-102],AX
INC WORD PTR [bp-26]
; k++;

MOV AX,[bp-56]
MOV WORD PTR [bp-104],AX
INC WORD PTR [bp-56]
JMP L22
L23:

; while(j<len2){arr[k]=rightArr[j];j++;k++;}
L26:
; j<len2


MOV AX,[bp-38]
CMP AX,[bp-20]
jl L24
MOV WORD PTR [bp-106],0
JMP L25
L24:
MOV WORD PTR [bp-106],1
L25:

; check while loop condition
CMP [bp-106],0
JE L27
MOV AX,[bp+4]
MOV WORD PTR [bp-108],AX
MOV AX,[bp+6]
MOV WORD PTR [bp-110],AX
MOV AX,[bp+8]
MOV WORD PTR [bp-112],AX
; arr[k]=rightArr[j];

MOV BX,[bp-38]
ADD BX,BX
MOV CX,rightArr[BX]

MOV BX,[bp-56]
ADD BX,BX
MOV arr[BX],CX
; j++;

MOV AX,[bp-38]
MOV WORD PTR [bp-114],AX
INC WORD PTR [bp-38]
; k++;

MOV AX,[bp-56]
MOV WORD PTR [bp-116],AX
INC WORD PTR [bp-56]
JMP L26
L27:

L_merge:
ADD SP,116
POP BP
RET
merge ENDP

mergeSort PROC
PUSH BP
MOV BP,SP
SUB SP,32

MOV AX,[bp+4]
MOV WORD PTR [bp-2],AX
MOV AX,[bp+6]
MOV WORD PTR [bp-4],AX
; if(start<end){int mid;mid=start+(end-start)/2;mergeSort(start,mid);mergeSort(mid+1,end);merge(start,mid,end);}


MOV AX,[bp-2]
CMP AX,[bp-4]
jl L28
MOV WORD PTR [bp-6],0
JMP L29
L28:
MOV WORD PTR [bp-6],1
L29:

CMP [bp-6],0
JE L30
MOV AX,[bp+4]
MOV WORD PTR [bp-8],AX
MOV AX,[bp+6]
MOV WORD PTR [bp-10],AX

; mid=start+(end-start)/2;

MOV AX,[bp-8]
MOV WORD PTR [bp-24],AX

MOV AX,[bp-10]
MOV WORD PTR [bp-14],AX

MOV AX,[bp-14]
SUB AX,[bp-8]
MOV WORD PTR [bp-16],AX
MOV CX,[bp-16]
CWD
MOV WORD PTR [bp-20],CX
MOV WORD PTR [bp-18],2
MOV CX,[bp-20]
MOV AX,CX
IDIV WORD PTR [bp-18]
MOV WORD PTR [bp-22],AX
MOV AX,[bp-24]
ADD AX,[bp-22]
MOV WORD PTR [bp-26],AX
MOV CX,[bp-26]
MOV WORD PTR [bp-12],CX
; mergeSort(start,mid);

PUSH [bp-12]

PUSH [bp-8]
CALL mergeSort
ADD SP,4
; mergeSort(mid+1,end);

PUSH [bp-10]

MOV AX,[bp-12]
MOV WORD PTR [bp-30],AX
MOV WORD PTR [bp-28],1
MOV AX,[bp-30]
ADD AX,[bp-28]
MOV WORD PTR [bp-32],AX
PUSH [bp-32]
CALL mergeSort
ADD SP,4
; merge(start,mid,end);

PUSH [bp-10]

PUSH [bp-12]

PUSH [bp-8]
CALL merge
ADD SP,6
L30:

L_mergeSort:
ADD SP,32
POP BP
RET
mergeSort ENDP

display PROC
PUSH BP
MOV BP,SP
SUB SP,10

MOV AX,[bp+4]
MOV WORD PTR [bp-2],AX

; for(i=0;i<size;i++)printf(arr[i]);
MOV WORD PTR [bp-6],0
MOV CX,[bp-6]
MOV WORD PTR [bp-4],CX
L33:
; i<size;


MOV AX,[bp-4]
CMP AX,[bp-2]
jl L31
MOV WORD PTR [bp-8],0
JMP L32
L31:
MOV WORD PTR [bp-8],1
L32:

; check for loop condition
CMP [bp-8],0
JE L34

; printf(arr[i]);

MOV BX,[bp-4]
ADD BX,BX
MOV AX,arr[BX]
MOV FOR_PRINT,AX
CALL OUTPUT
; i++

MOV AX,[bp-4]
MOV WORD PTR [bp-10],AX
INC WORD PTR [bp-4]
JMP L33
L34:

L_display:
ADD SP,10
POP BP
RET
display ENDP

main PROC
MOV AX, @DATA
MOV DS, AX
PUSH BP
MOV BP,SP
SUB SP,28

; size=4;
MOV WORD PTR [bp-4],4
MOV CX,[bp-4]
MOV WORD PTR [bp-2],CX
; arr[0]=5;
MOV WORD PTR [bp-8],5
MOV CX,[bp-8]
MOV WORD PTR [bp-6],0
MOV BX,[bp-6]
ADD BX,BX
MOV arr[BX],CX
; arr[1]=4;
MOV WORD PTR [bp-12],4
MOV CX,[bp-12]
MOV WORD PTR [bp-10],1
MOV BX,[bp-10]
ADD BX,BX
MOV arr[BX],CX
; arr[2]=3;
MOV WORD PTR [bp-16],3
MOV CX,[bp-16]
MOV WORD PTR [bp-14],2
MOV BX,[bp-14]
ADD BX,BX
MOV arr[BX],CX
; arr[3]=12;
MOV WORD PTR [bp-20],12
MOV CX,[bp-20]
MOV WORD PTR [bp-18],3
MOV BX,[bp-18]
ADD BX,BX
MOV arr[BX],CX
; display(size);

PUSH [bp-2]
CALL display
ADD SP,2
; mergeSort(0,size-1);

MOV AX,[bp-2]
MOV WORD PTR [bp-26],AX
MOV WORD PTR [bp-24],1
MOV AX,[bp-26]
SUB AX,[bp-24]
MOV WORD PTR [bp-28],AX
PUSH [bp-28]
MOV WORD PTR [bp-22],0
PUSH [bp-22]
CALL mergeSort
ADD SP,4
; display(size);

PUSH [bp-2]
CALL display
ADD SP,2
L_main:
ADD SP,28
POP BP

;DOS EXIT
MOV AH,4ch
INT 21h
main ENDP
END MAIN


