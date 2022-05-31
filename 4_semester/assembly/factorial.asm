section .bss
    res resb 2
section .text
    global _start
_start:
    mov eax, 1
    mov ebx, 3
    call _fact
    add eax, '0'
    mov [res], eax
_print:
    mov edx, 1
    mov ecx, res
    mov ebx, 1
    mov eax, 4
    int 0x80
_exit:
    mov eax, 1
    int 0x80
_fact:
    mul ebx
    dec ebx
    cmp ebx, 1
    jg _fact
    ret