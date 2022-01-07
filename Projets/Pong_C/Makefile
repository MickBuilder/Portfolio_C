###### VARIABLES #######
ifeq ($(OS),Windows_NT)
  ifeq ($(shell uname -s),) # not in a bash-like shell
	RM = del /F /Q
	MKDIR = mkdir
  else # in a bash-like shell, like msys
	RM = rm -f
	MKDIR = mkdir -p
  endif
	LDFLAGS = -L lib -lmingw32 -lSDL2main -lSDL2 -mwindows
	EXTENSION=exe
else
	LDFLAGS = `sdl2-config --cflags --libs` 
	RM = rm -f
	MKDIR = mkdir -p
	EXTENSION=out
endif

CC = gcc
CFLAGS 	= -ansi -Wall -pedantic -I include
RM = rm -f

SRC 		= ./src
INCLUDE 	= ./src/include
TESTDIR 	= ./tests
OBJ 		= ./obj
BIN 		= ./bin

sources 		= $(wildcard $(SRC)/*.c)
test_sources 	= $(wildcard $(TESTDIR)/*.c)
includes 		= $(wildcard $(INCLUDE)/*.h)
objects 		= $(sources:$(SRC)/%.c=$(OBJ)/%.o)
test_objects 	= $(test_sources:$(TESTDIR)/%.c=$(OBJ)/%.o)

MAIN = $(BIN)/pong.$(EXTENSION)
TEST = test.$(EXTENSION)

###### REGLES #######

all: $(MAIN) #$(TEST)

$(MAIN): $(objects)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
 
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