#include <iostream>
#include <array>
#include "../include/minesweeper.h"
#include <cstdlib>
#include <time.h>

void minesweeper::init_grid(){
	srand(time(NULL));
	//initialize player grid
	for(auto &row : grid){
		row.fill('#');
	}
	//initialize mine grid
	for(auto &row : mines){
		row.fill('o');
	}
	//plant mines
	for(int i = 0; i < ROW; i++){
		int x = rand() % ROW;
		int y = rand() % COL;
		mines[x][y] = 'x';
	}
	resetCalls(); //sets recursion call checks to false
}

void minesweeper::print_grid(){
	unsigned short i;
	std::cout << "    ";
	for(i = 0; i < ROW; i++) std::cout << ' ' << i;
	std::cout << "\n    ";
	for(i = 0; i < ROW; i++) std::cout << "--";
	std::cout << '\n';
	for(i = 0; i < ROW; i++){
		std::cout << ' ' << i << " | ";
		for(unsigned short j = 0; j < COL; j++){
			std::cout << grid[i][j] << ' ';
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

void minesweeper::mark(unsigned x, unsigned y){
	if(x < ROW && y < COL){
		if(grid[x][y] == '#'){
			if(isMine(x,y)){
				grid[x][y] = 'X';
				mineHit = true; //triggers game over
			}
			else {
				grid[x][y] = howNear(x,y);
				if(grid[x][y] == '0'){
					resetCalls(); //resets recursion calls
					clear_empty(x,y); //clears nearby tiles, since none are mines
				}
			}
		}
		else std::cout << "Try again.\n";
	}
}

void minesweeper::clear_empty(unsigned x, unsigned y){
	/* If the marked tile is a 0, automatically marks all adjacent tiles
	* Using recursionCalled to limit excess memory being used.
	* Each tile will only have 1 call. 
	* The calls are reset to false when clear_empty is initially called
	*/
	if(x > 0){
		grid[x-1][y] = howNear(x-1,y);
		if(grid[x-1][y] == '0' && !recursionCalled[0]){
			recursionCalled[0] = true;
			return clear_empty(x-1,y);
		}
	}
	if(y > 0){
		grid[x][y-1] = howNear(x,y-1);
		if(grid[x][y-1] == '0' && !recursionCalled[1]){
			recursionCalled[1] = true;
			return clear_empty(x,y-1);
		}
	}
	if(x > 0 && y > 0){
		grid[x-1][y-1] = howNear(x-1,y-1);
		if(grid[x-1][y-1] == '0' && !recursionCalled[2]){
			recursionCalled[2] = true;
			return clear_empty(x-1,y-1);
		}
	}
	if(x < domain){
		grid[x+1][y] = howNear(x+1,y);
		if(grid[x+1][y] == '0' && !recursionCalled[3]){
			recursionCalled[3] = true;
			return clear_empty(x+1,y);
		}
	}
	if(y < range){
		grid[x][y+1] = howNear(x,y+1);
		if(grid[x][y+1] == '0' && !recursionCalled[4]){
			recursionCalled[4] = true;
			return clear_empty(x,y+1);
		}
	}
	if(x < domain && y < range){
		grid[x+1][y+1] = howNear(x+1,y+1);
		if(grid[x+1][y+1] == '0' && !recursionCalled[5]){
			recursionCalled[5] = true;
			return clear_empty(x+1,y+1);
		}
	}
	if(x > 0 && y < range){
		grid[x-1][y+1] = howNear(x-1,y+1);
		if(grid[x-1][y+1] == '0' && !recursionCalled[6]){
			recursionCalled[6] = true;
			return clear_empty(x-1,y+1);
		}
	}
	if(x < domain && y > 0){
		grid[x+1][y-1] = howNear(x+1,y-1);
		if(grid[x+1][y-1] == '0' && !recursionCalled[7]){
			recursionCalled[7] = true;
			return clear_empty(x+1,y-1);
		}
	}
	return;
}

bool minesweeper::isMine(unsigned x, unsigned y){
	return (mines[x][y] == 'x'); //mines are represented by x and safe spots by o
}

char minesweeper::howNear(unsigned x, unsigned y){
	//calculates how many mines are adjacent and diagonal to this tile
	unsigned short count = 0;
	if(x > 0)
		if(isMine(x-1,y)) count++;
	if(x > 0 && y > 0)
		if(isMine(x-1,y-1)) count++;
	if(x > 0 && y < range)
		if(isMine(x-1,y+1)) count++;
	if(y > 0)
		if(isMine(x,y-1)) count++;
	if(y < range)
		if(isMine(x,y+1)) count++;
	if(x < domain && y > 0)
		if(isMine(x+1,y-1)) count++;
	if(x < domain)
		if(isMine(x+1,y)) count++;
	if(x < domain && y < range)
		if(isMine(x+1,y+1)) count++;
	//return the character representation
	return '0'+count;
}

bool minesweeper::gameWon(){
	unsigned count = 0;
	for(auto &row : grid){
		for(auto &tile : row){
			if(tile == '#') count++;
			if(count > ROW){
				return false;
			}
		}
	}
	return true;
}
