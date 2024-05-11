#pragma once

#include <iostream>
#include <cstdlib>

using namespace std;

const int STACK_SIZE = 100;
typedef int Data;



class Stack {

	Data data[STACK_SIZE];
	int top;
public:
	Stack() { top = -1; } //Stack 선언시 top 은 -1로 초기화를 한다.
	void Push(Data d);
	Data Pop();
	Data Peek();
	void Clear();
	void Replace(Data d);
	bool IsEmpty() { return top == -1; }
	bool IsFull() {return top == STACK_SIZE - 1;}

	void PrintStack();

	int Length() { return top +1; }
};