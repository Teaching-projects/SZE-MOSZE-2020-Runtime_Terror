SHELL=/bin/bash

OBJS = unit.o player.o game.o main.o json.o
OUT = a.out
CFLAGS = -Wall -std=c++17
CC = g++

default: build

build:
	$(CC) $(CFLAGS) *.cpp

buildtest:
	bash -c "chmod +x test.sh"
	bash -c "./test.sh"

memory_leak_check:
	bash -c "valgrind --error-exitcode=1 --leak-check=full ./a.out unit1.json unit2.json 2> ./memory-leak-check.txt"

static_code_analysis:
	bash -c "cppcheck --enable=all *.cpp 2> static-code-analysis.txt"
	bash -c "cppcheck --enable=warning --error-exitcode=1 *.cpp"

documentation:
	doxygen doxconf

clean:
	rm -rf $(OBJS) $(OUT)