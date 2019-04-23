#include "pch.h"
#include "GamePlay.h"
#include <iostream>;

GamePlay::GamePlay(std::string n)
{
	name = n;
}

void GamePlay::Update() {
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << name << ": " << (i * 10) + 10 << "% complete." << std::endl;
	}
}

GamePlay::~GamePlay()
{
}
