#include <iostream>
#include <array>
#include <sstream>
#include <string>
#include <vector>
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
    Game board;
	board.start(&Game::getPlayerInput, &Game::getPlayerInput);
}
