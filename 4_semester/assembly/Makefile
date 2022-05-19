file := arr_sum

all: linkage

linkage: objectFile
	ld -m elf_i386 -s -o $(file) $(file).o
objectFile:
	nasm -f elf $(file).asm

#linkage: oFiles
#		ld -o $(file) $(file).o
#oFiles:
#		nasm -f elf64 -g -F dwarf $(file).asm

clean:
	rm $(file) $(file).o
