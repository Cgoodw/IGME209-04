 // Theater.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
#include <conio.h>
#include <chrono>
#include <ctime>
#include <ratio>

int iter(int n) {
	int x = 0;
	while (n != 0) {
		if (n % 2 == 0) {
			x += 4;
		}
		else {
			x += 3;
		}
		n--;
	}
	return x;
}

int recur(int n) {
	if (n==0) {
		return 0;
	}
	else {
		if (n % 2 == 0) {
			return recur(n-1)+4;
		}
		else {
			return recur(n-1) + 3;
		}
	}
}

int form(int n) {
	return ((n/2) * 4) + (n-(n/2)) * 3;
}

int main()
{
	using namespace std::chrono;

	high_resolution_clock::time_point t1 = high_resolution_clock::now();
    std::cout << "Alien Theater \n"; 
	std::cout << iter(10) << "\n";
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
	std::cout << "Iteration took  " << time_span.count() << " seconds." << "\n";

	t1 = high_resolution_clock::now();
	std::cout << recur(10) << "\n";
	t2 = high_resolution_clock::now();
	time_span = duration_cast<duration<double>>(t2 - t1);
	std::cout << "Recursion took  " << time_span.count() << " seconds." << "\n";



	t1 = high_resolution_clock::now();
	std::cout << form(10) << "\n";
	t2 = high_resolution_clock::now();
	time_span = duration_cast<duration<double>>(t2 - t1);
	std::cout << "The formula took  " << time_span.count() << " seconds." << "\n";


	_getch();
}
