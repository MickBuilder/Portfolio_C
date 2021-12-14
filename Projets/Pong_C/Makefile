###### VARIABLES #######
CC = gcc
CFLAGS = -ansi -Wall -pedantic

RM = rm -f

SRC = ./src/
OBJ = ./obj/
INCLUDE = ./include/

sources = $(wildcard $(SRC)*.c)
objects = $(sources:.c=.o)

MAIN = pong.out

all: $(MAIN)

$(MAIN): $(objects)
	$(CC) $(CFLAGS) -o $@ $(objects)

$(OBJ_DIR):
	mkdir $@

$(OBJ_DIR)%.o: %.c $(INCLUDE)/%.h $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

run:
	./$(MAIN)

clean:
	$(RM) -r $(OBJ)
	$(RM) $(MAIN)

.PHONY: all clean run