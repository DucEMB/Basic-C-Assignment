CC = gcc
CFLAGS = -I.

assignment: main.o
	$(CC) -o $@ $<

main.o: animalstyle.h processfunc.h
	$(CC) -c $^