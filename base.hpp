/******************************************************************
 John Hash - fancy pants
 Final Project "Mars Escape"
 CS 162 Fall 2018
 Dec 4, 2018
 base.hpp
 This is the header file for the Base class. It is
 a derived class of the base class Space. (Base here referring to
 the space on the board that is the player's "Base.")
 *****************************************************************/

#ifndef base_hpp
#define base_hpp

#include "space.hpp"
#include <iostream>

class Base : public Space
{
private:
    
public:
    Base();
    void baseMessage();
    
};

#endif
