/******************************************************************
 John Hash
 Final Project "Mars Escape"
 CS 162 Fall 2018
 Dec 4, 2018
 astronaut.cpp
 This is the implementation file for the Astronaut class. Along
 with the Game class, it does most of the work of the game.
 *****************************************************************/

#include "astronaut.hpp"

/*************************************************************************
                                Astronaut()
 Constructor for Astronaut class. Sets initial location of Astronaut, and
 sets injured = false.
 **************************************************************************/
Astronaut::Astronaut(Space* l)
{
    location = l;
    injured = false;
}

/*************************************************************************
 set and get functions for astronaut's location
 **************************************************************************/
Space* Astronaut::getLocation()
{
    return location;
}

void Astronaut::setLocation(Space* s)
{
    location = s;
}

/*************************************************************************
                            moveMenu()
 Prints out the list of available actions each day. Only viable moves and
 resource gathering actions are displayed. Takes pointers to the Mine and
 Farm spaces to pass them on the the resources gatherin functions.
 **************************************************************************/
void Astronaut::moveMenu(Mine* m, Farm* f)
{
    // this vector will hold all the viable choices and will be searched for user input
    vector<int> choiceList;
    

    // pointer to current location of astronaut player
    Space* current = getLocation();
    
    cout << "You are currently at " << current->getSpaceName() << "." << endl;
    
    // if statement block of choices, null checker prevents non-viable ones from displaying
    cout << "You can move: " << endl;
    if (current->getUp() != nullptr)
    {
        // gets names of adjacent space
        cout << "UP to " << current->getUpName() << " by pressing 1" << endl;
        // if viable choice, puts it in the vector
        choiceList.push_back(1);
    }
    
    if (current->getDown() != nullptr)
    {
        cout << "DOWN to " << current->getDownName() << " by pressing 2" << endl;
        choiceList.push_back(2);
    }
    
    if (current->getLeft() != nullptr)
    {
        cout << "LEFT to " << current->getLeftName() << " by pressing 3" << endl;
        choiceList.push_back(3);
    }
    
    if (current->getRight() != nullptr)
    {
        cout << "RIGHT to " << current->getRightName() << " by pressing 4" << endl;
        choiceList.push_back(4);
    }
    
    if (current->getSpaceName() == "MINE" && canisters[1] == true)
    {
        cout << "Mine ammonia for hydrazine fuel by pressing 5" << endl;
        choiceList.push_back(5);
    }
    
    if (current->getSpaceName() == "FARM" && canisters[0] == true)
    {
        cout << "Farm for food by pressing 6" << endl;
        choiceList.push_back(6);
    }
    
    bool goodChoice = false;
    
    // takes choice as a string
    string choice;
    getline(cin, choice);
    cin.clear();
    int validChoice = validInt(choice, 1, 6);
    
    // code make sure a valid integer is selected
    while (goodChoice == false)
    {
        if (std::find(choiceList.begin(), choiceList.end(), validChoice) != choiceList.end())
        {
            goodChoice = true;
        }
        
        else
        {
            cout << "Enter a valid choice." << endl;
            //cin >> validChoice;
            //cin.clear();
            
            getline(cin, choice);
            cin.clear();
            validChoice = validInt(choice, 1, 6);
        }
    }
    
    // call the moveOrMine function, pass it choice and pointers to resourse spaces
    moveOrMine(validChoice, m, f);
}

/*************************************************************************
                        moveOrMine()
 Takes an int for user choice, and pointers to Mine and Farm.
 It has two switch statements on choice to select where the player moves
 and the other to decide to farm or mine.
 **************************************************************************/
void Astronaut::moveOrMine(int choice, Mine* m, Farm* f)
{
    Space* current = getLocation();
    
    // switch statement on choice for move
    switch (choice)
    {
            // if the choice is move, change current location to new one
        case 1: setLocation(current->getUp());
            // set space to explored
            current->setExplored();
            // increase times visited by 1
            current->setTimesVisited(1);
            break;
        case 2: setLocation(current->getDown());
            current->setExplored();
            current->setTimesVisited(1);
            break;
        case 3: setLocation(current->getLeft());
            current->setExplored();
            current->setTimesVisited(1);
            break;
        case 4: setLocation(current->getRight());
            current->setExplored();
            current->setTimesVisited(1);
            break;
    }
    
    // found the farm canister in Scrap Heap
    if (current->getSpaceName() == "SCRAP HEAP" && current->getTimesVisited() == 1)
    {

        canisters[0] = true;
    }
    
    //  found the fuel canister Crash site
    if (current->getSpaceName() == "CRASH SITE" && current->getTimesVisited() == 1)
    {

        canisters[1] = true;
    }
    
    // switch statement for deciding to farm or mine
    switch (choice)
    {
            // if choice is to mine or farm, call function
        case 5: mineFuel(m);
            break;
        case 6: farmFood(f);
            break;
    }
}


/*************************************************************************
                        mineFuel()
 Takes a pointer to the mine Space. Carries out the random events that can
 happen there. 15% chance injury, 60% chance success, 25% chance failure.
 **************************************************************************/
void Astronaut::mineFuel(Mine* m)
{
    cout << "Time to start mining ammonia for hydrazine fuel." << endl;
    
    // can only mine if not injured
    if (injured == false)
    {
        int event = rand() % 20 + 1;
        
        // 1-3 are injuries
        if (event == 1 || event == 2)
        {
            cout << "That's a bad cut. You need to get back to base for first aid." << endl;
            setInjuredStatus(true);
        }
        
        else if (event == 3)
        {
            cout << "Airhose and arm has been damaged by an explosion. Get back to base to repair it." << endl;
        }
        
        // 4-15 are successful mining events
        else if (event >= 4 && event <= 10)
        {
            cout << "That's a good haul of ammonia for the day. Nice work." << endl;
            // call setFuel from mine pointer
            m->setFuel(1);
        }
        
        else if (event >= 11 && event < 16)
        {
            cout << "You've extracted all the ammonia you can for the day." << endl;
            m->setFuel(1);
            
        }
        
        // 16-20 are unsuccessful mining events
        else if (event >= 16)
        {
            cout << "It was a bad day. You couldn't find any ammonia." << endl;
        }
        
    }
    
    // warning that you can't work, if you're injured
    else
    {
        cout << "Stop trying to work with that injury. Get back to base!" << endl;
    }
}

/*************************************************************************
                                    farmFood()
 Takes a pointer to the farm space.
 15% chance injury, 60% chance success, 25% chance failure.
 **************************************************************************/
void Astronaut::farmFood(Farm* f)
{
    cout << "Time to start picking these vegetables." << endl;
   
    // can only farm if not injured
    if (injured == false)
    {
        int event = rand() % 20 + 1;
        
        // 1-3 are injuries
        if (event == 1 || event == 2)
        {
            cout << "That was a nasty fall. You need to get back to base for first aid." << endl;
            setInjuredStatus(true);
        }
        
        else if (event == 3)
        {
            cout << "You sprained your ankle really bad. Get back to base." << endl;
            setInjuredStatus(true);
        }
        
        // 4-15 are successful farming events
        else if (event >= 4 && event <= 10)
        {
            cout << "That's enough farming for the day. Nice work." << endl;
            // calls setFood on farm pointer
            f->setFood(1);
        }
        
        else if (event >= 11 && event < 16)
        {
            cout << "These veggies are looking good. Let's call it a day." << endl;
            f->setFood(1);
        }
        
        // 16-20 are unsuccessful farming events
        else if (event >= 16)
        {
            cout << "That storm last night really wrecked parts of the garden. No food was harvested." << endl;
        }
        
    }
    
    // warning that you can't work, if you're injured
    else
    {
        cout << "Stop trying to work with that injury. Get back to base!" << endl;
    }
}

/*************************************************************************
 set and get functions for astronaut's injury status
 **************************************************************************/
bool Astronaut::getInjuredStatus()
{
    return injured;
}

void Astronaut::setInjuredStatus(bool inj)
{
    injured = inj;
}

/*************************************************************************
                                showMap()
 Some simple illustrations of the map that are called when the player moves
 to a new space.
 **************************************************************************/
void Astronaut::showMap()
{
    if (location->getSpaceName() == "BASE")
    {
        cout << "******************************** " << endl;
        cout << "*     MINE     *  CRASH SITE   * " << endl;
        cout << "*              *               * " << endl;
        cout << "*              *               * " << endl;
        cout << "************************************************ " << endl;
        cout << "*     BASE     * ANCIENT LAKE  *  LAUNCH SITE  * " << endl;
        cout << "*              *               *               * " << endl;
        cout << "* You Are Here *               *               * " << endl;
        cout << "************************************************ " << endl;
        cout << "*  SCRAP HEAP  *     FARM      * " << endl;
        cout << "*              *               * " << endl;
        cout << "*              *               * " << endl;
        cout << "******************************** " << endl;
    }
    
    else if (location->getSpaceName() == "MINE")
    {
        cout << "******************************** " << endl;
        cout << "*     MINE     *  CRASH SITE   * " << endl;
        cout << "*              *               * " << endl;
        cout << "* You Are Here *               * " << endl;
        cout << "************************************************ " << endl;
        cout << "*     BASE     * ANCIENT LAKE  *  LAUNCH SITE  * " << endl;
        cout << "*              *               *               * " << endl;
        cout << "*              *               *               * " << endl;
        cout << "************************************************ " << endl;
        cout << "*  SCRAP HEAP  *     FARM      * " << endl;
        cout << "*              *               * " << endl;
        cout << "*              *               * " << endl;
        cout << "******************************** " << endl;
    }
    
    else if (location->getSpaceName() == "SCRAP HEAP")
    {
        cout << "******************************** " << endl;
        cout << "*     MINE     *  CRASH SITE   * " << endl;
        cout << "*              *               * " << endl;
        cout << "*              *               * " << endl;
        cout << "************************************************ " << endl;
        cout << "*     BASE     * ANCIENT LAKE  *  LAUNCH SITE  * " << endl;
        cout << "*              *               *               * " << endl;
        cout << "*              *               *               * " << endl;
        cout << "************************************************ " << endl;
        cout << "*  SCRAP HEAP  *     FARM      * " << endl;
        cout << "*              *               * " << endl;
        cout << "* You Are Here *               * " << endl;
        cout << "******************************** " << endl;
    }
    
    else if (location->getSpaceName() == "FARM")
    {
        cout << "******************************** " << endl;
        cout << "*     MINE     *  CRASH SITE   * " << endl;
        cout << "*              *               * " << endl;
        cout << "*              *               * " << endl;
        cout << "************************************************ " << endl;
        cout << "*     BASE     * ANCIENT LAKE  *  LAUNCH SITE  * " << endl;
        cout << "*              *               *               * " << endl;
        cout << "*              *               *               * " << endl;
        cout << "************************************************ " << endl;
        cout << "*  SCRAP HEAP  *     FARM      * " << endl;
        cout << "*              *               * " << endl;
        cout << "*              * You Are Here  * " << endl;
        cout << "******************************** " << endl;
    }
    
    else if (location->getSpaceName() == "ANCIENT LAKE")
    {
        cout << "******************************** " << endl;
        cout << "*     MINE     *  CRASH SITE   * " << endl;
        cout << "*              *               * " << endl;
        cout << "*              *               * " << endl;
        cout << "************************************************ " << endl;
        cout << "*     BASE     * ANCIENT LAKE  *  LAUNCH SITE  * " << endl;
        cout << "*              *               *               * " << endl;
        cout << "*              *  You Are Here *               * " << endl;
        cout << "************************************************ " << endl;
        cout << "*  SCRAP HEAP  *     FARM      * " << endl;
        cout << "*              *               * " << endl;
        cout << "*              *               * " << endl;
        cout << "******************************** " << endl;
    }
    
    else if (location->getSpaceName() == "CRASH SITE")
    {
        cout << "******************************** " << endl;
        cout << "*     MINE     *  CRASH SITE   * " << endl;
        cout << "*              *               * " << endl;
        cout << "*              *  You Are Here * " << endl;
        cout << "************************************************ " << endl;
        cout << "*     BASE     * ANCIENT LAKE  *  LAUNCH SITE  * " << endl;
        cout << "*              *               *               * " << endl;
        cout << "*              *               *               * " << endl;
        cout << "************************************************ " << endl;
        cout << "*  SCRAP HEAP  *     FARM      * " << endl;
        cout << "*              *               * " << endl;
        cout << "*              *               * " << endl;
        cout << "******************************** " << endl;
    }
    
    else if (location->getSpaceName() == "LAUNCH SITE")
    {
        cout << "******************************** " << endl;
        cout << "*     MINE     *  CRASH SITE   * " << endl;
        cout << "*              *               * " << endl;
        cout << "*              *               * " << endl;
        cout << "************************************************ " << endl;
        cout << "*     BASE     * ANCIENT LAKE  *  LAUNCH SITE  * " << endl;
        cout << "*              *               *               * " << endl;
        cout << "*              *               *  You Are Here * " << endl;
        cout << "************************************************ " << endl;
        cout << "*  SCRAP HEAP  *     FARM      * " << endl;
        cout << "*              *               * " << endl;
        cout << "*              *               * " << endl;
        cout << "******************************** " << endl;
    }

}

/*************************************************************************
                                validInt()
 validInt() takes a string and a minimum and maxiumn parameter to check
 if the user input is an integer and whether it is between the minimum and
 maximum specified value.
 **************************************************************************/
int Astronaut::validInt(string input, int min, int max)
{
    bool checker = false;
    int isNotInt = 0;
    int goodNum = 0;
    
    char isEnter = input[0];
    
    while (checker == false)
    {
        for (int i = 0; i < input.length(); i++)
        {
            if (!isdigit(input[i]))
            {
                isNotInt = 1;
            }
        }
        
        if (isEnter == '\0')
        {
            isNotInt = 0;
            cout << "Please enter valid integer" << endl;;
            cin.clear();
            getline(cin, input);
            cout << endl;
            isEnter = input[0];
        }
        else if (isNotInt == 0 && stoi(input) >= min && stoi(input) <= max)
        {
            goodNum = stoi(input);
            checker = true;
        }
        else
        {
            isNotInt = 0;
            cout << "Please enter valid integer" << endl;;
            cin.clear();
            getline(cin, input);
            cout << endl;
        }
    }
    return goodNum;
}
