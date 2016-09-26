#include <iostream>

int main()
{
	Board* computer = new Board();
	Board* player = new Board();
	computer->randomShips();
	int choice = 0;
	while(choice != 1 && choice != 2)
	{
		std::cout << "\nPlayer, do you want to...";
		std::cout << "\n\t1) place your ships yourself?";
		std::cout << "\n\t2) have your ships randomly placed?";
		std::cout << "\n: ";
		std::cin >> choice;
		if(choice == 1)
		{
			player->pickShips();
		}
		else if(choice == 2)
		{
			player->randomShips();
		}
	}
	//Let user guess
	//Computer guesses random spot - if a hit, pick consecutive spot (depth first)
	bool playerWins = false;
	bool compWins = false;
	do
	{
		playerWins = game->playerGuess();
		if(!playerWins)
		{
			compWins = game->compGuess();
		}
	}while(!playerWins && !compWins)​
	delete computer;
	delete player;
	return(0);
}
