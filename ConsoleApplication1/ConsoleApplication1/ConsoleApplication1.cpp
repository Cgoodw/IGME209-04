// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "NumberPrinter.h"
#include <thread>
#include <vector>
#include "GamePlay.h"
int main()
{
	for (size_t i = 0; i < 10; i++)
	{
		NumberPrinter x(5);
		
		//x.Print();
		std::thread thread(&NumberPrinter::Print,x);
		thread.join();
		std::thread threada(&NumberPrinter::Print, x);
		threada.join();
		std::thread threadb(&NumberPrinter::Print, x);
		threadb.join();
		std::thread threadc(&NumberPrinter::Print, x);
		threadc.join();
		std::thread threadd(&NumberPrinter::Print, x);
		threadd.join();
		//---------------------------------------------------------------

	}
	GamePlay phx("Physics");
	GamePlay par("Particles");
	GamePlay vfx("FX");
	GamePlay pat("Pathfinding");
	GamePlay gen("Generation");

	std::vector<std::thread*> list;

	std::thread threadPH(&GamePlay::Update, phx);
	list.push_back(&threadPH);
	threadPH.join();
	std::thread threadPA(&GamePlay::Update, par);
	list.push_back(&threadPA);
	threadPA.join();
	std::thread threadVF(&GamePlay::Update, vfx);
	list.push_back(&threadVF);
	threadVF.join();
	std::thread threadPT(&GamePlay::Update, pat);
	list.push_back(&threadPT);
	threadPT.join();
	std::thread threadGE(&GamePlay::Update, gen);
	list.push_back(&threadGE);
	threadGE.join();

	std::cout << "Update Complete- Time to Draw!";

}
