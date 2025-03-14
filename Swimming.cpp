#include <iostream>
#include "include\Swimming.h"
#include <ctime>
#include <cstdlib>
#include <windows.h>

using namespace std;

void PrintSwimmingGameIntroduction(){
    cout << "Welcome To Swimming Competition" << endl;
    cout << "choose your lane (1-10) " << endl;
    cout << "First To Finish Wins" << endl;
}

Character::Character(bool choosen_player){
    ChoosenPlayer = choosen_player;
    Progression = 0;
}

int Character::RandomSwimDistance(){
    return rand() % 2;
}

void PrintSwimmingPoolAndPlayerProgress(Character &Player, Character Swimmers[], int PoolMeters, int playerLane){
    for(int i = 0; i < 10; i++){
        cout << "********************" << endl;
        for(int j = 0; j < PoolMeters; j++){
            if(i + 1 == playerLane && j == Player.Progression){
                cout << "0";
            } else if (i + 1 != playerLane && j == Swimmers[i].Progression){
            cout << "X";
            }else{
                cout << " ";
            }
        }
        cout << "|" << endl;
    }
            cout << "********************" << endl;
}
