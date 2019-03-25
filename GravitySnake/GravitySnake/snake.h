#pragma once
#include <Box2D/Box2D.h>

void update(b2World& world);

void display(b2Vec2 positionP, b2Vec2 positionT);

void applyForces(b2Body* snake, int key);

void moveTarget(float& xPos, float& yPos);

void processInput(b2Body& player, b2World& world);

void ApplyForceUp(b2Body& player);

void ApplyForceDown(b2Body& player);

void ApplyForceLeft(b2Body& player);

void ApplyForceRight(b2Body& player);

void StopMoving(b2Body& player);

void ReverseGravity(b2World& world);

void setupTargets(int cnt);

bool selectNextTarget(int targets);

int main();

extern b2Vec2* targetLocations;
extern b2Vec2 currentLocation;