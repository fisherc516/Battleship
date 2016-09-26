#ifndef GAME_H
#define GAME_H

#include "board.h"
#include <iostream>

class Game
{
	public:
		Game(Board* p, Board* c);
		void playerGuess();
		void compGuess();
	private:
		Board* player;
		Board* computer;
};

#endif
