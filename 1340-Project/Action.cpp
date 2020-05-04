#include "Action.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

//print the status of player
void Action::printstatus(int stage) {
    cout << name << endl
        << "HP: " << hp <<"/"<<maxhp[stage]<<endl
        << "Attack: " << atk[stage] << endl
        << "Defense: " << def[stage] << endl
        << endl;
}

//deal damage to the enemy
void Action::attack(int& enemyhp,int enemydef, int stage) {
	srand(time(0));
    int hit = rand() % 10 + 1;
    if (hit <9) {
        if ((atk[stage] - enemydef)>=0){    
            enemyhp -= (atk[stage] - enemydef);
		    cout << "Hit!" << endl;
        }
        else{
            enemyhp=enemyhp;
        }
    }
    else {
		cout << "Missed!"<<endl;
    }
}

//randomly get items from the item list
void Action::gotitem() {
	srand(time(0));
	int getitem = rand() % 6;
	cout << "you have collected a " << itemslist[getitem] << "!" << endl;
	itemsgot.push_back(getitem);
}

//choose items from the list and use
void Action::items(int& enemyhp, int stage) {
	if (itemsgot.size() == 0) {
		cout << "You have no item!" << endl;
		return;
	}
	int i = 1;
	cout << "Your items: \n(enter '0' to return)\n";
	for (auto it = itemsgot.begin(); it != itemsgot.end(); ++it) { //use of iterators
		cout << i << ". " << itemslist[*it] << endl;
		++i;
	}
	cout << "Choice: ";
	cin >> i;
	if (i == 0)
		return;
	system("clear");
	switch (itemsgot.at(i - 1)) {
	case 0:
		cout << "Dealt "<<atk[stage]+10<<" damage to the enemy!" << endl;
		enemyhp -= atk[stage] + 10;
		break;
	case 1:
		cout << "Dealt "<< atk[stage] + 30<<" damage to the enemy!" << endl;
		enemyhp -= atk[stage] + 30;
		break;
	case 2:
		cout << "You drank the poison! HP-10!";
		hp -= 10;
		break;
	case 3:
		cout << "Your HP has been recovered by 50." << endl;
		hp += 50;
		if (hp > maxhp[stage]) {
			hp = maxhp[stage];
		}
		break;
	case 4:
		cout << "Your defense has increased by 30." << endl;;
		def[stage] += 30;
		break;
	case 5:
		cout << "Your attack power has increased by 20." << endl;
		atk[stage] += 20;
		break;
	}
	itemsgot.erase(itemsgot.begin() + i - 1);

}

//reduce damage taken for the next round
void Action::guard(int enemyatk, int stage) {
	hp += def[stage];
	cout << "Blocked!" << endl;
}

