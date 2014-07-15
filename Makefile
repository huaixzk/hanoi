CFLAGS ?= -lGL -lglut -lGLU
.PHONY: tests asms

all:hanoi ascii1 asms  tgl tests

asms:
	cd ./asm && make

tests:
	cd ./tests/hello && make

hanoi: hanoi.c 
	gcc $< -o $@
ascii1: ascii1.c
	gcc $< -o $@
tgl: tgl.c
	gcc $< $(CFLAGS) -o $@
clean:
	rm -rf hanoi ascii1 tgl
	cd ./asm && make clean
	cd ./tests/hello && make clean
