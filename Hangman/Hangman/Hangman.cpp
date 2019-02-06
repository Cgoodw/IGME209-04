#include "hangman.h"
#include "stdafx.h"
#include <cstring>
#include <iostream>
using namespace std;


void showGallows(int numGuesses) {

	//body part
	char head[5] = "    ";
	char arms[5] = "    ";
	char legs[5] = "    ";
	char body[5] = "    ";


	//printing them

	if (numGuesses < 6) {
		head[1] = 'O';
		if (numGuesses < 5) {
			arms[0] = '/';
			arms[1] = '|';
			if (numGuesses < 4) {
				arms[2] = '\\';
				if (numGuesses < 3) {
					body[1] = '|';
					legs[0] = '/';
					if (numGuesses < 1) {
						legs[2] = '\\';
					}

				}
			}
		}
	}
	cout << "\n----|\n";
	cout << "|  " << head << "\n";
	cout << "|  " << arms << "\n";
	cout << "|  " << body << "\n";
	cout << "|  " << legs << "\n";
	cout << "|         \n";
	cout << "=============\n";

}


void showSolved(char word[], char guesses[]) {
	char display[7]="______";
	for (size_t i = 0; i < strlen(word); i++)
	{
		for (size_t j = 0; j < strlen(guesses); j++)
		{

			if (word[i] == guesses[j]) {
				display[i] = word[i];
			}
			
		}
	}
	cout << display <<"\n";

}
