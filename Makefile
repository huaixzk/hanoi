all:hanoi ascii1
hanoi: hanoi.c 
	gcc $< -o $@
ascii1: ascii1.c
	gcc $< -o $@
clean:
	rm -rf hanoi
