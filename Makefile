SHELL=/bin/bash

OBJS = json.o player.o game.o main.o unit.o
OUT = a.out
CFLAGS = -Wall -std=c++17
CC = g++

default: build

build: $(OBJS)
	$(CC) $(CFLAGS) -o $(OUT) $(OBJS)

json.o: json.cpp
	$(CC) $(CFLAGS) -c json.cpp

unit.o: unit.cpp
	$(CC) $(CFLAGS) -c unit.cpp

player.o: player.cpp
	$(CC) $(CFLAGS) -c player.cpp

game.o: game.cpp
	$(CC) $(CFLAGS) -c game.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

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