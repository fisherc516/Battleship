#include "board.h"

Board::Board()
{
	shipBoard = new char*[10];
	hitBoard = new char*[10];
	for(int row = 0; row < 10; row++)
	{
		shipBoard[row] = new char[10];
		hitBoard[row] = new char[10];
		for(int column = 0; column < 10; column++)
		{
			shipBoard[row][column] = '.';
			hitBoard[row][column] = '.';
		}
	}
}
Board::~Board()
{
	for(int i = 0; i < 10; i++)
	{
		delete[](shipBoard[i]);
		delete[](hitBoard[i]);
	}
	delete[] shipBoard;
	delete[] hitBoard;
}
void Board::pickShips() //Carrier,Battleship,Cruiser,Submarine,Destroyer
{
	printBoards(2);
	std::cout << "\nPlace the Aircraft Carrier (5 spaces)";
	getCoordinates(5);
	printBoards(2);
	std::cout << "\nPlace the Battleship (4 spaces)";
	getCoordinates(4);
	printBoards(2);
	std::cout << "\nPlace the Cruiser (3 spaces)";
	getCoordinates(3);
	printBoards(2);
	std::cout << "\nPlace the Submarine (3 spaces)";
	getCoordinates(3);
	printBoards(2);
	std::cout << "\nPlace the Destroyer (2 spaces)";
	getCoordinates(2);
}
void Board::getCoordinates(int shipLength)
{
	bool isEntryCorrect = false;
	std::string precoordinates = "";
	std::string coordinates = "";
	std::cout << "\nEnter the starting and ending coordinates e.g. A0-A3";
	do
	{
		std::cout << "\n\n: ";
		std::string precoordinates = "";
		std::string coordinates = "";
		std::cin >> precoordinates;
		
		// Remove all but alphanumeric characters
		for(int i = 0; i < precoordinates.length(); i++)
		{
			if(std::isalpha(precoordinates[i]))
			{
				char c = toupper(precoordinates[i]);
				coordinates = coordinates + c;
			}
			else if(std::isdigit(precoordinates[i]))
			{
				coordinates = coordinates + precoordinates[i];
			}
		}
		
		if(coordinates.length() != 4)
		{
			std::cout << "\nPlease make sure you have no extra characters in your coordinates";
		}
		else if(!coordinatesChecker(coordinates))
		{
			std::cout << "\nPlease make sure your letters/numbers are correct (A-J, 0-9)";
		}
		else if(!spaceChecker(coordinates,shipLength))
		{
			std::cout << "\nPlease make sure you've selected " << shipLength << " spaces in a line";
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
			shipBoard[i][j] = '.';
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
			shipBoard[column][row] = '5';
			shipBoard[column-1][row] = '5';
			shipBoard[column-2][row] = '5';
			shipBoard[column-3][row] = '5';
			shipBoard[column-4][row] = '5';
		}
		else
		{
			shipBoard[column][row] = '5';
			shipBoard[column+1][row] = '5';
			shipBoard[column+2][row] = '5';
			shipBoard[column+3][row] = '5';
			shipBoard[column+4][row] = '5';
		}
	}
	else if(orientation == 2) //Vertical
	{
		if(row >= 6)
		{
			shipBoard[column][row] = '5';
			shipBoard[column][row-1] = '5';
			shipBoard[column][row-2] = '5';
			shipBoard[column][row-3] = '5';
			shipBoard[column][row-4] = '5';
		}
		else
		{
			shipBoard[column][row] = '5';
			shipBoard[column][row+1] = '5';
			shipBoard[column][row+2] = '5';
			shipBoard[column][row+3] = '5';
			shipBoard[column][row+4] = '5';
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
		}while(shipBoard[column][row] != '.');
		orientation = rand()%2 + 1;
		if(orientation == 1) //Horizontal
		{
			if(column >= 7)
			{
				if(shipBoard[column-1][row] == '.' && shipBoard[column-2][row] == '.' && shipBoard[column-3][row] == '.')
				{
					shipBoard[column][row] = '4';
					shipBoard[column-1][row] = '4';
					shipBoard[column-2][row] = '4';
					shipBoard[column-3][row] = '4';
					isFourPlaced = true;
				}
				else
				{
					orientation = 2;
				}
			}
			else
			{
				if(shipBoard[column+1][row] == '.' && shipBoard[column+2][row] == '.' && shipBoard[column+3][row] == '.')
				{
					shipBoard[column][row] = '4';
					shipBoard[column+1][row] = '4';
					shipBoard[column+2][row] = '4';
					shipBoard[column+3][row] = '4';
					isFourPlaced = true;
				}
				else if(column >= 3)
				{
					if(shipBoard[column-1][row] == '.' && shipBoard[column-2][row] == '.' && shipBoard[column-3][row] == '.')
					{
						shipBoard[column][row] = '4';
						shipBoard[column-1][row] = '4';
						shipBoard[column-2][row] = '4';
						shipBoard[column-3][row] = '4';
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
				if(shipBoard[column][row-1] == '.' && shipBoard[column][row-2] == '.' && shipBoard[column][row-3] == '.')
				{
					shipBoard[column][row] = '4';
					shipBoard[column][row-1] = '4';
					shipBoard[column][row-2] = '4';
					shipBoard[column][row-3] = '4';
					isFourPlaced = true;
				}
			}
			else
			{
				if(shipBoard[column][row+1] == '.' && shipBoard[column][row+2] == '.' && shipBoard[column][row+3] == '.')
				{
					shipBoard[column][row] = '4';
					shipBoard[column][row+1] = '4';
					shipBoard[column][row+2] = '4';
					shipBoard[column][row+3] = '4';
					isFourPlaced = true;
				}
				else if(row >= 3)
				{
					if(shipBoard[column][row-1] == '.' && shipBoard[column][row-2] == '.' && shipBoard[column][row-3] == '.')
					{
						shipBoard[column][row] = '4';
						shipBoard[column][row-1] = '4';
						shipBoard[column][row-2] = '4';
						shipBoard[column][row-3] = '4';
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
		}while(shipBoard[column][row] != '.');
		orientation = rand()%2 + 1;
		if(orientation == 1) //Horizontal
		{
			if(column >= 8)
			{
				if(shipBoard[column-1][row] == '.' && shipBoard[column-2][row] == '.')
				{
					shipBoard[column][row] = '3';
					shipBoard[column-1][row] = '3';
					shipBoard[column-2][row] = '3';
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
				if(shipBoard[column+1][row] == '.' && shipBoard[column+2][row] == '.')
				{
					shipBoard[column][row] = '3';
					shipBoard[column+1][row] = '3';
					shipBoard[column+2][row] = '3';
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
					if(shipBoard[column-1][row] == '.' && shipBoard[column-2][row] == '.')
					{
						shipBoard[column][row] = '3';
						shipBoard[column-1][row] = '3';
						shipBoard[column-2][row] = '3';
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
				if(shipBoard[column][row-1] == '.' && shipBoard[column][row-2] == '.')
				{
					shipBoard[column][row] = '3';
					shipBoard[column][row-1] = '3';
					shipBoard[column][row-2] = '3';
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
				if(shipBoard[column][row+1] == '.' && shipBoard[column][row+2] == '.')
				{
					shipBoard[column][row] = '3';
					shipBoard[column][row+1] = '3';
					shipBoard[column][row+2] = '3';
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
					if(shipBoard[column][row-1] == '.' && shipBoard[column][row-2] == '.')
					{
						shipBoard[column][row] = '3';
						shipBoard[column][row-1] = '3';
						shipBoard[column][row-2] = '3';
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
		}while(shipBoard[column][row] != '.');
		orientation = rand()%2 + 1;
		if(orientation == 1) //Horizontal
		{
			if(column >= 9)
			{
				if(shipBoard[column-1][row] == '.')
				{
					shipBoard[column][row] = '2';
					shipBoard[column-1][row] = '2';
					isTwoPlaced = true;
				}
				else
				{
					orientation = 2;
				}
			}
			else
			{
				if(shipBoard[column+1][row] == '.')
				{
					shipBoard[column][row] = '2';
					shipBoard[column+1][row] = '2';
					isTwoPlaced = true;
				}
				else if(column >= 1)
				{
					if(shipBoard[column-1][row] == '.')
					{
						shipBoard[column][row] = '2';
						shipBoard[column-1][row] = '2';
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
				if(shipBoard[column][row-1] == '.')
				{
					shipBoard[column][row] = '2';
					shipBoard[column][row-1] = '2';
					isTwoPlaced = true;
				}
			}
			else
			{
				if(shipBoard[column][row+1] == '.')
				{
					shipBoard[column][row] = '2';
					shipBoard[column][row+1] = '2';
					isTwoPlaced = true;
				}
				else if(row >= 1)
				{
					if(shipBoard[column][row-1] == '.')
					{
						shipBoard[column][row] = '2';
						shipBoard[column][row-1] = '2';
						isTwoPlaced = true;
					}
				}
			}
		}
	}while(!isTwoPlaced);
}
void Board::printBoards(int n) const
{
	if(n == 2 || n == 3)
	{
		std::cout << "\nHere is your board of ships\n . - unguessed by opponent\n X - hit by opponent\n _ - miss by opponent\n";
		std::cout << "   0 1 2 3 4 5 6 7 8 9\n";
		for(int i = 0; i < 10; i++)
		{
			std::cout << " " << static_cast<char>('A'+i);
			for(int j = 0; j < 10; j++)
			{
				std::cout << " " << shipBoard[i][j];
			}
			std::cout << "\n";
		}
	}
	if(n == 1 || n == 3)
	{
		std::cout << "\nHere is your board of guesses\n . - unguessed\n X - hit\n _ - miss\n";
		std::cout << "   0 1 2 3 4 5 6 7 8 9\n";
		for(int i = 0; i < 10; i++)
		{
			std::cout << " " << static_cast<char>('A'+i);
			for(int j = 0; j < 10; j++)
			{
				std::cout << " " << hitBoard[i][j];
			}
			std::cout << "\n";
		}
		std::cout << "--------------------\n";
	}
}
bool Board::coordinatesChecker(std::string c)
{
	int letter1 = c[0]-'A';
	int num1 = c[1]-'0';
	int letter2 = c[2]-'A';
	int num2 = c[3]-'0';
	if(letter1 < 0 || letter1 > 9)
	{
	   	return(false);
	}
	else if(num1 < 0 || num1 > 9)
	{
		return(false);
	}
	else if(letter2 < 0 || letter2 > 9)
	{
		return(false);
	}
	else if(num2 < 0 || num2 > 9)
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
	int sr = c[0] - 'A';
	int sc = c[1] - '0';
	int er = c[2] - 'A';
	int ec = c[3] - '0';
	char length = '0'+spaces;
	if(sr == er+spaces-1 && sc == ec)
	{
		for(int i = 0; i < spaces; i++)
		{
			if(shipBoard[er+i][sc] != '.')
			{
				return(false);
			}
		}
		for(int j = 0; j < spaces; j++)
		{
			shipBoard[er+j][sc] = length;
		}
		return(true);
	}
	else if(sr == er-spaces+1 && sc == ec)
	{
		for(int i = 0; i < spaces; i++)
		{
			if(shipBoard[sr+i][sc] != '.')
			{
				return(false);
			}
		}
		for(int j = 0; j < spaces; j++)
		{
			shipBoard[sr+j][sc] = length;
		}
		return(true);
	}
	else if(sr == er && sc == ec+spaces-1)
	{
		for(int i = 0; i < spaces; i++)
		{
			if(shipBoard[sr][ec+i] != '.')
			{
				return(false);
			}
		}
		for(int j = 0; j < spaces; j++)
		{
			shipBoard[sr][ec+j] = length;
		}
		return(true);
	}
	else if(sr == er && sc == ec-spaces+1)
	{
		for(int i = 0; i < spaces; i++)
		{
			if(shipBoard[sr][sc+i] != '.')
			{
				return(false);
			}
		}
		for(int j = 0; j < spaces; j++)
		{
			shipBoard[sr][sc+j] = length;
		}
		return(true);
	}
	else
	{
		return(false);
	}
}
char** Board::getShipBoard()
{
	return(shipBoard);
}
char** Board::getHitBoard()
{
	return(hitBoard);
}
