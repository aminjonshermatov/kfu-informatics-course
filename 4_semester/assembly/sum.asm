section .bss
	a resb 1
	b resb 1
	ans resb 1
section .text
	global _start
_start:
	mov edx, 2
	mov ecx, a
	mov ebx, 2
	mov eax, 3
	int 0x80

	mov edx, 2
	mov ecx, b
	mov ebx, 2
	mov eax, 3
	int 0x80

	mov eax, [a]
	sub eax, '0'
	mov ebx, [b]
	sub ebx, '0'
	add eax, ebx
	add eax, '0'
	mov [ans], eax

	mov edx, 1
	mov ecx, ans
	mov ebx, 1
	mov eax, 4
	int 0x80
_exit:
	mov eax, 1
	int 0x80
