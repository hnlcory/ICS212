CC = gcc
CFLAGS = -ansi -pedantic-errors -Wall -c
OBJ = homework3

all: $(OBJ)

$(OBJ): user_interface.o database.o
	$(CC) -o $(OBJ) user_interface.o database.o 

user_interface.o: user_interface.c
	$(CC) $(CFLAGS) user_interface.c

database.o: database.c
	$(CC) $(CFLAGS) database.c



