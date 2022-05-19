section .data
	n equ 22
	stars times n db '*'
section .text
	global _start
_start:
	mov edx, n
	mov ecx, stars
	mov ebx, 1
	mov eax, 4
	int 0x80
_exit:
	mov eax, 1
	int 0x80
