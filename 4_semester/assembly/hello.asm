section .data
	msg db 'Hello, asm!', 0xa
	len equ $ - msg

section .text
	global _start

_start:
	mov edx, len
	mov ecx, msg
	mov ebx, 1 ;stdout
	mov eax, 4 ;sys_write
	int 0x80 ;kernel call
		
	mov eax, 1
	int 0x80 ;kernel call
