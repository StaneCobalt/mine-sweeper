const unsigned ROW = 8;
const unsigned COL = 8;

class minesweeper{
	private:
		char grid[ROW][COL];
		char mines[ROW][COL];
		bool mineHit;
		bool recursionCalled[8];
	public:
		minesweeper() { mineHit = false; }
		void init_grid();
		void print_grid();
		void mark(unsigned x, unsigned y);
		void clear_empty(unsigned x, unsigned y);
		bool isMine(unsigned x, unsigned y);
		char howNear(unsigned x, unsigned y);
		bool getMineHit() { return mineHit; }
		bool gameWon();
		bool getRecursionCalled(int n){
			return (n > 0 && n < 8) ? recursionCalled[n] : false;
		}
		void resetCalls(){
			for(unsigned short i = 0; i < 8; i++){
				recursionCalled[i] = false;
			}
		}
};