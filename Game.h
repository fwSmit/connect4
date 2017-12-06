#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <array>
#include <sstream>
#include <string>
#include <functional>
#include <SFML/Graphics.hpp>
#include "BotParameters.h"
#include "Pieces.h"

using namespace std;

const char empty_char = '-';
const char playerO_char = 'O';
const char playerX_char = 'X';
enum Player : bool {O = false, X = true, Beginning = false};

class Game
{
    Pieces pieces;
	bool currPlayer = Player::Beginning;
public:

    Game();
	
	void start(std::function<int(Game)> player1, std::function<int(Game)> player2);
	void drawBoard(sf::RenderWindow& window);
	char getPlayerChar(){
		if(currPlayer == Player::X){
			return 'X';
		}else{
			return 'O';
		}
	}
	bool isFull(){
		return pieces.isFull();
	}
	const Pieces getPieces() const {
		return pieces;
	}

	bool getCurrentPlayer() const {
		return currPlayer;
	}
    bool isInputCorrect(unsigned int input) const
    {
        //cout << "validating input " << input << endl;
        if(!(input > 0 && input < (pieces.getXSize() + 1))) {
            return false;
        } else {
            return pieces.getPiece(input-1, 0) == empty_char;
        }
    }

    void placePiece(unsigned int at)
    {
        // assuming input is correct
        for(int i = pieces.getYSize()-1; i >= 0; i--) {
            if(pieces.getPiece(at, i) == empty_char) {
                //cout << "found empty spot at " << at << ", " << i  << endl;
                if(currPlayer == Player::O) {
					pieces.setPiece(at, i, playerO_char);
                } else {
					pieces.setPiece(at, i, playerX_char);
                }
                break;
            }
        }
    }

	void print(){
		pieces.print();
	}

    bool hasWon() const;

	
	unsigned int getPlayerInput() const
	{
		string input;
		unsigned int result;
		cout << "type 1-7 to place a piece at that position" << endl << endl;
		while(1) {
			std::getline (std::cin, input);
			stringstream ss(input);
			if(ss >> result && isInputCorrect(result)) {
				break;
			}
			cout << "input not correct" << endl;
		}
		//std::cout << "placing a piece at " << result << std::endl;
		cout << endl;
		return result - 1;

	}

	void nextPlayer(){
		//cout << "next Player in function" << endl;
		currPlayer =! currPlayer;
	}
	
	int getNumberWinningMoves(BotParameters params) const;
};

#endif // GAME_H
