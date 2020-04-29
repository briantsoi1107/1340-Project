#include <iostream>
#include <vector>
#include <stdlib.h>
#include <ctime>
using namespace std;

void gotitem() {

    string itemlist[7]{"Shuriken","Caltrop","Kunai","First-aid kit","Medicine","Defense skill ","Upgraded costume"};
    vector<int> itemsgot;
    srand(time(0));
    int getitem = rand() % 7;
    cout << "you have collected a " << itemlist[getitem]<< " from enemies." << endl;
    itemsgot.push_back(getitem);
}
