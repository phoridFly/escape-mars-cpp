/******************************************************************
 John Hash
 Final Project "Mars Escape"
 CS 162 Fall 2018
 Dec 4, 2018
 farm.cpp
 This is the implementation file for the Farm class. It is
 a derived class of the base class Space.
 *****************************************************************/

#include "farm.hpp"

Farm::Farm(): Space()
{
    spaceName = "FARM";
    needCanister = true;
    food = 0;
}

int Farm::getFood()
{
    return food;
}

void Farm::setFood(int f)
{
    food = food + f;
    
}

