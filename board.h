#ifndef BOARD_H
#define BOARD_H

#include <cstdio> /** NULL */
#include <cstdlib> /** srand(), rand() */
#include <ctime> /** time() */
#include <iostream>

class Board
{
	public:
		Board();
		void randomShips();
		void pickShips();
		void printBoards();
	private:
		int shipBoard [10][10];
		char hitBoard [10][10];
};

#endif
