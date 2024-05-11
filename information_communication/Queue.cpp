
#pragma once
#include "Queue.h"
static void Error(string s) { cerr << s; exit(-1); }


void Queue::Insert(Data d) {
	if (IsFull()) Error("Queue is full");
	rear = (rear + 1) % QUEUE_SIZE;
	data[rear] = d;
	length++;
}

Data Queue::Delete() {
	if (IsEmpty()) Error("Queue is Empty");
	Data out = data[front];
	front = (front + 1) % QUEUE_SIZE; 
	length--;
	return out;

}

Data Queue :: Peek()
{
	if (IsEmpty()) Error("Queue is Empty");
	return data[front];
	
}

void Queue::PrintQueue() {
	cout << "Queue: ";
	for (int i = 0; i < length; i++) {
		cout << data[(front + i) % QUEUE_SIZE];
		cout << " ";

	}

	cout << endl;
}

