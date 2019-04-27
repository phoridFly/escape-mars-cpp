/******************************************************************
 John Hash
 Final Project "Mars Escape"
 CS 162 Fall 2018
 Dec 4, 2018
 Scrap_heap.cpp
 This is the implementation file for the Scrap_heap class. It is
 a derived class of the base class Space.
 *****************************************************************/

#include "scrap_heap.hpp"

Scrap_heap::Scrap_heap(): Space()
{
    spaceName = "SCRAP HEAP";
}

void Scrap_heap::canisterMessage()
{
    cout << "You found the FARM Canister in the SCRAP HEAP!" << endl;
    cout << "You can now FARM for FOOD." << endl;
    cout << "\n";
}
