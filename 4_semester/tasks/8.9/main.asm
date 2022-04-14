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
	; input data
	mov rax, 0		;sys_read
	mov rdi, 0		;stdin
	mov rsi, buf
	mov rdx, 1
	syscall

	cmp [buf], byte ' '
	je split
	mov rax, [buf]
	sub rax, '0'
	mov rbx, [num]
	shr rbx, 2
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
	mov rdi, 1		; stdout
	pop rsi			; address to print
	add rsi, '0'
	mov rdx, 1
	syscall
	sub dword [counter], 1
	cmp dword [counter], 0
	jne print
exit:
	mov rax, 60
	mov rdi, 0
	syscall
