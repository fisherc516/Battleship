#include "board.h"

Board::Board()
{
	for(int column = 0; column < 10; column++)
	{
		for(int row = 0; row < 10; row++)
		{
			shipBoard[column][row] = 0;
			hitBoard[column][row] = '.';
		}
	}
}
void Board::pickShips() //Carrier,Battleship,Cruiser,Submarine,Destroyer
{
	bool isEntryCorrect = false;
	std::string coordinates = "";
	std::cout << " Here is your board\n";
	std::cout << "   0 1 2 3 4 5 6 7 8 9\n";
	for(int i = 0; i < 10; i++)
	{
		std::cout << " " << i;
		for(int j = 0; j < 10; j++)
		{
			std::cout << " " << shipBoard[i][j];
		}
		std::cout << "\n";
	}
	std::cout << "\nPlace the Aircraft Carrier (5 spaces)";
	std::cout << "\nEnter the starting and ending coordinates like this:\n(starting column,starting row),(ending column,ending row) - Don't use spaces";
	do
	{
		std::cout << "\n\n: ";
		std::cin >> coordinates;
		if(coordinates.length() != 11)
		{
			std::cout << "\nPlease do not use spaces";
			std::cin >> coordinates;
		}
		else if(!numbersChecker(coordinates))
		{
			std::cout << "\nPlease make sure your numbers are correct (0-9)";
		}
		else if(!spaceChecker(coordinates,5))
		{
			std::cout << "\nPlease make sure you've selected 5 spaces in a line";
		}
		else
		{
			isEntryCorrect = true;
		}
	}while(!isEntryCorrect);
	
	
}
void Board::randomShips() //5,4,3,3,2
{
	srand(time(NULL));
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			shipBoard[i][j] = 0;
			hitBoard[i][j] = '.';
		}
	}
	//5
	int column = rand()%10;
	int row = rand()%10;
	int orientation = rand()%2 + 1;
	if(orientation == 1) //Horizontal
	{
		if(column >= 6)
		{
			shipBoard[column][row] = 5;
			shipBoard[column-1][row] = 5;
			shipBoard[column-2][row] = 5;
			shipBoard[column-3][row] = 5;
			shipBoard[column-4][row] = 5;
		}
		else
		{
			shipBoard[column][row] = 5;
			shipBoard[column+1][row] = 5;
			shipBoard[column+2][row] = 5;
			shipBoard[column+3][row] = 5;
			shipBoard[column+4][row] = 5;
		}
	}
	else if(orientation == 2) //Vertical
	{
		if(row >= 6)
		{
			shipBoard[column][row] = 5;
			shipBoard[column][row-1] = 5;
			shipBoard[column][row-2] = 5;
			shipBoard[column][row-3] = 5;
			shipBoard[column][row-4] = 5;
		}
		else
		{
			shipBoard[column][row] = 5;
			shipBoard[column][row+1] = 5;
			shipBoard[column][row+2] = 5;
			shipBoard[column][row+3] = 5;
			shipBoard[column][row+4] = 5;
		}
	}
	//4
	bool isFourPlaced = false;
	do
	{
		do
		{
			column = rand()%10;
			row = rand()%10;
		}while(shipBoard[column][row] != 0);
		orientation = rand()%2 + 1;
		if(orientation == 1) //Horizontal
		{
			if(column >= 7)
			{
				if(shipBoard[column-1][row] == 0 && shipBoard[column-2][row] == 0 && shipBoard[column-3][row] == 0)
				{
					shipBoard[column][row] = 4;
					shipBoard[column-1][row] = 4;
					shipBoard[column-2][row] = 4;
					shipBoard[column-3][row] = 4;
					isFourPlaced = true;
				}
				else
				{
					orientation = 2;
				}
			}
			else
			{
				if(shipBoard[column+1][row] == 0 && shipBoard[column+2][row] == 0 && shipBoard[column+3][row] == 0)
				{
					shipBoard[column][row] = 4;
					shipBoard[column+1][row] = 4;
					shipBoard[column+2][row] = 4;
					shipBoard[column+3][row] = 4;
					isFourPlaced = true;
				}
				else if(column >= 3)
				{
					if(shipBoard[column-1][row] == 0 && shipBoard[column-2][row] == 0 && shipBoard[column-3][row] == 0)
					{
						shipBoard[column][row] = 4;
						shipBoard[column-1][row] = 4;
						shipBoard[column-2][row] = 4;
						shipBoard[column-3][row] = 4;
						isFourPlaced = true;
					}
					else
					{
						orientation = 2;
					}
				}
				else
				{
					orientation = 2;
				}
			}
		}
		if(orientation == 2) //Vertical
		{
			if(row >= 7)
			{
				if(shipBoard[column][row-1] == 0 && shipBoard[column][row-2] == 0 && shipBoard[column][row-3] == 0)
				{
					shipBoard[column][row] = 4;
					shipBoard[column][row-1] = 4;
					shipBoard[column][row-2] = 4;
					shipBoard[column][row-3] = 4;
					isFourPlaced = true;
				}
			}
			else
			{
				if(shipBoard[column][row+1] == 0 && shipBoard[column][row+2] == 0 && shipBoard[column][row+3] == 0)
				{
					shipBoard[column][row] = 4;
					shipBoard[column][row+1] = 4;
					shipBoard[column][row+2] = 4;
					shipBoard[column][row+3] = 4;
					isFourPlaced = true;
				}
				else if(row >= 3)
				{
					if(shipBoard[column][row-1] == 0 && shipBoard[column][row-2] == 0 && shipBoard[column][row-3] == 0)
					{
						shipBoard[column][row] = 4;
						shipBoard[column][row-1] = 4;
						shipBoard[column][row-2] = 4;
						shipBoard[column][row-3] = 4;
						isFourPlaced = true;
					}
				}
			}
		}
	}while(!isFourPlaced);
	//3,3
	bool isFirstThreePlaced = false;
	bool isSecondThreePlaced = false;
	do
	{
		do
		{
			column = rand()%10;
			row = rand()%10;
		}while(shipBoard[column][row] != 0);
		orientation = rand()%2 + 1;
		if(orientation == 1) //Horizontal
		{
			if(column >= 8)
			{
				if(shipBoard[column-1][row] == 0 && shipBoard[column-2][row] == 0)
				{
					shipBoard[column][row] = 3;
					shipBoard[column-1][row] = 3;
					shipBoard[column-2][row] = 3;
					if(isFirstThreePlaced)
					{
						isSecondThreePlaced = true;
					}
					else
					{
						isFirstThreePlaced = true;
					}
				}
				else
				{
					orientation = 2;
				}
			}
			else
			{
				if(shipBoard[column+1][row] == 0 && shipBoard[column+2][row] == 0)
				{
					shipBoard[column][row] = 3;
					shipBoard[column+1][row] = 3;
					shipBoard[column+2][row] = 3;
					if(isFirstThreePlaced)
					{
						isSecondThreePlaced = true;
					}
					else
					{
						isFirstThreePlaced = true;
					}
				}
				else if(column >= 2)
				{
					if(shipBoard[column-1][row] == 0 && shipBoard[column-2][row] == 0)
					{
						shipBoard[column][row] = 3;
						shipBoard[column-1][row] = 3;
						shipBoard[column-2][row] = 3;
						if(isFirstThreePlaced)
						{
							isSecondThreePlaced = true;
						}
						else
						{
							isFirstThreePlaced = true;
						}
					}
					else
					{
						orientation = 2;
					}
				}
				else
				{
					orientation = 2;
				}
			}
		}
		if(orientation == 2) //Vertical
		{
			if(row >= 8)
			{
				if(shipBoard[column][row-1] == 0 && shipBoard[column][row-2] == 0)
				{
					shipBoard[column][row] = 3;
					shipBoard[column][row-1] = 3;
					shipBoard[column][row-2] = 3;
					if(isFirstThreePlaced)
					{
						isSecondThreePlaced = true;
					}
					else
					{
						isFirstThreePlaced = true;
					}
				}
			}
			else
			{
				if(shipBoard[column][row+1] == 0 && shipBoard[column][row+2] == 0)
				{
					shipBoard[column][row] = 3;
					shipBoard[column][row+1] = 3;
					shipBoard[column][row+2] = 3;
					if(isFirstThreePlaced)
					{
						isSecondThreePlaced = true;
					}
					else
					{
						isFirstThreePlaced = true;
					}
				}
				else if(row >= 2)
				{
					if(shipBoard[column][row-1] == 0 && shipBoard[column][row-2] == 0)
					{
						shipBoard[column][row] = 3;
						shipBoard[column][row-1] = 3;
						shipBoard[column][row-2] = 3;
						if(isFirstThreePlaced)
						{
							isSecondThreePlaced = true;
						}
						else
						{
							isFirstThreePlaced = true;
						}
					}
				}
			}
		}
	}while(!isSecondThreePlaced);
	//2
	bool isTwoPlaced = false;
	do
	{
		do
		{
			column = rand()%10;
			row = rand()%10;
		}while(shipBoard[column][row] != 0);
		orientation = rand()%2 + 1;
		if(orientation == 1) //Horizontal
		{
			if(column >= 9)
			{
				if(shipBoard[column-1][row] == 0)
				{
					shipBoard[column][row] = 2;
					shipBoard[column-1][row] = 2;
					isTwoPlaced = true;
				}
				else
				{
					orientation = 2;
				}
			}
			else
			{
				if(shipBoard[column+1][row] == 0)
				{
					shipBoard[column][row] = 2;
					shipBoard[column+1][row] = 2;
					isTwoPlaced = true;
				}
				else if(column >= 1)
				{
					if(shipBoard[column-1][row] == 0)
					{
						shipBoard[column][row] = 2;
						shipBoard[column-1][row] = 2;
						isTwoPlaced = true;
					}
					else
					{
						orientation = 2;
					}
				}
				else
				{
					orientation = 2;
				}
			}
		}
		if(orientation == 2) //Vertical
		{
			if(row >= 9)
			{
				if(shipBoard[column][row-1] == 0)
				{
					shipBoard[column][row] = 2;
					shipBoard[column][row-1] = 2;
					isTwoPlaced = true;
				}
			}
			else
			{
				if(shipBoard[column][row+1] == 0)
				{
					shipBoard[column][row] = 2;
					shipBoard[column][row+1] = 2;
					isTwoPlaced = true;
				}
				else if(row >= 1)
				{
					if(shipBoard[column][row-1] == 0)
					{
						shipBoard[column][row] = 2;
						shipBoard[column][row-1] = 2;
						isTwoPlaced = true;
					}
				}
			}
		}
	}while(!isTwoPlaced);
}
void Board::printBoards()
{
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			std::cout << " " << hitBoard[i][j];
		}
		std::cout << "\n";
	}
	std::cout << "--------------------\n";
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			std::cout << " " << shipBoard[i][j];
		}
		std::cout << "\n";
	}
}
bool Board::numbersChecker(std::string c)
{
	if(c[1]!='0' && c[1]!='1' && c[1]!='2' && c[1]!='3' && c[1]!='4' && c[1]!='5' && c[1]!='6' && c[1]!='7' && c[1]!='8' && c[1]!='9')
	{
	   	return(false);
	}
	else if(c[3]!='0' && c[3]!='1' && c[3]!='2' && c[3]!='3' && c[3]!='4' && c[3]!='5' && c[3]!='6' && c[3]!='7' && c[3]!='8' && c[3]!='9')
	{
		return(false);
	}
	else if(c[7]!='0' && c[7]!='1' && c[7]!='2' && c[7]!='3' && c[7]!='4' && c[7]!='5' && c[7]!='6' && c[7]!='7' && c[7]!='8' && c[7]!='9')
	{
		return(false);
	}
	else if(c[9]!='0' && c[9]!='1' && c[9]!='2' && c[9]!='3' && c[9]!='4' && c[9]!='5' && c[9]!='6' && c[9]!='7' && c[9]!='8' && c[9]!='9')
	{
		return(false);
	}
	else
	{
		return(true);
	}
}
bool Board::spaceChecker(std::string c, int spaces)
{
	int sc = c[1] - '0';
	int sr = c[3] - '0';
	int ec = c[7] - '0';
	int er = c[9] - '0';
	if(sc == ec+spaces-1 && sr == er)
	{
		for(int i = 0; i < spaces; i++)
		{
			if(shipBoard[ec+i][sr] != 0)
			{
				return(false);
			}
		}
		return(true);
	}
	else if(sc == ec-spaces+1 && sr == er)
	{
		for(int i = 0; i < spaces; i++)
		{
			if(shipBoard[sc+i][sr] != 0)
			{
				return(false);
			}
		}
		return(true);
	}
	else if(sc == ec && sr == er+spaces-1)
	{
		for(int i = 0; i < spaces; i++)
		{
			if(shipBoard[sc][er+i] != 0)
			{
				return(false);
			}
		}
		return(true);
	}
	else if(sc == ec && sr == er-spaces+1)
	{
		for(int i = 0; i < spaces; i++)
		{
			if(shipBoard[sc][sr+i] != 0)
			{
				return(false);
			}
		}
		return(true);
	}
	else
	{
		return(false);
	}
}
