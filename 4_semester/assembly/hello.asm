section .data
	msg db 'Hello, asm!', 0xa
	len equ $ - msg
section .text
	global _start
_start:
	mov edx, len
	mov ecx, msg
	mov ebx, 1
	mov eax, 4
	int 0x80
_exit:
	mov eax, 1
	int 0x80
