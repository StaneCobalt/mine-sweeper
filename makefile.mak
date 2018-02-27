CC = g++ $(CCFLAGS)

CCFLAGS = -std=c++11

all: minesweeper

minesweeper: main.o minesweeper.o
	$(CC) main.o minesweeper.o -o minesweeper.exe

main.o: main.cpp split.h minesweeper.h
	$(CC) -c main.cpp

minesweeper.o: minesweeper.cpp minesweeper.h
	$(CC) -c minesweeper.cpp
