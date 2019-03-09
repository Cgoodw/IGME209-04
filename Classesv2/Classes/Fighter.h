#pragma once
#include "Player.h"
class Fighter :
	public Player
{
public:
	Fighter();
	Fighter(char*, int, int, int, int);
	~Fighter();
	void printFighter();
	
private:
	int weaponSkill;
};

