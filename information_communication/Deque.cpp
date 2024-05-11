#pragma once
#include "Deque.h"
static void Error(string s) { cerr << s;exit(-1); }


void Deque::InsertFront(Data d) {
	if (IsFull()) Error("Queue is full");

	front = (front - 1 + QUEUE_SIZE) % QUEUE_SIZE;
	data[front] = d;
	length++;


}

Data Deque::DeleteRear() {
	if (IsEmpty()) { Error("Queue is empty"); }
	Data out = data[rear];
	rear = (rear - 1 + QUEUE_SIZE) % QUEUE_SIZE;
	length--;
	return out;
}

Data Deque::PeekRear() {
	if (IsEmpty()) Error("Queue si empty");
	return data[rear];
}