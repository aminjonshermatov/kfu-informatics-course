file := main

all: linkage

linkage: oFiles
	ld -o main $(file).o
oFiles:
	nasm -f elf64 -g -F dwarf $(file).asm

clean:
	rm main *.o
