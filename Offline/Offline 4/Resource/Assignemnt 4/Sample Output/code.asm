.MODEL small
.stack 100H
.DATA
s2 dw ?
t0 dw ?
a2 dw ?
b2 dw ?
c2 dw ?
d2 dw ?
x3 dw ?
y3 dw ?
t1 dw ?
t2 dw ?
s3 dw ?
t3 dw ?

.CODE
sum proc
push ax
push bx
push dx
push si
push di
push a2
push b2
push c2
push d2
push s2
push t0

push bp
mov bp,sp
mov ax,[bp+26]
mov a2,ax
mov ax,[bp+28]
mov b2,ax
mov ax,[bp+30]
mov c2,ax
mov ax,[bp+32]
mov d2,ax

mov ax,a2
add ax,b2
mov t0,ax
mov ax,t0
mov s2,ax
mov cx,s2
jmp L0
L0:
pop bp
pop t0
pop s2
pop d2
pop c2
pop b2
pop a2
pop di
pop si
pop dx
pop bx
pop ax
ret 8
sum endp

main proc
mov ax,@data
mov ds,ax

mov t1,10
mov ax,t1
mov x3,ax
mov t2,12
mov ax,t2
mov y3,ax
push x3
push y3
push y3
push x3

call sum
mov ax,cx
mov t3,ax
mov ax,t3
mov s3,ax
mov ax,s3
call OUTDEC
L1:

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

