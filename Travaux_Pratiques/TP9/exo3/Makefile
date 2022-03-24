###### VARIABLES #######
CC = gcc
CFLAGS = -ansi -Wall -pedantic -I include #-Werror

RM = rm -f

SRC = ./src/
OBJ = ./obj/

OFILES = $(OBJ)main.o $(OBJ)args_utility.o

all: main.out

main.out: $(OFILES)
	$(CC) $(CFLAGS) -o $@ $(OFILES)

$(OBJ):
	mkdir $@

$(OBJ)main.o: $(SRC)main.c $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@ 
	
$(OBJ)args_utility.o: $(SRC)args_utility.c 
	$(CC) $(CFLAGS) -o $@ -c $<

run: all
	time ./main.out

clean:
	$(RM) -r $(OBJ)
	$(RM) ./main.out

.PHONY: all clean run