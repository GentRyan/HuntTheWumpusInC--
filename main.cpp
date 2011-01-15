#include "main.h"
using namespace std;

int main()
{
    cout << "Hunt the Wumpus!" << endl;
    Player_Character hunter;
    char playerChoice = ' ';
    int playerNewRoom = 0;
    int newTarget = 0;
    //int a;
    while (true)
    {

        hunter.playerStatus();
        cout << "Move or shoot? (m-s) ";
        //playerChoice = getchar();
        cin >> playerChoice;
        if (playerChoice == 'm')
        {
            cin >> playerNewRoom;
            if (hunter.validRoom(playerNewRoom)) {hunter.Move(playerNewRoom);}
            else {cout << "There's no tunnel to that room!";}

        }
        if (playerChoice == 's')
        {
            cin >> newTarget;
            hunter.Shoot(newTarget);
        }

    }
}
