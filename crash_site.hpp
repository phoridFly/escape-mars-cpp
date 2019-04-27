/******************************************************************
 John Hash
 Final Project "Mars Escape"
 CS 162 Fall 2018
 Dec 4, 2018
 crash_site.hpp
 This is the header file for the Crash_site class. It is
 a derived class of the base class Space.
 *****************************************************************/

#ifndef crash_site_hpp
#define crash_site_hpp

#include <iostream>
#include "space.hpp"
using std::cout;
using std::endl;

class Crash_site : public Space
{
private:
    
public:
    Crash_site();
    void canisterMessage();
    
};

#endif
