#include <iostream>
#include "minesweeper.h"

int main(int argc, char** argv){
	minesweeper ms;
	ms.init_grid();
	ms.print_grid();
	//TODO: add logic for selecting value and checking if mine was hit
	return 0;
} 