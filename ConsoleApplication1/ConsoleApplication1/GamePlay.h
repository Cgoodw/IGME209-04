#pragma once
#include <string>
class GamePlay
{
public:
	std::string name;
	GamePlay(std::string n);
	~GamePlay();
	void Update();
};

