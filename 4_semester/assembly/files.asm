section .bss
    fd_in   resb 1
    fd_out  resb 1
    buf     resb 2
    res     resb 1
section .data
    f_in    db 'data.in'
    f_out   db 'data.out'
section .text
    global _start
_start:
    mov eax, 5
    mov ebx, f_in
    mov ecx, 0
    mov edx, 777o
    int 0x80
    mov [fd_in], eax
    mov eax, 3
    mov ebx, [fd_in]
    mov ecx, buf
    mov edx, 2
    int 0x80
    mov eax, 6
    mov ebx, [fd_in]
    int 0x80
    mov ecx, [buf]
    and ecx, 0xff
    sub ecx, '0'
    shr word [buf], 8
    add ecx, [buf]
    mov [res], ecx
    mov eax, 8
    mov ebx, f_out
    mov ecx, 777o
    int 0x80
    mov [fd_out], eax
    mov eax, 4
    mov ebx, [fd_out]
    mov ecx, [res]
    mov edx, 1
    int 0x80
    mov eax, 6
    mov ebx, [fd_out]
    int 0x80
    mov eax, 1
    int 0x80
