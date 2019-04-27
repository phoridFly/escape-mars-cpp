/******************************************************************
 John Hash
 Final Project "Mars Escape"
 CS 162 Fall 2018
 Dec 4, 2018
 launch.cpp
 This is the implementation file for the Launch class. It is
 a derived class of the base class Space.
 *****************************************************************/

#include "launch.hpp"

Launch::Launch(): Space()
{
    spaceName = "LAUNCH SITE";
}

// end of game message
void Launch::launchMessage()
{
    cout << "\n";
    cout << " _____________________________________________" << endl;
    cout << "YOU HAVE MADE IT OFF MARS! CONGRATULATIONS!" <<endl;
    cout <<"\n";
    cout << " _____________________________________________" << endl;
    cout <<"\n";
}

// went to launch too early message
void Launch::notYetMessage()
{
    cout << "You haven't gathered enough supplies to launch!" << endl;
    cout << "\n";
}
