// Classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Player.h"
int main()
{
	Player play1;
	Player play2((char*)"Mike", 5, 5, 5);
	Player* play3 = new Player();
	Player* play4 = new Player((char*)"Nick", 5, 10, 15);

    std::cout << "------Players-----\n"; 
	std::cout << "P1-----\n";
	play1.printPlayer();

	std::cout << "P2-----\n";
	play2.printPlayer();

	std::cout << "P3-----\n";
	play3->printPlayer();

	std::cout << "P4-----\n";
	play4->printPlayer();

	delete play3;
	delete play4;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
