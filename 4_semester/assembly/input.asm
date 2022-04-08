section .data
	msg db 'output: '
	lenMsg equ $-msg

section .bss
	num resb 5

section .text
	global _start
_start:
	; input data
	mov eax, 3
	mov ebx, 2
	mov ecx, num
	mov edx, 5
	int 80h
	; print `msg`
	mov eax, 4
	mov ebx, 1
	mov ecx, msg
	mov edx, lenMsg
	int 80h
	; print `${num}`
	mov eax, 4
	mov ebx, 1
	mov ecx, num
	mov edx, 5
	int 80h
	; exit
	mov eax, 1
	mov ebx, 0
	int 80h
