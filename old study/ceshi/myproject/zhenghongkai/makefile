all:tcpc.out tcps.out


tcpc.out: tcpc.o control.o menu.o mode.o link.o
	gcc -o $@ $^ -Wall -g -lpthread

tcps.out: tcps.o control.o menu.o mode.o link.o
	gcc -o $@ $^ -Wall -g -lpthread
%.o:%.c
	gcc -o $@ -c $< -Wall -g -lpthread
clean:
	rm -rf *.*~ *~
	rm -rf *.o
	rm -rf *.out
