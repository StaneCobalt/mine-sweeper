#include <array>

const unsigned ROW = 8;
const unsigned COL = 8;
const unsigned domain = ROW-1;
const unsigned range = COL-1;

class minesweeper{
	private:
		std::array<std::array<char,ROW>,COL> grid;
		std::array<std::array<char,ROW>,COL> mines;
		bool mineHit;
	public:
		minesweeper() { mineHit = false; }
		void init_grid();
		void print_grid();
		void mark(unsigned x, unsigned y);
		bool marked(unsigned x, unsigned y){ return grid[x][y] != '#'; }
		void clear_empty(unsigned x, unsigned y);
		bool isMine(unsigned x, unsigned y);
		char howNear(unsigned x, unsigned y);
		bool getMineHit() { return mineHit; }
		bool gameWon();
};
