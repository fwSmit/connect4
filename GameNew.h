#pragma once
#include <array>
#include <SFML/Graphics.hpp>
#include "TGUI/TGUI.hpp"

enum Player : bool {O = false, X = true, Beginning = false};

class Game
{
	Player currPlayer = Player::Beginning;
	sf::Font font;
	enum class GameState { menu, inGame, ended};
	GameState gameState = GameState::menu;
	bool TwoPlayer = false;
	tgui::Button::Ptr button1;
	tgui::Button::Ptr button2;
	sf::RenderWindow& window;
	void drawBoard();
	
	// pieces
	const char empty_char = '-';
	const char playerO_char = 'O';
	const char playerX_char = 'X';
	const char error_char = 'Q';
	constexpr int getXSize() {return 7;}
	constexpr int getYSize() {return 6;}
	array<array <char, getYSize()>, getXSize()> pieces;
	void clear();
	char getPiece(int x, int y) const;
	char getPiece(int x) const;
	void print() const;
	void setPiece(int x, int y, char target);
	bool isInputCorrect(unsigned int input) const;
	bool isFull() const;
public:
	void placePiece(unsigned int at);
	bool hasWon() const;
	Game(sf::RenderWindow& window, tgui::Gui& gui);
	void loop();
	void handleEvent(sf::Event event);
	char getPlayerChar();
	void nextPlayer();
	const Pieces getPieces() const;
	bool isFull(){
		return pieces.isFull();
	}
	bool getCurrentPlayer() const {
		return currPlayer;
	}
	//void start(std::function<int(Game)> player1, std::function<int(Game)> player2);
	//void print();
	//unsigned int getPlayerInput() const;
	//int getNumberWinningMoves(BotParameters params) const;
};

