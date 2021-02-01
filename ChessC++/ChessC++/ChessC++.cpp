// ChessC++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Board.h";
using namespace std;

int main()
{
    cout << "Hello World!\n";
    //Create and fill the chessboard
    Board chessGame;

    //Give each player a turn to start in this game
    bool player = 0;
    
    //Game Starts
    while (true)
    {
        if (player == 0)
        {
            cout << "Player 1's Turn!\n";
        }
        else if(player == 1)
        {
            cout << "Player 2's Turn!\n";
        }

         //display the chessboard
         chessGame.displayBoard();

         //Choose a piece
         chessGame.choosePieceLocation(player);

         //Scan the positions that are possible
         chessGame.chooseDestination(player);


         //Change the boolean value of player after every turn
         if (player == 0)
         {
             player = 1;
         }
         else
         {
             player = 0;
         }
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
