/******************************************************************
 John Hash
 Final Project "Mars Escape"
 CS 162 Fall 2018
 Dec 4, 2018
 farm.hpp
 This is the header file for the Farm class. It is
 a derived class of the base class Space.
 *****************************************************************/

#ifndef farm_hpp
#define farm_hpp

#include <iostream>

#include "space.hpp"


class Farm : public Space
{
private:
    
    int food;
    
public:
    Farm();
    int getFood();
    void setFood(int f);
    
    
};

#endif
