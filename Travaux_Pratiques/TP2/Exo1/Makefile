###### VARIABLES #######
CC = gcc
CFLAGS = -ansi -Wall -pedantic

RM = rm -f

SRC = ./src/
OBJ = ./obj/

OFILES = $(OBJ)hello_world.o

all: main.out

main.out: $(OFILES)
	$(CC) $(CFLAGS) -o $@ $(OFILES)

$(OBJ):
	mkdir $@

$(OBJ)hello_world.o: $(SRC)hello_world.c $(OBJ)
	$(CC) $(CFLAGS) -o $@ -c $<

run:
	./main

clean:
	$(RM) -r $(OBJ)
	$(RM) ./main.out

.PHONY: all clean