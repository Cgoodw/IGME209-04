// ConsoleApplication10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;

class MovableObject
{
public:
	int xPos;
	int yPos;
	void PrintPos()
	{
		cout << "X:" << xPos << " Y:" << yPos << endl;
	}
};

class Player : public MovableObject
{
public:
	char* name;
	Player()
	{
		cout << "player ctor" << endl;
		name = new char[15];
	}

	~Player()
	{
		cout << "player dtor" << endl;
		delete[] name;
	}
};

class Monster : public MovableObject
{
public:
	int damage;
};

int main()
{
	//Monster *boss = new Monster();
	//Player *pOne = new Player();

	//Player is not deleted if it's set as a moveableObj
	MovableObject *boss = new Monster();
	MovableObject *pOne = new Player();

	Monster *fakeMonster = (Monster*)pOne;


	// add code here
	//Addresses
	cout << "pOne address:        " << (void *)pOne << "\n";
	cout << "boss address:        " << (void *)boss << "\n";
	cout << "fakeMonster address: " << (void *)fakeMonster << "\n";

	//positions
	pOne->xPos = 10;
	pOne->yPos = 12;

	boss->xPos = 5;
	boss->yPos = 6;

	fakeMonster->xPos = 3;
	fakeMonster->yPos = 5;


	//print
	pOne->PrintPos();
	boss->PrintPos();
	fakeMonster->PrintPos();






	delete boss;
	delete pOne;
	
	// already deleted
	//delete fakeMonster;
	
	

	_getch();
    return 0;
}

