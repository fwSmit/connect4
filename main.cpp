#include <iostream>
#include <array>
#include <sstream>
#include <string>
#include <vector>
#include <time.h>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Bot.h"
#include "TGUI/TGUI.hpp"


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
	

	sf::RenderWindow window(sf::VideoMode(7*140 + 10, 6*140 + 10), "SFML works!");
	sf::CircleShape circle(100.f);

	tgui::Gui gui{window};

	Game game(window, gui);
	

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

			game.handleEvent(event);
			gui.handleEvent(event);
        }
        window.clear();
		game.loop();
		//window.draw(circle);

		gui.draw();
        window.display();
    }

    //Game board;
	//board.start(&Game::getPlayerInput, &Game::getPlayerInput);
}
