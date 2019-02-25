#pragma once
class Player
{
private:
	char*name;
	int strength;
	int health;
	int speed;

public:
	Player();
	Player(char* , int, int, int);
	~Player();
	void printPlayer();

};

