.MODEL small
.stack 100H
.DATA
t0 dw ?
ara2 dw 20 dup ($)
t1 dw ?
t2 dw ?
x2 dw ?
y2 dw ?
z2 dw ?
a3 dw ?
b3 dw ?
c3 dw ?
i3 dw ?
ara3 dw 20 dup ($)
t3 dw ?
t4 dw ?
t5 dw ?
t6 dw ?
t7 dw ?

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
push t1
push t2

push bp
mov bp,sp
mov ax,[bp+26]
mov x2,ax
mov ax,[bp+28]
mov y2,ax
mov ax,[bp+30]
mov z2,ax

mov t0,12
mov ax,t0
mov z2,ax
mov t2,131
mov t1,3
mov bx, t1
add bx,bx
mov ax,t2
mov ara2[bx],ax
L0:
pop bp
pop t2
pop t1
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

mov t3,12
mov ax,t3
mov b3,ax
mov t4,14
mov ax,t4
mov c3,ax
mov t6,10
mov t5,2
mov bx, t5
add bx,bx
mov ax,t6
mov ara3[bx],ax
mov ax,b3
add ax,c3
mov t7,ax
mov a3,ax
L1:

mov ah,4ch
int 21h
main endp
end main

