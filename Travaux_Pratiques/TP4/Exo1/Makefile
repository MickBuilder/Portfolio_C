###### VARIABLES #######
CC = gcc
CFLAGS = -ansi -Wall -pedantic

RM = rm -f

SRC = ./src/
INC = ./src/include/
OBJ = ./obj/

OFILES = $(OBJ)main.o $(OBJ)stack.o

all: main.out

main.out: $(OFILES)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ):
	mkdir $@

$(OBJ)main.o: $(SRC)main.c $(INC)stack.h $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@ 

$(OBJ)stack.o: $(SRC)stack.c $(INC)stack.h $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@ 

run: all
	./main.out

clean:
	$(RM) -r $(OBJ)
	$(RM) ./main.out

.PHONY: all clean