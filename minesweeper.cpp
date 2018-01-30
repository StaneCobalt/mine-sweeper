#include <iostream>
#include "minesweeper.h"
using std::cout;

int main(int argc, char** argv){
	minesweeper ms;
	ms.init_grid();
	ms.print_grid();
	//TODO: add logic for selecting value and checking if mine was hit
	return 0;
} 