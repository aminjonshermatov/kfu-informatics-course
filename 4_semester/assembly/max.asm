section .data
	a dd '47'
	b dd '22'
	c dd '31'
section .bss
	max resb 2
section .text
	global _start
_start:
	mov ecx, [a]
	cmp ecx, [b]
	jg check_ecx_and_c
	mov ecx, [b]
check_ecx_and_c:
	cmp ecx, [c]
	jg print
	mov ecx, [c]
print:
	mov [max], ecx
	mov edx, 2
	mov ecx, max
	mov ebx, 1
	mov eax, 4
	int 0x80
	mov eax, 1
	int 0x80

