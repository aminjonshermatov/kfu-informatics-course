section .data
	msg db 'Allocated 16kb of memory', 0xa
	len equ $-msg
section .text
	global _start
_start:
	mov eax, 45
	xor ebx, ebx
	int 80h
	add eax, 16 * 1024
	mov ebx, eax
	mov eax, 45
	int 80h
	cmp eax, 0
	jl _exit
	mov edi, eax
	sub edi, 4
	mov ecx, 4 * 1024
	xor eax, eax
	std
	rep stosd
	cld
	mov eax, 4
	mov ebx, 1
	mov ecx, msg
	mov edx, len
	int 80h
_exit:
	mov eax, 1
	int 80h
