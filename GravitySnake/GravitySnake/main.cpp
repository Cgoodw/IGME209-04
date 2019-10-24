#include "snake.h"
#include "sfml.h"
#include <iostream>
#define SMFL_STATIC
#include <Box2D/Box2D.h>
#include <conio.h>

#include <string>

#include <vector>
int targets;

int main()
{
	//variables
	float xPos=0;
	float yPos=0;
	int targets = 0;
	int key=0;
	bool win;
	bool gravityDown;
	bool flipped=false;

	//welcome and instruction
	int tars = 0;
	std::cout << "Welcome to Gravity Snake \n";
	std::cout << "Use the arrow Keys to move and hit targets. \n";
	std::cout << "Every few targets, gravity will switch, collect all targets to win\n";
	while (tars < 10) {
		std::cout << "How many Targets do you want? (Minimum 10):   ";
		std::cin >> tars;
		if (tars < 10) {
			std::cout << "Number must be more than 10 \n" ;
		}
	}
	setupTargets(tars);


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


	//create snake body
	std::vector<sf::CircleShape> snakeBod;

	for (int i = 0; i < tars; i++) {
		sf::CircleShape snakeB(10, 5);
		snakeB.setFillColor(sf::Color(100, 100, 240));

		snakeBod.push_back(snakeB);
	}
	// GUI

	sf::Font font;
	font.loadFromFile("arial.ttf");
	sf::Text text("Score: ", font ,20);
	sf::Text scoreText("0", font, 20);

	sf::Text gravityText("Gravity Normal", font, 20);

	scoreText.setPosition(100,0);

	gravityText.setPosition(300, 0);

	//create target
	moveTarget(xPos, yPos, targets);
	b2BodyDef targetDef;
	targetDef.type = b2_staticBody;
	targetDef.position.Set(xPos, yPos);
	b2Body* target = world.CreateBody(&targetDef);

	
	b2Vec2 positionP;
	b2Vec2 positionT;

	positionP = snake->GetPosition();
	positionT = target->GetPosition();


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
		if (b2Distance(positionP,positionT)<150) {

			selectNextTarget(targets);
			moveTarget(xPos, yPos, targets);
			target->SetTransform(b2Vec2(xPos, yPos), target->GetAngle());
			targets++;
		}

		//if the snakes goes off the screen
		if (snake->GetPosition().x > 6500 || snake->GetPosition().x < -6500 || snake->GetPosition().y < -6000 || snake->GetPosition().y > 6000) {

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

			if (targets > 1) {
				scoreText.setString(std::to_string(targets - 1));
			}
			
			//draw body
			for (int i = 0; i < targets - 1; i++) {
				if (!flipped) {
					snakeBod[i].setPosition(snakeSquare.getPosition().x, snakeSquare.getPosition().y + (1+i * 10));
				}
				else {
					snakeBod[i].setPosition(snakeSquare.getPosition().x, snakeSquare.getPosition().y - (1+i * 10));
				}
				window.draw(snakeBod[i]);
			}



			window.draw(text);
			window.draw(scoreText);
			window.draw(gravityText);

			window.display();
		}

		if (targets>2&&targets % 3 == 0) {
			if (!flipped) {
				ReverseGravity(world);
				//std::cout << "Gravity Flipped!"<<std::endl;
				gravityText.setString("Gravity Flipped!");
					
				flipped = true;
			}
		}
		else{
			flipped = false;
			gravityText.setString("Gravity Normal");
		}



	}
	std::cout << std::endl << "--------------" << std::endl << "Finished!";
	window.close();
	_getch();
	return 0;

}
