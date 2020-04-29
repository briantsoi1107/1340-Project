#include "Action.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void Action::printstatus() {
    cout << name << endl
        << "HP: " << hp << endl
        << "Attack: " << atk << endl
        << "Defense: " << def << endl
        << endl;
}

void Action::attack(int& enemyhp,int enemydef) {

    int hit = rand() % 10 + 1;
    if (hit > 1) {
        enemyhp -= (atk - enemydef);
		cout << "Hit!" << endl;
    }
    else {
		cout << "Missed!"<<endl;
    }
}

void Action::gotitem() {
	int getitem = rand() % 7;
	cout << "you have collected a " << itemslist[getitem] << " from enemies!" << endl;
	itemsgot.push_back(getitem);
}


void Action::items(int& enemyhp) {
	if (itemsgot.size() == 0) {
		cout << "You have no item!" << endl;
		return;
	}
	int i = 1;
	cout << "Your items: \n(enter '0' to return)\nChoice: " << endl;
	for (auto it = itemsgot.begin(); it != itemsgot.end(); ++it) {
		cout << i << ". " << itemslist[*it] << endl;
		++i;
	}
	cin >> i;
	if (i == 0)
		return;
	switch (itemsgot.at(i - 1)) {
	case 0:
		cout << "Dealt 10 damage to the enemy!" << endl;
		enemyhp -= 10;
		break;
	case 1:
		cout << "Dealt 5 damage to the enemy!" << endl;
		enemyhp -= 5;
		break;
	case 2:
		cout << "You drank the poison! HP-10!";
		hp -= 10;
		break;
	case 3:
		cout << "Your HP has been recovered by 10." << endl;
		hp += 10;
		if (hp > 100) {
			hp = 100;
		}
	case 4:
		cout << "Your defense has increased by 10." << endl;;
		def += 10;
		break;
	case 5:
		cout << "Your attack power has increased by 10." << endl;
		atk += 10;
		break;
	}
	itemsgot.erase(itemsgot.begin() + i - 1);

}

void Action::defend(int enemyatk) {

	hp += def;
	cout << "Blocked!" << endl;
}

