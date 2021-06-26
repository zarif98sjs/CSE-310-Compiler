.MODEL small
.stack 100H
.DATA
a2 dw ?
b2 dw ?
ara2 dw 10 dup ($)
t0 dw ?
t1 dw ?
t2 dw ?
t3 dw ?
t4 dw ?
t5 dw ?

.CODE
main proc
mov ax,@data
mov ds,ax

mov t1,23
mov t0,2
mov bx, t0
add bx,bx
mov ax,t1
mov ara2[bx],ax
mov t2,1
mov ax,t2
mov a2,ax
mov t3,2
mov ax,t3
mov b2,ax
mov ax, a2
cmp ax, b2
jg L1
mov t4,0
jmp L2
L1:
mov t4,1
L2:
cmp t4,0
je L3
inc a2
jmp L4
L3:
dec a2
L4:
mov t5,0
mov cx,t5
jmp L0
L0:

mov ah,4ch
int 21h
main endp
end main

