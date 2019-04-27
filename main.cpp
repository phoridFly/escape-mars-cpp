/******************************************************************
 John Hash - fancy pants
 Final Project "Mars Escape"
 CS 162 Fall 2018
 Dec 4, 2018
 main.cpp
 Creates the ransom seed for the game and a Game object to start.
 *****************************************************************/

#include <iostream>
#include "game.hpp"

int main()
{
    srand(static_cast<unsigned>(time(NULL)));
    
    Game game;
    
    // call the game's main menu function
    game.menu();
    
    return 0;
}
