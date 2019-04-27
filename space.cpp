/******************************************************************
 John Hash
 Final Project "Mars Escape"
 CS 162 Fall 2018
 Dec 4, 2018
 space.cpp
 This is the implementation file for the Space class. It is
 a base class for the derived spaces and is abstract.
 *****************************************************************/

#include "space.hpp"


/******************************************************************
 constructor
 ******************************************************************/
Space::Space()
{
    
    up = nullptr;
    down = nullptr;
    left = nullptr;
    right = nullptr;
    spaceName = " ";
    needCanister = false;
    explored = false;
    timesVisited = 0;
    
}

/******************************************************************
 pure virtual blank destructor
 ******************************************************************/
Space::~Space()
{
    
}

/******************************************************************
 setter functions for the 4 space pointers
 ******************************************************************/
void Space::setUp(Space* u)
{
    up = u;
}
void Space::setDown(Space* d)
{
    down = d;
}
void Space::setLeft(Space* l)
{
    left = l;
}
void Space::setRight(Space* r)
{
    right = r;
}

/******************************************************************
 getters for the 4 space pointers
 ******************************************************************/
Space* Space::getUp()
{
    return up;
}
Space* Space::getDown()
{
    return down;
    
}
Space* Space::getLeft()
{
    return left;
    
}
Space* Space::getRight()
{
    return right;
    
}

/******************************************************************
 gets the name of the space
 ******************************************************************/
string Space::getSpaceName()
{
    return spaceName;
}

/******************************************************************
 getters for the names of the adjacent spaces
 ******************************************************************/
string Space::getUpName()
{
    string name = up->getSpaceName();
    return name;
}
string Space::getDownName()
{
    string name = down->getSpaceName();
    return name;
}
string Space::getLeftName()
{
    string name = left->getSpaceName();
    return name;
}
                      
string Space::getRightName()
{
    string name = right->getSpaceName();
    return name;
}

/******************************************************************
flag that returns bool to keep track of wheter space has
been explored
******************************************************************/
bool Space::getExplored()
{
    return explored;
}

void Space::setExplored()
{
    explored = true;
}

/******************************************************************
 get and set to keep track of number of times space was visited
 ******************************************************************/
void Space::setTimesVisited(int num)
{
    timesVisited = timesVisited + num;
}

int Space::getTimesVisited()
{
    return timesVisited;
}
