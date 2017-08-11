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


const bool botPlays = true;
const bool testBot = false;

int main()
{
    Game board;
	Bot bot;
    bool finished = false;
  	if(testBot){
		bot.test();
	}
	else{
		while(!finished) {
			//cout << "player " << currPlayer << "'s turn" << endl;
			
			if(botPlays){
				if(board.getCurrentPlayer() == Player::O){
					int bestMove = bot.getBestMove(board); 
					cout << "AI moves at " << bestMove << endl;
					board.placePiece(bestMove-1);
				}else{
					board.getPlayerInput();
				}
				board.print();
			}
			else{
				bot.getBestMove(board);
				board.print();
				board.getPlayerInput();
				cout << "number of winning moves = " << board.getNumberWinningMoves() << endl;
			}	
			if(board.hasWon()){
				board.print();
				cout << "player" << (board.getCurrentPlayer() == Player::O? " O " : " X ") << "has won" << endl;
				finished = true;
			}
			board.nextPlayer();

		}
		return 0;
	}
}
