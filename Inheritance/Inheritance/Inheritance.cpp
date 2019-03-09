#include "pch.h"
#include <iostream>
#include <vector>
#include "Item.h"
#include "Laser.h"
#include "Scope.h"
#include "Battery.h"
#include "Mask.h"
using namespace std;
int main()
{
	Laser laser("laser", 5, 3);
	Scope scope("scope", 2, 1);
	Battery battery("battery", 5, 10);
	Mask mask("mask", 3, 10);

	Laser *laserp;
	Scope *scopep;
	Battery *batteryp;
	Mask *maskp;

	laserp = &laser;
	scopep = &scope;
	batteryp = &battery;
	maskp = &mask;


	vector<Item*> inventory;

	inventory.push_back(laserp);
	inventory.push_back(scopep);
	inventory.push_back(batteryp);
	inventory.push_back(maskp);


	for (size_t i = 0; i < inventory.size(); i++)
	{
		inventory[i]->print();
	}

}
