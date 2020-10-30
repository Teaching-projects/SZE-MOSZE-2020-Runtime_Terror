SHELL=/bin/bash

OBJS = player.o game.o main.o unit.o json.o
OUT = a.out
CFLAGS = -Wall -std=c++17
CC = g++

default: build

build: $(OBJS)
	$(CC) $(CFLAGS) -o $(OUT) $(OBJS)

json.o: Json.cpp
	$(CC) $(CFLAGS) -c Json.cpp

player.o: Player.cpp
	$(CC) $(CFLAGS) -c Player.cpp

unit.o: Unit.cpp
	$(CC) $(CFLAGS) -c Unit.cpp

game.o: Game.cpp
	$(CC) $(CFLAGS) -c Game.cpp

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