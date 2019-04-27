/******************************************************************
 John Hash
 Final Project "Mars Escape"
 CS 162 Fall 2018
 Dec 4, 2018
 scrap_heap.hpp
 This is the header file for the Scrap_heap class. It is
 a derived class of the base class Space.
 *****************************************************************/

#ifndef scrap_heap_hpp
#define scrap_heap_hpp

#include <iostream>

#include "space.hpp"

using std::endl;
using std::cout;

class Scrap_heap : public Space
{
private:
    
public:
    Scrap_heap();
    void canisterMessage();
    
};

#endif
