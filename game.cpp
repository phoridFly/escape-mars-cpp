/******************************************************************
 John Hash
 Final Project "Mars Escape"
 CS 162 Fall 2018
 Dec 4, 2018
 game.cpp
 This is the implementation file for the Game class. It is the file
 that controls the flow of the game. It contains the main menu
 function, setup function, and run game function that contains the
 main game do while loop. It also contains a validate integer
 function.
 *****************************************************************/

#include "game.hpp"
#include "space.hpp"
#include "base.hpp"
#include "mine.hpp"
#include "scrap_heap.hpp"
#include "farm.hpp"
#include "ancient_lake.hpp"
#include "crash_site.hpp"
#include "launch.hpp"
#include "astronaut.hpp"

/*************************************************************************
                            menu()
 menu() introduces the player to the game and allows them to continue to
 the game or exit.
 **************************************************************************/
void Game::menu()
{
    string choice;
    int goodChoice;
    
    // do while loop lets player keep playing without exiting
    do
    {
        
        cout << endl;
        
        cout << "   ******  *****    *****       **       *****  ******             " << endl;
        cout << "   *      *        *           *  *      *    * *         " << endl;
        cout << "   *      *       *           *    *     *    * *      " << endl;
        cout << "   ******  ***    *          ********    *****  ******        " << endl;
        cout << "   *           *  *         *        *   *      *       " << endl;
        cout << "   *           *   *       *          *  *      *       " << endl;
        cout << "   ****** *****     ***** *            * *      ******         " << endl;
        cout << "\n";
        cout << "   *      *        **       *****     *****           " << endl;
        cout << "   * *   **       *  *      *    *   *        " << endl;
        cout << "   *  * * *      *    *     *    *   *        " << endl;
        cout << "   *   *  *     ********    ******     ***      " << endl;
        cout << "   *      *    *        *   *     *        *   " << endl;
        cout << "   *      *   *          *  *      *       *   " << endl;
        cout << "   *      *  *            * *       * *****       " << endl;
        cout << "\n";

        cout << " _____________________________________________________________" << endl;
        
        cout << "\n";
        
        // all the information about the game for the player to know
        cout << "Premise:" << endl;
        cout << "You are an astronaut who needs to leave Mars before " << endl;
        cout << "the next global dust storm. You will die if you fail " << endl;
        cout << "to make it to the rocket with enough food and fuel to " << endl;
        cout << "make the trip back to Earth." << endl;
        cout << "\n";
        cout << "Gameplay:" << endl;
        cout << "You have a base, a farm, a mine, a rocket on the lanchpad " << endl;
        cout << "and three additional locations. Two of these contain canisters " << endl;
        cout << "(one food and one fuel) that you'll need to fill with food and " << endl;
        cout << "fuel to leave. Explore the map, find the cansisters, acquire the " << endl;
        cout << "resources, and reach the rocket. " << endl;
        cout << "\n";
        cout << "Rules: " << endl;
        cout << "Each move to a new location requires one day. Each attempt at mining " << endl;
        cout << "or farming requires one day. Mining and farming attempts may " << endl;
        cout << "result in success, failure, or injury. Each success results in " << endl;
        cout << "one gained resource unit. 10 units of food and 10 units of " << endl;
        cout << "fuel are needed before the rocket can launch. If injury occurs " << endl;
        cout << "you must go back to base to recover before resource gathering can " << endl;
        cout << "continue. " << endl;
        cout << "Difficulty level guidelines:" << endl;
        cout << "Easy, 100 days. Normal, 50 days. Very Hard, 35 days." << endl;
        cout << "\n";
        
        cout << "To start the game, enter 1." << endl;
        cout << "To quit, enter 2." << endl;
        cout << "Choice: ";
        getline(cin,choice);
        
        // checks that the choice is a positive int and 1 or 2
        goodChoice = validInt(choice, 1, 2);
        
        if (goodChoice == 1)
            gameSetup();
        
        if (goodChoice ==1)
        {
            cout << "Do you want to play again?" << endl;
            cout << "Make selection from below." << endl;
        }
        
    } while (goodChoice == 1);
    
    if (goodChoice ==1)
    {
        cout << "Do you want to play again?" << endl;
        cout << "Make selection from below." << endl;
    }
}

/*************************************************************************
                                gameSetup()
 Asks the player to set the difficulty level by specifying number of days.
 **************************************************************************/
void Game::gameSetup()
{
    cout << "How many days do you want to give yourself (29-100)?" << endl;
    cout << "(It is possible to beat the game with 29 days with no injuries)" << endl;
    string days;
    getline(cin, days);
    
    int goodDays = validInt(days, 29, 100);
    
    // calls runGame and passes the user specified days
    runGame(goodDays);
    
}

/*************************************************************************
                                    runGame()
 Contains main game loop. It creates the space objects and pointerss to them.
 All the spaces are linked together by their pointers.
 **************************************************************************/
void Game::runGame(int days)
{
    Base *base = new Base;
    Mine *mine = new Mine;
    Scrap_heap *scrap = new Scrap_heap;
    Farm *farm = new Farm;
    Ancient_lake *lake = new Ancient_lake;
    Crash_site *crash = new Crash_site;
    Launch *launch = new Launch;
    Astronaut *player = new Astronaut(base);
    
    // link the spaces together
    
    // mine
    mine->setUp(nullptr);
    mine->setDown(base);
    mine->setLeft(nullptr);
    mine->setRight(crash);
    
    // base
    base->setUp(mine);
    base->setDown(scrap);
    base->setLeft(nullptr);
    base->setRight(lake);
    
    // scrap pile
    scrap->setUp(base);
    scrap->setDown(nullptr);
    scrap->setLeft(nullptr);
    scrap->setRight(farm);
    
    // crash site
    crash->setUp(nullptr);
    crash->setDown(lake);
    crash->setLeft(mine);
    crash->setRight(nullptr);
    
    // ancient lake
    lake->setUp(crash);
    lake->setDown(farm);
    lake->setLeft(base);
    lake->setRight(launch);
    
    // farm
    farm->setUp(lake);
    farm->setDown(nullptr);
    farm->setLeft(scrap);
    farm->setRight(nullptr);
    
    // launch site
    launch->setUp(nullptr);
    launch->setDown(nullptr);
    launch->setLeft(lake);
    launch->setRight(nullptr);
    
    // main game loop until days run out
    
    int day = 0;
    do
    {
        // print out current day/sol
        cout << " _____________________________________________" << endl;
        cout << "          SOL " << day + 1 << "         " << endl;
        cout << " _____________________________________________" << endl;
        
        // simply displays the map
        player->showMap();
        
        // announcement for lake bed
        if (player->getLocation()->getSpaceName() == "ANCIENT LAKE")
        {
            lake->lakeMessage();
        }
        
        cout << "\n";
        
        if (player->getLocation()->getSpaceName() == "LAUNCH SITE" && farm->getFood() < 10
            && mine->getFuel() < 10)
        {
            launch->notYetMessage();
        }
        
        // one time announcement that you found the farm canister in Scrap Heap
        if (player->getLocation()->getSpaceName() == "SCRAP HEAP" && player->getLocation()->getTimesVisited() == 0)
        {
            scrap->canisterMessage();

        }
        
        // one time announcement that you found the fuel canister Crash site
        if (player->getLocation()->getSpaceName() == "CRASH SITE" && player->getLocation()->getTimesVisited() == 0)
        {
            crash->canisterMessage();
        }
        
        
        // movePlayer allows the player to move or mine or farm
        player->moveMenu(mine, farm);
        
        // announcement for healing an injury and restoring health
        if (player->getLocation()->getSpaceName() == "BASE" && player->getInjuredStatus() == true)
        {
            base->baseMessage();
            player->setInjuredStatus(false);
        }
        
        // summary for the day
        bool health = player->getInjuredStatus();
        cout << " _____________________________________________" << endl;
        
        cout << "              End of Sol Summary:                 " << endl;
        cout << " You have mined " << mine->getFuel() << "/10 fuel." << endl;
        cout << " You have farmed " << farm->getFood() << "/10 food." << endl;
        
        // display health status
        if (health == false)
            cout << " You are not injured." << endl;
        
        if (health == true)
        {
            cout << " You are injured and need to visit the base before "<< endl;
            cout << "you can do anymore work." << endl;
        }
        cout << " _____________________________________________" << endl;
        
        
        // winning scenario, on launch site, at least 10 food and 10 fuel
        if (player->getLocation()->getSpaceName() == "LAUNCH SITE" && farm->getFood() >= 10
            && mine->getFuel() >= 10)
        {
            launch->launchMessage();
            day = 101;
        }
        
        day++;
    }
    while (day < days);
    
    // losing message after days run out and not enough food an fuel procured
    if (day == days)
    {
        cout << "\n";
        cout << " _____________________________________________" << endl;
        cout << "You failed to escape before the global dust storm." << endl;
        cout << "Try again the game again, and select more days." << endl;
        cout << "\n";
        cout << " _____________________________________________" << endl;
        cout << "\n";

    }
    
    // free up allocated memory
    delete player;
    delete base;
    delete crash;
    delete farm;
    delete launch;
    delete lake;
    delete mine;
    delete scrap;
    
}

/*************************************************************************
                            validInt()
 validInt() takes a string and a minimum and maxiumn parameter to check
 if the user input is an integer and whether it is between the minimum and
 maximum specified value.
 **************************************************************************/
int Game::validInt(string input, int min, int max)
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
