section .data
	msg db 'x'
	r record a:3=2, b:3, c:10=3FFh

section .text
	global _start
_start:
	mov rax, 1
	mov rdi, 1
	mov rsi, msg
	mov rdx, 1
	syscall
exit:
	mov rax, 60
	mov rdi, 0
	syscall
