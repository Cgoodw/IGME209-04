// Cstrings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstring>

int main()
{
    char wordA[50]= "supercalifraglistic"; 
	char wordB[25] = "expialidocious";

	std::cout << "Length:  " << strlen(wordA) << std::endl;
	strcat_s(wordA, wordB);

	std::cout << wordA << std::endl;
	int x =0;

	for (size_t i = 0; i < strlen(wordA); i++)
	{
		if (wordA[i]=='i'){
			x++;
		}
	}
	std::cout << "# of I's: " << x;

}