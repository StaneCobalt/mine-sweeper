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
		char howNear(unsigned x, unsigned y);
		bool getMineHit() { return mineHit; }
		bool gameWon();
};