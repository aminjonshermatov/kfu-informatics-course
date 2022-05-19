section .bss
	num resb 1
section .text
	global _start
_start:
	mov ecx, 10
	mov eax, '1'
_loop:
	mov [num], eax
	push ecx
	
	mov edx, 1
	mov ecx, num
	mov ebx, 1
	mov eax, 4
	int 0x80

	mov eax, [num]
	sub eax, '0'
	inc eax
	add eax, '0'
	pop ecx
	loop _loop
_exit:
	mov eax, 1
	int 0x80
