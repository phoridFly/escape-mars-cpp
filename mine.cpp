/******************************************************************
 John Hash
 Final Project "Mars Escape"
 CS 162 Fall 2018
 Dec 4, 2018
 mine.cpp
 This is the implementation file for the Mine class. It is
 a derived class of the base class Space.
 *****************************************************************/

#include "mine.hpp"

Mine::Mine(): Space()
{
    spaceName = "MINE";
    needCanister = true;
    fuel = 0;

}

// returns the amount of fuel mined
int Mine::getFuel()
{
    return fuel;
}

// updates the amount of fuel mined
void Mine::setFuel(int f)
{
    fuel = fuel + f;

}

