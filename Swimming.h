#ifndef SWIMMING_H
#define SWIMMING_H

using namespace std;

class Character{
public:
    bool ChoosenPlayer;
    int Progression;
    Character(bool choosen_player);
    int RandomSwimDistance();
};

void PrintSwimmingPoolAndPlayerProgress(Character &Player, Character Swimmers[], int PoolMeters, int playerLane);

void PrintSwimmingGameIntroduction();
#endif
