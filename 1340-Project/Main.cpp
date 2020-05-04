#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>
#include "Action.h"
using namespace std;

//battle
void battle(Action& a, int enemyhp, int enemyatk, int enemydef, string enemyname, int stage) { //variables passed by reference
    int choice;
    int maxenemyhp = enemyhp;
    int count = 0;
    while (not(enemyhp <= 0 || a.hp <= 0)) {
        sleep(2);
        system("clear");
        a.printstatus(stage);
        cout << enemyname << "'s HP: " << enemyhp << endl;
        do{
            cout << "Your turn:\n1. Attack\n2. Items\n3. Guard\nChoice: ";
            cin >> choice;
        } while (choice != 1 && choice!= 2 && choice!= 3);
        system("clear");
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
        if (enemyhp > 0 && count!=2) {
            sleep(2);
            system("clear");
            cout << enemyname << " has attacked you!\n";
            if((enemyatk - a.def[stage])>=0){
                a.hp -= enemyatk - a.def[stage];
            }
            else{
                a.hp = a.hp;
            }
        }

        if (stage > 2 && count % 2 == 0) {
            sleep(2);
            system("clear");
            cout << enemyname << " has healed!" << endl;
            enemyhp += 20;
        }
        if (stage > 1) {
            sleep(2);
            system("clear");
            cout << "Number of rounds before huge attack: " << 3 - (count+1)  << endl; //Increasing difficulty by limiting the number of rounds can be played by the player
            count++;
            if (count==3) {
                a.hp -= (60-a.def[stage]);
                sleep(2);
                system("clear");
                cout << enemyname << " has executed you.\n ";
                count=0;
            }
        }
    }
    //enemy dies
    if (enemyhp <= 0) {
        sleep(2);
        system("clear");
        cout << "You win!"<<endl;
        sleep(2);
        system("clear");
        a.gotitem();
        sleep(2);
        system("clear");
        if (stage<2){
            a.hp += 50;
            cout << "HP recovered by 50!\n";
            if (a.hp > a.maxhp[stage+1]) {
                a.hp = a.maxhp[stage+1];
            }
        }
        else if (stage>=2){
            a.hp += 100;
            cout << "HP recovered by 100!\n";
            if (a.hp > a.maxhp[stage+1]) {
                a.hp = a.maxhp[stage+1];
            }
        }
        //Save game status to a text file
        ofstream fout;
        fout.open("save.txt");
        fout << a.name << " " << a.hp << " " << stage + 1<<" ";
        for (auto it = a.itemsgot.begin(); it != a.itemsgot.end(); ++it) {
            fout << *it << " ";
        }
        fout.close();
        return;
    }
    //you dies
    else if(a.hp<=0){
            sleep(2);
            system("clear");
        do{
            cout << "Game Over..." << endl
                << "1. Try Again" << endl
                << "2. Save and Exit" << endl
                <<"Choice: ";
            cin >> choice;
        }while (choice != 1 && choice!= 2);
            switch (choice) {
            case 1:
                //replay the stage with hp recovered
                system("clear");
                cout << "Loading...\n";
                a.hp = a.maxhp[stage];
                enemyhp = maxenemyhp;
                battle(a, enemyhp, enemyatk, enemydef, enemyname, stage);
                break;
            case 2:
                //Save game status to a text file
                ofstream fout;
                fout.open("save.txt");
                fout << a.name << " " << a.maxhp[stage] << " "<< stage<<" ";
                for (auto it = a.itemsgot.begin(); it != a.itemsgot.end(); ++it) { //use of iterators
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
    int enemyhp[4] = { 60,120,200,300 }, enemyatk[4] = { 10,20,40,50 }, enemydef[4] = { 5,10,15,20 };
    string enemyname[4] = { "Bandit","Daimyo","Shogun","Emperor" };
    cout << "1340 Project\nA Text-based RPG.\n";
    //use of sleep and clear screen for better text outputting
    sleep(3);
    system("clear");
    //Main Menu
    cout << "1. New Game\n2. Continue\nChoice: ";
    do {
        cin >> choice;
    } while (choice != 1 && choice != 2);
    system("clear");
    if (choice == 1) {
        cout << "Enter your name: ";
        cin >> player.name;
        system("clear");
        cout << player.name << ", you are a ninja assassin.\n";
        sleep(2.5);
        cout << "You had given a mission to assassinate the infamous emperor of the country.\n";
        sleep(3);
        cout << "You have now reached outside the enemies' base - the 'Himeji Castle'.\n";
        sleep(3);
        cout << "You have to fight the enemies along the way to the emperor’s location...\n";
        sleep(4);
        system("clear");
        for (int stage = 0; stage < 4; stage++) {
            cout << "Stage " << stage + 1 << endl
                << "Enemy: " << enemyname[stage] << endl;
            battle(player, enemyhp[stage], enemyatk[stage], enemydef[stage], enemyname[stage], stage);
            sleep(2);
            system("clear");
        }
        cout << "Congratulations!\nYou have beat the game!\nThanks for playing!" << endl;
    }
    else if (choice == 2) {
        //load game status and continue
        ifstream fin;
        fin.open("save.txt");
        int Stage, items;       
        fin >> player.name>> player.hp >> Stage;
        while (true) {
            fin >> items;
            player.itemsgot.push_back(items);
            if (fin.eof())
                break;
        }
        fin.close();
        cout << "Welcome back! " << player.name<<endl;
        sleep(2);
        system("clear");
        for (int stage = Stage; stage < 4; stage++) {
            cout << "Stage " << stage + 1 << endl
                << "Enemy: " << enemyname[stage] << endl;
            battle(player, enemyhp[stage], enemyatk[stage], enemydef[stage], enemyname[stage], stage);
            sleep(2);
            system("clear");
        }
        cout << "Congratulations!\nYou have beat the game!\nThanks for playing!" << endl;

    }
 

    return 0;
    
}


