#include <iostream>
#include <cstdlib>
#include <time.h>

const unsigned ROW = 8;
const unsigned COL = 8;

class minesweeper{
	private:
		char grid[ROW][COL];
		char mines[ROW][COL];
		bool mineHit;
	public:
		minesweeper() { mineHit = false; }
		void init_grid();
		void print_grid();
		void mark(unsigned x, unsigned y);
		bool isMine(unsigned x, unsigned y);
		
};

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
				std::cout << "You hit a mine!\n";
				mineHit = true;
			}
			else grid[x][y] = '0'; //TODO: show number of nearby mines
		}
	}
}

bool minesweeper::isMine(unsigned x, unsigned y){
	return (mines[x][y] == 'o');
}
