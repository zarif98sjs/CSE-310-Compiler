.MODEL small
.stack 100H
.DATA
a2 dw ?
b2 dw ?
c2 dw ?
i2 dw ?
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

mov t0,0
mov ax,t0
mov b2,ax
mov t1,1
mov ax,t1
mov c2,ax
mov t2,0
mov ax,t2
mov i2,ax
L5:
mov t3,4
mov ax, i2
cmp ax, t3
jl L1
mov t4,0
jmp L2
L1:
mov t4,1
L2:
cmp t4,0
je L6
mov t5,3
mov ax,t5
mov a2,ax
L3:
dec a2
cmp a2,0
je L4
inc b2
jmp L3
L4:
inc i2
jmp L5
L6:
mov ax,a2
call OUTDEC
mov ax,b2
call OUTDEC
mov ax,c2
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

