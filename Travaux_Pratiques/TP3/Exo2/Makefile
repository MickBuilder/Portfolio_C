###### VARIABLES #######
CC = gcc
CFLAGS = -ansi -Wall -pedantic

RM = rm -f

SRC = ./src/
OBJ = ./obj/

OFILES = $(OBJ)word_count.o

all: main.out

main.out: $(OFILES)
	$(CC) $(CFLAGS) -o $@ $(OFILES)

$(OBJ):
	mkdir $@

$(OBJ)word_count.o: $(SRC)word_count.c $(OBJ)
	$(CC) $(CFLAGS) -o $@ -c $<

run: all
	./main.out

clean:
	$(RM) -r $(OBJ)
	$(RM) ./main.out

.PHONY: all clean