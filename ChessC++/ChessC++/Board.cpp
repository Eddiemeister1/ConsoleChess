#include "Board.h"
#include <iostream>
using namespace std;

char chessboard[8][8] = { {'R','B' ,'N', 'K', 'Q', 'N', 'B', 'R'},
			   {'P','P' ,'P', 'P', 'P', 'P', 'P', 'P'},
			   {'o', 'o','o', 'o', 'o', 'o', 'o', 'o'},
			   {'o', 'o','o', 'o', 'o', 'o', 'o', 'o'},
			   {'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o'},
			   {'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o'},
			   {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
			   {'r', 'b', 'n', 'q', 'k', 'n', 'b', 'r'} };

//Creating and filling up the chessboard
Board::Board() {
	cout << "Creating the chessboard...\n";

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << chessboard[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "Chessboard was created!";
};