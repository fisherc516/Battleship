#ifndef GAME_H
#define GAME_H

#include "board.h"
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>

class Game
{
	public:
		// Sets player and computer
		Game(Board* p, Board* c);
		// Lets player guess coordinates to attack; returns true if all computer's ships are sunk
		bool playerGuess();
		// Chooses random coordinates to attack; returns true if all player's ships are sunk
		bool compGuess();
		// Makes sure coordinate is valid
		bool numbersChecker(std::string g);
	private:
		Board* player;
		Board* computer;
};

#endif
