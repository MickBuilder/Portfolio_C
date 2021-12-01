###### VARIABLES #######
CC = gcc
CFLAGS = -ansi -Wall -pedantic

RM = rm -f

SRC = ./src/
OBJ = ./obj/

OFILES = $(OBJ)display_src_code.o

all: main.out

main.out: $(OFILES)
	$(CC) $(CFLAGS) -o $@ $(OFILES)

$(OBJ):
	mkdir $@

$(OBJ)display_src_code.o: $(SRC)display_src_code.c $(OBJ)
	$(CC) $(CFLAGS) -o $@ -c $<

run: all
	./main.out

clean:
	$(RM) -r $(OBJ)
	$(RM) ./main.out

.PHONY: all clean