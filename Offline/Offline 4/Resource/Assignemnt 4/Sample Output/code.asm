.MODEL small
.stack 100H
.DATA
t0 dw ?
t1 dw ?
t2 dw ?
a2 dw ?
x3 dw ?
t3 dw ?
t4 dw ?
t5 dw ?
a3 dw ?
b3 dw ?
a4 dw ?
b4 dw ?
t6 dw ?
t7 dw ?
t8 dw ?
t9 dw ?

.CODE
f proc
push ax
push bx
push dx
push si
push di
push a2
push t0
push t1
push t2

push bp
mov bp,sp
mov ax,[bp+22]
mov a2,ax

mov t0,2
mov ax, t0
imul a2
mov t1, ax
mov cx,t1
jmp L0
mov t2,9
mov ax,t2
mov a2,ax
L0:
pop bp
pop t2
pop t1
pop t0
pop a2
pop di
pop si
pop dx
pop bx
pop ax
ret 2
f endp

g proc
push ax
push bx
push dx
push si
push di
push a3
push b3
push x3
push t3
push t4
push t5

push bp
mov bp,sp
mov ax,[bp+26]
mov a3,ax
mov ax,[bp+28]
mov b3,ax

push a3

call f
mov ax,cx
mov t3,ax
mov ax,t3
add ax,a3
mov t4,ax
mov ax,t4
add ax,b3
mov t5,ax
mov ax,t5
mov x3,ax
mov cx,x3
jmp L1
L1:
pop bp
pop t5
pop t4
pop t3
pop x3
pop b3
pop a3
pop di
pop si
pop dx
pop bx
pop ax
ret 4
g endp

main proc
mov ax,@data
mov ds,ax

mov t6,1
mov ax,t6
mov a4,ax
mov t7,2
mov ax,t7
mov b4,ax
push b4
push a4

call g
mov ax,cx
mov t8,ax
mov ax,t8
mov a4,ax
mov ax,a4
call OUTDEC
mov t9,0
mov cx,t9
jmp L2
L2:

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

