#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <array>
#include <sstream>
#include <string>

using namespace std;

typedef array<array <char, 6>, 7> pieces_t;
const char empty_char = '-';
const char player1_char = 'X';
const char player2_char = 'O';

class Game
{
    pieces_t pieces;
public:

    pieces_t getPieces()
    {
        return pieces;
    }

    Game();

    friend ostream& operator<< (ostream& os, Game& b)
    {
        /*pieces_t _pieces = b.getPieces();
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
        return os;*/


        pieces_t _pieces = b.getPieces();
        for(size_t i = 1; i < _pieces.size()+1; i++) {
            std::cout << i << "  ";
        }
        std::cout << endl;


        for(size_t y = 0; y < _pieces[0].size(); y++) {
            for(size_t x = 0; x < _pieces.size(); x++) {
                os << _pieces[x][y] << "  ";
            }
            os << endl;
        }
        return os;

    }

    bool isInputCorrect(unsigned int input)
    {
        //cout << "validating input " << input << endl;
        if(!(input > 0 && input < (pieces.size() + 1))) {
            return false;
        } else {
            return pieces[input-1][0] == empty_char;
        }
    }

    void placePiece(unsigned int at, bool currPlayer)
    {
        // assuming input is correct
        for(int i = pieces[0].size()-1; i >= 0; i--) {
            if(pieces[at][i] == empty_char) {
                cout << "found empty spot at " << at << ", " << i  << endl;
                if(currPlayer) {
                    pieces[at][i] = player1_char;
                } else {
                    pieces[at][i] = player2_char;
                }
                break;
            }
        }
    }
};

#endif // GAME_H
