// ConsoleApplication10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;

class MovableObject
{
public:
	int xPos;
	int yPos;
	void PrintPos()
	{
		cout << "X:" << xPos << " Y:" << yPos << endl;
	}
};

class Player : public MovableObject
{
public:
	char* name;
	Player()
	{
		cout << "player ctor" << endl;
		name = new char[15];
	}

	~Player()
	{
		cout << "player dtor" << endl;
		delete[] name;
	}
};

class Monster : public MovableObject
{
public:
	int damage;
};

int main()
{
	//Monster *boss = new Monster();
	//Player *pOne = new Player();
	MovableObject *boss = new Monster();
	MovableObject *pOne = new Player();
	Monster *fakeMonster = (Monster*)pOne;

	// add code here
	cout << "\n\nFake Monster " << &fakeMonster << " pOne " << &pOne << " Boss " << &boss;

	pOne->xPos = 2;
	pOne->yPos = 3;
	boss->xPos = 4;
	boss->yPos = 5;

	pOne->PrintPos();
	boss->PrintPos();


	delete boss;
	delete pOne;
	// cause the code to crash 
	//delete fakeMonster;

	_getch();
    return 0;
}

