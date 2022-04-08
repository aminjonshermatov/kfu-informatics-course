section .data
	stars times 9 dw 3 + 48

section .text
	global _start
_start:
	mov eax, 4
	mov ebx, 1
	mov ecx, stars
	mov edx, 18
	int 80h

	mov eax, 1
	int 80h
