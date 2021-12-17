###### VARIABLES #######
CC = gcc
CFLAGS = -ansi -Wall -pedantic 
RM = rm -f

# Dossiers du projets
SRC = src
INCLUDE = src/include
OBJ = obj

OBJECTS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(wildcard $(SRC)/*.c))

MAIN = pong.out

all: $(MAIN)

$(MAIN): $(OBJ) $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

$(OBJ):
	mkdir $@

obj/%.o: src/%.c $(INCLUDE)/%.h 
	$(CC) $(CFLAGS) -o $@ -c $<

run:
	./$(MAIN)

clean:
	$(RM) -r $(OBJ)
	$(RM) $(MAIN)

.PHONY: all clean run