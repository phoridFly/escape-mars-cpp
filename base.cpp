/******************************************************************
 John Hash
 Final Project "Mars Escape"
 CS 162 Fall 2018
 Dec 4, 2018
 base.cpp
 This is the implementation file for the Base class. It is
 a derived class of the base class Space. (Base here referring to
 the space on the board that is the player's "Base.")
 *****************************************************************/

#include "base.hpp"

Base::Base(): Space()
{
    spaceName = "BASE";
}

void Base::baseMessage()
{
    std::cout << "That should fix that injury. Ready to head out tomorrow." << std::endl;
}
