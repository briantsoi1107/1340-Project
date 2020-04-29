#ifndef Action_h
#define Action_h
#include <vector>
#include <string>
using namespace std;
class Action{
private:
	vector<int> itemsgot = { 0,2,3 };
	string itemslist[7]={ "Shuriken","Caltrop","Poisons","Medicine","Book of Defensive Skills ","Book of Advanced Ninjutsu" };
public:
	string name;
	int hp=100, atk=10, def=5;
	void printstatus();
	void attack(int& enemyhp, int enemydef);
	void items(int& enemyhp);
	void gotitem();
	void defend(int enemyatk);


};




#endif