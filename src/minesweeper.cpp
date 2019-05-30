#include <iostream>
#include <array>
#include "../include/minesweeper.h"
#include <cstdlib>
#include <time.h>

void minesweeper::init_grid() {
	srand(time(nullptr));
	//initialize player grid
	for(auto &row : grid) {
		row.fill('#');
	}
	//initialize mine grid
	for(auto &row : mines) {
		row.fill('o');
	}
	//plant mines
	for(int i = 0; i < ROW; i++) {
		int x = rand() % ROW;
		int y = rand() % COL;
		mines[x][y] = 'x';
	}
}

void minesweeper::print_grid() {
	unsigned short i;
	std::cout << "    ";
	for(i = 0; i < ROW; i++)
		std::cout << ' ' << i;
	std::cout << "\n    ";
	for(i = 0; i < ROW; i++)
		std::cout << "--";
	std::cout << '\n';
	for(i = 0; i < ROW; i++) {
		std::cout << ' ' << i << " | ";
		for(unsigned short j = 0; j < COL; j++)
			std::cout << grid[i][j] << ' ';
		std::cout << '\n';
	}
	std::cout << '\n';
}

void minesweeper::mark(unsigned x, unsigned y) {
	if(x < ROW && y < COL) {
		if(grid[x][y] == '#') {
			if(isMine(x,y)) {
				grid[x][y] = 'X';
				mineHit = true; //triggers game over
			} else {
				grid[x][y] = howNear(x,y);
				if(grid[x][y] == '0')
					clear_empty(x,y); //clears nearby tiles, since none are mines
			}
		}
		else
			std::cout << "Try again.\n";
	}
}

void minesweeper::clear_empty(unsigned x, unsigned y) {
	// If the marked tile is a 0, automatically marks all adjacent tiles
	const char zero = '0';

	if(x > 0) {
		if(!marked(x-1,y)) {
			grid[x-1][y] = howNear(x-1,y);
			if(grid[x-1][y] == zero)
				clear_empty(x-1,y);
		}
	}
	if(y > 0) {
		if(!marked(x,y-1)) {
			grid[x][y-1] = howNear(x,y-1);
			if(grid[x][y-1] == zero)
				clear_empty(x,y-1);
		}
	}
	if(x > 0 && y > 0) {
		if(!marked(x-1,y-1)) {
			grid[x-1][y-1] = howNear(x-1,y-1);
			if(grid[x-1][y-1] == zero)
				clear_empty(x-1,y-1);
		}
	}
	if(x < domain) {
		if(!marked(x+1,y)) {
			grid[x+1][y] = howNear(x+1,y);
			if(grid[x+1][y] == zero)
				clear_empty(x+1,y);
		}
	}
	if(y < range) {
		if(!marked(x,y+1)) {
			grid[x][y+1] = howNear(x,y+1);
			if(grid[x][y+1] == zero)
				clear_empty(x,y+1);
		}
	}
	if(x < domain && y < range) {
		if(!marked(x+1,y+1)) {
			grid[x+1][y+1] = howNear(x+1,y+1);
			if(grid[x+1][y+1] == zero)
				clear_empty(x+1,y+1);
		}
	}
	if(x > 0 && y < range) {
		if(!marked(x-1,y+1)) {
			grid[x-1][y+1] = howNear(x-1,y+1);
			if(grid[x-1][y+1] == zero)
				clear_empty(x-1,y+1);
		}
	}
	if(x < domain && y > 0) {
		if(!marked(x+1,y-1)) {
			grid[x+1][y-1] = howNear(x+1,y-1);
			if(grid[x+1][y-1] == zero)
				clear_empty(x+1,y-1);
		}
	}
	return;
}

bool minesweeper::isMine(unsigned x, unsigned y) {
	return (mines[x][y] == 'x'); //mines are represented by 'x' and safe spots by 'o'
}

unsigned minesweeper::mineCount(unsigned x, unsigned y) {
	try {
		if(x < domain && y < range)
			return (mines[x][y] == 'x') ? 1 : 0;
		return 0;
	} catch(int e) {
		return 0;
	}
}

char minesweeper::howNear(unsigned x, unsigned y) {
	//calculates how many mines are adjacent and diagonal to this tile
	unsigned count = 0;
	count += mineCount(x-1,y-1);
	count += mineCount(x-1,y);
	count += mineCount(x,y-1);
	count += mineCount(x+1,y+1);
	count += mineCount(x+1,y);
	count += mineCount(x,y+1);
	count += mineCount(x-1,y+1);
	count += mineCount(x+1,y-1);
	//return the character representation
	return '0'+count;
}

bool minesweeper::gameWon() {
	unsigned count = 0;
	for(auto &row : grid) {
		for(auto &tile : row) {
			if(tile == '#') count++;
			if(count > ROW) {
				return false;
			}
		}
	}
	return true;
}
