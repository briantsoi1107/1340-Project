#ifndef Action_h
#define Action_h
#include <vector>
#include <string>
using namespace std;
class Enemy
{
private:
	string enemy[4]{ "a","b","c","d" };
	int atk, hp, def;
public:
	void attack();
	void heal();

};

#endif