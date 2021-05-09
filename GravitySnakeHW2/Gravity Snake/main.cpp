#include <iostream>
#include "conio.h"
#include "snake.h";
#include "Box2D/Box2D.h"
using namespace std;

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
	do
	{
		
		b2Vec2 position = snake->GetPosition();
		float angle = snake->GetAngle();
		bool hit = false;
		key = _getch();
		if (key==97||key==119||key==115||key==100)
		//if(_kbhit())
			applyForces(snake, key);
		
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
		cout << "\n";
	} while (score <10||key != 27);

	cout << "you've hit the escape key! Time to end the program";
}
