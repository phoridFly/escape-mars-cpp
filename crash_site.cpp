/******************************************************************
 John Hash
 Final Project "Mars Escape"
 CS 162 Fall 2018
 Dec 4, 2018
 crash_site.cpp
 This is the implementation file for the Crash_site class. It is
 a derived class of the base class Space.
 *****************************************************************/

#include "crash_site.hpp"

Crash_site::Crash_site(): Space()
{
    spaceName = "CRASH SITE";
}

void Crash_site::canisterMessage()
{
    cout << "You found the FUEL Canister in the CRASH SITE!" << endl;
    cout << "You can now MINE for ammonia for FUEL." << endl;
}
