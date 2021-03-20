#include <iostream>
#include <memory>
#include "Game.h"
using namespace std;

int main()
{
	Smart();
	Dumb();
}

void Smart()
{
	shared_ptr<Game> smart(new Game());
}

void Dumb()
{
	Game* dumb = new Game();
}
