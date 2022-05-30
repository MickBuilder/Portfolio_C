###### VARIABLES #######
CC = gcc
CFLAGS =  -Wall -pedantic -I include #-Werror

RM = rm -f

SRC = ./src/
OBJ = ./obj/

OFILES = $(OBJ)main.o $(OBJ)file_info.o

all: larger_file.out

larger_file.out: $(OFILES)
	$(CC) $(CFLAGS) -o $@ $(OFILES)

$(OBJ):
	mkdir $@

$(OBJ)main.o: $(SRC)main.c $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@ 

$(OBJ)file_info.o: $(SRC)file_info.c 
	$(CC) $(CFLAGS) -o $@ -c $<
	
run: all
	./larger_file.out

clean:
	$(RM) -r $(OBJ)
	$(RM) ./larger_file.out

.PHONY: all clean run
