section .bss
	size equ 5
	num resb size
section .text
	global _start
_start:
	mov edx, size
	mov ecx, num
	mov ebx, 2
	mov eax, 3
	int 0x80
	mov edx, size
	mov ecx, num
	mov ebx, 1
	mov eax, 4
	int 0x80
_exit:
	mov eax, 1
	int 0x80
