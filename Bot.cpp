#include "Bot.h"
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int Bot::getBestMove(const Game& _board, BotParameters params){
	int bestScore = std::numeric_limits<int>::min();
	vector<int> bestMoves;
	Game board = _board;
	//board.nextPlayer();
	for(int i = 0; i < board.getXSize(); i++){
		if(board.isInputCorrect(i+1)){
			int currScore = getScore(board, board.getCurrentPlayer(), i, 5, params);
			cout << currScore << " ";
			// bestScore = max(currScore, bestScore)
			if(currScore > bestScore){
				bestMoves.clear();
			}
			if(currScore >= bestScore){
				bestScore = currScore;
				bestMoves.push_back(i+1);
			}
		}
		else{
			cout << "-  ";
		}
	}
	cout << endl;
	//cout << "best move: " << bestMove << endl;
	//if(bestScore == 0) cout << "random number " << std::rand() % 7 + 1 << endl;
	//if(bestScore == 0) return std::rand() % 7 + 1;
	if(bestMoves.size() == 0) cout << "error in getBestMove() " << endl;
	cout << "best moves size = " << bestMoves.size() << endl;
	size_t random_element = rand() % bestMoves.size();
	return bestMoves[random_element];
}

// bug: if there are no moves left getScore will return -2
int Bot::getScore(const Game& _board, const bool currentPlayer, int move, int depth, BotParameters params){
	if(depth == 0) return getNumberWinningMoves(_board, params);
	//cout << "move " << move << endl;
	Game board = _board;
	//board.nextPlayer();
	bool opponent_turn = currentPlayer != board.getCurrentPlayer(); 
	//cout << (currentPlayer == Player::X) << endl;
	//cout << "board current player" << (board.getCurrentPlayer() == Player::X) << endl;
	//cout << "opponent_turn " << boolalpha << opponent_turn << endl;
	board.placePiece(move);
	if (board.hasWon()){
		//cout << "someone won" << endl;
		return 10000 * depth;
	}
	if(board.isFull()){
		//cout << "board full" << endl;
		return 0;
	}
	//int bestScore = opponent_turn ? -10 : 10;
	int bestScore = std::numeric_limits<int>::min();
	for(int i = 0; i < board.getXSize(); i++){
		Game newBoard = board;
		newBoard.nextPlayer();
		if(board.isInputCorrect(i+1)){
			int score = getScore(newBoard, currentPlayer, i, depth-1, params);
			//if(opponent_turn){
				//bestScore = std::max(score, bestScore);
			//}else{
				//bestScore = std::min(score, bestScore);
			//}
			bestScore = std::max(score, bestScore);
		}
	}
	return -bestScore;

}

int Bot::getNumberWinningMoves(Game board, BotParameters params){
	int yourNumber= board.getNumberWinningMoves(params);
	board.nextPlayer();
	int enemyNumber = board.getNumberWinningMoves(params);
	return yourNumber - enemyNumber;
}
