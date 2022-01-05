###### VARIABLES #######
CC = gcc
CFLAGS = -ansi -Wall -pedantic

RM = rm -f

SRC 	= ./src/
TEST 	= ./test/
INC 	= ./src/include/
OBJ 	= ./obj/

OFILES = $(OBJ)main.o $(OBJ)puissance.o 
TEST_OFILES = $(OBJ)test_case.o $(OBJ)puissance.o

all: main.out test.out

main.out: $(OFILES)
	$(CC) $(CFLAGS) -o $@ $(OFILES)

test.out: $(TEST_OFILES)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ):
	mkdir $@

$(OBJ)main.o: $(SRC)main.c $(INC)puissance.h $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@ 

$(OBJ)puissance.o: $(SRC)puissance.c $(INC)puissance.h $(OBJ)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ)test_case.o: $(TEST)test_case.c $(INC)puissance.h $(TEST)test.h $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

test: test.out
	./test.out

run: main.out
	./main.out

clean:
	$(RM) -r $(OBJ)
	$(RM) ./main.out
	$(RM) ./test.out

.PHONY: all clean run test