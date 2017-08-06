#include "Game.h"

Game::Game()
{
    for(auto& i: pieces) {
            for(auto& j : i) {
                j = empty_char;
            }
        }
}


