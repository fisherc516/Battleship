#include "game.h"

Game::Game(Board* p, Board* c)
{
	player = p;
	computer = c;
}
bool Game::playerGuess()
{
	return(false);
}
bool Game::compGuess()
{
	return(false);
}
