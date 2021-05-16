#include "snake.h"
#include <iostream>
#define snake_h
#include "conio.h"
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"
using namespace std;
b2Vec2 targetLocations[];
b2Vec2* currentTarget;
//use set linear velocity
//change the gravity

void applyForcesUp(b2Body& snake)
{
	float mag = 7200;
	b2Body* player = &snake;
	player->ApplyForceToCenter(b2Vec2(0, mag), true);
	
}
void applyForcesDown(b2Body& snake)
{
	float mag = 7200;
	b2Body* player = &snake;
	player->ApplyForceToCenter(b2Vec2(0, -mag), true);
	
}
void applyForcesRight(b2Body& snake)
{
	float mag = 7200;
	b2Body* player = &snake;	
	player->ApplyForceToCenter(b2Vec2(mag, 0), true);
}
void applyForcesLeft(b2Body& snake)
{
	float mag = 7200;
	b2Body* player = &snake;
	player->ApplyForceToCenter(b2Vec2(-mag, 0), true);
}



void processInput(b2Body& snake)
{
	int key = 0;
	if (_kbhit())
	{

		key = _getch();
		//A=97; W=119; D=100; S=115
		switch (key)
		{
			case 97:
				applyForcesLeft(snake);
				break;
			case 119:
				applyForcesUp(snake);
				break;
			case 100:
				applyForcesRight(snake);
				break;
			case 115:
				applyForcesDown(snake);
				break;
		}
			//if(_kbhit())
			//applyForces(snake, key);
	}

}

void stopMoving(b2Body& snake)
{
	b2Body* player = &snake;
	player->SetLinearVelocity(b2Vec2 (0,0));
}

void reverseGravity(b2World& world)
{
	b2World* w = &world;
	b2Vec2 grav = w->GetGravity();
	grav *= -1;
	w->SetGravity(grav);
}

void setupTargets(int cnt)
{
	int x, y;
	const int count = cnt;
	
	b2Vec2* targets;
	for (int i =0; i<cnt; i++)
	{
		x = rand() % 20 - 10;
		y = rand() % 10;
		targetLocations[i] = b2Vec2(x,y);
	}
	targetLocations[cnt] = b2Vec2(-1000, -1000);
	currentTarget = &targetLocations[0];
}

bool selectNextTarget()
{
	currentTarget+=1;
	if ((*currentTarget).x == -1000)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void update(b2World& world)
{
	float timeStep = 1.0f / 7200.0f;
	int32 velocityIterations = 5;
	int32 positionIterations = 5;
	world.Step(timeStep, velocityIterations, positionIterations);
}

void display(b2Vec2 target, b2Vec2 snake)
{
	cout << "Target: " << target.x << ", " << target.y << "<-- Snake: " << snake.x << ", " << snake.y<<" ";
}

void applyForces(b2Body* snake, int key)
{
	float mag = 7200;
	switch (key)
	{
		//A=97; W=119; D=100; S=115
		
		case 97:
			//b2Vec2 vec = b2Vec2(-1, 0);
			
			snake->ApplyForceToCenter(b2Vec2(-mag, 0), true);
			break;
		case 119:
			//b2Vec2 vec = b2Vec2(0, -1);
			snake->ApplyForceToCenter(b2Vec2(0, mag), true);
			break;
		case 115:
			//b2Vec2 vec = b2Vec2(0, 1);
			snake->ApplyForceToCenter(b2Vec2(0, -mag), true);
			break;
		case 100:
			//b2Vec2 vec = b2Vec2(1, 0);
			snake->ApplyForceToCenter(b2Vec2(mag, 0), true);
			break;
	}
		

	
}

void moveTarget(float& xpos, float& ypos, b2Vec2& target)
{
	target.x += xpos;
	target.y += ypos;
}

