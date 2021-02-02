#pragma once
#include <map>
using namespace std;

class Board
{
private:
	int rowLocation;
	int columnLocation;
	void pawnScan(map<string, char> possibleLocations);

	public:
		Board();
		void displayBoard();
		void choosePieceLocation(bool player);
		void chooseDestination(bool player);
		int getRowLocation();
		int getColumnLocation();
};

