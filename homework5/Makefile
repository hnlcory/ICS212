CC = gcc
CFLAGS = -ansi -pedantic-errors -Wall -c
OBJ = homework5

all: $(OBJ)

$(OBJ): iofunctions.o driver.o
	$(CC) -o $(OBJ) iofunctions.o driver.o

driver.o: driver.c
	$(CC) $(CFLAGS) driver.c

iofunctions.o: iofunctions.c
	$(CC) $(CFLAGS) iofunctions.c
