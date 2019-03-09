#pragma once
#include "Item.h"
class Battery :
	public Item
{
	using Item::Item;
public:
	Battery();
	~Battery();
};

