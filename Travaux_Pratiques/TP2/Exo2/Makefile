###### VARIABLES #######
CC = gcc
CFLAGS = -ansi -Wall -pedantic

RM = rm -f

SRC = ./src/
OBJ = ./obj/

# OFILES = $(OBJ)addition.o $(OBJ)addition_bis.o

all: sum.out sum_bis.out

sum.out: $(OBJ)addition.o
	$(CC) $(CFLAGS) -o $@ $(OBJ)addition.o

sum_bis.out: $(OBJ)addition_bis.o
	$(CC) $(CFLAGS) -o $@ $(OBJ)addition_bis.o

$(OBJ):
	mkdir $@

$(OBJ)addition.o: $(SRC)addition.c $(OBJ)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ)addition_bis.o: $(SRC)addition_bis.c $(OBJ)
	$(CC) $(CFLAGS) -o $@ -c $<

run: all
	./sum.out

clean:
	$(RM) -r $(OBJ)
	$(RM) ./sum.out ./sum_bis.out

.PHONY: all clean