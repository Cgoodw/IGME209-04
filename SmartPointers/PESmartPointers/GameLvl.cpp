#include "stdafx.h"
#include "GameLvl.h"
#include <iostream>
#include <memory>



GameLvl::GameLvl()
{
	int lvlNum = 2;
	int difficulty = 5;
	int enemies[3] = {1, 3, 0};
	std::cout << "Created Level";
}


GameLvl::~GameLvl()
{
	std::cout << "Destroyed Level";
}
