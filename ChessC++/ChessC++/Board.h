#pragma once

class Board
{
private:
	int rowLocation;
	int columnLocation;

	public:
		Board();
		void displayBoard();
		void choosePieceLocation(bool player);
		void chooseDestination(bool player);
		int getRowLocation();
		int getColumnLocation();
		
};

