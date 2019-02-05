// PE5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#define SFML_STATIC
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>

int main()
{
	//window
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");


	//shapes
	//circle
	sf::CircleShape shape(50);
	shape.setFillColor(sf::Color(100, 250, 50));
	shape.setPosition(50, 300);

	//square
	sf::CircleShape square(80, 4);
	square.setFillColor(sf::Color(200, 100, 50));
	square.setPosition(200, 50);

	//octagon
	sf::CircleShape octagon(80, 8);
	octagon.setFillColor(sf::Color(200, 60, 250));
	octagon.setPosition(400, 300);
	while (window.isOpen())
	{

		//background

		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);
		window.draw(shape);
		window.draw(square);
		window.draw(octagon);

		window.display();
	}



	return 0;
}

