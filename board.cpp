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
			if(row >= 8)
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
			column = rand()%10 + 1;
			row = rand()%10 + 1;
		}while(shipBoard[column][row] != 0);
		orientation = rand()%2 + 1;
		if(orientation == 1) //Horizontal
		{
			if(column >= 9)
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
			if(row >= 9)
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
			column = rand()%10 + 1;
			row = rand()%10 + 1;
		}while(shipBoard[column][row] != 0);
		orientation = rand()%2 + 1;
		if(orientation == 1) //Horizontal
		{
			if(column >= 10)
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
			if(row >= 10)
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
