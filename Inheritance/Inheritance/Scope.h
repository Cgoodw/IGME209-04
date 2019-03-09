#pragma once
#include "Item.h"
class Scope :
	public Item
{
	using Item::Item;
public:
	Scope();
	~Scope();
};

