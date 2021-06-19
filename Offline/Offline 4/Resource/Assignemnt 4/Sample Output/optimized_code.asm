.MODEL small
.stack 100H
.DATA
x2 dw ?
y2 dw ?
z2 dw ?
t0 dw ?
t1 dw ?
t2 dw ?

.CODE
main proc
mov ax,@data
mov ds,ax

mov t0,4
mov ax,t0
mov x2,ax
L3:
mov t1,0
mov ax, x2
cmp ax, t1
jg L1
mov t2,0
jmp L2
L1:
mov t2,1
L2:
cmp t2,0
je L4
dec x2
jmp L3
L4:
mov ax,x2
call OUTDEC
L0:

mov ah,4ch
int 21h
main endp
OUTDEC PROC
;INPUT AX
PUSH AX
PUSH BX
PUSH CX
PUSH DX
OR AX,AX
JGE END_IF1
PUSH AX
MOV DL,'-'
MOV AH,2
INT 21H
POP AX
NEG AX
END_IF1:
XOR CX,CX
MOV BX,10D
REPEAT1:
XOR DX,DX
DIV BX
PUSH DX
INC CX
OR AX,AX
JNE REPEAT1
MOV AH,2
PRINT_LOOP:
POP DX
OR DL,30H
INT 21H
LOOP PRINT_LOOP

mov ah,2
mov dl,0dh
int 21h
mov dl,0ah
int 21h

POP DX
POP CX
POP BX
POP AX
RET
OUTDEC ENDP
end main

