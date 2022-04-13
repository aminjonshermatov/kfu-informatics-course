SYS_READ	equ 3
SYS_WRITE	equ 4
STDIN		equ 0
STDOUT		equ 1

section .data
	t db 5
	num dd 0

section .bss
	buf resb 1

section .text
	global _start
_start:
readCh:
	; input data
	mov eax, SYS_READ
	mov ebx, STDIN
	mov ecx, buf
	mov edx, 1
	int 80h

	cmp [buf], byte ' '
	je print
	mov eax, [buf]
	sub eax, 48
	mov ebx, [num]
	shr ebx, 2
	add ebx, eax
	mov [num], ebx
	jmp readCh
print:
	; print `{buf}`
	mov eax, 4
	mov ebx, 1
;	mov [num], dword 3
;	mov dword [ecx], num
;	add dword [ecx], 48
	mov ecx, num
	add dword [ecx], 48
	mov edx, 1
	int 80h

exit:
	mov eax, 1
	mov ebx, 0
	int 80h
