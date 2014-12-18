CC=cc
CFLAGS=-Wall

SRC=$(wildcard src/*.c) $(wildcard src/common/*.c)

all: $(SRC)
	gcc -c -Wall $^
	make lib

lib:
	ar rvs build/libcobra.a $(wildcard *.o)
	make cleano

test:
	gcc $(FLAGS) -I ./ test/main.c -Iinclude build/libcobra.a -o build/Cobra
	@echo ""
	@echo "Running..."
	./build/Cobra

cleano:
	rm -rf *.o

clean:
	rm -rf *.o
	rm -rf build/*.a

buildtest:
	make clean
	make all
	make test

.PHONY: all clean test