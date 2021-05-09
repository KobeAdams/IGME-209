#include "snake.h"
#include <iostream>
#define snake_h
#include "conio.h"

#include "Box2D/Box2D.h"
using namespace std;


void update(b2World& world)
{
	float timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;
	world.Step(timeStep, velocityIterations, positionIterations);
}

void display(b2Vec2 target, b2Vec2 snake)
{
	cout << "Target: " << target.x << ", " << target.y << "<-- Snake: " << snake.x << ", " << snake.y<<" ";
}

void applyForces(b2Body* snake, int key)
{
	float mag = 500;
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

