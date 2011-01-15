#include "wumpus_lair.h"

Wumpus_Lair::Wumpus_Lair()
{
    lairMap =
        {
            {1,4,7},
            {0,2,9},
            {1,3,11},
            {2,4,13},
            {0,3,5},
            {4,6,14},
            {5,7,16},
            {0,6,8},
            {7,9,17},
            {1,8,10},
            {9,11,18},
            {2,10,12},
            {11,13,19},
            {3,12,14},
            {5,13,15},
            {14,16,19},
            {6,15,17},
            {8,16,18},
            {10,17,19},
            {12,15,18}
        };
    srand( time( NULL ) );
    bat1 = (rand() % 20 + 1);
    bat2 = (rand() % 20 + 1);
    while (bat2==bat1) {bat2 = (rand() % 20 + 1);}
    pit1 = (rand() % 20 + 1);
    while (pit1==bat1 || pit1 == bat2) {pit1 = (rand() % 20 + 1);}
    pit2 = (rand() % 20 + 1);
    while (pit2==bat1 || pit2 == bat2 || pit2 == pit1) {pit2 = (rand() % 20 + 1);}
    wumpus = (rand() % 20 + 1);
    while (wumpus == bat1 || wumpus == bat2 || wumpus == pit1 || wumpus == pit2) {wumpus = (rand() % 20 + 1);}
}

int Wumpus_Lair::startLocation()
{
    int playerLocation = (rand() % 20 + 1);
    while (playerLocation == bat1 || playerLocation == bat2 || playerLocation == pit1 || playerLocation == pit2 || playerLocation == wumpus || playerLocation == 20) {playerLocation = (rand() % 20 + 1);}
    return playerLocation;
}

void Wumpus_Lair::displayDetails(int playerLocation, int playerQuiver)
{
    int wumpusWarning, batWarning, pitWarning;
    cout << endl << "You are in room " << playerLocation << " of the cave, and have " << playerQuiver << " arrows left." << endl;
    for (int i=0; i < 3; i++)
    {
        if (lairMap[playerLocation][i] == wumpus) {wumpusWarning = 1;}

        for (int j=0; j < 3; j++)
            {
                if (lairMap[i][j] == wumpus) {wumpusWarning = 1;}
            }
    }

    for (int i=0; i < 3; i++)
    {
        if (lairMap[playerLocation][i] == pit1 || lairMap[playerLocation][i] == pit2) {pitWarning = 1;}

        for (int j=0; j < 3; j++)
            {
                if (lairMap[i][j] == pit1 || lairMap[i][j] == pit2) {pitWarning = 1;}
            }
    }

    for (int i=0; i < 3; i++)
    {
        if (lairMap[playerLocation][i] == bat1 || lairMap[playerLocation][i] == bat2) {batWarning = 1;}

        for (int j=0; j < 3; j++)
            {
                if (lairMap[i][j] == bat2 || lairMap[i][j] == bat2) {batWarning = 1;}
            }
    }
    if (wumpusWarning == 1) {cout << "*sniff* (I can smell the evil Wumpus nearby!)" << endl;}
    if (batWarning == 1) {cout << "*rustle* *rustle* (must be bats nearby)" << endl;}
    if (pitWarning == 1) {cout << "*whoosh* (I feel a draft from some pits)." << endl;}

    //cout << "DEBUG: Wumpus at " << wumpus << endl;
    cout << "There are tunnels to rooms " << lairMap[playerLocation][0] << "," << lairMap[playerLocation][1] << ", and " << lairMap[playerLocation][2] << "." << endl;
}


bool Wumpus_Lair::wumpusLocationCheck(int location)
{
    if (location == wumpus) {return true;}
    return false;
}
bool Wumpus_Lair::pitLocationCheck(int playerLocation)
{
    if (playerLocation == pit1 || playerLocation == pit2) {return true;}
    return false;
}
bool Wumpus_Lair::batLocationCheck(int playerLocation)
{
    if (playerLocation == bat1 || playerLocation == bat2) {return true;}
    return false;
}
