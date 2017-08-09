#include <iostream>
#include <array>
#include <sstream>
#include <string>
#include "Game.h"
#include "Bot.h"

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
	Bot bot;
    bool finished = false;
   
    while(!finished) {
		board.print();
		bot.getBestMove(board); 
        //cout << "player " << currPlayer << "'s turn" << endl;
        board.getPlayerInput();
		if(board.hasWon()){
			board.print();
			cout << "player" << (board.getCurrentPlayer() == Player::O? " O " : " X ") << "has won" << endl;
			finished = true;
		}
		board.nextPlayer();

    }
    return 0;
}
