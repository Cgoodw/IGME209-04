// FileIO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
int main()
{
	std::ofstream fileOut;
	fileOut.open("text.txt");
	if (fileOut.is_open()) {
		fileOut << "Hello! \n";
		fileOut << "Greetings! \n";
		fileOut.close();
	}

	std::ifstream fileIn("text.txt", std::ios::binary);
	if (fileIn.is_open()) {
		fileIn.seekg(0, std::ios::end);
		int length = (int)fileIn.tellg();
		fileIn.seekg(0, std::ios::beg);
		char* fileContents = new char[length + 1];
		fileIn.read(fileContents, length);
		fileContents[length] = 0;
		for (int i = 0; i < length; i++)
		{
			std::cout << fileContents[i];
		}

		fileIn.close();
	}

	
}

