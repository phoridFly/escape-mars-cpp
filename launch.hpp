/******************************************************************
 John Hash
 Final Project "Mars Escape"
 CS 162 Fall 2018
 Dec 4, 2018
 launch.cpp
 This is the header file for the Launch class. It is
 a derived class of the base class Space.
 *****************************************************************/

#ifndef launch_hpp
#define launch_hpp

#include "space.hpp"

#include <iostream>
using std::endl;
using std::cout;

class Launch : public Space
{
private:
    
public:
    Launch();
    void launchMessage();
    void notYetMessage();
    
};

#endif
