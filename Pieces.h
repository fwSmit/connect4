#include <array>
#include <iostream>
using namespace std;
class Pieces{
		array<array <char, 6>, 7> pieces;
	public:
		char getPiece(int x, int y);
		void print();
		int getXSize(){return 7;}
		int getYSize(){return 6;}
		void setPiece(int x, int y, char target);
};
