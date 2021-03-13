#include "Player.h"
#include <iostream>

Player::Player()
{
	
	this->name = "Unknown";

	str = 10;
	dex = 10;
	wis = 10;
}

Player::Player(const char* name, int& str, int& dex, int& wis)
{
	this->name = name;
	this->str = str;
	this->dex = dex;
	this->wis = wis;
}

void Player::printPlayer()
{
	std::cout << name << "\nStrength : "<<str<<"\nDexterity : "<<dex<<"\nWisdom : "<<wis;
}
