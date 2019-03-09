#pragma once
#include "Item.h"
class Battery :
	public Item
{
public:
	Battery(std::string, int, int);
	~Battery();
};

