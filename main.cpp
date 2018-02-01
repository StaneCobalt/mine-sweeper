#include <iostream>
#include <string>
#include <vector>
#include "minesweeper.h"
#include "split.h"

int main(int argc, char** argv){
	std::string input;
	std::vector<std::string> v;
	int xPos, yPos;
	bool gameOver = false;
	minesweeper ms;
	ms.init_grid();
	ms.print_grid();
	while(!gameOver && input != "q" && input != "Q"){
		std::cout << "Enter an xy coordinate (example: 1,2) or press q to quit: ";
		std::cin >> input;
		if(input.length() > 2){
			v = split(input);
			xPos = std::stoi(v[0]);
			yPos = std::stoi(v[1]);
			if((xPos >= 0 && xPos < ROW)&&(yPos >= 0 && yPos < COL)){
				ms.mark(xPos,yPos);
				ms.print_grid();
				if(ms.getMineHit()){
					gameOver = true;
					std::cout << "Game Over\n";
				}
				else if(ms.gameWon()){
					gameOver = true;
					std::cout << "Congratulations! You beat Minesweeper!\n";
				}
			}
			else std::cout << "Please use integers in the range of 0 to " << ROW << '\n';
		}
		else std::cout << "Please use 2 integers in the range of 0 to " << ROW << " separated by a comma\n";
		std::cout << '\n';
	}
	return 0;
} 