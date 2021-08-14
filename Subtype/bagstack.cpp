#include <algorithm>
#include <iostream>
using namespace std;
#include "bagstack.h"

Bag::Bag(int bagCapacity) : capacity(bagCapacity) {
	if (capacity < 1) throw "Capacity must be >0";
	array = new int[capacity];
	top = -1;
}

Bag::~Bag() { delete[] array; }

inline int Bag::Size() const { return top + 1; }

inline bool Bag::IsEmpty() const { return Size() == 0; }

inline int Bag::Element() const {
	if (IsEmpty()) throw "Bag is empty";
	return array[0];
}
void Bag::Push(const int x) {
	if (capacity == top + 1) {
		ChangeSize1D(array, capacity, capacity * 2);
		capacity = capacity * 2;
	}
	array[++top] = x;
}

void ChangeSize1D(int*& a, const int oldsize, const int newSize)
{
	if (newSize < 0) throw "New length must be >= 0";
	int* temp = new int[newSize];
	int number = std::min(oldsize, newSize);
	std::copy(a, a + number, temp);
	delete[] a;
	a = temp;

}


void Bag::Pop() {
	if (top == -1)throw "Bag is empty. Cannot delete";
	int deletePos = top / 2;
	copy(array + deletePos + 1, array + top + 1, array + deletePos);
	top--;
}

Stack::Stack(int stackCapacity) :Bag(stackCapacity) {}

Stack::~Stack() { }

int Stack::Top() const
{
	if (IsEmpty())throw"Stack is empty.";
	return array[top];
}

void Stack::Pop()
{
	if (IsEmpty())throw"Stack is empty. Cannot delete.";
	top--;
}


ostream& operator<<(ostream& os, Bag& b)
{
	for (int i = 0; i < b.top + 1; i++) {
		os << b.array[i] << " ";
	}
	os << endl;
	return os;
}