#include <iostream>
#include "include\Swimming.h"
#include <ctime>
#include <cstdlib>
#include <windows.h>

using namespace std;

int main()
{
    srand(time(0));
    int playerLane;
    PrintSwimmingGameIntroduction();
do{
    while(true){
        cout << " Choose player number from (1-10): ";
        cin >> playerLane;

        if(cin.fail() || playerLane < 1 || playerLane > 10){
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid Number Please Try Again" << endl;
        }else{
            break;
        }
    }


    Character Player(true);

    Character Swimmers[10] = {false, false, false, false, false, false, false, false, false, false};

    int PoolMeters = 20;

    bool gameOver = false;

    while(!gameOver){
        system("cls");

        PrintSwimmingPoolAndPlayerProgress(Player, Swimmers, PoolMeters, playerLane);

        Player.Progression += Player.RandomSwimDistance();
        if(Player.Progression >= PoolMeters){
            Player.Progression = PoolMeters - 1;
            cout << "Player 0 Wins " << endl;
            gameOver = true;
        }

        for(int i = 0; i < 10; i++){
            Swimmers[i].Progression += Swimmers[i].RandomSwimDistance();
            if(Swimmers[i].Progression >= PoolMeters){
                Swimmers[i].Progression = PoolMeters - 1;
                cout << "Swimmers X in lane " << i + 1 << " Wins" << endl;
                gameOver = true;
            }
        }

        Sleep(200);
    }
    char restart;
    while (true) {
        cout << "Do You Want To Play Again? (y/n): ";
        cin >> restart;

        if (restart == 'n' || restart == 'N') {
            cout << "Thanks for playing! Goodbye!" << endl;
            return 0; // Exit the program
        } else if (restart == 'y' || restart == 'Y') {
            system("cls");
            break; // Restart the game
        } else {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid Input." << endl;
        }
    }
} while (true);
    return 0;
}
