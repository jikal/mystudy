all:server client
CC:=gcc
FLAG:=-Wall -g -lpthread
TARGET1:=server 
TARGET2:=client
OBJ1:=server_control.o server_model.o serverTest.c
OBJ2:=client_control.o client_model.o client_view.o clientTest.c 
$(TARGET1):$(OBJ1)
	$(CC) -o $@ $^ $(FLAG)
$(TARGET2):$(OBJ2)
	$(CC) -o $@ $^ $(FLAG)
%.o:%.c
	$(CC) -o $@ -c $< $(FLAG)
PHONY:clean
clean:
	rm -rf *.*~ *~
	rm -rf $(TARGET)
	rm -rf *.o
