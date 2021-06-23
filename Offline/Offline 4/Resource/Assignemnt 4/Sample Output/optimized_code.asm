.MODEL small
.stack 100H
.DATA
a2 dw ?
b2 dw ?
c2 dw ?
ara2 dw 10 dup ($)
t0 dw ?
t1 dw ?
t2 dw ?
t3 dw ?
t4 dw ?
t5 dw ?
t6 dw ?
t7 dw ?
t8 dw ?

.CODE
main proc
mov ax,@data
mov ds,ax

mov t1,10
mov t0,0
mov bx, t0
add bx,bx
mov ax,t1
mov ara2[bx],ax
mov t3,12
mov t2,9
mov bx, t2
add bx,bx
mov ax,t3
mov ara2[bx],ax
mov ax, ara2[bx]
mov t5, ax
mov ax, ara2[bx]
mov t7, ax
mov ax,t5
add ax,t7
mov t8,ax
mov a2,ax
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

