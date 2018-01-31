#include <iostream>
#include <string>
#include <vector>
#include "minesweeper.h"
#include "split.h"

int main(int argc, char** argv){
	minesweeper ms;
	ms.init_grid();
	ms.print_grid();
	std::string input;
	std::vector<std::string> v;
	int xPos, yPos;
	bool gameOver = false;
	while(!gameOver && input != "q" && input != "Q"){
		std::cout << "Enter an xy coordinate (example: 1,2) or press q to quit: ";
		std::cin >> input;
		v = split(input);
		xPos = std::stoi(v[0]);
		yPos = std::stoi(v[1]);
		if((xPos >= 0 && xPos < ROW)&&(yPos >= 0 && yPos < COL)){
			ms.mark(xPos,yPos);
			ms.print_grid();
		}
		else std::cout << "Please use integers in the range of 0 to " << COL << '\n';
		std::cout << '\n';
	}
	return 0;
} 