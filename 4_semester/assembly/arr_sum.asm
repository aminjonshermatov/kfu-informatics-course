section .data
	arr db 2, 3, 4
	sum db 0
section .text
	global _start
_start:
	mov eax, 3
	mov ebx, 0
	mov ecx, arr
_loop:
	add ebx, [ecx]
	add ecx, 1
	dec eax
	jnz _loop
	
	add ebx, '0'
	mov [sum], ebx
_print:
	mov edx, 1
	mov ecx, sum
	mov ebx, 1
	mov eax, 4
	int 0x80
_exit:
	mov eax, 1
	int 0x80
