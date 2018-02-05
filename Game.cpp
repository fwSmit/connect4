#define _USE_MATH_DEFINES
#include <math.h>
#include <assert.h>
#include "Game.h"
#include <cmath>
#include <iostream>

using namespace std;

Game::Game(sf::RenderWindow& _window, tgui::Gui& gui) : window(_window)
{
	tgui::Theme::Ptr theme = tgui::Theme::create("/home/friso/tgui-git/src/TGUI/widgets/Black.txt");
	button1 = theme->load("button");
	button1->setText("1 player");
	button1->setSize(sf::Vector2f(100, 100));
	button1->setPosition(100, 300);
	button1->connect("pressed", &Game::onePlayerStart, this);
	gui.add(button1, "button1");
	button2 = theme->load("button");
	button2->setText("2 player");
	button2->setSize(sf::Vector2f(100, 100));
	button2->setPosition(100, 500);
	button2->connect("pressed", &Game::twoPlayerStart, this);
	gui.add(button2, "button2");

	font.loadFromFile("../fonts/Ubuntu-M.ttf");

	clear();
	placePiece(1);
	placePiece(2);
	placePiece(2);
	placePiece(3);
	placePiece(3);
	placePiece(3);
	nextPlayer();
	placePiece(4);
	placePiece(4);
	placePiece(4);
	nextPlayer();

}

bool Game::hasWon() 
{
	bool won = false;
	char currPlayerPiece = getCurrentPlayerChar();
	winningPositions.clear();
	// horizontal win
	for(size_t yPos = 0; yPos < getYSize(); yPos ++) {
		for(size_t beginPos = 0; beginPos < getXSize() - 3; beginPos++) {
			unsigned int count = 0;
			for(size_t currPos = beginPos; currPos < beginPos +  4; currPos++) {
				if(getPiece(currPos, yPos) == currPlayerPiece) {
					count++;
					//cout << "found horizontal piece at " << currPos << "	" << yPos << endl;
				}
			}
			//cout << "got " << count << endl;
			if (count == 4){
				cout << "horizontal" << endl;
				winningPositions.push_back(std::make_pair(sf::Vector2i(beginPos, yPos), sf::Vector2i(beginPos + 3, yPos)));
				won = true;
				//return true;
			}
		}
	}

	//vertical win
	for(size_t xPos = 0; xPos < getXSize(); xPos++){
		for(size_t yBegin = 0; yBegin < getYSize()-3; yBegin++){
			unsigned int count = 0;
			for(size_t curr = 0; curr < 4; curr++){
				if(getPiece(xPos, yBegin+curr) == currPlayerPiece){
					count++;
					//cout << "found vertical piece at " << xPos << "	" << yBegin+curr << endl;
				}
			}
			if(count == 4){
				cout << "vertical" << endl;
				winningPositions.push_back(std::make_pair(sf::Vector2i(xPos, yBegin), sf::Vector2i(xPos, yBegin + 3)));
				won = true;
				//return true;
			}
		}
	}

	// across like \ (backslash) 
	for(size_t xPos = 0; xPos < getXSize()-3; xPos++){
		for(size_t yPos = 0; yPos < getYSize()-3; yPos++){
			unsigned int count = 0;
			for(size_t curr = 0; curr < 4; curr++){
				if(getPiece(xPos+curr, yPos+curr) == currPlayerPiece){
					count++;
					//cout << "found piece at " << xPos+3-curr << "	" << yPos+curr << endl;
				}
			}
			if(count == 4){
				cout << "backslash" << endl;
				//cout << xPos << "	" << yPos << endl;
				winningPositions.push_back(std::make_pair(sf::Vector2i(xPos, yPos), sf::Vector2i(xPos + 3, yPos + 3)));
				won = true;
				//return true;
			}
		}
		//cout << "reset count " << endl;
	}


	// across like / (forward slash) 
	for(size_t xPos = 0; xPos < getXSize()-3; xPos++){
		for(size_t yPos = 0; yPos < getYSize()-3; yPos++){
			unsigned int count = 0;
			for(size_t curr = 0; curr < 4; curr++){
				if(getPiece(xPos+curr, yPos+3-curr) == currPlayerPiece){
					count++;
				}
			}
			if(count == 4){
				cout << "/" << endl;
				winningPositions.push_back(std::make_pair(sf::Vector2i(xPos, yPos+3), sf::Vector2i(xPos + 3, yPos)));
				won = true;
				//return true;
			}
		}
	}
	return won;
}

//int Game::getNumberWinningMoves(BotParameters params) const {
	//unsigned int twoPiecesCount = 0;
	//unsigned int threePiecesCount = 0;

	//char currPlayerPiece = currPlayer == Player::O? playerO_char : playerX_char;
	//// horizontal win
	//for(size_t yPos = 0; yPos < getYSize(); yPos ++) {
		//for(size_t beginPos = 0; beginPos < getXSize() - 3; beginPos++) {
			//unsigned int count = 0;
			//unsigned int pieces_count = 0;
			//for(size_t currPos = beginPos; currPos < beginPos +  4; currPos++) {
				//if(getPiece(currPos, yPos) != empty_char){
					//pieces_count++;
				//}
				//if(getPiece(currPos, yPos) == currPlayerPiece) {
					//count++;
					////cout << "found horizontal piece at " << currPos << "	" << yPos << endl;
				//}
			//}
			////cout << "got " << count << endl;
			//if(pieces_count == 3 && count == 3){
				//threePiecesCount++;
			//}
			//if (pieces_count == 2 && count == 2){
				////cout << "horizontal" << endl;
				//twoPiecesCount++;
			//}
		//}
	//}

	////vertical win
	//for(size_t xPos = 0; xPos < getXSize(); xPos++){
		//for(size_t yBegin = 0; yBegin < getYSize()-3; yBegin++){
			//unsigned int count = 0;
			//unsigned int pieces_count = 0;
			//for(size_t curr = 0; curr < 4; curr++){
				//if(getPiece(xPos, yBegin+curr) == currPlayerPiece){
					//count++;
					////cout << "found vertical piece at " << xPos << "	" << yBegin+curr << endl;
				//}
				//if(getPiece(xPos, yBegin+curr) != empty_char){
					//pieces_count++;
				//}
			//}
			//if(pieces_count == 3 && count == 3){
				//threePiecesCount++;
			//}
			//if (pieces_count == 2 && count == 2){
				////cout << "horizontal" << endl;
				//twoPiecesCount++;
			//}
		//}
	//}

	//// across like \ (backslash) 
	//for(size_t xPos = 0; xPos < getXSize()-3; xPos++){
		//for(size_t yPos = 0; yPos < getYSize()-3; yPos++){
			//unsigned int count = 0;
			//unsigned int pieces_count = 0;
			//for(size_t curr = 0; curr < 4; curr++){
				//if(getPiece(xPos+curr, yPos+curr) == currPlayerPiece){
					//count++;
					////cout << "found piece at " << xPos+3-curr << "	" << yPos+curr << endl;
				//}
				//if(getPiece(xPos+curr, yPos+curr) != empty_char){
					//pieces_count++;
				//}
			//}
			//if(pieces_count == 3 && count == 3){
				//threePiecesCount++;
			//}
			//if (pieces_count == 2 && count == 2){
				////cout << "horizontal" << endl;
				//twoPiecesCount++;
			//}
		//}
		////cout << "reset count " << endl;
	//}


	//// across like / (forward slash) 
	//for(size_t xPos = 0; xPos < getXSize()-3; xPos++){
		//for(size_t yPos = 0; yPos < getYSize()-3; yPos++){
			//unsigned int count = 0;
			//unsigned int pieces_count = 0;
			//for(size_t curr = 0; curr < 4; curr++){
				//if(getPiece(xPos+curr, yPos+3-curr) == currPlayerPiece){
					//count++;
				//}
				//if(getPiece(xPos+curr, yPos+curr) != empty_char){
					//pieces_count++;
				//}
			//}
			//if(pieces_count == 3 && count == 3){
				//threePiecesCount++;
			//}
			//if (pieces_count == 2 && count == 2){
				////cout << "horizontal" << endl;
				//twoPiecesCount++;
			//}
		//}
	//}

	////cout << "threePiecesCount " << threePiecesCount << endl << "twoPiecesCount " << twoPiecesCount << endl;
	//int result = 	threePiecesCount * params.ThreeInARow
		//+ twoPiecesCount * params.TwoInARow;
	//[>switch (params){<]
	////case 1:
	////result = threePiecesCount;
	////break;
	////case 2:
	////result = twoPiecesCount + 5 * threePiecesCount;
	////break;

	////case 3:
	////result = twoPiecesCount;
	////break;
	////default:
	////result = 0;
	//[>}<]
	//return result;
//}


//void Game::start(std::function<int(Game)> player1, std::function<int(Game)> player2){
	//bool finished = false;
	//while(!finished) {
		//if(getCurrentPlayer() == Player::Beginning){
			////cout << "Beginning player" << endl;
			//placePiece(player1(*this));
		//}else{
			////cout << "not Beginning player" << endl;
			//placePiece(player2(*this));
		//}
		//print();
		//if(hasWon()){
			//print();
			//cout << "player" << (getCurrentPlayer() == Player::O? " O " : " X ") << "has won" << endl;
			//finished = true;
		//}
		////cout << "number of 2 pieces in a row " << getNumberWinningMoves() << endl;
		////cout << "next player" << endl;
		//nextPlayer();
	//}
//}

void Game::drawBoard(){
	sf::RectangleShape background(sf::Vector2f(window.getSize()));
	background.setFillColor(sf::Color::Green);
	window.draw(background);
	for(size_t y = 0; y < getYSize(); y++) {
		for(size_t x = 0; x < getXSize(); x++) {
			sf::CircleShape circle(circleSize/2);
			circle.setOrigin(circle.getRadius(), circle.getRadius());
			switch (getPiece(x,y)){
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
					circle.setFillColor(sf::Color::Red);
					break;
			}
			circle.setPosition(boardToScreen(sf::Vector2i(x, y)));
			window.draw(circle); 
		} 
	} 
}

void Game::handleEvent(sf::Event event){
	int circleSize = 130;
	int spacing = 10;
	if(event.type == sf::Event::MouseButtonPressed){
		if(event.mouseButton.button == sf::Mouse::Left){	
			switch(gameState){
				case GameState::menu:{
					}break;
				case GameState::inGame:{
					    unsigned int place = screenToBoardX(sf::Mouse::getPosition(window));
						if(!isColumnFull(place)){
							placePiece(place);
							if(hasWon()){
								gameState = GameState::ended;
							}
							else nextPlayer();
						}
						}break;
				case GameState::ended:
						cout << "mouse pressed in end game" << endl;
						clear();
						gameState = GameState::inGame;
						break;
				default:
					   break;
			}
		}
	}
}

void Game::loop(){
	switch(gameState){
		case GameState::menu:{
			 }break;
		case GameState::inGame:
			 drawBoard();
			 break;
		case GameState::ended:
			 drawBoard();
			 for(int i = 0; i < winningPositions.size(); i++){
				 drawLine(boardToScreen(winningPositions[i].first), boardToScreen(winningPositions[i].second));
			 }
			 break;
		default:
			 break;
	}
}

char Game::getPlayerChar(){
	if(currPlayer == Player::X){
		return playerX_char;
	}else{
		return playerO_char;
	}
}	

//unsigned int Game::getPlayerInput() const {
	//string input;
	//unsigned int result;
	//cout << "type 1-7 to place a piece at that position" << endl << endl;
	//while(1) {
		//std::getline (std::cin, input);
		//stringstream ss(input);
		//if(ss >> result && isInputCorrect(result)) {
			//break;
		//}
		//cout << "input not correct" << endl;
	//}
	////std::cout << "placing a piece at " << result << std::endl;
	//cout << endl;
	//return result - 1;

//}

void Game::nextPlayer(){
	if(currPlayer == Player::O) currPlayer = Player::X;
	else currPlayer = Player::O;
}

//void Game::print(){
	//print();
//}


void Game::clear(){
	for(int i = 0; i < getXSize(); i++){
		for(int j = 0; j < getYSize(); j++){
			setPiece(i, j, empty_char);
		}
	}
}

char Game::getPiece(int x, int y) const {
	if(isOutOfBounds(x)){
		cout << x << " " << y << "is out of bounds" << endl;
		return error_char;
	}
	return pieces[x][y];
}
void Game::print() const {
	for(size_t y = 0; y < getYSize(); y++) {
		for(size_t x = 0; x < getXSize(); x++) {
			cout << getPiece(x, y) << "  ";
		}
		cout << endl;
	}
	for(int i = 1; i <= getXSize(); i++){
		cout << i << "  ";
	}
	cout << endl;
}

void Game::setPiece(int x, int y, char target){
	pieces[x][y] = target;
}

bool Game::isFull() const {
	for(size_t i = 0; i < getXSize(); i++){
		for(size_t j = 0; j < getYSize(); j++){
			if(getPiece(i, j) == empty_char){
				return false;
			}
		}
	}
	return true;
}

bool Game::isInputCorrect(unsigned int input) const {
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

bool Game::isOutOfBounds(unsigned int input) const{
	if(input < 0 || input >= getXSize()){
		return true;
	}
	return false;
}

bool Game::isColumnFull(unsigned int input) const{
	return getPiece(input, 0) != empty_char;
}

void Game::placePiece(unsigned int at){
	for(int i = getYSize()-1; i >= 0; i--) {
		if(getPiece(at, i) == empty_char) {
			//cout << "found empty spot at " << at << ", " << i  << endl;
			setPiece(at, i, getPlayerChar());
			break;
		}
	}
}

void Game::onePlayerStart(){
	gameState = GameState::inGame;
	twoPlayer = false;
	hideButtons();
}


void Game::twoPlayerStart(){
	gameState = GameState::inGame;
	twoPlayer = true;
	hideButtons();
}

void Game::hideButtons(){
	button1->hide();
	button2->hide();
}

void Game::showButtons(){
	button1->show();
	button2->show();
}

char Game::getCurrentPlayerChar() const{
	return getCurrentPlayer() == Player::O ? playerO_char : playerX_char;
}

void Game::printPositions(std::vector<std::pair<sf::Vector2i, sf::Vector2i>> positions) const{
	for(int i = 0; i < positions.size(); i++){
		cout << "from: " << positions[i].first.x << ",  " << positions[i].first.y << endl;
		cout << "to: " << positions[i].second.x << ",  " << positions[i].second.y << endl;
	}
}

void Game::drawLine(sf::Vector2f begin, sf::Vector2f end){
	int thickness = 20;
	sf::Vector2f delta = end - begin;
	//delta.x = std::abs(begin.x - end.x);
	//delta.y = std::abs(begin.y - end.y);
	int size = std::sqrt(std::pow(delta.x, 2) + std::pow(delta.y, 2));
	float angle = std::atan2(delta.y, delta.x);
	angle = angle / (2*M_PI) * 360;
	sf::RectangleShape rect(sf::Vector2f(size, thickness));
	rect.setOrigin(0, thickness/2);
	rect.setRotation(angle);
	rect.setPosition(begin);
	std::cout << "delta " << delta.x << " " << delta.y << std::endl;
	std::cout << "angle " << angle << std::endl;
	window.draw(rect);
	
	//sf::VertexArray line(sf::PrimitiveType::Lines, 2);
	//line[0].position = begin;
	//line[0].color = sf::Color::Red;
	//line[1].position = end;
	//line[1].color = sf::Color::Red;
	//window.draw(line);
}

sf::Vector2f Game::boardToScreen(sf::Vector2i position) const {
	return sf::Vector2f(position.x * (circleSize + spacing) + board_offset_x + circleSize / 2, position.y * (spacing + circleSize) + board_offset_y + circleSize / 2);
}

unsigned int Game::screenToBoardX(sf::Vector2i position) const{
	return std::floor(double(position.x - board_offset_x) / double(circleSize + spacing));
}
