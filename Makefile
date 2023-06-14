CC=gcc
CFLAGS=-Wno-unused-parameter -Wall -Werror -Wextra

all: clean
	$(CC) $(CFLAGS) -c *.c
	$(CC) $(CFLAGS) *.o -o exec
	rm -rf *.o

debug:
	$(CC) $(CFLAGS) -g -c *.c
	$(CC) $(CFLAGS) -g *.o -o exec
	rm -rf *.o
play:
	./exec

clean:
	rm -rf *.o exec

rebuild: clean all