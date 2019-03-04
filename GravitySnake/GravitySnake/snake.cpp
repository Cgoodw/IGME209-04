#include "snake.h"
#include <iostream>
#define SMFL_STATIC
#include <SFML/Window.hpp>
#include <Box2D/Box2D.h>
#include <conio.h>
#include <random>

//updates the world
void update(b2World& world)
{
	float timeStep = 1.0f / 60.0f;
	int velocityIterations = 6;
	int positionIterations = 2;
	world.Step(timeStep, velocityIterations, positionIterations);
}

//displays the position of everything
void display(b2Vec2 positionP, b2Vec2 positionT)
{
	std::cout << "Position of player is: (" << positionP.x << "," << positionP.y << ")\n";
	std::cout << "Position of target is: (" << positionT.x <<","<<positionT.y<<")\n";

}

//applies force from keypress 
void applyForces(b2Body* snake , int key)
{


	snake->SetLinearVelocity(b2Vec2(0, 0));
	snake->SetAngularVelocity(0);
	switch (key)
	{
	case 72:    // key up
		snake->ApplyForceToCenter(b2Vec2(0, 100), true);
		break;
	case 80:    // key down
		snake->ApplyForceToCenter(b2Vec2(0, -50), true);
		break;
	case 77:    // key right
		snake->ApplyForceToCenter(b2Vec2(50, 0), true);
		break;
	case 75:    // key left
		snake->ApplyForceToCenter(b2Vec2(-50, 0), true);
		break;
	default:
		break;
	}

}

//moves the target
void moveTarget(float & xPos, float & yPos)
{
	//random number between -5 and 5
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_real_distribution<float> distribution(-5.0, 5.0);
	xPos = distribution(rng);
	yPos = distribution(rng);
}


