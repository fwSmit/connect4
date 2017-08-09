#include "Pieces.h"
#include <iostream>

using namespace std;

char Pieces::getPiece(int x, int y){
	if(x >= getXSize() || y >= getYSize()){
		cout << x << " " << y << "is out of bounds" << endl;
		return 'Q';
	}
		return pieces[x][y];
}
void Pieces::print(){
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
