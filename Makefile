CFLAGS += -lGL -lglut -lGLU
all:hanoi ascii1   tgl
	cd ./asm && make

hanoi: hanoi.c 
	gcc $< -o $@
ascii1: ascii1.c
	gcc $< -o $@
tgl: tgl.c
	gcc $< $(CFLAGS) -o $@
clean:
	rm -rf hanoi ascii1 tgl
	cd ./asm && make clean
