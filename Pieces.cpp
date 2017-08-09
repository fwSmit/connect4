#include "Pieces.h"
#include <iostream>
#include "Game.h"

using namespace std;

char Pieces::getPiece(int x, int y) const {
	if(x >= getXSize() || y >= getYSize()){
		cout << x << " " << y << "is out of bounds" << endl;
		return 'Q';
	}
		return pieces[x][y];
}
void Pieces::print() const {
	for(size_t y = 0; y < pieces[0].size(); y++) {
		for(size_t x = 0; x < pieces.size(); x++) {
			cout << pieces[x][y] << "  ";
		}
		cout << endl;
	}
	for(int i = 1; i <= getXSize(); i++){
		cout << i << "  ";
	}
	cout << endl;
}

void Pieces::setPiece(int x, int y, char target){
	pieces[x][y] = target;
}

bool Pieces::isFull() const {
	for(size_t i = 0; i < getXSize(); i++){
		for(size_t j = 0; j < getYSize(); j++){
			if(getPiece(i, j) == empty_char){
				return false;
			}
		}
	}
	return true;
}
