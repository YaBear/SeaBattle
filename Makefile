all:
	gcc -Wall -Werror -Wextra main.c

clean:
	rm -rf *.out

rebuild: clean all