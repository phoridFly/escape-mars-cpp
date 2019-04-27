/******************************************************************
 John Hash
 Final Project "Mars Escape"
 CS 162 Fall 2018
 Dec 4, 2018
 mine.hpp
 This is the header file for the Mine class. It is
 a derived class of the base class Space.
 *****************************************************************/

#ifndef mine_hpp
#define mine_hpp

#include "space.hpp"

class Mine : public Space
{
private:
    
    int fuel;
    
public:
    Mine();
    
    int getFuel();
    void setFuel(int f);
    
};

#endif
