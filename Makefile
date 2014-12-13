CC=gcc
TGT=build
INCLUDES = -Iinclude
FLAGS = -Wall $(INCLUDES)

CC_FILES = $(shell find src -type f -name "*.c" ! -name "main.c")

help:
	@echo ""
	@echo "Makefile for Building Cobra."
	@echo "Usage: make [ all | clean | help | build | run] " 
	@echo ""

build:
	zip -r cobra.zip ./build/Cobra

all: buildCC
	@echo "Done"
	@echo ""

buildCC:
	@echo "" 
	@echo "Building Cobra..."
	$(CC) $(FLAGS) $(CC_FILES) src/main.c -o build/Cobra 

run:
	./build/Cobra

clean:
	rm -rf build/*.o