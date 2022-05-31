section .bss
    res resb 1
section .text
    global _start
_start:
    mov ecx, '2'
    sub ecx, '0'
    mov edx, '4'
    sub edx, '0'
    call _mul
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
_mul:
    mov eax, ecx
    mul edx
    add eax, '0'
    ret