#include "pch.h"
#include "TempStack.h"

//template <class T>
//TempStack<T>::TempStack()
//{
//	data = new T[1];
//}
//
//template <class T>
//void TempStack<T>::Print() {
//	for (size_t i = 0; i < entries; i++)
//	{
//		cout << data[i]<< endl;
//	}
//}
//
//template<class T>
//int TempStack<T>::GetSize()
//{
//	return entries;
//}
//
//template<class T>
//void TempStack<T>::Pop()
//{
//	for (size_t i = 1; i < entries; i++)
//	{
//		data[i - 1] = data[i];
//	}
//	entries--;
//}
//
//template<class T>
//void TempStack<T>::Push(T input)
//{
//	if (entries + 1 > size) {
//		dataPlace = new T[size * 2];
//		for (size_t i = 0; i < entries; i++)
//		{
//			dataPlace[i] = data[i];
//		}
//		delete[] data;
//		data = dataPlace;
//		delete[] dataPlace;
//	}
//
//	for (size_t i = 0; i < entries; i++)
//	{
//		data[i + 1] = data[i];
//	}
//	data[0] = input;
//	entries++;
//}
//
//template<class T>
//bool TempStack<T>::IsEmpty()
//{
//	return entries==0;
//}
//
//template <class T>
//TempStack<T>::~TempStack()
//{
//	delete[] data;
//	cout << "deleted";
//}
//