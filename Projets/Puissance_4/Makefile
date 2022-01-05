###### VARIABLES #######
ifeq ($(OS),Windows_NT)
  ifeq ($(shell uname -s),) # not in a bash-like shell
	RM = del /F /Q
	MKDIR = mkdir
  else # in a bash-like shell, like msys
	RM = rm -f
	MKDIR = mkdir -p
  endif
	EXTENSION=.exe
else
	RM = rm -f
	MKDIR = mkdir -p
	EXTENSION=out
endif

CC = gcc
CFLAGS = -ansi -Wall -pedantic 
RM = rm -f

SRC 	= ./src
OBJ 	= ./obj
INCLUDE = ./src/include
TESTDIR = ./tests

sources 		= $(wildcard $(SRC)/*.c)
test_sources 	= $(wildcard $(TESTDIR)/*.c)
includes 		= $(wildcard $(INCLUDE)/*.h)
objects 		= $(sources:$(SRC)/%.c=$(OBJ)/%.o)
test_objects 	= $(test_sources:$(TESTDIR)/%.c=$(OBJ)/%.o)

MAIN = pong.$(EXTENSION)
TEST = test.$(EXTENSION)

###### REGLES #######

all: $(MAIN) $(TEST)

$(MAIN): $(objects)
	$(CC) $(CFLAGS) -o $@ $^
 
$(TEST): $(test_objects) $(OBJ)/toto.o
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ):
	mkdir $@

$(objects): $(OBJ)/%.o : $(SRC)/%.c $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(test_objects): $(OBJ)/%.o : $(TESTDIR)/%.c $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@



run: $(MAIN)
	./$(MAIN)

test: $(TEST)
	./$(TEST)

clean:
	$(RM) -r $(OBJ)
	$(RM) $(MAIN)
	$(RM) $(TEST)

.PHONY: all clean run test