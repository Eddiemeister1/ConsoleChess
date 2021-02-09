#pragma once
#include <map>
#include <string>
using namespace std;

class Board
{
private:
	int rowLocation;
	int columnLocation;
	void pawnScan(map <string, char> &possibleLocations, int pieceRow, int pieceColumn, bool player);
	void rookScan(map <string, char>& possibleLocations, int pieceRow, int pieceColumn, bool player);
	void bishopScan(map <string, char>& possibleLocations, int pieceRow, int pieceColumn, bool player);
	void addToMap(map <string, char> &possibleLocations, int pieceRow, int pieceColumn, int rowIncrement, int columnIncrement);

	public:
		Board();
		void displayBoard();
		void choosePieceLocation(bool player);
		void chooseDestination(bool player);
		int getRowLocation();
		int getColumnLocation();
};

