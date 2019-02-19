// PE8Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>


void changeVariable(int x) {
	x += 5;
	std::cout << "X's value is " << x << "\n";
}
void changePointer(int* x) {
	*x = 10;
	std::cout << "X's location is " << x << " and has been changed \n";
}

int getLengthArray(int a[]) {

	int e = 0;
	int count = 0;
	while (e != -1) {
		e = a[count];
		count++;
	}

	return count;
}

int getLengthPointer(int* z) {
	int f = 0;
	while (*z++) {
		f++;
	}
	return f;
}


int* createStackArray() {
	int data[5] = {0,1,2,3,4};
	return data;
}

int* createHeapArray(int length) {
	int* heapData= new int[length];

	for (size_t i = 0; i < length; i++)
	{
		heapData[i] = i;
	}
	return heapData;

}


int main()
{
	int x = 1;
	int arr[10] = {1, 2, 5, 6, 3, 2, 1, 9, -1 };
	int* point = arr;


    std::cout << "X is " << x << "\n";
	changeVariable(x);
	changePointer(&x);
	std::cout << "X is " << x << "\n";;
	//The first change changes the actual variable and the data it refers to
	//The second change changes the data at the address of memory that the variable points to

	std::cout << "------------------ \n";

	std::cout <<"Pointer as array \n";
	std::cout << getLengthArray(point)<<"\n";
	std::cout << "array as pointer \n";
	std::cout << getLengthPointer(arr) << "\n";

	std::cout << "------------------ \n";

	int* s = createStackArray();
	int* h = createHeapArray(5);

	std::cout << "Stack array \n";
	for (size_t i = 0; i < 5; i++)
	{
		std::cout << s[i];
	}
	std::cout << "\n";
	std::cout << "Heap array \n";
	for (size_t v = 0; v < 5; v++)
	{
		std::cout << h[v];
	}

	//the code in the stack is absolutely incorrect, it is negative too
	//this is due to it going out of scope because the stack can't allocate all the memory


	delete[] h;

	return 0;
}

