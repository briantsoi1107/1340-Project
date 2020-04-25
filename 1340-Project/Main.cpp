#include <iostream>
#include "Action.h"
using namespace std;
void printstatus() {
    cout << name << endl
        << "HP: " << hp << endl
        << "MP: " << mp << endl
        << "Attack: " << atk << endl
        << "Defense: " << def << endl
        << endl << enemy << endl
        << "HP: " << enemyhp;
  
}

int main()
{
    Action player;
    int choice;
    player.attack();
    cout << player.enemyhp;
    string name;
    cout << "Enter your name: ";
    cin >> name;
    cout >> 'Stage 1';
    printstatus();
    cout << "1. Attack\n2. Ability\n3.Items\n4. Defense";
    switch (choice) {
    case 1:
        player.attack();
        case 2;
            player.ability();
            break;
        case 3:
            player.items();
            break;
        case 4:
            player.defense();
            break;
    }
    return 0;
    
}


