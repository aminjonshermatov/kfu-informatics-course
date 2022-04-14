SYS_READ	equ 3
SYS_WRITE	equ 4
STDIN		equ 0
STDOUT		equ 1


section .data
	num dd 0
	counter dd 0
	divisor dd 10

section .bss
	buf resb 1

section .text
	global _start
_start:
readCh:
	; input data
	mov rax, SYS_READ
	mov rbx, STDIN
	mov rcx, buf
	mov rdx, 1
	int 80h

	cmp [buf], byte ' '
	je split
	mov rax, [buf]
	sub rax, 48
	mov rbx, [num]
	shr rbx, 2
	add rbx, rax
	mov [num], rbx
	jmp readCh

;	split number into chars
split:
	add [counter], dword 1
	mov rax, [num]
	mov rbx, [divisor]
	div rbx
	push rdx	;remainder
	mov [num], rax
	cmp rax, 0
	jne split

print:
	; print `{buf}`
	mov rax, SYS_WRITE
	mov rbx, STDOUT
	pop rcx
	add rcx, qword 48
	mov rdx, 1
	int 80h
	sub dword [counter], 1
	cmp dword [counter], 0
	jne print

exit:
	mov rax, 1
	mov rbx, 0
	int 80h
