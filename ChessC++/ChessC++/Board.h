#pragma once
class Board
{
public:
	char arr[8][8];
	Board(char *chessboard);

	void printBoard(char arr[8][8]);
};

