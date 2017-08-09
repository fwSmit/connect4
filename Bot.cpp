#include "Bot.h"
#include <iostream>

using namespace std;

int Bot::getBestMove(const Game& board){
	int bestScore = -10;
	//for(int i = 0; i < board.getPieces().getXSize(); i++){
	for(int i = 0; i < 1; i++){
		int currScore = getScore(board, i);
		cout << currScore << "  ";
		bestScore = std::max(currScore, bestScore);
	}
	cout << endl;
	return 0;
}

// bug: if there are no moves left getScore will return -2
int Bot::getScore(const Game& _board, int move){
	//cout << "move " << move << endl;
	Game board = _board;
	board.nextPlayer();
	if(board.isInputCorrect(move+1)){
		board.placePiece(move);
	}
	else{
		//cout << "error" << endl;
		return -2;
	}
	if (board.hasWon()){
		//cout << "someone won" << endl;
		return 1;
	}
	if(board.isFull()){
		//cout << "board full" << endl;
		return 0;
	}
	const Pieces boardPieces = board.getPieces();
	int bestScore = -10;
	for(int i = 0; i < boardPieces.getXSize(); i++){
		bestScore = std::max(-getScore(board, i), bestScore);
		
		// best score you can get
		if(bestScore == 1) break;
	}
	return bestScore;

}
