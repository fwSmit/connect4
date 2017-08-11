#include "Game.h"

class Bot{
public:
	int getBestMove(const Game& board);

	// score of 1 = win
	// 0 = draw
	// -1 = loss
	int getScore(const Game& board, const bool currentPlayer, int move, int depth);
	void test();
	int getNumberWinningMoves(Game board);
};
