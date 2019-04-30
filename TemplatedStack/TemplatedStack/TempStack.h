#pragma once
#include <iostream>
using namespace std;

template <class T>
class TempStack
{
public:
	TempStack();
	template <class T>
	TempStack<T> &operator=(TempStack<T> &other) {
		if (other == this) {
			return *this;
		}
		else {
			other.data = data;
			other.dataPlace = dataPlace;
		}
		return *this;

	}
	//TempStack(const TempStack& other) {
	//	memcpy(data, other.data,size);
	//}
	void Print();
	int GetSize();
	void Pop();
	void Push(T input);
	bool IsEmpty();
	~TempStack();
private:
	T* data = new T[2];
	T* dataPlace = nullptr;
	int size =2;
	int entries=0;
};

template <class T>
TempStack<T>::TempStack() 
{

}

template <class T>
void TempStack<T>::Print() {

	for (int i = entries-1; i>=0; i--)
	{
		cout << data[i] << "  ";
	}
	cout << endl;
}

template<class T>
int TempStack<T>::GetSize()
{
	return entries+1;
}

template<class T>
void TempStack<T>::Pop()
{
	data[entries-1]=0;
	entries--;
}

template<class T>
void TempStack<T>::Push(T input)
{
	if (entries + 1 >= size) {
		dataPlace = new T[size];

		for (int i = 0; i < entries; i++) {
			dataPlace[i] = data[i];
		}

		delete[] data;
		size *= 2;
		data = new T[size];

		for (int i = 0; i < entries; i++){
			data[i] = dataPlace[i];
		}
		delete[] dataPlace;
	}
	data[entries] = input;
	entries++;
	
}

template<class T>
bool TempStack<T>::IsEmpty()
{
	return entries==0;
}

template <class T>
TempStack<T>::~TempStack()
{
	delete[] data;
	cout << "deleted";
}
