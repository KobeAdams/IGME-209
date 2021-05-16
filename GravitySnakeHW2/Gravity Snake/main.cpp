#include <iostream>
#include "snake.h";
#include "conio.h"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Box2D/Box2D.h"
#include <sstream>
using namespace std;


typedef setupTagrets(setup);
typedef stopMoving(puase);
typedef processInput(pInput);
typedef reverseGravity(invert);
typedef newTarget (*selectedNextTarget)();



int main()
{
	cout << "Welcome to gravity Snake!\nUse the wasd keys to move the snake!\n";
	b2Vec2 gravity(0.0f, -(10.0f));
	b2World world = b2World(gravity);
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, -10.0f);
	b2Body* groundBody = world.CreateBody(&groundBodyDef);
	b2PolygonShape groundBox;
	groundBox.SetAsBox(50.0f, 10.0f);
	groundBody->CreateFixture(&groundBox, 0.0f);

	b2BodyDef snakeDef;
	snakeDef.type = b2_dynamicBody;
	snakeDef.position.Set(0.0f, 5.0f);
	b2Body* snake = world.CreateBody(&snakeDef);

	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;

	snake->CreateFixture(&fixtureDef);

	

	b2Vec2 target;
	int score = 0;

	target.x = 1.5;
	target.y = 1.2;
	int key = 0;
	string in = "";
	
	int input = 0;
	
	do
	{
		std::cout << "how many targets would you like? From 1 to 10";
		getline(cin,in);
		std::stringstream ss(in);
		ss >> input;
		if (input > 10 || input < 0)
		{
			std:: cout << "Invalid Input, please input from 1 to 10";
		}
		else
		{
			break;
		}

	} while (input > 10 || input < 1);
	

	setup * setUP;
	bool moreTargets = true;
	newTarget* refresh;

	setUP(input);
	do
	{
		processInput;


		moreTargets = refresh;
	} while (moreTargets==true);
	
	
	//do
	//{
		
		/*b2Vec2 position = snake->GetPosition();
		float angle = snake->GetAngle();
		bool hit = false;
		
		
		
		if (abs(target.x - position.x) <= 0.05 && abs(target.y - position.y) <= 0.05)
			hit = true;
		else
			hit = false;
		update(world);
		display(target, position);
		if (hit == true)
		{
			cout << "(hit target)";
			float x = rand() % 10 - 5;
			float y = rand() % 10 - 5;
			moveTarget(x,y, target);
			score++;
		}
		cout << "\n";*/
	//} while (score <10&&key != 27);

	cout << "you've hit the escape key! Time to end the program";
}
