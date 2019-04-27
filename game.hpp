/******************************************************************
 John Hash
 Final Project "Mars Escape"
 CS 162 Fall 2018
 Dec 4, 2018
 game.hpp
 This is the header file for the Game class. 
 *****************************************************************/

#ifndef game_hpp
#define game_hpp
#include <iostream>

using std::string;
using std::endl;
using std::cout;
using std::cin;

class Game
{
private:
    
public:
    void menu();
    void gameSetup();
    void runGame(int days);
    
    int validInt(string input, int min, int max);
};

#endif
