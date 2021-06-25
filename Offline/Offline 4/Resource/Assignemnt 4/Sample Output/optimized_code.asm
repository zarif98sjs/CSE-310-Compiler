.MODEL small
.stack 100H
.DATA
a2 dw ?
b2 dw ?
t0 dw ?
t1 dw ?
t2 dw ?
t3 dw ?

.CODE
main proc
mov ax,@data
mov ds,ax

mov t0,1
mov ax,t0
mov a2,ax
mov t1,2
mov ax,t1
mov b2,ax
mov ax, a2
cmp ax, b2
jg L1
mov t2,0
jmp L2
L1:
mov t2,1
L2:
cmp t2,0
je L3
inc a2
jmp L4
L3:
dec a2
L4:
mov t3,0
mov cx,t3
jmp L0
L0:

mov ah,4ch
int 21h
main endp
end main

