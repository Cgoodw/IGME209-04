#include "snake.h"
#include <iostream>
#define SMFL_STATIC
#include <SFML/Window.hpp>
#include <Box2D/Box2D.h>
#include <conio.h>
#include <random>


b2Vec2* targetLocations;
b2Vec2 currentLocation;

typedef void(*FunctionPtr)(b2Body&);
FunctionPtr moveUp = ApplyForceUp;
FunctionPtr moveDown = ApplyForceDown;
FunctionPtr moveLeft = ApplyForceLeft;
FunctionPtr moveRight = ApplyForceRight;

//updates the world
void update(b2World& world)
{
	float timeStep = 1.0f / 160.0f;
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


void setupTargets(int cnt)
{
	currentLocation = b2Vec2(0, 0);
	targetLocations = new b2Vec2[cnt + 1];

	std::random_device rd;
	std::mt19937 rng(rd());
	for (int i = 0; i < cnt-1; i++)
	{
		std::uniform_real_distribution<float> distribution(-5000.0, 5000.0);
		targetLocations[i] = b2Vec2(distribution(rng), distribution(rng));
	}
	targetLocations[cnt] = b2Vec2(-10000, -10000);


	currentLocation = targetLocations[0];
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
void moveTarget(float& xPos, float& yPos, int targets)
{
	currentLocation = targetLocations[targets];
	xPos = currentLocation.x;
	yPos = currentLocation.y;
}

void processInput(b2Body& player,b2World& world)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		moveLeft(player);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		moveRight(player);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		moveUp(player);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		moveDown(player);
	}
	//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
		
	//}
	
}

void ApplyForceUp(b2Body& player)
{
	player.ApplyForceToCenter(b2Vec2(0, -20), true);
}

void ApplyForceDown(b2Body& player)
{
	player.ApplyForceToCenter(b2Vec2(0, 10), true);
}

void ApplyForceLeft(b2Body& player)
{
	player.ApplyForceToCenter(b2Vec2(-10, 0), true);
}

void ApplyForceRight(b2Body& player)
{
	player.ApplyForceToCenter(b2Vec2(10, 0), true);
}

void StopMoving(b2Body& player)
{
	player.SetLinearVelocity(b2Vec2(0, 0));
	player.SetAngularVelocity(0);
}

void ReverseGravity(b2World& world)
{
	world.SetGravity(-world.GetGravity());
}


bool selectNextTarget(int targets)
{

	currentLocation = targetLocations[targets];

	if (currentLocation.x > -9999) {
		return false;
	}
	return true;
}

