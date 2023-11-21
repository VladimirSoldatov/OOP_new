#include "Array.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <conio.h>
using namespace std;
// конструктор (по умолчанию — 10 элементов)
Array::Array(int aSize)
	: size{ aSize }, arr{ new int[size] {} }
{}
// конструктор копирования
Array::Array(const Array& a)
{
	for (int i = 0; i < size; ++i)
	{
		arr[i] = a.arr[i];
	}
}

// деструктор
Array::~Array()
{
	delete[] arr;
}
// размер файла
int Array::length() const
{
	return size;
}
// оператор присвоения
const Array& Array::operator=(const Array& a)
{
	if (&a != this)
	{
		if (size != a.size)
		{
			delete[] arr;
			size = a.size;
			arr = new int[size];
		}
		for (int i = 0; i < size; ++i)
		{
			arr[i] = a.arr[i];
		}
	}
	return *this;
}
// оператор сравнения
bool Array::operator==(const Array& a) const
{
	if (size != a.size)
	{
		return false;
	}
	for (int i{ 0 }; i < size; ++i) {
		if (arr[i] != a.arr[i]) {
			return false;
		}
	}
	return true;
}
// оператор индексирования
int& Array::operator[](int index)
{
	if (index < 0 || index >= size)
	{
		cout << "Out of range" << endl;
		_getch();
		exit(1);
	}
	return arr[index];
}
// оператор индексирования (get)
int Array::operator[](int index) const
{
	if (index < 0 || index >= size)
	{
		cout << "Out of range" << endl;
		_getch();
		exit(1);
	}
	return arr[index];
}
// оператор ввода
istream& operator>>(istream& input, Array& a)
{
	for (size_t i{ 0 }; i < a.size; ++i) {
		input >> a.arr[i];
	}
	return input;
}
// оператор вывода
ostream& operator<<(ostream& output, const Array& a)
{
	for (int i{ 0 }; i < a.size; ++i) {
		output << a.arr[i] << " ";
	}
	output << endl;
	return output;
}