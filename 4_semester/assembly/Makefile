file := input

all: linkage

linkage: objectFile
	ld -m elf_i386 -s -o $(file) $(file).o
objectFile:
	nasm -f elf $(file).asm

clean:
	rm $(file) $(file).o
