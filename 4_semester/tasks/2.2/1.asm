SYS_EXIT 	equ 1
SYS_READ	equ 3
SYS_WRITE	equ 4
STDIN		equ 0
STDOUT		equ 1

section .data
	b db 'a'
	w dw 2
	d dd 1
	q dq 3

section .bss

section .text
	global _start
_start:
	mov eax, SYS_WRITE
	mov ebx, STDOUT
	mov ecx, b
	mov edx, 1
	int 80h

	mov b, ax ; because b size: 1byte but ax register size: 2bytes

	mov eax, SYS_EXIT
	int 80h
