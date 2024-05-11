#pragma once
#include <iostream>
#include<cstdlib>
#include <stdlib.h>

using namespace std;

const int QUEUE_SIZE = 100;
typedef int Data;


class Queue {
protected:
	Data data[QUEUE_SIZE];
	int front, rear;
	int length;   // 큐에는 length를 지정해주어야함.
public:
	Queue() { front = 0; rear = -1; length = 0; }
	void Insert(Data d);
	Data Delete();
	Data Peek();
	bool IsEmpty() { return length == 0; }
	bool IsFull() { return length == QUEUE_SIZE; }
	void PrintQueue();
	void PrintBuffer();
	int Length() { return length; }



};

