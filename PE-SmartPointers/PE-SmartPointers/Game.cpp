#include <iostream>
#include "Game.h"


Game::Game()
{
	lvlNum = 1;
	enemyNum = 5;
	randTreas = 17;
	std::cout << "Game has been created\n";
}

Game::~Game()
{
	std::cout << "Game has been Deleted\n";
}