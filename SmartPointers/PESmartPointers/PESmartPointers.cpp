// PESmartPointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <memory>
#include <conio.h>
#include "GameLvl.h"

//Also add your checks for memory leaks to the end of the main program
void makeLvl() {
	GameLvl* notSLevel = new GameLvl();
}
void makeLvlS() {
	std::shared_ptr<GameLvl> sLevel(new GameLvl());
}

int main()
{
	//normal pointer
	//makeLvl();
	//memory leaks, destructor not called


	makeLvlS();
	//destructor is called

	_getch();
    return 0;
}

