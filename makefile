SRC  = $(wildcard src/*.c)
DEPS = $(wildcard src/*.h)
OBJ  = $(addsuffix .o,$(subst src/,bin/,$(basename $(SRC))))

BIN     = ./bin
OUT     = $(BIN)/app
INSTALL = /usr/bin/avm

CC     = gcc
CSTD   = c99
CFLAGS = -static -Og -std=$(CSTD) -Wall -Wextra -Werror -pedantic -Wno-deprecated-declarations

compile: $(BIN) $(OBJ) $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(OBJ) $(LIBS)

bin/%.o: src/%.c $(DEPS)
	$(CC) -c $< $(CFLAGS) -o $@

$(BIN):
	mkdir -p bin

install:
	cp $(OUT) $(INSTALL)

clean:
	rm -r $(BIN)/*

all:
	@echo compile, install, clean
