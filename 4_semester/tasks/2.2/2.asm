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
	mov ecx, w
	mov edx, 2
	int 80h

	mov ax, 53
;	mov w, ax	;doesn't work because w isn't memory
	mov [w], ax

	mov eax, SYS_WRITE
	mov ebx, STDOUT
	mov ecx, w
	mov edx, 2
	int 80h

	mov eax, SYS_EXIT
	int 80h
