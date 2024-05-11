#pragma once
#include <iostream>
#include <cstdlib>

using namespace std;
const int STACK_SIZE = 100;


class Stack {
private:
	string name[STACK_SIZE];
	int id[STACK_SIZE];
	int top;
	bool IsFull() { return top == STACK_SIZE - 1; }
	bool IsEmpty() { return top == -1; }

public:
	Stack() { top = -1; }
	void Push(string n, int i);
	void Pop();
	void Peek();
};
