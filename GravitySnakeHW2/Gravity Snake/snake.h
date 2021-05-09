#pragma once
#include "Box2D/Box2D.h"


void update(b2World& world);

void display(b2Vec2 target, b2Vec2 snake);

void applyForces(b2Body* snake, int key);

void moveTarget(float& xpos, float& ypos, b2Vec2& target);

