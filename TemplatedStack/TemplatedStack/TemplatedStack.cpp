// TemplatedStack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "TempStack.h"
int main()
{
	TempStack<int> stck;

	if (stck.IsEmpty()) {
		cout << "List is Empty";
	}
	else {
		cout << "List is not Empty";
	}
	cout << endl;

	stck.Push(1);
	stck.Print();
	stck.Pop();

	if (stck.IsEmpty()) {
		cout << "List is Empty";
	}
	else {
		cout << "List is not Empty";
	}
	cout << endl;

	stck.Push(1);
	stck.Push(2);
	stck.Push(3);
	stck.Pop();

	if (stck.IsEmpty()) {
		cout << "List is Empty";
	}
	else {
		cout << "List is not Empty";
	}
	cout << endl;

	stck.Print();
}
