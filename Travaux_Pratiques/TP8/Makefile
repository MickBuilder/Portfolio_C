###### VARIABLES #######
CC = gcc
CFLAGS = -ansi -Wall -pedantic #-Werror

RM = rm -f

SRC = ./src/
OBJ = ./obj/

OFILES = $(OBJ)stack_height.o

all: main.out

main.out: $(OFILES)
	$(CC) $(CFLAGS) -o $@ $(OFILES)

$(OBJ):
	mkdir $@

$(OBJ)stack_height.o: $(SRC)stack_height.c $(OBJ)
	$(CC) $(CFLAGS) -o $@ -c $<

run: all
	./main.out

clean:
	$(RM) -r $(OBJ)
	$(RM) ./main.out

.PHONY: all clean