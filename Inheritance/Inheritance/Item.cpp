#include "pch.h"
#include "Item.h"
#include <iostream>

Item::Item(std::string n, int d, int w)
{
	name = n;
	damage = d;
	weight = w;
}


Item::~Item()
{
}

void Item::print()
{
	std::cout << "Name: " << name.c_str()<< "\n";
	std::cout << "Damage: " << damage << "\n";
	std::cout << "Weight: " << weight << "\n";
}
