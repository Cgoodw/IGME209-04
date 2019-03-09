// Classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Player.h"
#include "Fighter.h"
int main()
{
	Fighter play1;
	Fighter play2((char*)"Mike", 5, 5, 5, 5);

	std::cout << "------Fighters-----\n";
	std::cout << "-------1-----\n";
	play1.printFighter();

	std::cout << "-------2-----\n";
	play2.printFighter();

}
