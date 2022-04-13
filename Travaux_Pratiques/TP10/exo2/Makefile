###### VARIABLES #######
CC = gcc
CFLAGS = -ansi -Wall -pedantic -I include #-Werror

RM = rm -f

SRC = ./src/
OBJ = ./obj/

OFILES = $(OBJ)main.o $(OBJ)person.o $(OBJ)file_utils.o

all: main.out

main.out: $(OFILES)
	$(CC) $(CFLAGS) -o $@ $(OFILES)

$(OBJ):
	mkdir $@

$(OBJ)main.o: $(SRC)main.c $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@ 

$(OBJ)person.o: $(SRC)person.c 
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ)file_utils.o: $(SRC)file_utils.c 
	$(CC) $(CFLAGS) -o $@ -c $<
	
run: all
	./main.out

clean:
	$(RM) -r $(OBJ)
	$(RM) ./main.out

.PHONY: all clean run