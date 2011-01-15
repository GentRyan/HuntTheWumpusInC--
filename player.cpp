#include "player.h"

using namespace std;
Player_Character::Player_Character( )
{
  Wumpus_Lair maze;
  quiver = 5;
  location = maze.startLocation();
  srand( time( NULL ) );
}

void Player_Character::Move( int newLocation )
{
  location = newLocation;

  if ( maze.wumpusLocationCheck( location ) ) Lose(1);

  if ( maze.pitLocationCheck( location ) ) Lose(2);

  if ( maze.batLocationCheck( location ) )
    {
        cout << "*flap*  *flap*  *flap*  (humongous bats pick you up and move you!)" << endl;
        srand( time( NULL ) );
        Move ( (rand() % 20 + 1) );
    }
}

void Player_Character::Shoot(int target)
{
  quiver--;
  /*cout << "Enter up to 5 rooms for the arrow to shoot through. The arrow must have a path to follow. 0 means end of input." << endl;
  int targetChoice = 1;
  int targetCounter = 0;
  int targetPath[5] = { 0 };
  int temporaryRoom[3] = { 0 };
  bool possiblePath = false;
  while (targetChoice != 0 &&  targetCounter != 6)
  {
        targetCounter++;
        cin >> targetChoice;
        targetPath[targetCounter] = targetChoice;
  }
  int temporaryHolder;
  int pathCheckerCounter = 0;
  for (; pathCheckerCounter < 5; pathCheckerCounter++)
  {
        possiblePath = false;
        temporaryHolder = targetPath[pathCheckerCounter];
        temporaryRoom[3] = maze.lairMap[temporaryHolder][3];
        for (int j = 0; j < 4; j++)
            {
            temporaryHolder = targetPath[(pathCheckerCounter + 1)];
            if (temporaryRoom[j] == temporaryHolder) {possiblePath = true;}
            }
  }
    for(int i; i < 6; i++)
    {
      cout << targetPath[i] << " " << endl;
    }

  if (possiblePath)
  {
      for(int i; i < 6; i++)
      {
        if ( maze.wumpusLocationCheck(targetPath[i]) ) Lose(1);
      }
  }
  else
  {
      cout << "Invalid path! The arrow falls useless on the ground." << endl;
  }
    */
  if ( maze.wumpusLocationCheck(target) ) Win();
  if (quiver == 0) Lose(3);
}

void Player_Character::Lose(int loseCondition)
{
    switch (loseCondition)
    {
        case 1:
            std::cout << "*ROAR* *chomp* *snurfle* *chomp*!" << endl;
            std::cout << "Much to the delight of the Wumpus, you walked right into his mouth," << endl;
            std::cout << "making you one of the easiest dinners he's ever had!  For you, however" << endl;
            std::cout << "it's a rather unpleasant death.  The only good thing is that it's been" << endl;
            std::cout << "so long since the evil Wumpus cleaned his teeth that you immediately" << endl;
            std::cout << "passed out from the stench!" << endl;
            exit(EXIT_SUCCESS); //TODO, change this to Care to play another game? (y-n) function
            break;
        case 2:
            std::cout << "*AAAUUUUGGGGGHHHHHhhhhhhhhhh...*" << endl;
            std::cout << "The whistling sound and updraft as you walked into this room of the" << endl;
            std::cout << "cave apparently wasn't enough to clue you in to the presence of the" << endl;
            std::cout << "bottomless pit.  You have a lot of time to reflect on this error as" << endl;
            std::cout << "you fall many miles to the core of the earth.  Look on the bright side;" << endl;
            std::cout << "you can at least find out if Jules Verne was right..." << endl;
            exit(EXIT_SUCCESS);
            break;
        case 3:
            std::cout << "You turn and look at your quiver, and realize with a sinking feeling" << endl;
            std::cout << "that you've just shot your last arrow (figuratively, too).  Sensing this" << endl;
            std::cout << "with its psychic powers, the evil Wumpus rampagees through the cave, finds" << endl;
            std::cout << "you, and with a mighty *ROAR* eats you alive!" << endl;
            exit(EXIT_SUCCESS);
            break;
    }
}
void Player_Character::playerStatus()
{
    maze.displayDetails(location, quiver);
}

bool Player_Character::validRoom(int playerNewRoom)
{
    bool result = false;
    for (int i=0; i < 3; i++)
    {
        if (maze.lairMap[location][i] == playerNewRoom) {result = true;}
    }
    return result;
}

void Player_Character::Win()
{
    cout << "You have slain the Wumpus! A winner is you!" << endl;
    exit(EXIT_SUCCESS);
}
