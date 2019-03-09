#include "pch.h"
#include "Player.h"
#include <iostream>
Player::Player() {
	name = (char*)"unknown";
	strength = 10;
	speed = 10;
	health = 10;

}

Player::Player(char * n, int st, int sp, int hp)
{
	name = (char*)n;
	strength = st;
	speed = sp;
	health = hp;
}

void Player::printPlayer() {
	std::cout << "Name: " << name << "\n";
	std::cout << "Strength: " << strength << "\n";
	std::cout << "Speed: " << speed << "\n";
	std::cout << "Health: " << health << "\n";
}


Player::~Player()
{
}
