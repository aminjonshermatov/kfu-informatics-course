section .text
   global _start

_start:	                 
	
   mov   ecx, num
   mov   edx, 1
   mov   ebx, 1
   mov   eax, 4
   int   0x80
   
   sub byte [ecx], '0'
   shl byte [ecx], 1
   add byte[ecx], '0'
   

   mov   edx, 1
   mov   ebx, 1
   mov   eax, 4
   int   0x80
    
   mov   eax, 1
   int   80h

section	.data 
   num dd '2'
