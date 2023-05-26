CC = gcc
CFLAGS= -g -Wall -Wextra

all: board run

board: board.c chess.h
	$(CC) -o board board.c

run: 
	./board

clean:
	rm board
