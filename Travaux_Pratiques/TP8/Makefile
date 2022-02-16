###### VARIABLES #######
CC = gcc
CFLAGS = -ansi -Wall -pedantic #-Werror

RM = rm -f

SRC = ./src/
OBJ = ./obj/

OFILES = $(OBJ)syracuse_utils.o

all: main.out

main.out: $(OFILES)
	$(CC) $(CFLAGS) -o $@ $(OFILES)

$(OBJ):
	mkdir $@

$(OBJ)syracuse_utils.o: $(SRC)syracuse_utils.c $(OBJ)
	$(CC) $(CFLAGS) -o $@ -c $<

run: all
	time ./main.out

clean:
	$(RM) -r $(OBJ)
	$(RM) ./main.out

.PHONY: all clean