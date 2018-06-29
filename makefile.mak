CC = g++ $(CCFLAGS)

CCFLAGS = -std=c++11

all: minesweeper

minesweeper: main.o minesweeper.o
	$(CC) main.o minesweeper.o -o minesweeper.exe

main.o: src/main.cpp include/split.h include/minesweeper.h
	$(CC) -c src/main.cpp

minesweeper.o: src/minesweeper.cpp include/minesweeper.h
	$(CC) -c src/minesweeper.cpp
