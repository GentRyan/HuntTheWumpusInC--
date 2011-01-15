#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "wumpus_lair.h"
using namespace std;

class Player_Character
{

private:
    int quiver;
    int location;
    Wumpus_Lair maze;

public:
    void Move(int newLocation);
    void Shoot(int);
    Player_Character();
    void Win();
    void Lose(int loseCondition);
    void playerStatus();
    bool validRoom(int playerNewRoom);
};


#endif // PLAYER_H_INCLUDED
