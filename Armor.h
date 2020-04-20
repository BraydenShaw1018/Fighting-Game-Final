#ifndef ARMOR.H
#define ARMOR.H
#include <cstring>
#include <utility>
#include <iostream>

using namespace std;

class Armor

{
protected:
	int defense;
	int cost;
	string name;
	string tier;

public:
	Armor(int c, int d, string n, string t)
	{
		name = n;
		tier = t;
		cost = c;
		defense = d;
	}
	int getCost() { return cost; }
	int setCost(int c) { cost = c; }
	int getDefense() { return defense; }
	int setDefense(int d) { defense = d; }
	string getName() { return name; }
	string setName(string n) { name = n; }
	string getTier() { return tier; }
	string setTier(string t) { tier = t; }
	virtual void use() = 0;
};

class leatherVest : public Armor
{

public:

	leatherVest() : Armor(cost, defense, name, tier) {}
	void use()
	{
		setDefense(175);
		setCost(50);
		setName("Leather Vest");
		setTier("Low");

	};
};

class militaryGradePlates : public Armor
{

public:

	militaryGradePlates() : Armor(cost, defense, name, tier) {}
	void use()
	{
		setDefense(300);
		setCost(175);
		setName("Military Grade Plates");
		setTier("Mid");
	};
};

class alienPlasmaVest : public Armor
{

public:

	alienPlasmaVest() : Armor(cost, defense, name, tier) {}
	void use()
	{
		setDefense(750);
		setCost(400);
		setName("Alien Plasma Vest");
		setTier("High");
	};
};
#endif

