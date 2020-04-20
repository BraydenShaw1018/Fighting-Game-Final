#ifndef WEAPON.H
#define WEAPON.H
#include <cstring>
#include <utility>
#include <iostream>


using namespace std;

class Weapon
{

protected:
	int damage;
	int cost;
	string name;
	string tier;

public:
	Weapon(int c, int d, string n, string t)
	{
		name = n;
		tier = t;
		cost = c;
		damage = d;
	}
	int getCost() { return cost; }
	int setCost(int c) { cost = c; }
	int getDamage() { return damage; }
	int setDamage(int d) { damage = d; }
	string getName() { return name; }
	string setName(string n) { name = n; }
	string getTier() { return tier; }
	string setTier(string t) { tier = t; }
	virtual void use() = 0;

};
class sharpenedStick : public Weapon
{
public:
	sharpenedStick() : Weapon(cost, damage, name, tier) {}
	void use()
	{
		setDamage(rand() % 50 + 25);
		setCost(75);
		setName("Sharpened Stick");
		setTier("Low");
	};
};
class ironSword : public Weapon
{
public:
	ironSword() : Weapon(cost, damage, name, tier) {}
	void use()
	{
		setDamage(rand() % 55 + 40);
		setCost(200);
		setName("Iron Sword");
		setTier("Mid");
	};
};
class plasmaSword : public Weapon
{
public:
	plasmaSword() : Weapon(cost, damage, name, tier) {}

	void use()
	{
		setDamage(rand() % 75 + 60);
		setCost(500);
		setName("Plasma Sword");
		setTier("High");
	};
};
#endif

