#include "Game.h"

Game::Game()
{
	for(int i = 0; i < pieces.getXSize(); i++){
		for(int j = 0; j < pieces.getYSize(); j++){
			pieces.setPiece(i, j, empty_char);
		}
	}
}

bool Game::hasWon(bool player)
{
    char currPlayerPiece = player? playerO_char : playerX_char;
	// horizontal win
    for(size_t yPos = 0; yPos < pieces.getYSize(); yPos ++) {
        for(size_t beginPos = 0; beginPos < pieces.getXSize() - 3; beginPos++) {
            unsigned int count = 0;
            for(size_t currPos = beginPos; currPos < beginPos +  4; currPos++) {
                if(pieces.getPiece(currPos, yPos) == currPlayerPiece) {
                    count++;
					//cout << "found horizontal piece at " << currPos << "	" << yPos << endl;
                }
            }
            //cout << "got " << count << endl;
			if (count == 4){
				cout << "horizontal" << endl;
				return true;
			}
        }
    }

	//vertical win
	for(size_t xPos = 0; xPos < pieces.getXSize(); xPos++){
		for(size_t yBegin = 0; yBegin < pieces.getYSize()-3; yBegin++){
			unsigned int count = 0;
			for(size_t curr = 0; curr < 4; curr++){
				if(pieces.getPiece(xPos, yBegin+curr) == currPlayerPiece){
					count++;
					//cout << "found vertical piece at " << xPos << "	" << yBegin+curr << endl;
				}
			}
			if(count == 4){
				cout << "vertical" << endl;
				return true;
			}
		}
	}

	// across like \ (backslash) 
	for(size_t xPos = 0; xPos < pieces.getXSize()-3; xPos++){
		for(size_t yPos = 0; yPos < pieces.getYSize()-3; yPos++){
			unsigned int count = 0;
			for(size_t curr = 0; curr < 4; curr++){
				if(pieces.getPiece(xPos+curr, yPos+curr) == currPlayerPiece){
					count++;
					//cout << "found piece at " << xPos+3-curr << "	" << yPos+curr << endl;
				}
			}
			if(count == 4){
				cout << "backslash" << endl;
				//cout << xPos << "	" << yPos << endl;
				return true;
			}
		}
		//cout << "reset count " << endl;
	}


	// across like / (forward slash) 
	for(size_t xPos = 0; xPos < pieces.getXSize()-3; xPos++){
		for(size_t yPos = 0; yPos < pieces.getYSize()-3; yPos++){
			unsigned int count = 0;
			for(size_t curr = 0; curr < 4; curr++){
				if(pieces.getPiece(xPos+curr, yPos+3-curr) == currPlayerPiece){
					count++;
				}
			}
			if(count == 4){
				cout << "/" << endl;
				return true;
			}
		}
	}

    return false;
}


