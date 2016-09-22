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
void Board::pickShips()
{
	
}
void Board::randomShips() //5,4,3,3,2
{
	//5
	int column = rand()%10 + 1;
	int row = rand()%10 + 1;
	int orientation = rand()%2 + 1;
	if(orientation == 1) //Horizontal
	{
		if(column >= 7)
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
		if(row >= 7)
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
		column = rand()%10 + 1;
		row = rand()%10 + 1;
	}while(shipBoard[column][row] != 0);
	orientation = rand()%2 + 1;
	if(orientation == 1) //Horizontal
	{
		if(column >= 8)
		{
			if(shipBoard[column-1][row] == 0 && shipBoard[column-2][row] == 0 && shipBoard[column-3][row] == 0)
			{
				shipBoard[column][row] = 4;
				shipBoard[column-1][row] = 4;
				shipBoard[column-2][row] = 4;
				shipBoard[column-3][row] = 4;
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
			}
			else if(column >= 4)
			{
				if(shipBoard[column-1][row] == 0 && shipBoard[column-2][row] == 0 && shipBoard[column-3][row] == 0)
				{
					shipBoard[column][row] = 4;
					shipBoard[column-1][row] = 4;
					shipBoard[column-2][row] = 4;
					shipBoard[column-3][row] = 4;
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
		
	}
}
