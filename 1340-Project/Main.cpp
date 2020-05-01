#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
#include "Action.h"
using namespace std;


void battle(Action& a, int enemyhp, int enemyatk, int enemydef, string enemyname, int stage) {
    int choice;
    int maxenemyhp = enemyhp;
    while (not(enemyhp <= 0 || a.hp <= 0)) {
        Sleep(2000);
        system("CLS");
        a.printstatus(stage);
        cout << enemyname << "'s HP: " << enemyhp << endl;
        do{
            cout << "Your turn:\n1. Attack\n2. Items\n3. Guard\nChoice: ";
            cin >> choice;
        } while (choice != 1 && choice!= 2 && choice!= 3);
        system("CLS");
        switch (choice) {
        case 1:
            a.attack(enemyhp, enemydef,stage);
            break;
        case 2:
            a.items(enemyhp,stage);
            break;
        case 3:
            a.guard(enemyatk,stage);
            break;       
        }
        Sleep(2000);
        system("CLS");
        cout << enemyname << "'s turn:"<<endl;
        cout << "You are hit!" << endl;
        a.hp -= enemyatk - a.def[stage];
    }
    if (enemyhp <= 0) {
        Sleep(2000);
        system("CLS");
        cout << "You win!"<<endl;
        Sleep(2000);
        system("CLS");
        a.gotitem();
        Sleep(2000);
        system("CLS");
        cout << "HP recovered by 50!\n";
        a.hp += 50;
        if (a.hp > a.maxhp[stage+1]) {
            a.hp = a.maxhp[stage+1];
        }
        ofstream fout;
        fout.open("save.txt");
        fout << a.name << " " << a.hp << " " << stage + 1<<" ";
        for (auto it = a.itemsgot.begin(); it != a.itemsgot.end(); ++it) {
            fout << *it << " ";
        }
        fout.close();
        return;
    }
    else if(a.hp<=0){
        do {
            Sleep(2000);
            system("CLS");
            cout << "Game Over..." << endl
                << "1. Try Again" << endl
                << "2. Save and Exit" << endl
                <<"Choice: ";
            cin >> choice;
        } while (choice != 1 && choice!= 2);
            switch (choice) {
            case 1:
                system("CLS");
                cout << "Loading...\n";
;               a.hp = a.maxhp[stage];
                enemyhp = maxenemyhp;
                battle(a, enemyhp, enemyatk, enemydef, enemyname, stage);
                break;
            case 2:
                ofstream fout;
                fout.open("save.txt");
                fout << a.name << " " << a.hp << " "<< stage;
                for (auto it = a.itemsgot.begin(); it != a.itemsgot.end(); ++it) {
                    fout << *it << " ";
                }
                fout.close();
                exit(0);
                break;
            }
        }
 
}

int main()
{
    Action player;
    int choice;
    int enemyhp[4] = { 60,120,200,300 }, enemyatk[4] = { 10,30,60,80 }, enemydef[4] = { 5,10,15,20 };
    string enemyname[4] = { "Bandit","Daimyo","Shogun","Emperor" };
    cout << "1340 Project\nA Text-based RPG.\n";
    Sleep(3000);
    system("CLS");
    cout << "1. New Game\n2. Continue\nChoice: ";
    do {
        cin >> choice;
    } while (choice != 1 && choice != 2);
    system("CLS");
    if (choice == 1) {
        cout << "Enter your name: ";
        cin >> player.name;
        system("CLS");
        cout << player.name << ", you are a ninja assassin.\n";
        Sleep(2500);
        cout << "You had given a mission to assassinate the infamous emperor of the country.\n";
        Sleep(3000);
        cout << "You have now reached outside the enemies' base - the 'Himeji Castle'.\n";
        Sleep(3000);
        cout << "You have to fight the enemies along way to the emperor’s location...\n";
        Sleep(4000);
        system("CLS");
        for (int stage = 0; stage < 4; stage++) {
            cout << "Stage " << stage + 1 << endl
                << "Enemy: " << enemyname[stage] << endl;
            battle(player, enemyhp[stage], enemyatk[stage], enemydef[stage], enemyname[stage], stage);
            Sleep(2000);
            system("CLS");
        }
        cout << "Congratulations!\nYou have beat the game!\nThanks for playing!" << endl;
    }
    else if (choice == 2) {
        ifstream fin;
        int Stage, items;
        fin.open("save.txt");
        fin >> player.name>> player.hp >> Stage;
        while (true) {
            fin >> items;
            player.itemsgot.push_back(items);
            if (fin.eof())
                break;
        }
        fin.close();
        cout << "Welcome back! " << player.name<<endl;
        Sleep(2000);
        system("CLS");
        for (int stage = Stage; stage < 4; stage++) {
            cout << "Stage " << stage + 1 << endl
                << "Enemy: " << enemyname[stage] << endl;
            battle(player, enemyhp[stage], enemyatk[stage], enemydef[stage], enemyname[stage], stage);
            Sleep(2000);
            system("CLS");
        }
        cout << "Congratulations!\nYou have beat the game!\nThanks for playing!" << endl;

    }
 

    return 0;
    
}


