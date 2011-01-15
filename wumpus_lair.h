#ifndef WUMPUS_LAIR_H_INCLUDED
#define WUMPUS_LAIR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;
class Wumpus_Lair
{
    private:
        int pit1;
        int pit2;
        int bat1;
        int bat2;
        int wumpus;
    public:
        bool wumpusLocationCheck(int location);
        bool pitLocationCheck(int playerLocation);
        bool batLocationCheck(int playerLocation);
        void displayDetails(int,int);
        int lairMap[20][3];
        int startLocation();
        Wumpus_Lair();

};

#endif // WUMPUS_LAIR_H_INCLUDED
