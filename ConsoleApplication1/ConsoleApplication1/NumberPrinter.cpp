#include "pch.h"
#include "NumberPrinter.h"
#include <iostream>

NumberPrinter::NumberPrinter(int x)
{
	number = x;
}


NumberPrinter::~NumberPrinter()
{
}

void NumberPrinter::Print() {
	std::cout << number << " ";
}