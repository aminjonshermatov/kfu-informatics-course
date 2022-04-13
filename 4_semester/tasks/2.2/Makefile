file := 3

all: linkage

linkage: oFiles
	ld -m elf_i386 -s -o main $(file).o
oFiles:
	nasm -f elf $(file).asm

clean:
	rm main *.o
