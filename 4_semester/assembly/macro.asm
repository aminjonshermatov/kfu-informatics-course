%macro _print 2
    mov edx, %2
    mov ecx, %1
    mov ebx, 1
    mov eax, 4
    int 0x80
%endmacro
section .data
    msg db 'Hello macro!', 0xa, 0xd
    lenMsg equ $-msg
    num db 9
section .text
    global _start
_start:
    _print msg, lenMsg
    add byte [num], '0'
    _print num, 1
_exit:
    mov eax, 1
    int 0x80
