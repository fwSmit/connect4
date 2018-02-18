#include "Game.h"
#include "BotParameters.h"

class Bot{
public:
	Bot bot(){
		std::srand(std::time(nullptr)); //set the seed to the current time
	}
	int getBestMove(const Game& board, BotParameters params);

	// score of 1 = win
	// 0 = draw
	// -1 = loss
	int getScore(const Game& board, const bool currentPlayer, int move, int depth, BotParameters params);
	int getNumberWinningMoves(Game board, BotParameters params);
};
