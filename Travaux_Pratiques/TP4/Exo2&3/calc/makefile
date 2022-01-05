CC=gcc
CFLAGS=-Wall -ansi -g -pedantic
LDFLAGS=-lMLV -lm

RM = rm -f

SRC = ./src/
INC = ./src/include/
OBJ = ./obj/

OFILES = $(OBJ)main.o $(OBJ)interface.o $(OBJ)stack.o $(OBJ)operation.o

all: main.out

main.out: $(OFILES)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

$(OBJ):
	mkdir $@

$(OBJ)main.o: $(SRC)main.c $(INC)stack.h $(INC)interface.h $(INC)operation.h $(OBJ)
	$(CC) -c $< -o $@ $(CFLAGS)

$(OBJ)interface.o: $(SRC)interface.c $(INC)interface.h $(INC)stack.h
	$(CC) -c $< -o $@ $(CFLAGS) -lMLV

$(OBJ)stack.o: $(SRC)stack.c $(INC)stack.h
	$(CC) -c $< -o $@ $(CFLAGS)

$(OBJ)operation.o: $(SRC)operation.c $(INC)operation.h $(INC)stack.h $(INC)interface.h
	$(CC) -c $< -o $@ $(CFLAGS) -lm

clean:
	$(RM) -r $(OBJ)
	$(RM) ./main.out

.PHONY: all clean