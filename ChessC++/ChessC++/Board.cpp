#include "Board.h"
#include <iostream>
#include <map>;
using namespace std;

char chessboard[9][9] = { {'#', '1', '2', '3', '4', '5', '6', '7', '8'},
			   {'1', 'R','B' ,'N', 'K', 'Q', 'N', 'B', 'R'},
			   {'2', 'P','P' ,'P', 'P', 'P', 'P', 'P', 'P'},
			   {'3', 'o', 'o','o', 'o', 'o', 'o', 'o', 'o'},
			   {'4', 'o', 'o','o', 'o', 'o', 'o', 'o', 'o'},
			   {'5', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o'},
			   {'6', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o'},
			   {'7', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
			   {'8', 'r', 'b', 'n', 'q', 'k', 'n', 'b', 'r'} };

//Creating and filling up the chessboard
Board::Board() {
	cout << "Creating the chessboard...\n";

	displayBoard();

	cout << "Chessboard was created!";
};

void Board::displayBoard()
{

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << chessboard[i][j] << "  ";
		}
		cout << "\n";
	}
};

void Board::choosePieceLocation(bool player)
{
	//For debugging purposes
	cout << "Player " << player<< "\n";

	//int rowLocation;
	//int columnLocation;
	//It could be a good idea to put a while loop for exception handling
	while (true)
	{
		cout << "What row?\n";
		cin >> rowLocation;

		cout << "What column?\n";
		cin >> columnLocation;

		char location = chessboard[rowLocation][columnLocation];
		
		//Basic Exception Handling for the player choosing their own piece
		try {
				if (player == 0)
				{
					if (location == 'R' || location == 'N' || location == 'B' || location == 'K' || location == 'Q' || location == 'P')
					{
						cout << "Success! You chose your piece!\n";
						break;
					}
					else
					{
						throw string("ERROR! This is not one of your pieces!\n");
					}
				}
				else if (player == 1)
				{
					if (location == 'r' || location == 'n' || location == 'b' || location == 'k' || location == 'q' || location == 'p')
					{
						cout << "Success! You chose your piece!\n";
						break;
					}
					else
					{
						throw string("ERROR! This is not one of your pieces!\n");
					}
				}
			}
		catch (string &e)
		{
			cout << e << endl;
		}
	}

};

void Board::chooseDestination(bool player)
{
	//First, identify the piece that the player chose
	int pieceRow = getRowLocation();
	int pieceColumn = getColumnLocation();
	char piece = chessboard[pieceRow][pieceColumn];

	//Convert the integer values for row and column into char and concatenate them into a string
	char row = '0' + pieceRow;
	char column = '0' + pieceColumn;
	string location;
	location = row;
	location += column;

	//Second, scan and record the possible locations on the board based on the behavior of the piece

	//To do this, we can create a Map to store the possible locations
	map <string, char> possibleLocations;

	if (piece == 'P' || piece == 'p')
	{
		cout << "This is a pawn\n";
	}
	else if (piece == 'R' || piece == 'r')
	{
		cout << "This is a rook\n";
	}
	else if (piece == 'B' || piece == 'b')
	{
		cout << "This is a bishop\n";
	}
	else if (piece == 'N' || piece == 'n')
	{
		cout << "This is a knight\n";
	}
	else if (piece == 'Q' || piece == 'q')
	{
		cout << "This is a queen\n";
	}
	else if (piece == 'K' || piece == 'k')
	{
		cout << "This is a king\n";
	}
	//Third, ask the player what location is desired for your destination
	//The user's input would then get determined if it is a viable option

}

int Board::getRowLocation()
{
	return rowLocation;
}

int Board::getColumnLocation()
{
	return columnLocation;
}

void pawnScan(map<string, char> possibleLocations)
{

}