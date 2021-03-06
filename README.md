<a href="https://www.codefactor.io/repository/github/stanecobalt/mine-sweeper"><img src="https://www.codefactor.io/repository/github/stanecobalt/mine-sweeper/badge" alt="CodeFactor" /></a>
# Minesweeper
### by Stephen Sladek

This is my attempt at creating the classic game Minesweeper. It is developed using 2 2D arrays, one for holding the player's interface, and the other for the underlying mines.

## How to Play
In order to play, the player will simply enter the xy coordinates of the block that they would like to select, separated by a comma.

The numbers represent how many adjacent mines there are. The goal of the game is to find all the empty tiles without hitting any of the mines. The number of mines is dependent upon the number of rows. So if there are 8 rows, then there are 8 mines in the field.

### Gameplay
<img src="images/playthrough.gif" alt="animated playthrough of minesweeper" width="75%" />

## Building the Project

I like to use MinGW to build my projects. If you want to build the game just use the following command:
`g++ main.cpp minesweeper.h minesweeper.cpp split.h -o minesweeper.exe`

Alternatively, if you have CMake installed, you can just run `make all` in the command prompt and the makefile will put it together for you.

After that just run minesweeper.exe and have fun doing minesweeper console style!
