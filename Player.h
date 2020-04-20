#ifndef PLAYER_H
#define PLAYER_H
#include "Gear.h"
#include "Armor.h"
#include "Weapon.h"
#include <cstring>
#include <utility>
#include <iostream>
#include <ctime>
#include<fstream>
#include <vector>

using namespace std;

[Serialiazble]

class Player
{
private:

	int health;
	int level;
	int money;
	string name;
	Weapon* uWeapon;
	Armor* uArmor;
	vector<Gear*> Gear;

public:

	Player(int h, int l, int m, string n)
	{
		health = h;
		name = n;
		money = m;
		level = l;
		srand(time(NULL));
	}
	string getName() { return name; }
	string setName(string n) { name = n; }
	int getHealth() { return health; }
	int setHealth(int h) { health = h; }
	int getLevel() { return level; }
	int setLevel(int l) { level = l; }
	int getMoney() { return money; }
	int setMoney(int m) { money = m; }
	bool isHealth0() { return health == 0; }
	Armor* getArmor() { return uArmor; }
	Armor* setArmor(Armor* a) { uArmor = a; }
	Weapon* getWeapon() { return uWeapon; }
	Weapon* setWeapon(Weapon* w) { uWeapon = w; }
	string Profile()
	{
		cout << "Name: " << name << endl;
		cout << "Health: " << health << endl;
		cout << "Money: " << money << endl;
		cout << "Level: " << level << endl;
		cout << "Weapon in use: " << uWeapon->getName() << endl;
		cout << "Armor in use: " << uArmor->getName() << endl;
	}
};
#endif

