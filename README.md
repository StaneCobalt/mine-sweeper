# Minesweeper
### by Stephen Sladek

This is my attempt at creating the classic game Minesweeper. It is developed using 2 2D arrays, one for holding the player's interface, and the other for the underlying mines.

## How to Play
In order to play, the player will simply enter the xy coordinates of the block that they would like to select, separated by a comma.

The numbers represent how many adjacent mines there are. The goal of the game is to find all the empty tiles without hitting any of the mines. The number of mines is dependent upon the number of rows. So if there are 8 rows, then there are 8 mines in the field.

I like to use MinGW to build my projects. If you want to build the game just use the following command:
`g++ main.cpp minesweeper.h minesweeper.cpp split.h -o minesweeper.exe`

After that just run minesweeper.exe and have fun doing minesweeper console style!

### Starting New Game
<img src="https://github.com/StaneCobalt/mine-sweeper/blob/master/images/screenshot0.PNG" width="50%" />

### Winning Game
<img src="https://github.com/StaneCobalt/mine-sweeper/blob/master/images/screenshot2.PNG" width="50%" />

### Game Over
<img src="https://github.com/StaneCobalt/mine-sweeper/blob/master/images/screenshot1.PNG" width="50%" />
