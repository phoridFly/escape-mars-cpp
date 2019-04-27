/******************************************************************
 John Hash
 Final Project "Mars Escape"
 CS 162 Fall 2018
 Dec 4, 2018
 astronaut.hpp
 This is the header file for the Astronaut class. 
 *****************************************************************/

#ifndef astronaut_hpp
#define astronaut_hpp
#include "space.hpp"
#include "farm.hpp"
#include "mine.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::vector;


class Astronaut
{
private:
    
    // vector container will hold bool values true or false for canister
    // if found, farm canister is [0] and fuel canister is [1]
    vector<bool> canisters {false, false};
    
    // Space pointer to location
    Space* location;

    // bool flag for if injured
    bool injured;
    
public:
    // takes Space pointer to set initial location
    Astronaut(Space* l);
    
    Space* getLocation();
    void setLocation(Space* s);

    void moveMenu(Mine* m, Farm* f);
    void moveOrMine(int choice, Mine* m, Farm* f);
    
    void mineFuel(Mine* m);
    void farmFood(Farm* f);
    
    void showMap();
    
    int validInt(string input, int min, int max);
    
    bool getInjuredStatus();
    void setInjuredStatus(bool inj);
    
};

#endif
