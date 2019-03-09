#include "pch.h"
#include "Fighter.h"
#include <iostream>

Fighter::Fighter()
{
	weaponSkill = 10;
}

Fighter::Fighter(char * n, int ws, int st, int sp, int hp)
:Player(n, st, sp, hp)
{
	weaponSkill = ws;
}


Fighter::~Fighter()
{
}

void Fighter::printFighter()
{
	printPlayer();
	std::cout << "Weapon Skill: " << weaponSkill << "\n";
}
