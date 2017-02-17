#ifndef BOARD_H
#define BOARD_H

#include <cstdio> /** NULL */
#include <cstdlib> /** srand(), rand() */
#include <ctime> /** time() */
#include <iostream>
#include <string>

class Board
{
	public:
		// Creates two 2D arrays for tracking hits and misses	
		Board();
		// Deletes a board
		~Board();
		// Places ships randomly on shipBoard
		void randomShips();
		// Allows user to place ships manually
		void pickShips();
		// Illicits valid ship placement from user
		void getCoordinates(int shipLength);
		// Prints hitBoard(1)/shipBoard(2)/or both(3)
		void printBoards(int n) const;
		// Makes sure letters and numbers of coordinates are valid
		bool coordinatesChecker(std::string c);
		// Makes sure coordinates span correct number of spaces for each ship's length
		bool spaceChecker(std::string c, int spaces);
		// Returns shipBoard
		char** getShipBoard();
		// Returns hitBoard
		char** getHitBoard();	
	private:
		char** shipBoard;
		char** hitBoard;
};

#endif
