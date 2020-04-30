.SUFFIXES: .o .asm

hello: hello.o
	ld -o $@ $<

.asm.o:
	nasm -felf64 $<
