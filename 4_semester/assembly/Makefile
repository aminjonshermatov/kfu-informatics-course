all: hello.o
	ld -m elf_i386 -s -o hello hello.o
hello.o:
	nasm -f elf hello.asm
