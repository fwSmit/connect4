#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <array>
#include <sstream>
#include <string>
#include "Pieces.h"
using namespace std;

const char empty_char = '-';
const char playerO_char = 'O';
const char playerX_char = 'X';
enum Player : bool {O = false, X = true};

class Game
{
    Pieces pieces;
	bool currPlayer;
public:

    Game();

    bool isInputCorrect(unsigned int input)
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

    bool hasWon(bool player);

	
	unsigned int getPlayerInput()
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
		placePiece(result-1);
		cout << endl;
		currPlayer =! currPlayer;
		return result;

	}
};

#endif // GAME_H
