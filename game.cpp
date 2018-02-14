#include "game.h"

Game::Game(Board* p, Board* c)
{
	player = p;
	computer = c;
}
bool Game::playerGuess()
{
	int row;
	int column;
	std::string preguess = "";
	std::string guess = "";
	bool isEntryCorrect = false;
	
	player->printBoards(3);
	do
	{
		std::cout << "\nGuess a spot e.g. A0";
		do
		{
			std::cout << "\n\n: ";
			preguess = "";
			guess = "";
			std::cin >> preguess;
		
			// Remove all but alphanumeric characters
			for(int i = 0; i < preguess.length(); i++)
			{
				if(std::isalpha(preguess[i]))
				{
					char c = toupper(preguess[i]);
					guess = guess + c;
				}
				else if(std::isdigit(preguess[i]))
				{
					guess = guess + preguess[i];
				}
			}
		
			if(guess.length() != 2)
			{
				std::cout << "\nPlease make sure you have no extra characters in your guess";
			}
			else if(!numbersChecker(guess))
			{
				std::cout << "\nPlease make sure your letters/numbers are correct (A-J, 0-9)";
			}
			else
			{
				isEntryCorrect = true;
			}
		}while(!isEntryCorrect);
		if(player->getHitBoard()[guess[0]-'A'][guess[1]-'0'] != '.')
		{
			std::cout << "\nYou have already guessed that spot!";
		}
	}while(player->getHitBoard()[guess[0]-'A'][guess[1]-'0'] != '.');
	
	column = guess[1] - '0';
	row = guess[0] - 'A';
	if(computer->getShipBoard()[row][column] != '.') //Hit
	{
		player->getHitBoard()[row][column] = 'X';
	}
	else //Miss
	{
		player->getHitBoard()[row][column] = '_';
	}
	
	//Check if player has won	
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			if(computer->getShipBoard()[i][j] != '.')
			{
				if(player->getHitBoard()[i][j] != 'X')
				{
					return(false);
				}
			}
		}
	}
	return(true);
}
bool Game::compGuess() //TODO intelligent guessing
{
	int column;
	int row;
	
	if(compMoves.isEmpty())
	{
		//Randomly choose a spot
		srand(time(NULL));
		do
		{
			column = rand()%10;
			row = rand()%10;
		}while(computer->getHitBoard()[row][column] != '.');
	}
	else
	{
		//Choose spot based on last hit
		do
		{
			int next = compMoves.peek();
			column = next%10;
			row = (next - (next%10))/10;
			compMoves.pop();
		}while(computer->getHitBoard()[row][column] != '.');
	}
	
	std::cout << "\n\nComputer guesses " << static_cast<char>('A'+row) << column << std::endl;
	
	if(player->getShipBoard()[row][column] != '.')
	{
		computer->getHitBoard()[row][column] = 'X';
		player->getShipBoard()[row][column] = 'X';
	}
	else
	{
		computer->getHitBoard()[row][column] = '_';
		player->getShipBoard()[row][column] = '_';
	}
	
	//Check if computer has won
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			if(std::isdigit(player->getShipBoard()[i][j]))
			{
				return(false);
			}
		}
	}
	return(true);
}
bool Game::numbersChecker(std::string g)
{
	int letter = g[0] - 'A';
	int number = g[1] - '0';
	if(letter < 0 || letter > 9)
	{
	   	return(false);
	}
	else if(number < 0 || number > 9)
	{
		return(false);
	}
	else
	{
		return(true);
	}
}
