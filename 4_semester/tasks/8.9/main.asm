section .data
	num dq 0
	counter dd 0
	divisor dq 10

section .bss
	buf resb 1

section .text
	global _start
_start:
readCh:
	mov rax, 0
	mov rdi, 0
	mov rsi, buf
	mov rdx, 1
	syscall

	cmp [buf], byte ' '
	je split
	mov rax, [buf]
	sub rax, '0'
	mov rbx, [num]
	shl rbx, 2
	add rbx, rax
	mov [num], rbx
	jmp readCh

;	split number into chars
split:
	add [counter], dword 1
	mov rdx, 0
	mov rax, [num]
	mov rbx, [divisor]
	idiv rbx
	push rdx	;remainder
	mov [num], rax
	cmp rax, 0
	jne split

print:
	mov rax, 1
	mov rdi, 1
	pop rbx
	mov [rsi], rbx
	add byte [rsi], '0'
	mov rdx, 1
	syscall

	sub dword [counter], 1
	cmp dword [counter], 0
	jne print
exit:
	mov rax, 60
	mov rdi, 0
	syscall
