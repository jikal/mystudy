usr.out:view.o control.o model.o link2.o usrtest.c
	gcc -o $@ $^ -Wall -g
%.o:%.c
	gcc -o $@ -c $< -Wall -g
clean:
	rm -rf *.*~ *~
	rm -rf *.o
	rm -rf usr.out
