#include <iostream>
#include "Action.h"
using namespace std;
void printstatus() {
    cout << name << endl
        << "HP: " << hp << endl
        << "Attack: " << atk << endl
        << "Defense: " << def << endl
        << endl << enemy << endl
        << "HP: " << enemyhp;
  
}

int main()
{
    Action player;
    int choice,stage=0;
    temphp;

    player.attack();
    cout << player.enemyhp;
    string name;
    cout << "*********************************************************************
In an ancient Japanese village. You has given a mission to assassinate the infamous emperor of the country. You has reached the enemies' base - 'the Himeji Castle'. You have to fight with the enemies you meet on the way to the emperor’s location…
carefully decide which action to take at different stages.
*********************************************************************
XXXXX THINK CAREFULLY BEFORE TAKING ACTIONS XXXXX" << endl;

    cout << "Enter your name: ";
    cin >> name;
    cout << "Stage " << stage << endl;
    printstatus();
    temphp=hp;
    while ( not(hp<=0 || enemyhp <=0)){
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
     }
    if (hp<=0){
        cout << "You lose..." ;
        hp= temphp;
    }
    else if (enemyhp <=0){
        cout << "Congratulations! You win.";
        stage++;
    }
    return 0;    
}
