#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;
const int SIZE = 100;
void Error(string s) { cerr << s; exit(-1); }

template <typename Data>

class StackTemplate {
	Data data[SIZE];
	int top;
public:
	StackTemplate() { top = -1; }
	void Push(Data d) {
		if (IsFull()) Error("Stack is full");
		data[++top] = d;
	}

	Data Pop() {
		if (IsEmpty()) Error("Stack is Empty");
		return data[top--];
	}

	Data Peek() {
		if (IsEmpty()) Error("Stack is Empty");
		return Data[top];
	}

	bool IsEmpty() { return top == -1; }
	bool IsFull() {
		return top == SIZE - 1;
	}
	void PrintStack() {
		for (int i = 0; i <= top; i++) {
			cout << data[i] << endl;
		}
		cout << endl;
	}

	int Length() { return top + 1; }
};



