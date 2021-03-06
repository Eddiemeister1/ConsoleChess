#include "Board.h"
#include <iostream>
#include <string>
#include <map>

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

 string player1Pieces = "RBNKQP";
 string player2Pieces = "rbnkqp";

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
	int destinationRow;
	int destinationColumn;
	char piece = chessboard[pieceRow][pieceColumn];

	//Second, scan and record the possible locations on the board based on the behavior of the piece

	//To do this, we can create a Map to store the possible locations
	map <string, char> possibleLocations;
	if (piece == 'P' || piece == 'p')
	{
		cout << "This is a pawn\n";
		pawnScan(possibleLocations, pieceRow, pieceColumn , player);
	}
	else if (piece == 'R' || piece == 'r')
	{
		cout << "This is a rook\n";
		rookScan(possibleLocations, pieceRow, pieceColumn, player);

	}
	else if (piece == 'B' || piece == 'b')
	{
		cout << "This is a bishop\n";
		bishopScan(possibleLocations, pieceRow, pieceColumn, player);
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

	while (true)
	{
		//Third, ask the player what location is desired for your destination
		try {
			cout << "What row is your destination?" << endl;
			cin >> destinationRow;
			cout << "What column is your destination?" << endl;
			cin >> destinationColumn;
			char row = '0' + destinationRow;
			char column = '0' + destinationColumn;
			string location;
			location = row;
			location += column;

			//The user's input would then get determined if it is a viable option
			if (possibleLocations.find(location) == possibleLocations.end())
			{
				//Not found
				throw string("ERROR! Destination is not a Viable option!");
			}
			else
			{
				cout << "Success! Destination is a viable option!" << endl;
				chessboard[destinationRow][destinationColumn] = chessboard[pieceRow][pieceColumn];
				chessboard[pieceRow][pieceColumn] = 'o';
				possibleLocations.clear();
				break;
			}
		}
		catch (string& e)
		{
			cout << e << endl;
		}
	}
}

int Board::getRowLocation()
{
	return rowLocation;
}

int Board::getColumnLocation()
{
	return columnLocation;
}

void Board::bishopScan(map <string, char>& possibleLocations, int pieceRow, int pieceColumn, bool player)
{
	//We can start increasing by row as well as increasing and decreasing by column
	int rowIncrement = 1;
	int columnIncrement = 1;
	cout << "Scanning the Bishop Possible Locations" << endl;
	for (rowIncrement; pieceRow + rowIncrement < 9; rowIncrement++)
	{
		cout << "Checking the rows..." << endl;
		if (pieceColumn + columnIncrement < 9)
		{
			cout << "Scanning the possible columns" << endl;
			if (player == 0)
			{
				if (player1Pieces.find(chessboard[pieceRow + rowIncrement][pieceColumn + columnIncrement]) == string::npos)
				{
					//If their own piece has not been found, add it to the map
					addToMap(possibleLocations, pieceRow, pieceColumn, rowIncrement, columnIncrement);
				}
			}
			else if (player == 1)
			{
				if (player2Pieces.find(chessboard[pieceRow + rowIncrement][pieceColumn + columnIncrement]) == string::npos)
				{
					//If their own piece has not been found, add it to the map
					addToMap(possibleLocations, pieceRow, pieceColumn, rowIncrement, columnIncrement);
				}
			}
		}

		if (pieceColumn - columnIncrement > 0)
		{
			if (player == 0)
			{
				if (player1Pieces.find(chessboard[pieceRow + rowIncrement][pieceColumn - columnIncrement]) == string::npos)
				{
					//If their own piece has not been found, add it to the map
					columnIncrement *= -1;
					addToMap(possibleLocations, pieceRow, pieceColumn, rowIncrement, columnIncrement);
					columnIncrement *= -1;
				}
			}
			else if (player == 1)
			{
				if (player2Pieces.find(chessboard[pieceRow + rowIncrement][pieceColumn - columnIncrement]) == string::npos)
				{
					//If their own piece has not been found, add it to the map
					columnIncrement *= -1;
					addToMap(possibleLocations, pieceRow, pieceColumn, rowIncrement, columnIncrement);
					columnIncrement *= -1;
				}
			}
		}
		columnIncrement++;
	}

	rowIncrement = -1;
	columnIncrement = 1;
	for (rowIncrement; pieceRow + rowIncrement > 0; rowIncrement--)
	{
		cout << "Checking the backrows..." << endl;
		if (pieceColumn + columnIncrement < 9)
		{
			cout << "Scanning the possible backcolumns" << endl;
			if (player == 0)
			{
				if (player1Pieces.find(chessboard[pieceRow + rowIncrement][pieceColumn + columnIncrement]) == string::npos)
				{
					//If their own piece has not been found, add it to the map
					addToMap(possibleLocations, pieceRow, pieceColumn, rowIncrement, columnIncrement);
				}
			}
			else if (player == 1)
			{
				if (player2Pieces.find(chessboard[pieceRow + rowIncrement][pieceColumn + columnIncrement]) == string::npos)
				{
					//If their own piece has not been found, add it to the map
					addToMap(possibleLocations, pieceRow, pieceColumn, rowIncrement, columnIncrement);
				}
			}
		}

		if (pieceColumn - columnIncrement > 0)
		{
			if (player == 0)
			{
				if (player1Pieces.find(chessboard[pieceRow + rowIncrement][pieceColumn - columnIncrement]) == string::npos)
				{
					//If their own piece has not been found, add it to the map
					columnIncrement *= -1;
					addToMap(possibleLocations, pieceRow, pieceColumn, rowIncrement, columnIncrement);
					columnIncrement *= -1;
				}
			}
			else if (player == 1)
			{
				if (player2Pieces.find(chessboard[pieceRow + rowIncrement][pieceColumn - columnIncrement]) == string::npos)
				{
					//If their own piece has not been found, add it to the map
					columnIncrement *= -1;
					addToMap(possibleLocations, pieceRow, pieceColumn, rowIncrement, columnIncrement);
					columnIncrement *= -1;
				}
			}
		}
		columnIncrement++;
	}

}
void Board::rookScan(map<string, char>& possibleLocations, int pieceRow, int pieceColumn, bool player)
{
	//We can start increasing and decreasing by row and then by column
//First, increasing by row
	int rowIncrement = 1;
	for (rowIncrement; pieceRow + rowIncrement < 9; rowIncrement++)
	{
		if (player == 0)
		{
			if (player1Pieces.find(chessboard[pieceRow + rowIncrement][pieceColumn]) != string::npos)
			{
				//Their own piece has been found
				break;
			}
		}
		else if (player == 1)
		{
			if (player2Pieces.find(chessboard[pieceRow + rowIncrement][pieceColumn]) != string::npos)
			{
				//Their own piece has been found
				break;
			}
		}
		addToMap(possibleLocations, pieceRow, pieceColumn, rowIncrement, 0);
	}

	//Decreasing by row
	rowIncrement = -1;
	for (rowIncrement; pieceRow + rowIncrement > 0; rowIncrement--)
	{
		if (player == 0)
		{
			if (player1Pieces.find(chessboard[pieceRow + rowIncrement][pieceColumn]) != string::npos)
			{
				//Their own piece has been found
				break;
			}
		}
		else if (player == 1)
		{
			if (player2Pieces.find(chessboard[pieceRow + rowIncrement][pieceColumn]) != string::npos)
			{
				//Their own piece has been found
				break;
			}
		}
		addToMap(possibleLocations, pieceRow, pieceColumn, rowIncrement, 0);
	}

	//Increasing by column
	int columnIncrement = 1;
	for (columnIncrement; pieceColumn + columnIncrement < 9; columnIncrement++)
	{
		if (player == 0)
		{
			if (player1Pieces.find(chessboard[pieceRow][pieceColumn + columnIncrement]) != string::npos)
			{
				//Their own piece has been found
				break;
			}
		}
		else if (player == 1)
		{
			if (player2Pieces.find(chessboard[pieceRow + rowIncrement][pieceColumn + columnIncrement]) != string::npos)
			{
				//Their own piece has been found
				break;
			}
		}
		addToMap(possibleLocations, pieceRow, pieceColumn, 0, columnIncrement);
	}

	//Decreasing by column
	columnIncrement = -1;
	for (columnIncrement; pieceColumn + columnIncrement > 0; columnIncrement--)
	{
		if (player == 0)
		{
			if (player1Pieces.find(chessboard[pieceRow][pieceColumn + columnIncrement]) != string::npos)
			{
				//Their own piece has been found
				break;
			}
		}
		else if (player == 1)
		{
			if (player2Pieces.find(chessboard[pieceRow][pieceColumn + columnIncrement]) != string::npos)
			{
				//Their own piece has been found
				break;
			}
		}
		addToMap(possibleLocations, pieceRow, pieceColumn, 0, columnIncrement);
	}
}
void Board::pawnScan(map<string, char> &possibleLocations, int pieceRow, int pieceColumn, bool player)
{
	if (player == 0)
	{
		//If this space is empty,...
		if (chessboard[pieceRow + 1][pieceColumn] == 'o')
		{
			//...add it to the map
			addToMap(possibleLocations, pieceRow, pieceColumn, 1, 0);
		}

		if (pieceRow == 2)
		{
			//If this space is empty,...
			if (chessboard[pieceRow + 2][pieceColumn] == 'o')
			{
				//...add it to the map
				addToMap(possibleLocations, pieceRow, pieceColumn, 2, 0);
			}
		}

		//Enemy space
		if (pieceColumn - 1 > 0)
		{
			if (player2Pieces.find(chessboard[pieceRow + 1][pieceColumn - 1]) != string::npos)
			{
				addToMap(possibleLocations, pieceRow, pieceColumn, 1, -1);
			}
		}

		if (pieceColumn + 1 < 9)
		{
			if (player2Pieces.find(chessboard[pieceRow + 1][pieceColumn + 1]) != string::npos)
			{
				addToMap(possibleLocations, pieceRow, pieceColumn, 1, 1);
			}
		}
	}
	else if (player == 1)
	{
		//If this space is empty,...
		if (chessboard[pieceRow - 1][pieceColumn] == 'o')
		{
			//...add it to the map
			addToMap(possibleLocations, pieceRow, pieceColumn, -1, 0);
		}

		if (pieceRow == 7)
		{
			//If this space is empty,...
			if (chessboard[pieceRow - 2][pieceColumn] == 'o')
			{
				//...add it to the map
				addToMap(possibleLocations, pieceRow, pieceColumn, -2, 0);
			}
		}

		//Enemy space
		if (pieceColumn - 1 > 0)
		{
			if (player1Pieces.find(chessboard[pieceRow - 1][pieceColumn - 1] != string::npos))
			{
				addToMap(possibleLocations, pieceRow, pieceColumn, -1, -1);
			}
		}

		if (pieceColumn + 1 < 9)
		{
			if (player1Pieces.find(chessboard[pieceRow - 1][pieceColumn + 1] != string::npos))
			{
				addToMap(possibleLocations, pieceRow, pieceColumn, -1, 1);
			}
		}
	}
}

void Board::addToMap(map <string, char> &possibleLocations, int pieceRow, int pieceColumn, int rowIncrement, int columnIncrement)
{
	//...add it to the map
	pieceRow += rowIncrement;
	pieceColumn += columnIncrement;

	char row = '0' + pieceRow;
	char column = '0' + pieceColumn;
	string location;
	location = row;
	location += column;
	possibleLocations.insert(pair<string, char>(location, chessboard[pieceRow][pieceColumn]));
}