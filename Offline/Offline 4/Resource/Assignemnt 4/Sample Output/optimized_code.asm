.MODEL small
.stack 100H
.DATA
t0 dw ?
x2 dw ?
y2 dw ?
z2 dw ?
a3 dw ?
b3 dw ?
c3 dw ?
i3 dw ?
t1 dw ?
t2 dw ?

.CODE
f proc
push ax
push bx
push dx
push si
push di
push x2
push y2
push z2
push t0

push bp
mov bp,sp
mov ax,[bp+22]
mov x2,ax
mov ax,[bp+24]
mov y2,ax
mov ax,[bp+26]
mov z2,ax

mov t0,12
mov ax,t0
mov z2,ax
L0:
pop bp
pop t0

pop di
pop si
pop dx
pop bx
pop ax
ret
f endp

main proc
mov ax,@data
mov ds,ax

mov t1,0
mov ax,t1
mov b3,ax
mov t2,1
mov ax,t2
mov c3,ax
L1:

mov ah,4ch
int 21h
main endp
end main

