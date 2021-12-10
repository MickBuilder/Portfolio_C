###### VARIABLES #######
CC = gcc
CFLAGS = -ansi -Wall -pedantic

RM = rm -f

SRC_DIR = ./src/
SRC = $(wildcard $(SRC_DIR)*.c)

OBJ_DIR = ./obj/
OBJ = $(SRC:.c=.o)

OFILES = $(OBJ)*.o

MAIN = pong.out

all: $(MAIN)

$(MAIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OFILES)

$(OBJ_DIR):
	mkdir $@

$(OBJ)%.o: $(SRC)%.c $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

run:
	./$(MAIN)

clean:
	$(RM) -r $(OBJ)
	$(RM) $(MAIN)

.PHONY: all clean run