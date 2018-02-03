#include <iostream>
#include "minesweeper.h"
#include <cstdlib>
#include <time.h>

void minesweeper::init_grid(){
	srand(time(NULL));
	//initialize player grid
	for(unsigned short i = 0; i < ROW; i++){
		for(unsigned short j = 0; j < COL; j++){
			grid[i][j] = '?';
		}
	}
	//initialize mine grid
	for(unsigned short i = 0; i < ROW; i++){
		for(unsigned short j = 0; j < COL; j++){
			mines[i][j] = 'x';
		}
	}
	//plant mines
	for(int i = 0; i < ROW; i++){
		int x = rand() % ROW;
		int y = rand() % COL;
		mines[x][y] = 'o';
	}
}

void minesweeper::print_grid(){
	for(unsigned short i = 0; i < ROW; i++){
		for(unsigned short j = 0; j < COL; j++){
			std::cout << grid[i][j] << ' ';
		}
		std::cout << '\n';
	}
}

void minesweeper::mark(unsigned x, unsigned y){
	if(x < ROW && y < COL){
		if(grid[x][y] == '?'){
			if(isMine(x,y)){
				std::cout << "- You hit a mine! -\n";
				grid[x][y] = 'X';
				mineHit = true; //triggers game over
			}
			else {
				grid[x][y] = howNear(x,y);
				if(grid[x][y] == '0'){
					clear_empty(x,y);
				}
			}
		}
		else std::cout << "Try again.\n";
		//TODO: add check for full grid, minus the mine tiles
	}
}

void minesweeper::clear_empty(unsigned x, unsigned y){
	//if marked tile is a 0, automatically marks all adjacent tiles
	if(x > 0)
		grid[x-1][y] = howNear(x-1,y);
	if(y > 0)
		grid[x][y-1] = howNear(x,y-1);
	if(x > 0 && y > 0)
		grid[x-1][y-1] = howNear(x-1,y-1);
	if(x < ROW-1)
		grid[x+1][y] = howNear(x+1,y);	
	if(y < COL-1)
		grid[x][y+1] = howNear(x,y+1);
	if(x < ROW-1 && y < COL-1)
		grid[x+1][y+1] = howNear(x+1,y+1);
	if(x > 0 && y < COL-1)
		grid[x-1][y+1] = howNear(x-1,y+1);
	if(x < ROW-1 && y > 0)
		grid[x+1][y-1] = howNear(x+1,y-1);
}

bool minesweeper::isMine(unsigned x, unsigned y){
	return (mines[x][y] == 'o');
}

char minesweeper::howNear(unsigned x, unsigned y){
	//calculates how many mines are adjacent and diagonal to this tile
	unsigned short count = 0;
	if(x > 0)
		if(isMine(x-1,y)) count++;
	if(x > 0 && y > 0)
		if(isMine(x-1,y-1)) count++;
	if(x > 0 && y < COL-1)
		if(isMine(x-1,y+1)) count++;
	if(y > 0)
		if(isMine(x,y-1)) count++;
	if(y < COL-1)
		if(isMine(x,y+1)) count++;
	if(x < ROW-1 && y > 0)
		if(isMine(x+1,y-1)) count++;
	if(x < ROW-1)
		if(isMine(x+1,y)) count++;
	if(x < ROW-1 && y < COL-1)
		if(isMine(x+1,y+1)) count++;
	//return the character representation
	switch(count){
		case 0:
			return '0';
		case 1:
			return '1';
		case 2:
			return '2';
		case 3:
			return '3';
		case 4:
			return '4';
		case 5:
			return '5';
		case 6:
			return '6';
		case 7:
			return '7';
		case 8:
			return '8';
		default:
			return '#';
	}
}

bool minesweeper::gameWon(){
	unsigned count = 0;
	for(auto &row : grid){
		for(auto &tile : row){
			if(tile == '?') count++;
			if(count > ROW){
				return false;
			}
		}
	}
	return true;
}
