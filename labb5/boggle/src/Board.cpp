#include "Board.h"
#include "shuffle.h"

static const int NUM_CUBES = 16;   // the number of cubes in the game
static const int BOARD_SIZE = 4;
static const std::string CUBE_SIDES[NUM_CUBES] = {        // the letters on all 6 sides of every cube
/*"AAAAAA", "BBBBBB", "CCCCCC", "DDDDDD",
"EEEEEE", "FFFFFF", "GGGGGG", "HHHHHH",
"IIIIII", "JJJJJJ", "KKKKKK", "LLLLLL",
"MMMMMM", "NNNNNN", "OOOOOO", "PPPPPP"*/
   "AAEEGN", "ABBJOO", "ACHOPS", "AFFKPS",
   "AOOTTW", "CIMOTU", "DEILRX", "DELRVY",
   "DISTTY", "EEGHNW", "EEINSU", "EHRTVW",
   "EIOSST", "ELRTTY", "HIMNQU", "HLNNRZ"
};

Board::Board() {
	unsigned int sideIndex = 0;
	cubes = Grid<Cube>(BOARD_SIZE, BOARD_SIZE);
	for (unsigned int i = 0; i < BOARD_SIZE; ++i) {
		for (unsigned int j = 0; j < BOARD_SIZE; ++j) {
			cubes[i][j] = Cube(CUBE_SIDES[sideIndex]);
			sideIndex++;
		}
	}
	shuffleBoard();
}

void Board::shuffleBoard() {
	for (Cube c : cubes) {
		c.shuffle();
	}
	shuffle(cubes); 
}

std::string Board::toString() const {
	std::string result = "";
	for (unsigned int i = 0; i < BOARD_SIZE; ++i) {
		for (unsigned int j = 0; j < BOARD_SIZE; ++j) {
			result += cubes[i][j].sideUp();
			result += ' ';
		}
		result += "\n";
	}
	return result;
}

bool Board::isNeighbor(int row, int col, char c) const {
	vector<pair<int, int>> indices(row * col);
	for (int r = row - 1; r <= row + 1; ++r) {
		for (int c = col - 1; c <= col + 1; ++c) {
			if (cubes.inBounds(r, c)) {
				indices.push_back(pair<int,int>(r, c));
			}
		}
	}
	for (auto index : indices) {
		if (cubes[index.first][index.second].sideUp() == c) return true;
	}
	return false;
}

int factorial(int n) {
	if (n == 0) return 1;
	else return n*factorial(n - 1);
}

