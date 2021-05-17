#include "Fighter.h"
#include <iostream>
using namespace std;
Fighter::Fighter()
{
	weapSkill = 15;
}

Fighter::Fighter(const char* fname, int weapSkill, int str, int dex, int wis) :Player(fname, str, dex, wis)
{
	this->weapSkill = weapSkill;
}

Fighter::~Fighter()
{
	cout << "Destroying Fighter Object!\n";
}

void Fighter::Attack(Player* player)
{
	cout << this->getName() << " attacks " << player->getName() << " with a weapon!\n";
}

void Fighter::PrintFighter()
{
	PrintPlayer();
	cout << "Weapon Skill: " << weapSkill <<"\n\n";
}