#include <iostream>
#include <array>
#include <sstream>
#include <string>
#include <vector>
#include <time.h>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Bot.h"


using namespace std;

/*const pieces_t testBoard {
{-,-,-,-,-,-,-},
{-,-,-,-,-,-,-},
{-,-,-,-,-,-,-},
{-,-,-,-,-,-,-},
{'X','X','X','X',-,-,-}
};*/


const bool botAgainstBot = true;
const bool botPlays = true;
const bool testBot = false;

int main()
{
	srand( time(NULL));
	Game game;
	

	sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
		game.drawBoard(window);

        window.display();
    }

    //Game board;
	//board.start(&Game::getPlayerInput, &Game::getPlayerInput);
}
