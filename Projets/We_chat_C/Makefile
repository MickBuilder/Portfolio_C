###### VARIABLES #######
ifeq ($(OS),Windows_NT)
  ifeq ($(shell uname -s),) # not in a bash-like shell
	RM = del /F /Q
	MKDIR = mkdir
  else # in a bash-like shell, like msys
	RM = rm -f
	MKDIR = mkdir -p
  endif
#   for the compiler error https://stackoverflow.com/questions/42849623/allegro-5-game-wont-compile-with-gcc
	LDFLAGS = -L lib -lallegro -lallegro_primitives -lallegro_dialog -mwindows
	EXTENSION=exe
else
	# LDFLAGS = `pkg-config --libs --cflags allegro-5` 
	# RM = rm -f
	# MKDIR = mkdir -p
	# EXTENSION=out
	LDFLAGS = -L./lib/ -lallegro -lallegro_primitives -lallegro_dialog -Wl,-rpath,.
	RM = rm -f
	MKDIR = mkdir -p
	EXTENSION=out
endif

# To fix my problem on linux platform, I use this link to set a env variable
# Stack Over https://stackoverflow.com/questions/787684/set-ld-library-path-from-makefile

CC = gcc
CFLAGS 	= -ansi -Wall -pedantic -I include
RM = rm -f

SRC 		= ./src
TESTDIR 	= ./tests
OBJ 		= ./obj
BIN 		= ./bin

sources 		= $(wildcard $(SRC)/*.c)
test_sources 	= $(wildcard $(TESTDIR)/*.c)
objects 		= $(sources:$(SRC)/%.c=$(OBJ)/%.o)
test_objects 	= $(test_sources:$(TESTDIR)/%.c=$(OBJ)/%.o)

MAIN = $(BIN)/game.$(EXTENSION)
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
	LD_LIBRARY_PATH=${PWD}/lib ./$(MAIN)

test: $(TEST)
	./$(TEST)

clean:
	$(RM) -r $(OBJ)
	$(RM) $(MAIN)
	$(RM) $(TEST)

.PHONY: all clean run test
