#pragma once
#include <iostream>
struct Item
{
public:
	Item(std::string,int,int);
	~Item();

	void print();

private:
	std::string name;
	int damage;
	int weight;
};

