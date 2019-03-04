#pragma once
#include <Box2D/Box2D.h>

void update(b2World& world);

void display(b2Vec2 positionP, b2Vec2 positionT);

void applyForces(b2Body* snake, int key);

void moveTarget(float& xPos, float& yPos);

int main();

