#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <array>
#include <sstream>
#include <string>
#include <functional>
#include <SFML/Graphics.hpp>
#include "BotParameters.h"
#include "Pieces.h"
#include "TGUI/TGUI.hpp"

using namespace std;

enum Player : bool {O = false, X = true, Beginning = false};

class Game
{
	Pieces pieces;
	Player currPlayer = Player::Beginning;
	sf::Font font;
	enum class GameState { menu, inGame, ended};
	GameState gameState = GameState::menu;
	bool TwoPlayer = false;
	tgui::Button::Ptr button1;
	tgui::Button::Ptr button2;
	sf::RenderWindow& window;
	void drawBoard();
public:
	bool isFull(){
		return pieces.isFull();
	}
	bool getCurrentPlayer() const {
		return currPlayer;
	}
    void placePiece(unsigned int at);
    bool hasWon() const;
	//Game(){}
	Game(sf::RenderWindow& window, tgui::Gui& gui);
	void loop();
	//void start(std::function<int(Game)> player1, std::function<int(Game)> player2);
	void handleEvent(sf::Event event);
	char getPlayerChar();
	const Pieces getPieces() const {
		return pieces;
	}


	//void print(){
		//pieces.print();
	//}


	//unsigned int getPlayerInput() const;

	void nextPlayer(){
		if(currPlayer == Player::O) currPlayer = Player::X;
		else currPlayer = Player::O;
	}
	int getNumberWinningMoves(BotParameters params) const;
};

#endif // GAME_H
