#include "Game.h"
#include <cmath>

Game::Game()
{
	for(int i = 0; i < pieces.getXSize(); i++){
		for(int j = 0; j < pieces.getYSize(); j++){
			pieces.setPiece(i, j, empty_char);
		}
	}

	font.loadFromFile("../fonts/Ubuntu-M.ttf");

	//for(int i = 0; i < 3; i++){
	//pieces.setPiece(i, 5, playerX_char);
	//}

	//for(int i = 0; i < 3; i++){
	//pieces.setPiece(i, 3, playerX_char);
	//}
}

bool Game::hasWon() const
{
	char currPlayerPiece = currPlayer == Player::O? playerO_char : playerX_char;
	// horizontal win
	for(size_t yPos = 0; yPos < pieces.getYSize(); yPos ++) {
		for(size_t beginPos = 0; beginPos < pieces.getXSize() - 3; beginPos++) {
			unsigned int count = 0;
			for(size_t currPos = beginPos; currPos < beginPos +  4; currPos++) {
				if(pieces.getPiece(currPos, yPos) == currPlayerPiece) {
					count++;
					//cout << "found horizontal piece at " << currPos << "	" << yPos << endl;
				}
			}
			//cout << "got " << count << endl;
			if (count == 4){
				//cout << "horizontal" << endl;
				return true;
			}
		}
	}

	//vertical win
	for(size_t xPos = 0; xPos < pieces.getXSize(); xPos++){
		for(size_t yBegin = 0; yBegin < pieces.getYSize()-3; yBegin++){
			unsigned int count = 0;
			for(size_t curr = 0; curr < 4; curr++){
				if(pieces.getPiece(xPos, yBegin+curr) == currPlayerPiece){
					count++;
					//cout << "found vertical piece at " << xPos << "	" << yBegin+curr << endl;
				}
			}
			if(count == 4){
				//cout << "vertical" << endl;
				return true;
			}
		}
	}

	// across like \ (backslash) 
	for(size_t xPos = 0; xPos < pieces.getXSize()-3; xPos++){
		for(size_t yPos = 0; yPos < pieces.getYSize()-3; yPos++){
			unsigned int count = 0;
			for(size_t curr = 0; curr < 4; curr++){
				if(pieces.getPiece(xPos+curr, yPos+curr) == currPlayerPiece){
					count++;
					//cout << "found piece at " << xPos+3-curr << "	" << yPos+curr << endl;
				}
			}
			if(count == 4){
				//cout << "backslash" << endl;
				//cout << xPos << "	" << yPos << endl;
				return true;
			}
		}
		//cout << "reset count " << endl;
	}


	// across like / (forward slash) 
	for(size_t xPos = 0; xPos < pieces.getXSize()-3; xPos++){
		for(size_t yPos = 0; yPos < pieces.getYSize()-3; yPos++){
			unsigned int count = 0;
			for(size_t curr = 0; curr < 4; curr++){
				if(pieces.getPiece(xPos+curr, yPos+3-curr) == currPlayerPiece){
					count++;
				}
			}
			if(count == 4){
				//cout << "/" << endl;
				return true;
			}
		}
	}

	return false;
}

int Game::getNumberWinningMoves(BotParameters params) const {
	unsigned int twoPiecesCount = 0;
	unsigned int threePiecesCount = 0;

	char currPlayerPiece = currPlayer == Player::O? playerO_char : playerX_char;
	// horizontal win
	for(size_t yPos = 0; yPos < pieces.getYSize(); yPos ++) {
		for(size_t beginPos = 0; beginPos < pieces.getXSize() - 3; beginPos++) {
			unsigned int count = 0;
			unsigned int pieces_count = 0;
			for(size_t currPos = beginPos; currPos < beginPos +  4; currPos++) {
				if(pieces.getPiece(currPos, yPos) != empty_char){
					pieces_count++;
				}
				if(pieces.getPiece(currPos, yPos) == currPlayerPiece) {
					count++;
					//cout << "found horizontal piece at " << currPos << "	" << yPos << endl;
				}
			}
			//cout << "got " << count << endl;
			if(pieces_count == 3 && count == 3){
				threePiecesCount++;
			}
			if (pieces_count == 2 && count == 2){
				//cout << "horizontal" << endl;
				twoPiecesCount++;
			}
		}
	}

	//vertical win
	for(size_t xPos = 0; xPos < pieces.getXSize(); xPos++){
		for(size_t yBegin = 0; yBegin < pieces.getYSize()-3; yBegin++){
			unsigned int count = 0;
			unsigned int pieces_count = 0;
			for(size_t curr = 0; curr < 4; curr++){
				if(pieces.getPiece(xPos, yBegin+curr) == currPlayerPiece){
					count++;
					//cout << "found vertical piece at " << xPos << "	" << yBegin+curr << endl;
				}
				if(pieces.getPiece(xPos, yBegin+curr) != empty_char){
					pieces_count++;
				}
			}
			if(pieces_count == 3 && count == 3){
				threePiecesCount++;
			}
			if (pieces_count == 2 && count == 2){
				//cout << "horizontal" << endl;
				twoPiecesCount++;
			}
		}
	}

	// across like \ (backslash) 
	for(size_t xPos = 0; xPos < pieces.getXSize()-3; xPos++){
		for(size_t yPos = 0; yPos < pieces.getYSize()-3; yPos++){
			unsigned int count = 0;
			unsigned int pieces_count = 0;
			for(size_t curr = 0; curr < 4; curr++){
				if(pieces.getPiece(xPos+curr, yPos+curr) == currPlayerPiece){
					count++;
					//cout << "found piece at " << xPos+3-curr << "	" << yPos+curr << endl;
				}
				if(pieces.getPiece(xPos+curr, yPos+curr) != empty_char){
					pieces_count++;
				}
			}
			if(pieces_count == 3 && count == 3){
				threePiecesCount++;
			}
			if (pieces_count == 2 && count == 2){
				//cout << "horizontal" << endl;
				twoPiecesCount++;
			}
		}
		//cout << "reset count " << endl;
	}


	// across like / (forward slash) 
	for(size_t xPos = 0; xPos < pieces.getXSize()-3; xPos++){
		for(size_t yPos = 0; yPos < pieces.getYSize()-3; yPos++){
			unsigned int count = 0;
			unsigned int pieces_count = 0;
			for(size_t curr = 0; curr < 4; curr++){
				if(pieces.getPiece(xPos+curr, yPos+3-curr) == currPlayerPiece){
					count++;
				}
				if(pieces.getPiece(xPos+curr, yPos+curr) != empty_char){
					pieces_count++;
				}
			}
			if(pieces_count == 3 && count == 3){
				threePiecesCount++;
			}
			if (pieces_count == 2 && count == 2){
				//cout << "horizontal" << endl;
				twoPiecesCount++;
			}
		}
	}

	//cout << "threePiecesCount " << threePiecesCount << endl << "twoPiecesCount " << twoPiecesCount << endl;
	int result = 	threePiecesCount * params.ThreeInARow
		+ twoPiecesCount * params.TwoInARow;
	/*switch (params){*/
	//case 1:
	//result = threePiecesCount;
	//break;
	//case 2:
	//result = twoPiecesCount + 5 * threePiecesCount;
	//break;

	//case 3:
	//result = twoPiecesCount;
	//break;
	//default:
	//result = 0;
	/*}*/
	return result;
}


void Game::start(std::function<int(Game)> player1, std::function<int(Game)> player2){
	bool finished = false;
	while(!finished) {
		if(getCurrentPlayer() == Player::Beginning){
			//cout << "Beginning player" << endl;
			placePiece(player1(*this));
		}else{
			//cout << "not Beginning player" << endl;
			placePiece(player2(*this));
		}
		print();
		if(hasWon()){
			print();
			cout << "player" << (getCurrentPlayer() == Player::O? " O " : " X ") << "has won" << endl;
			finished = true;
		}
		//cout << "number of 2 pieces in a row " << getNumberWinningMoves() << endl;
		//cout << "next player" << endl;
		nextPlayer();
	}
}

void Game::drawBoard(sf::RenderWindow& window){
	int circleSize = 130;
	int spacing = 10;
	sf::RectangleShape background(sf::Vector2f(window.getSize()));
	background.setFillColor(sf::Color::Green);
	window.draw(background);
	for(size_t y = 0; y < pieces.getYSize(); y++) {
		for(size_t x = 0; x < pieces.getXSize(); x++) {
			sf::CircleShape circle(circleSize/2);
			switch (pieces.getPiece(x,y)){
				case empty_char:
					circle.setFillColor(sf::Color::Black);
					break;
				case playerO_char:
					circle.setFillColor(sf::Color::Yellow);
					break;
				case playerX_char:
					circle.setFillColor(sf::Color::Blue);
					break;
				default:
					break;
			}
			circle.setPosition(x*(circleSize+spacing)+spacing, y*(spacing+ circleSize)+spacing);
			window.draw(circle); 
		} 
	} 
}

void Game::handleEvent(sf::Event event, sf::RenderWindow& window){
	int circleSize = 130;
	int spacing = 10;
	if(event.type == sf::Event::MouseButtonPressed){
		if(event.mouseButton.button == sf::Mouse::Left){	
			switch(gameState){
				case GameState::menu:{
					gameState = GameState::inGame;
					}break;
				case GameState::inGame:{
					   double place = std::floor(double(sf::Mouse::getPosition(window).x - spacing) / double(circleSize + spacing));
					   std::cout << sf::Mouse::getPosition(window).x << "	" << place << endl;
					   placePiece(place);
					   if(hasWon()){
						   gameState = GameState::ended;
					   }
					   else{
						   nextPlayer();
					   }
					   }break;
				case GameState::ended:
						gameState = GameState::inGame;
						break;
				default:
					   break;
			}
		}
	}
}

void Game::loop(sf::RenderWindow& window){
	switch(gameState){
		case GameState::menu:{
			 sf::Text text("Start", font, 100);  
			 window.draw(text);
			 }break;
		case GameState::inGame:
			 drawBoard(window);
			 break;
		case GameState::ended:
			 //drawBoard(window);
			 break;
		default:
			 break;
	}
}	
