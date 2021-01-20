#include "Board.h"
#include <iostream>
using namespace std;

Board::Board(char *chessboard) {

	cout << "Creating the board!";
	//Create the 8 X 8 array
	char arr[8][8] = { {'R', 'B', 'N', 'K', 'Q', 'N', 'B', 'R'},
					   {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
					   {'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o'},
				       {'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o'},
				       {'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o'},
				       {'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o'},
					   {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
				       {'r', 'b', 'n', 'k', 'q', 'n', 'b', 'r'}};
	chessboard = *arr;
};

void printBoard(char *chessboard) {
	cout << "Chess Game!" << "\n";

	cout << "  0 1 2 3 4 5 6 7" << "\n";
	
	//char arr[8][8] = chessboard;

	for(int i = 0; i < 8; i++)
	{
		cout << i << " ";

		for (int j = 0; j < 8; j++)
		{
			cout << arr[i][j] << " ";
		}

		cout << "\n";
	}

}