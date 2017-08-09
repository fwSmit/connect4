#include <iostream>
#include <array>
#include <sstream>
#include <string>
#include "Game.h"

using namespace std;

/*const pieces_t testBoard {
{-,-,-,-,-,-,-},
{-,-,-,-,-,-,-},
{-,-,-,-,-,-,-},
{-,-,-,-,-,-,-},
{'X','X','X','X',-,-,-}
};*/




int main()
{
    Game board;
    bool finished = false;
    bool currPlayer = 0;
   
    while(!finished) {
		board.print();
        //cout << "player " << currPlayer << "'s turn" << endl;
        board.getPlayerInput();
		if(board.hasWon(currPlayer)){
			board.print();
			cout << "player" << (currPlayer? " O " : " X ") << "has won" << endl;
			finished = true;
		}
		currPlayer = !currPlayer;

    }
    return 0;
}
