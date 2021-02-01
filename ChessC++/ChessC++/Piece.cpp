#include "Piece.h"
#include <iostream>
using namespace std;

Piece::Piece(char piece)
{
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
};