#include "hangman.h"
#include "stdafx.h"
#include <cstring>
#include <iostream>
using namespace std;

void showGallows(int numGuesses);
void showSolved(char word[], char guesses[]);

int main()
{
	bool lost = false;

	//number of wrong guesses
	int guessNum = 0;

	//number of actual choices
	int choicenum = 0;

	//number of correct letters
	int correctLetters = 0;

	char word[8]="hockey";
	char guess[26]="";
	cout << "Welcome to Hangman!\n";
	cout << "Your word has " << strlen(word) << " letters.\n";

	while (!lost)
	{
		
		char guessedLetter;

		cout << "Enter your guess:  ";
		cin >> guessedLetter;



		bool alreadyGuessed = false;
		for (size_t i = 0; i < strlen(guess); i++)
		{
			if (guess[i] == guessedLetter) {
				alreadyGuessed = true;

			}
		}
		if (alreadyGuessed) {
			cout<< "You already guessed that letter \n";
			continue;
		}


		guess[choicenum] = guessedLetter;



		bool contained = false;
		for (size_t i = 0; i < strlen(word); i++)
		{
			if (word[i] == guessedLetter) {
				contained = true;

			}
		}
		if (!contained) {
			guessNum++;
		}
		else {
			correctLetters++;
		}
		if (guessNum > 4) {
			lost = true;
			break;
		}

		showGallows(6 - guessNum);
		showSolved(word, guess);

		if (correctLetters == 6) {
			break;
		}

		choicenum++;
	}

	if (lost) {
		showGallows(0);
		cout << "Sorry, you lose :( \n";
	}
	else {
		cout << "Congrats!! You won! \n";
	}

	return 0;
}

