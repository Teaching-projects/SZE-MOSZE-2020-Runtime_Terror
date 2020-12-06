SHELL=/bin/bash

OBJS = Monster.o Hero.o main.o JSON.o Map.o MarkedMap.o Game.o PreparedGame.o ObserverTextRenderer.o HeroTextRenderer.o
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

Map.o: Map.cpp
	$(CC) $(CFLAGS) -c Map.cpp

MarkedMap.o: MarkedMap.cpp MarkedMap.h Map.h
	$(CC) $(CFLAGS) -c MarkedMap.cpp 

Game.o: Game.cpp Monster.h Hero.h Map.h Renderer.h
	$(CC) $(CFLAGS) -c Game.cpp

PreparedGame.o: PreparedGame.cpp PreparedGame.h Game.h MarkedMap.h JSON.h Renderer.h
	$(CC) $(CFLAGS) -c PreparedGame.cpp

ObserverTextRenderer.o: ObserverTextRenderer.cpp ObserverTextRenderer.h Game.h TextRenderer.h
	$(CC) $(CFLAGS) -c ObserverTextRenderer.cpp

HeroTextRenderer.o: HeroTextRenderer.cpp HeroTextRenderer.h Game.h TextRenderer.h
	$(CC) $(CFLAGS) -c HeroTextRenderer.cpp

main.o: main.cpp JSON.h PreparedGame.h HeroTextRenderer.h ObserverTextRenderer.h
	$(CC) $(CFLAGS) -c main.cpp

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