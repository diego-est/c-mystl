
.POSIX:

.PHONY: run build

SRC = ./src/main.c ./src/mystl.c
CC = clang
CFLAGS = -Wconversion -Wall -Wswitch-enum -Wextra -pedantic --std=c11
DEBUG = ./build/debug/debug
RELEASE = ./build/release/release

all: options build

options:
	@echo mystl build options:
	@echo "CC	= $(CC)"
	@echo "CFLAGS	= $(CFLAGS)"

run: build
	$(DEBUG)

build:
	$(CC) $(CFLAGS) -Os $(SRC) -o $(DEBUG)

debug: check
	$(CC) $(CFLAGS) -Og -ggdb $(SRC) -o $(DEBUG)

release:
	$(CC) $(CFLAGS) -O3 $(SRC) -o $(RELEASE)

format:
	clang-format -i $(SRC) --style="{BasedOnStyle: GNU, ColumnLimit: 100}"

check:
	clang-tidy -extra-arg=-std=c11 $(SRC)
