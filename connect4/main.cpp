#include <iostream>
#include <array>
#include <sstream>
#include <string>

using namespace std;

typedef array<array <char, 7>, 6> pieces_t;
const char empty_char = '-';
const char player1_char = 'X';
const char player2_char = 'O';

const pieces_t testBoard {
{-,-,-,-,-,-,-},
{-,-,-,-,-,-,-},
{-,-,-,-,-,-,-},
{-,-,-,-,-,-,-},
{'X','X','X','X',-,-,-}
};

bool hasWon(bool player, pieces_t pieces){
    for(size_t beginPos = 0; beginPos < pieces_t.size()-4; beginPos++){
        for(size_t currPos = 0; currPos < 4; currPos++){

        }
    }
    return false;
}

class Board
{
    pieces_t pieces;
public:

    pieces_t getPieces()
    {
        return pieces;
    }

    Board()
    {
        for(auto& i: pieces) {
            for(auto& j : i) {
                j = empty_char;
            }
        }
    }
    friend ostream& operator<< (ostream& os, Board& b)
    {
        pieces_t _pieces = b.getPieces();
        for(size_t i = 1; i < _pieces[0].size()+1; i++) {
            std::cout << i << "  ";
        }
        std::cout << endl;
        for(size_t i = 0; i < _pieces.size(); i++) {
            os << "{";
            for(size_t j = 0; j < _pieces[i].size(); j++) {
                os << "-" << ",";
            }
            os << "}" << endl;
        }
        return os;

        /*
        pieces_t _pieces = b.getPieces();
        for(size_t i = 1; i < _pieces[0].size()+1; i++) {
            std::cout << i << "  ";
        }
        std::cout << endl;
        for(size_t i = 0; i < _pieces.size(); i++) {
            os << "{";
            for(size_t j = 0; j < _pieces[i].size(); j++) {
                os << _pieces[i][j] << ",";
            }
            os << "}" << endl;
        }
        return os;
        */
    }

    bool isInputCorrect(unsigned int input)
    {
        //cout << "validating input " << input << endl;
        if(!(input > 0 && input < (pieces[0].size() + 1))) {
            return false;
        } else {
            return pieces[0][input-1] == empty_char;
        }
    }

    void placePiece(unsigned int at, bool currPlayer)
    {
        // assuming input is correct
        for(int i = pieces.size()-1; i >= 0; i--) {
            if(pieces[i][at] == empty_char) {
                cout << "found empty spot at " << i << ", " << at  << endl;
                if(currPlayer) {
                    pieces[i][at] = player1_char;
                } else {
                    pieces[i][at] = player2_char;
                }
                break;
            }
        }
    }
};
unsigned int getPlayerInput(Board& board, bool currPlayer)
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
    Board board;
    bool finished = false;
    bool currPlayer = 0;

    unsigned int position;
    while(!finished) {
        cout << board << endl;
        //cout << "player " << currPlayer << "'s turn" << endl;
        getPlayerInput(board, currPlayer);
        currPlayer= !currPlayer;
    }
    return 0;
}
