#include <iostream>
#include <array>
#include <sstream>
#include <string>
#include "Game.h"

using namespace std;

/*const pieces_t testBoard {
{-,-,-,-,-,-,-},
{-,-,-,-,-,-,-},
{-,-,-,-,-,-,-},
{-,-,-,-,-,-,-},
{'X','X','X','X',-,-,-}
};*/

bool hasWon(bool player, pieces_t pieces)
{
    char currPlayerPiece = player? player1_char : player2_char;
    for(size_t yPos = 0; yPos < pieces[0].size(); yPos ++) {
        for(size_t beginPos = 0; beginPos < pieces.size()-4; beginPos++) {
            unsigned int count = 0;
            for(size_t currPos = beginPos; currPos < beginPos +  4; currPos++) {
                if(pieces[currPos][yPos] == currPlayerPiece) {
                    count++;
                }
            }
            cout << "got " << count << endl;
        }
    }
    return false;
}

unsigned int getPlayerInput(Game& board, bool currPlayer)
{
    string input;
    unsigned int result;
    cout << "type 1-7 to place a piece at that position" << endl << endl;
    while(1) {
        std::getline (std::cin, input);
        stringstream ss(input);
        if(ss >> result && board.isInputCorrect(result)) {
            break;
        }
        cout << "input not correct" << endl;
    }
    //std::cout << "placing a piece at " << result << std::endl;
    board.placePiece(result-1, currPlayer);
    cout << endl;
    return result;

}


int main()
{
    Game board;
    bool finished = false;
    bool currPlayer = 0;

    while(!finished) {
        cout << board << endl;
        //cout << "player " << currPlayer << "'s turn" << endl;
        getPlayerInput(board, currPlayer);
        currPlayer= !currPlayer;
        if(hasWon(currPlayer, board.getPieces())) {
            cout << "player " << currPlayer << "has won" << endl;
        }
    }
    return 0;
}
