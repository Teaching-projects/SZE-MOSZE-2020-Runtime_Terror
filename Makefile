SHELL=/bin/bash

OUT = a.out
CFLAGS = -Wall -std=c++17
CC = g++-9

default: build

build:
	$(CC) $(CFLAGS) *.cpp -o $(OUT)

buildtest:
	chmod +x test.sh
	./test.sh

memory_leak_check:
	cat input.txt | valgrind --error-exitcode=1 --leak-check=full ./$(OUT) 2> ./memory-leak-check.txt

static_code_analysis:
	cppcheck --enable=all *.cpp 2> static-code-analysis.txt
	cppcheck --enable=warning --error-exitcode=1 *.cpp

documentation:
	doxygen doxconf

unittest:
	cd /usr/src/gtest && cmake CMakeLists.txt && make
	ln -st /usr/lib/ /usr/src/gtest/libgtest.a && ln -st /usr/lib/ /usr/src/gtest/libgtest_main.a
	cd test && cmake CMakeLists.txt
	cd test && make
	cd test && ./runTests

clean:
	rm -rf $(OBJS) $(OUT)