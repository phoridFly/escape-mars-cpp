/******************************************************************
 John Hash
 Final Project "Mars Escape"
 CS 162 Fall 2018
 Dec 4, 2018
 space.hpp
 This is the header file for the Space class. It is
 a base class for the derived spaces and is abstract.
 *****************************************************************/

#ifndef space_hpp
#define space_hpp
#include <iostream>
using std::string;

class Space
{
  
protected:
    
    // Space pointers to adjacent spaces
    Space* up;
    Space* down;
    Space* left;
    Space* right;
    
    // whether space requires a canister
    bool needCanister;
    string spaceName;
    bool explored;
    int timesVisited;
    
public:
    Space();
    virtual ~Space() = 0;
    
    // setters for points to adjacent spaces
    void setUp(Space* u);
    void setDown(Space* d);
    void setLeft(Space* l);
    void setRight(Space* r);
    
    Space* getUp();
    Space* getDown();
    Space* getLeft();
    Space* getRight();
    
    string getSpaceName();
    
    // gets names of adjacent spaces
    string getUpName();
    string getDownName();
    string getLeftName();
    string getRightName();
    
    bool getExplored();
    void setExplored();
    
    void setTimesVisited(int num);
    int getTimesVisited();
    
};
#endif
