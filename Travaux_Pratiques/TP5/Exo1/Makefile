###### VARIABLES #######
CC = gcc
CFLAGS = -ansi -Wall -pedantic

RM = rm -f

SRC = ./src/
TEST = ./test/
INC = ./src/include/
OBJ = ./obj/

OFILES = $(OBJ)main.o $(OBJ)array.o
TOBJ = $(OBJ)array_test.o $(OBJ)array.o

all: main.out test.out

main.out: $(OFILES)
	$(CC) $(CFLAGS) -o $@ $^

test.out: $(TOBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ):
	mkdir $@

$(OBJ)main.o: $(SRC)main.c $(INC)array.h $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@ 

$(OBJ)array.o: $(SRC)array.c $(INC)array.h $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@ 

$(OBJ)array_test.o: $(TEST)array_test.c $(INC)array.h $(TEST)test.h $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

test: all
	./test.out

run: all
	./main.out

clean:
	$(RM) -r $(OBJ)
	$(RM) ./main.out
	$(RM) ./test.out

.PHONY: all clean run test