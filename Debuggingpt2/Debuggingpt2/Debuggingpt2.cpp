#include "pch.h"
#include <iostream>
using namespace std;

char* reverseString(char* inputString) {
	char newString[256] = "";
	int len = strlen(inputString);
	for (int i = 0; i < len; i++) {
		char c = inputString[i];
		//subtract extra one due to null terminator
		newString[len - (i+1)] = c;
	}
	//add one for null terminator
	strcpy_s(inputString, sizeof inputString+1,(const char*)&newString);
	return inputString;
}

int main()
{
	char x[20] = "";
	cout << "Enter a string:  ";
	cin >> x;
	char* z= reverseString(x);
	cout << z;
}
