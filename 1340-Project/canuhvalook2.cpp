#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void attack(int hp, int atk, int lvl) {
    int enemyhp[10]={60,90,100,120,150,180,200,250,300,500};
    int enemydef[10]={1,3,8,8,10,13,15,18,22,26};
    srand(time(0));
    int hit = rand() % atk + 1;
    if (hit > (atk*0.6)) {
        enemyhp[lvl] -= (hit - enemydef[lvl]);
    }
    else { 
        cout<<"Missed!"
    }
}

void defense(int hp, int def, int lvl) {
    int enemyatk[10]={4,5,10,15,30,30,35,40,40,50};
    srand(time(0));
    int mydef = rand() % def + 1;
    if (mydef < (def*0.8)) {
        hp -= (enemyatk[lvl]-mydef);
        cout << “Hit";
    }
}
