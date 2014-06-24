# Makefile for fun
# hello0 for hello0.s  ------- 32bit asm
# hello1  for hello1.s  ------- 32bit asm oth
# hello_1 for hello0.s  ------- 32 -- 64bit asm
# helloX64 for hellox64.s  ------- 32bit asm
# hello2 for hello2.c ------- 32bit C
# hello3 for hello2.c  -------- 64bit C
target = hello0 hello1 hello_1 helloX64 hello2 hello3
CFLAGS += -m32
all: $(target)

hello0: hello0.s
	as --32 $< -o hello.o
	ld -m elf_i386 hello.o -o $@

hello1: hello1.s
	as --32 $< -o hello1.o
	ld -m elf_i386 hello1.o -o $@

hello_1: hello0.s
	as $< -o hello_1.o
	ld hello_1.o -o $@

helloX64: helloX64.s
	as $< -o helloX64.o
	ld helloX64.o -o $@

hello_2: hello2.c
	$(CC) $(CFLAGS) $< -o $@

hello3: hello2.c
	$(CC) $< -o $@

clean:
	rm -rf a.out *.o  $(target)
