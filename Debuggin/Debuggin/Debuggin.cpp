// Debuggin.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

void generateRandom(int numOfRandoms) {
	int num = 0;
	srand(NULL);
	for (size_t i = 0; i < numOfRandoms; i++)
	{
		num = rand() % 500 + 1;
		cout << "\n The number " << i + 1 << " random number is: " << num;
	}
}

int main()
{
	int x = 0;
	cout << "Number of random numbers:  ";
	cin >> x;
	generateRandom(x);

}
