#ifndef Action_h
#define Action_h
#include <vector>
#include <string>
using namespace std;
class Action{ //use of class
private:
	string itemslist[6]={ "Shuriken","Caltrop","Poison","Medicine","Book of Defensive Skills ","Book of Advanced Ninjutsu" };

public:
	vector<int> itemsgot = {0,1,2,3}; //dynamic mememory management
	string name;
	int maxhp[4] = { 50,100,150,200 }, hp = 50, atk[4] = { 20,30,55,65}, def[4] = { 5,10,20,40 };
	void printstatus(int stage);
	void attack(int& enemyhp, int enemydef, int stage);
	void items(int& enemyhp, int stage);
	void gotitem();
	void guard(int enemyatk, int stage);


};




#endif