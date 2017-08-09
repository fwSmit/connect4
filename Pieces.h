#ifndef __PIECES_H__
#define __PIECES_H__

#include <array>
#include <iostream>
using namespace std;
class Pieces{
		array<array <char, 6>, 7> pieces;
	public:
		char getPiece(int x, int y) const;
		void print() const;
		int getXSize() const {return 7;}
		int getYSize() const {return 6;}
		void setPiece(int x, int y, char target);
		bool isFull() const;
};

#endif
