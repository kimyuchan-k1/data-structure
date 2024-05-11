#pragma once
#include "Queue.h"


class Deque : public Queue {
public:
	Deque() { rear = QUEUE_SIZE - 1; }
	void InsertFront(Data d);
	void InsertRear(Data d) { Insert(d); }
	Data DeleteFront() { return Delete(); }
	Data DeleteRear();
	Data PeekFront() { return Peek(); }
	Data PeekRear();
};