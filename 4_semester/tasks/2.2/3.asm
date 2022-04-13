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
	mov ax, [w]

	mov eax, SYS_EXIT
	int 80h
