#include "snake.h"
#include <iostream>
#define SMFL_STATIC
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <conio.h>

int main()
{
	//variables
	float xPos;
	float yPos;
	int targets=0;
	int key=0;

	//SFML
	//window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Gravity Snake");
	
	//Snake
	sf::CircleShape snakeSquare(10, 4);
	snakeSquare.setFillColor(sf::Color(0, 200, 90));
	snakeSquare.setPosition(0, 0);

	//Target
	sf::CircleShape targetSquare(10,4);
	targetSquare.setFillColor(sf::Color(200, 100, 0));
	targetSquare.setPosition(200, 50);

	//create world
	b2Vec2 gravity(0.0f, -9.8f);
	b2World world(gravity);

	//create snake
	b2BodyDef snakeDef;
	snakeDef.type = b2_dynamicBody;
	snakeDef.position.Set(0.0f, 0.0f);
	b2Body* snake = world.CreateBody(&snakeDef);

	//create target
	moveTarget(xPos, yPos);

	b2BodyDef targetDef;
	targetDef.type = b2_staticBody;
	targetDef.position.Set(xPos,yPos);
	b2Body* target = world.CreateBody(&targetDef);
	

	//welcome and instruction
	std::cout << "Welcome to Gravity Snake \n";
	std::cout << "Hit 3 Targets to win! \n";
	std::cout << "Press the up, down, left, and right keys to move the snake \n";
	std::cout << "Press ESC to exit the game \n";

	
	b2Vec2 positionP;
	b2Vec2 positionT;

	positionP = snake->GetPosition();
	positionT = target->GetPosition();

	//loop for key presses
	while (targets < 3)
	{
		positionP = snake->GetPosition();
		positionT = target->GetPosition();
		//gets keyboard press
		if (_kbhit())
		{
			key = _getch();
			if (key == 27) {
				break;
			}
			update(world);
			applyForces(snake, key);
			display(positionP, positionT);
		}

		//if snake gets cklose to the target
		if (b2Distance(snake->GetPosition(), target->GetPosition())<1) {

			moveTarget(xPos, yPos);
			target->SetTransform(b2Vec2(xPos, yPos),0.0);
			std::cout << "---------HIT!------------- \n";
			targets++;
		}

		//if the snakes goes off the screen
		if (snake->GetPosition().x > 5 || snake->GetPosition().x < -5 || snake->GetPosition().y < -5 || snake->GetPosition().y > 5) {

			std::cout << "----Off the screen, you lose------ \n";
			break;
		}


		//Not Implemented fully
		//updates visuals
		if (window.isOpen())
		{
			// check all the window's events that were triggered since the last iteration of the loop
			sf::Event event;
			while (window.pollEvent(event))
			{
				// "close requested" event: we close the window
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear(sf::Color::Black);
			window.draw(snakeSquare);
			window.draw(targetSquare);

			window.display();
		}




	}
	std::cout << "Finished!";

	_getch();
	return 0;
}
