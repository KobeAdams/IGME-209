#include "Player.h"
#include <iostream>
using namespace std;
Player::Player()
{
	name = "Unknown";
	str = 10;
	dex = 10;
	wis = 10;
}

Player::Player(const char*cName,int strength,int dext, int wisdom)
{
	name = cName;
	str = strength;
	dex = dext;
	wis = wisdom;
}

Player::~Player()
{
	cout << "Destroying Player Object!\n";
}

const char* Player::getName()
{
	return name;
}

void Player::Attack(Player* player)
{
	cout << this->name << " attacks " << player->getName() << "\n";
}

void Player::PrintPlayer()
{
	cout << "Name: " << (name) <<
		"\nStrength: "<<str<<"\nDexterity: "<<dex<<"\nWisdom:"<<wis<< "\n\n";
}