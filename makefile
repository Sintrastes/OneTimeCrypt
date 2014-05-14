CC = gcc
CFLAGS = -Wall -std=c99
NAME = cypher

build:
	$(CC) cypher.c $(CFLAGS) -o $(NAME)
debug:
	$(CC) cypher.c $(CFLAGS) -g -o $(NAME) && gdb $(NAME)
clean:
	rm $(NAME)

