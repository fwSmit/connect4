#ifndef __PIECES_H__
#define __PIECES_H__

#include <array>
#include <iostream>
using namespace std;
const char empty_char = '-';
const char playerO_char = 'O';
const char playerX_char = 'X';
const char error_char = 'Q';
class Pieces{
		std::array<std::array <char, 6>, 7> pieces;
	public:
		Pieces();
		void clear();
		char getPiece(int x, int y) const;
		void print() const;
		int getXSize() const {return 7;}
		int getYSize() const {return 6;}
		void setPiece(int x, int y, char target);
		bool isInputCorrect(unsigned int input) const;
		bool isFull() const;
		void placePiece(unsigned int at, char player_char);
};

#endif
