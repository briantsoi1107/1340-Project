#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <windows.h>
#include "Action.h"
using namespace std;


void battle(Action& a, int& enemyhp, int enemyatk, int enemydef, string enemyname) {
    int choice;
    while (not(enemyhp <= 0 || a.hp <= 0)) {
        Sleep(2000);
        system("CLS");
        a.printstatus();
        cout << enemyname << "'s HP: " << enemyhp << endl;
        do{ 
            cout << "Your turn:\n1. Attack\n2. Items\n3. Defend\nChoice: ";
            cin >> choice;
        } while (choice != 1 && choice!= 2 && choice!= 3);
        system("CLS");
        switch (choice) {
        case 1:
            a.attack(enemyhp, enemydef);
            break;
        case 2:
            a.items(enemyhp);
            break;
        case 3:
            a.defend(enemyatk);
            break;       
        }
        Sleep(2000);
        system("CLS");
        cout << enemyname << "'s turn:"<<endl;
        cout << "You are hit!" << endl;
        a.hp -= enemyatk - a.def;

    }
    if (enemyhp <= 0) {
        cout << "Congratulations! You win!"<<endl;
        a.gotitem();
        return;
    }
    else if(a.hp<=0){
        do {
            cout << "You lose..." << endl
                << "1. Try Again" << endl
                << "2. Save and Exit" << endl;
            cin >> choice;
        } while (choice != 1 && 2);
            switch (choice) {
            case 1:
                return battle(a, enemyhp, enemyatk, enemydef, enemyname);
                break;
            case 2:
                //save game
                exit(0);
                break;
            }
        }
 
}

int main()
{
    Action player;
    int stage = 1, choice;
    srand(time(0));
    cout << "Enter your name: ";
    cin >> player.name;
    system("CLS");
    cout << "In an ancient Japanese village.\nYou has given a mission to assassinate the infamous emperor of the country.\nYou has reached the enemies' base - the 'Himeji Castle'.\nYou have to fight with the enemies you meet on the way to the emperor’s location…\n" << endl;
    cout << "1. New Game\n2. Continue\nChoice: ";
    do {
        cin >> choice;
    } while (choice != 1 && choice != 2);
    if (choice == 1) {
        system("CLS");
        cout << "Stage " << stage << endl;
        int enemyhp = 60, enemyatk = 15, enemydef = 5;
        string enemyname = "Soilder";
        battle(player, enemyhp, enemyatk, enemydef, enemyname);
        stage++;
    }
    return 0;
    
}


