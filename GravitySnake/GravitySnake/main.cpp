#include "snake.h"
#include <iostream>
#define SMFL_STATIC
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <conio.h>



int main()
{
	//variables
	float xPos=0;
	float yPos=0;
	int targets = 0;
	int key=0;


	//SFML
	//window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Gravity Snake");
	window.setActive(true);
	
	//Snake
	sf::CircleShape snakeSquare(11);
	snakeSquare.setFillColor(sf::Color(0, 200, 90));
	snakeSquare.setPosition(0, 0);

	//Target
	sf::CircleShape targetSquare(10,4);
	targetSquare.setFillColor(sf::Color(200, 100, 0));
	targetSquare.setPosition(200, 50);

	//create world
	b2Vec2 gravity(0.0f, 0.6f);
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
	int tars = 0;
	std::cout << "Welcome to Gravity Snake \n";
	std::cout << "Use the arrow Keys to move and E to reverse gravity. \n";
	while (tars < 10) {
		std::cout << "How many Targets do you want?:   ";
		std::cin >> tars;
		if (tars < 10) {
			std::cout << "Number must be more than 10";
		}
	}
	setupTargets(tars);

	
	b2Vec2 positionP;
	b2Vec2 positionT;

	positionP = snake->GetPosition();
	positionT = target->GetPosition();

	//world.SetGravity(b2Vec2 (0,0.06));

	//loop for key presses
	while (targets < tars)
	{
		window.setActive(true);
		window.requestFocus();
		positionP = snake->GetPosition();
		positionT = target->GetPosition();

		//gets keyboard press
		processInput(*snake,world);
		update(world);
		
		//if snake gets close to the target
		if (b2Distance(positionP,positionT)<1) {

			selectNextTarget(targets);
			moveTarget(xPos, yPos);
			std::cout << "---------HIT!------------- \n";
			b2BodyDef targetDef;
			targetDef.type = b2_staticBody;
			targetDef.position.Set(xPos, yPos);
			b2Body* target = world.CreateBody(&targetDef);
			targets++;
		}

		//if the snakes goes off the screen
		if (snake->GetPosition().x > 6000 || snake->GetPosition().x < -6000 || snake->GetPosition().y < -6000 || snake->GetPosition().y > 6000) {

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

			//converting coordinate systems
			snakeSquare.setPosition(positionP.x/16+(window.getSize().x/2),positionP.y/16+(window.getSize().y/2));
			targetSquare.setPosition(positionT.x/16 + (window.getSize().x / 2), positionT.y/16 + (window.getSize().y / 2));

			window.clear(sf::Color::Black);
			window.draw(snakeSquare);
			window.draw(targetSquare);

			window.display();
		}




	}
	std::cout << "Finished!";

	_getch();
	return 0;

	//clear memory
	delete targetLocations;
}
