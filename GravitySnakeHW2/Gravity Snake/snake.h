#pragma once
#include "Box2D/Box2D.h"


void update(b2World& world);

void processInput(b2Body& snake);

void applyForcesUp(b2Body& snake);
void applyForcesDown(b2Body& snake);
void applyForcesLeft(b2Body& snake);
void applyForcesRight(b2Body& snake);

void stopMoving(b2Body& snake);

void reverseGravity(b2World& world);

void setupTargets(int cnt);

bool selectNextTarget();


void display(b2Vec2 target, b2Vec2 snake);

void applyForces(b2Body* snake, int key);

void moveTarget(float& xpos, float& ypos, b2Vec2& target);

