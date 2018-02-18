#pragma once
#include <array>
#include <SFML/Graphics.hpp>
#include "TGUI/TGUI.hpp"
#include "BotParameters.h"

// temporary
#include <iostream>

enum Player : bool {O = false, X = true, Beginning = false};


class Game
{
	Player currPlayer = Player::Beginning;
	Player AI = Player::O;
	sf::Font font;
	enum class GameState { menu, inGame, ended};
	GameState gameState = GameState::menu;
	bool twoPlayer = false;
	bool timeout = false; // used by the bot so it's not too fast

	tgui::Button::Ptr button1;
	tgui::Button::Ptr button2;
	sf::RenderWindow& window;
	sf::Vector2f boardToScreen(sf::Vector2i position) const;
	unsigned int screenToBoardX(sf::Vector2i position) const;

	void drawBoard();
	
	// pieces
	const static char empty_char = '-';
	const static char playerO_char = 'O';
	const static char playerX_char = 'X';
	const static char error_char = 'Q';
	const static size_t XSize = 7;
	const static size_t YSize = 6;
	const int circleSize = 130; // diameter of the circle
	const int spacing = 10;
	const int board_offset_x = 10;
	const int board_offset_y = 10;
	std::array<std::array <char, YSize>, XSize> pieces;
	std::vector<std::pair<sf::Vector2i, sf::Vector2i>> winningPositions;
	void clear();
	char getPiece(int x, int y) const;
	char getPiece(int x) const;
	void print() const;
	void setPiece(int x, int y, char target);
	void onePlayerStart();
	void twoPlayerStart();
	void hideButtons();
	void showButtons();
	void drawLine(sf::Vector2f begin, sf::Vector2f end);



	// temporary
	void printPositions(std::vector<std::pair<sf::Vector2i, sf::Vector2i>> positions) const;
public:
	bool isInputCorrect(unsigned int input) const;
	bool isOutOfBounds(unsigned int input) const;
	bool isColumnFull(unsigned int input) const;
	constexpr int getXSize() {return XSize;}
	constexpr int getYSize() {return YSize;}
	bool isFull() const;
	void placePiece(unsigned int at);
	bool hasWon();
	Game(sf::RenderWindow& window, tgui::Gui& gui);
	void loop();
	void handleEvent(sf::Event event);
	char getPlayerChar();
	void nextPlayer();
	bool getCurrentPlayer() const {
		return currPlayer;
	}
	void endMove(); // checks if someone has won and otherwise calls nextPlayer
	char getCurrentPlayerChar() const;
	//void start(std::function<int(Game)> player1, std::function<int(Game)> player2);
	//void print();
	//unsigned int getPlayerInput() const;
	int getNumberWinningMoves(BotParameters params) const;
};

