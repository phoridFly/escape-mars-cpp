/******************************************************************
 John Hash
 Final Project "Mars Escape"
 CS 162 Fall 2018
 Dec 4, 2018
 ancient_lake.cpp
 This is the implementation file for the Ancient_lake class. It is
 a derived class of the base class Space.
 *****************************************************************/

#include "ancient_lake.hpp"

// constructor
Ancient_lake::Ancient_lake(): Space()
{
    spaceName = "ANCIENT LAKE";
}

// interaction with lake
void Ancient_lake::lakeMessage()
{
    std::cout << "I really wish this place still had water...." << std::endl;

}
