#include "Bot.h"
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int Bot::getBestMove(const Game& board, BotParameters params){
	int bestScore = std::numeric_limits<int>::min();
	//int bestScore = -1000;
	vector<int> bestMoves;
	for(int i = 0; i < board.getXSize(); i++){
		if(!board.isColumnFull(i)){
			int currScore = getScore(board, board.getCurrentPlayer(), i, 5, params);
			cout << currScore << " ";
			// bestScore = max(currScore, bestScore)
			if(currScore > bestScore){
				bestMoves.clear();
				cout << "new best score" << endl;
			}
			if(currScore >= bestScore){
				bestScore = currScore;
				bestMoves.push_back(i);
			}
		}
		else{
			cout << "column full";
		}
	}
	cout << endl;
	if(bestMoves.size() == 0) cout << "error in getBestMove() " << endl;
	cout << "best moves size = " << bestMoves.size() << endl;
	size_t random_element = rand() % bestMoves.size();
	return bestMoves[random_element];
}

// bug: if there are no moves left getScore will return -2
int Bot::getScore(const Game& _board, const bool currentPlayer, int move, int depth, BotParameters params){
	//if(depth == 0){ return getNumberWinningMoves(_board, params);}
	if(depth == 0) { return 0; }
	Game board = _board;
	bool opponent_turn = currentPlayer != board.getCurrentPlayer(); 
	board.placePiece(move);
	if (board.hasWon()){
		//cout << "someone won" << endl;
		return 10.0 * depth;
	}
	if(board.isFull()){
		//cout << "board full" << endl;
		return 0;
	}
	int bestScore = std::numeric_limits<int>::min();
	for(int i = 0; i < board.getXSize(); i++){
		Game newBoard = board;
		newBoard.nextPlayer();
		if(!board.isColumnFull(i)){
			int score = getScore(newBoard, currentPlayer, i, depth-1, params);
			bestScore = std::max(score, bestScore);
		}
	}
	return -bestScore;
}

int Bot::getNumberWinningMoves(Game board, BotParameters params){
	//int yourNumber= board.getNumberWinningMoves(params);
	//board.nextPlayer();
	//int enemyNumber = board.getNumberWinningMoves(params);
	return 0;
	//return yourNumber - enemyNumber;
}
