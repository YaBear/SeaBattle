CC=gcc
CFLAGS=-Wall -Werror -Wextra

all: clean
	$(CC) $(CFLAGS) -c *.c
	$(CC) $(CFLAGS) *.o -o exec
	rm -rf *.o

play:
	./exec

clean:
	rm -rf *.o exec

rebuild: clean all