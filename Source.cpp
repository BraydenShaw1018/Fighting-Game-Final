// Brayden Shaw
// Fighting Game Final
// This is my own work

#include <iostream>
#include<cstring>
#include "Enemies.h"
#include "Armor.h"
#include "Player.h"
#include "Weapon.h"
#include "Gear.h"
#include <fstream>
#include <utility>
#include <ctime>

using namespace std;

int main()
{
	Giant boss;
	Enemies* Boss = &boss;
	int health, level, money;
	string name;
	Player uPlayer(health, level, money, name);
	int result;

	cout << "Type 1 for new character or 0 to load one." << endl;
	cin >> result;
	if (result == 1) 
	{
		string uName;
		cout << "Enter a username." << endl;
		cin >> uName;
		uPlayer.setName(uName);
		uPlayer.setHealth(50);
		uPlayer.setMoney(0);
		uPlayer.setLevel(1);
		cout << "Welcome fantasy fight." << endl;
		cout << "You can level up by winning in the arena." << endl;
		cout << "Weapons and armor can be purchased as you progress." << endl;
		cout << "The final boss can be beat at level 10." << endl;
		cout << "Inventory can be viewed at anytime." << endl;
	}
	else if (result == 0)
	{
		cout << "Enter the  name of the file you want to load in." << endl;
		ifstream fin("input.in");
		if (!fin)
		{
			cout << "File not found.";
			exit(2);
		}
		int health, level, money;
		Weapon* W;
		Armor* A;
		string name;
		while (fin >> health >> level >> money >> name)
		{
			Player uPlayer(health, level, money, name);
		}
	}
	else
		cout << "Please enter a 1 or 0." << endl;
	do {
		int input;
		cout << "Press 1 if you want to view your player profile.  " << endl;
		if (input == 1)
		{
			uPlayer.Profile();
		}
		userInput(uPlayer);
	} while (uPlayer.isHealth0() ==  false;
	return 0;
}
void userInput(Player u)
{
	int r;
	cout << "Type 0 to go to the store, 1 to enter a safe area, 2 to save progress." << endl;
	cin >> r;
	if (r == 0)
	{
		store(u);
	}
	else if (r == 1)
	{
	}
	else if (r == 2)
	{
		savePlayer(u);
	}
	else
		cout << "Please enter a 1 or 0" << endl;
}
Player store(Player u)
{
	int purchase;
	leatherVest h;
	Armor* H = &h;
	sharpenedStick p;
	Weapon* P = &p;

	militaryGradePlates k;
	Armor* K = &k;
	ironSword r;
	Weapon* R = &r;

	alienPlasmaVest m;
	Armor* M = &m;
	plasmaSword rg;
	Weapon* rG = &rg;

	cout << "What do you need?";

	if (u.getLevel() >= 3)
	{
		cout << "Type 1 for Leather Vest, 2 for sharpened stick." << endl;
		cout << K->getName() << K->getCost() << K->getTier() << endl;
		cout << R->getName() << R->getCost() << R->getTier() << endl;

	}
	else if (u.getLevel() >= 6)
	{
		cout << "Type 3 for Military Grade Plates, 4 for Iron sword." << endl;
		cout << M->getName() << M->getCost() << M->getTier() << endl;
		cout << rG->getName() << rG->getCost() << rG->getTier() << endl;

	}
	else
	{
		cout << "Type 5 for Alien Plasm Vest,6 for Plasma Sword." << endl;
		cout << H->getName() << H->getCost() << H->getTier() << endl;
		cout << P->getName() << P->getCost() << P->getTier() << endl;

	}
	if (purchase == 1)
	{
		if (u.setMoney(u.getMoney - H->getCost()) < 0)
		{
			cout << "You do not have enough money." << endl;
		}
		else
		{
			u.setMoney(u.getMoney - H->getCost());
			u.setArmor(H);
		}
		userInput(u);
	}
	else if (purchase == 2)
	{
		if (u.setMoney(u.getMoney - P->getCost()) < 0)
		{
			cout << "You do not have enough money." << endl;
		}
		else
		{
			u.setMoney(u.getMoney - P->getCost());
			u.setWeapon(P);
		}
		userInput(u);
	}
	else if (purchase == 3)
	{
		if (u.setMoney(u.getMoney - K->getCost()) < 0)
		{
			cout << "You do not have enough money." << endl;
		}
		else
		{
			u.setMoney(u.getMoney - K->getCost());
			u.setArmor(K);
		}
		userInput(u);
	}
	else if (purchase == 4)
	{
		if (u.setMoney(u.getMoney - R->getCost()) < 0)
		{
			cout << "You do not have enough money." << endl;
		}
		else
		{
			u.setMoney(u.getMoney - R->getCost());
			u.setWeapon(R);
		}
		userInput(u);
	}
	else if (purchase == 5)
	{
		if (u.setMoney(u.getMoney - M->getCost()) < 0)
		{
			cout << "You do not have enough money." << endl;
		}
		else
		{
			u.setMoney(u.getMoney - M->getCost());
			u.setArmor(M);
		}
		userInput(u);
	}
	else if (purchase == 6)
	{
		if (u.setMoney(u.getMoney - rG->getCost()) < 0)
		{
			cout << "You do not have enough money." << endl;
		}
		else
		{
			u.setMoney(u.getMoney - rG->getCost());
			u.setWeapon(rG);
		}
		userInput(u);
	}
	else
		userInput(u);
}
void savePlayer(Player u)
{
	string file;
	ofstream userfile;
	cout << "Where would you like to save?" << endl;
	cin >> file;
	userfile.open(file);
	userfile.write((char*)&u, sizeof(u));
	userfile.close();
	exit(0);
}
Player safeArea(Player u)
{
	if (u.getLevel() < 5)
	{
		Zombie g;
		Enemies* bite = &g;
		bite->getLevel();
		while (u.isHealth0() == false || bite->isHealth0() == false)
		{
			bite->setHealth(bite->getHealth - u.getWeapon()->getDamage);
			u.setHealth((u.getHealth() + u.getArmor()->getDefense()) - bite->getDamage);
		}
		if (u.isHealth0() == true)
		{
			cout << "You lose" << endl;
			u.setHealth(100);
			userInput(u);
		}
		else
		{
			cout << "You won" << endl;
			u.setHealth(100);
			u.setMoney(u.getMoney() + 50);
			u.setLevel(u.getLevel() + 1);
			userInput(u);
		}
	}
	if (u.getLevel() <= 9 && u.getLevel() >= 4)
	{
		Skeleton s;
		Enemies* bow = &s;
		bow->getLevel();
		while (u.isHealth0() == false || bow->isHealth0() == false)
		{
			bow->setHealth(bow->getHealth - u.getWeapon()->getDamage);
			u.setHealth((u.getHealth() + u.getArmor()->getDefense()) - bow->getDamage);
		}
		if (u.isHealth0() == true)
		{
			cout << "You lose" << endl;
			u.setHealth(100);
			userInput(u);
		}
		else
		{
			cout << "You won" << endl;
			u.setHealth(100);
			u.setMoney(u.getMoney() + 150);
			u.setLevel(u.getLevel() + 2);
			userInput(u);
		}
	}
	if (u.getLevel() == 10)
	{
		Giant b;
		Enemies* Smash = &b;
		Smash->setHealth(1000);
		Smash->setDamage(rand() % 350 + 200);
		Smash->setLevel(10);
		while (u.isHealth0() == false || Smash->isHealth0() == false)
		{
			Smash->setHealth(Smash->getHealth - u.getWeapon()->getDamage);
			u.setHealth((u.getHealth() + u.getArmor()->getDefense()) - Smash->getDamage);
		}
		if (u.isHealth0() == true)
		{
			cout << "You lost" << endl;
			u.setHealth(100);
			userInput(u);
		}
		else
		{
			cout << "You won" << endl;
			u.setHealth(100);
			u.setMoney(u.getMoney() + 90000);
			u.setLevel(u.getLevel() + 10);
			userInput(u);
		}
	}
}