all:cli.out soc.out
cli.out:view.o client.o  model.o 
	gcc -o $@ $^ -Wall -g -lpthread  
soc.out:view.o socket.o  models.o list.o
	gcc -o $@ $^ -Wall -g -lpthread 
%.o:%.c
	gcc -o $@ -c $< -Wall -g -lpthread 
clean:
	rm -rf *.*~ *～
	rm -rf *.o
	rm -rf soc.out cli.out
