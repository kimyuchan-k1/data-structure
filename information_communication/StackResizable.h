#pragma once
#include<iostream>
#include <cstdlib>
using namespace std;
typedef int Data;


class StackResizable {
	Data* data;
	int top;
	int stackSize;
	bool IsFull() { return top == stackSize - 1; }
	void IncreaseStackSize();

public:
	StackResizable();
	void Push(Data d);
	Data Pop();
	Data Peek();
	bool IsEmpty() { return top == -1; }
	int Length() { return top + 1; }
};
