#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "../include/minesweeper.h"
#include "../include/split.h"

#ifdef _WIN32
	void clearScreen(){
		system("CLS");
	}

#elif _APPLE_
	void clearScreen(){
		system("clear");
	}

#elif _linux_
	void clearScreen(){
		system("clear & clear");
	}

#else
	void clearScreen(){
		std::cout << "\n";
	}
	
#endif

int main(int argc, char** argv){
	const std::string title = "\n -------------------------\n| Welcome to Minesweeper! |\n -------------------------\n\n";
	std::string input;
	std::vector<std::string> v;
	int xPos, yPos;
	bool gameOver = false;
	minesweeper ms;
	
	clearScreen();
	std::cout << title;
	ms.init_grid();
	ms.print_grid();
	
	while((!gameOver)&&(input != "q")&&(input != "Q")){
		std::cout << "Enter a Row, Column coordinate (example: 1,2) or press q to quit: ";
		std::cin >> input;
		if(input.length() > 2){
			try{
				v = split(input);
				xPos = std::stoi(v[0]);
				yPos = std::stoi(v[1]);
				if((xPos >= 0 && xPos < ROW)&&(yPos >= 0 && yPos < COL)){
					ms.mark(xPos,yPos);
					clearScreen();
					std::cout << title;
					ms.print_grid();
					if(ms.getMineHit()){
						gameOver = true;
						std::cout << "You hit a mine!\n- Game Over -" << std::endl;
					} else if(ms.gameWon()){
						gameOver = true;
						std::cout << "Congratulations!\n- You beat Minesweeper! -" << std::endl;
					}
				} else {
					std::cout << "Please use integers in the range of 0 to " << domain << '\n';
				}
			}
			catch(int e){
				std::cerr << "An Exception Occurred. " << e << std::endl;
			}
		}
		else if(input !="q" && input !="Q") {
			std::cout << "Please use 2 integers in the range of 0 to " << domain << " separated by a comma\n";
		}
	}
	return 0;
}
