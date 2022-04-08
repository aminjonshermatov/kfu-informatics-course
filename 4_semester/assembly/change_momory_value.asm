section .data
	name db 'Zara Ali'

section .text
	global _start
_start:
	mov eax, 4
	mov ebx, 1
	mov ecx, name
	mov edx, 8
	int 80h

	mov [name], dword 'Nuna'

	mov eax, 4
	mov ebx, 1
	mov ecx, name
	mov edx, 8
	int 80h

	mov eax, 1
	int 80h
