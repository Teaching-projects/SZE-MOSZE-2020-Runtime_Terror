SHELL=/bin/bash

OBJS = Monster.o Hero.o main.o JSON.o
OUT = a.out
CFLAGS = -Wall -std=c++17
CC = g++-9

default: build

build: $(OBJS)
	$(CC) $(CFLAGS) -o $(OUT) $(OBJS)

JSON.o: JSON.cpp JSON.h
	$(CC) $(CFLAGS) -c JSON.cpp

Hero.o: Hero.cpp Hero.h Monster.h JSON.h
	$(CC) $(CFLAGS) -c Hero.cpp

Monster.o: Monster.cpp Monster.h JSON.h
	$(CC) $(CFLAGS) -c Monster.cpp

main.o: main.cpp Hero.h Monster.h JSON.h
	$(CC) $(CFLAGS) -c main.cpp

buildtest:
	chmod +x test.sh
	./test.sh

memory_leak_check:
	valgrind --error-exitcode=1 --leak-check=full ./a.out scenario/scenario1.json 2> ./memory-leak-check.txt

static_code_analysis:
	cppcheck --enable=all *.cpp 2> static-code-analysis.txt
	cppcheck --enable=warning --error-exitcode=1 *.cpp

documentation:
	doxygen doxconf

unittest:
	cd test && cmake CMakeLists.txt && make && ./runTests

clean:
	rm -rf $(OBJS) $(OUT)