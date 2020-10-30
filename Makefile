SHELL=/bin/bash

OBJS = Unit.o Player.o Game.o main.o Json.o
OUT = a.out
CFLAGS = -Wall -std=c++17
CC = g++

default: build

build: $(OBJS)
	$(CC) $(CFLAGS) -o $(OUT) $(OBJS)

Json.o: Json.cpp Json.h
	$(CC) $(CFLAGS) -c Json.cpp

Player.o: Player.cpp Player.h
	$(CC) $(CFLAGS) -c Player.cpp

Unit.o: Unit.cpp Unit.h Json.h
	$(CC) $(CFLAGS) -c Unit.cpp

Game.o: Game.cpp Game.h Player.h
	$(CC) $(CFLAGS) -c Game.cpp

main.o: main.cpp Player.h Game.h
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