/*
* This is the datastructure that describes a board object.
*/

#ifndef BOARD_H
#define BOARD_H
#include <string>
#include "grid.h"
#include "Cube.h"

class Board {
	public:
	/*
	Constructs a board.
	*/
	Board();
	/*
	Changes the sides of the cubes. Parameter sides must be 16 strings of 6
	characters each.
	*/
	void setCubeSides(const std::vector<std::string>& sides);
	/*
	Sets the cube sides to the default sides.
	*/
	void setDefault();
	/*
	Gets a string representation of the board.
	*/
	std::string toString() const;
	/*
	 * Marks or unmarks a cube as visited in backtracking algorithm.
	 */
	void setVisited(const int row, const int col, const bool aFlag);

	bool isVisited(const int row, const int col) const;
	/*
	 * Returns the up-facing cube side at given index.
	 */
	char cubeSideAt(const unsigned int row, const unsigned int col) const;
	/*
	 * Gets the indices of all neighbors to the given index.
	*/
	std::vector<std::pair<int,int>> getNeighbors(int row, int col) const;
	/*
	 * Gets possible starting points for backtracking algorithm. Returns a vector of
	 * indices where the given char is found.
	 */
	std::vector<std::pair<int,int>> getPossibleStartingPoints(char c) const;
	
	/*
	 * Gets indices for ALL of the board's cubes.
	 */
	std::vector<std::pair<int,int>> getAllStartingPoints() const;

	static const int BOARD_SIZE = 4;

	private:
	/*
	Checks whether the char given is a neighbor to the given index, or if it is
	equal to the char of the given index.
	*/
	bool isNeighbor(int row, int col, char c) const;
	/*
	Shuffles the board.
	*/
	void shuffleBoard();
	/*
	The cubes
	*/
	Grid<Cube> cubes;

};


#endif