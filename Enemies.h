#ifndef ENEMIES_H
#define ENEMIES_H
#include <cstring>
#include <utility>
#include <iostream>
#include<ctime>

using namespace std;

class Enemies
{
protected:
	int Health;
	int Level;
	string name;
	int damage;


public:
	Enemies(int h, int l, string n, int d)
	{
		Health = h;
		name = n;
		Level = l;
		damage = d;
	}
	string getName() { return name; }
	string setName(string n) { name = n; }
	int getHealth() { return Health; }
	int setHealth(int h) { Health = h; }
	int getLevel() { return Level; }
	int setLevel(int l) { Level = l; }
	int getDamage() { return damage; }
	int setDamage(int d) { damage = d; }
	bool isHealth0() { return Health == 0; }
	virtual void use() = 0;
};
class Zombie : public Enemies
{
public:
	Zombie() : Enemies(Health, Level, name, damage) {}
	void use() {};
};
class Skeleton : public Enemies
{
public:
	Skeleton() : Enemies(Health, Level, name, damage) {}
	void use()
	{
		setHealth(rand() % 500 + 250);
		setDamage(rand() % 100 + 25);
		setLevel(rand() % 6 + 2);
	};
};
class Giant : public Enemies
{
public:
	Giant() : Enemies(Health, Level, name, damage) {}
	void use()
	{
		setHealth(rand() % 350 + 75);
		setDamage(damage * rand() % 50 + 25);
		setLevel(rand() % 4 + 1);
	};
};
#endif

