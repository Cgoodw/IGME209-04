// HelloWorld.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> 

void main()
{
	int sec = 0;
	double area = 0;
	int result = 0;


	std::cout << "Hello, world!\n";

	//    Day  Hr   Min   Sec
	sec = 31 * 24 * 60 * 60;

	//pi r^2
	area = 3.14159*6.2*6.2;

	//int division test
	//answer is 3.333 repeating
	//round would go to 3 
	result = 10 / 3;

	printf("Seconds in December: %d \n", sec);
	printf("Area of circle with 6.2 radius: %f \n", area);
	printf("Integer division test %d \n", result);
}

