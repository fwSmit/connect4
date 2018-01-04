#include "Pieces.h"
#include <iostream>
#include "Game.h"

using namespace std;

Pieces::Pieces(){
	cout << "constructor " << endl;
	clear();
	cout << "end of constructor " << endl;
}

void Pieces::clear(){
	for(int i = 0; i < getXSize(); i++){
		for(int j = 0; j < getYSize(); j++){
			setPiece(i, j, empty_char);
		}
	}
}

char Pieces::getPiece(int x, int y) const {
	if(!isInputCorrect(x)){
		cout << x << " " << y << "is out of bounds" << endl;
		return error_char;
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

bool Pieces::isInputCorrect(unsigned int input) const {
	//std::cout << "input is: " << input << std::endl; 
	if(input >= 0 && input < getXSize()){
		//cout << "in bounds" << endl;
		//cout << "highest piece: " << pieces[input][0] << endl;
		return pieces[input][0] == empty_char;
	}
	else{
		cout << "out of bounds: " << input << endl;
		return false;
	}
}

void Pieces::placePiece(unsigned int at, char player_char){
	for(int i = getYSize()-1; i >= 0; i--) {
		if(getPiece(at, i) == empty_char) {
			//cout << "found empty spot at " << at << ", " << i  << endl;
			setPiece(at, i, player_char);
			break;
		}
	}
}
