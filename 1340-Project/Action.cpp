#include "Action.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void Action::printstatus(int stage) {
    cout << name << endl
        << "HP: " << hp <<"/"<<maxhp[stage]<<endl
        << "Attack: " << atk[stage] << endl
        << "Defense: " << def[stage] << endl
        << endl;
}

void Action::attack(int& enemyhp,int enemydef, int stage) {
	srand(time(0));
    int hit = rand() % 10 + 1;
    if (hit > 1) {
        enemyhp -= (atk[stage] - enemydef);
		cout << "Hit!" << endl;
    }
    else {
		cout << "Missed!"<<endl;
    }
}

void Action::gotitem() {
	srand(time(0));
	int getitem = rand() % 6;
	cout << "you have collected a " << itemslist[getitem] << "!" << endl;
	itemsgot.push_back(getitem);
}


void Action::items(int& enemyhp, int stage) {
	if (itemsgot.size() == 0) {
		cout << "You have no item!" << endl;
		return;
	}
	int i = 1;
	cout << "Your items: \n(enter '0' to return)\n";
	for (auto it = itemsgot.begin(); it != itemsgot.end(); ++it) {
		cout << i << ". " << itemslist[*it] << endl;
		++i;
	}
	cout << "Choice: ";
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
		cout << "Your HP has been recovered by 15." << endl;
		hp += 15;
		if (hp > maxhp[stage]) {
			hp = maxhp[stage];
		}
		break;
	case 4:
		cout << "Your defense has increased by 10." << endl;;
		def[stage] += 10;
		break;
	case 5:
		cout << "Your attack power has increased by 10." << endl;
		atk[stage] += 10;
		break;
	}
	itemsgot.erase(itemsgot.begin() + i - 1);

}

void Action::guard(int enemyatk, int stage) {
	hp += def[stage];
	cout << "Blocked!" << endl;
}

