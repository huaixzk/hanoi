all:hanoi ascii1  
	cd ./asm && make

hanoi: hanoi.c 
	gcc $< -o $@
ascii1: ascii1.c
	gcc $< -o $@
clean:
	rm -rf hanoi ascii1
	cd ./asm && make clean
