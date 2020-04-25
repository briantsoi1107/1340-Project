#include "Action.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void attack() {
    srand(time(0));
    int hit = rand() % 10 + 1;
    if (hit > 8) {
        enemyhp -= (atk - edef);
    }
    else { 
        cout<<"Missed!"
    }
   
    void ability() {
        cout<<"1."
}
    
}