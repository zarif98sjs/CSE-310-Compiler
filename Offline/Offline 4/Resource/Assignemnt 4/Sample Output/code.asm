.MODEL small
.stack 100H
.DATA
x2 dw ?
t0 dw ?
t1 dw ?
t2 dw ?

.CODE
main proc
mov ax,@data
mov ds,ax

mov t0,10
mov t1,10
mov ax,t0
add ax,t1
mov t2,ax
mov ax,t2
mov x2,ax
L0:

mov ah,4ch
int 21h
main endp
end main

