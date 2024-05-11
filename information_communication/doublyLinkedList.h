#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;
typedef int Data;


struct Node {
	Data data;
	Node* next; Node* prev;
	Node(Data d = 0, Node* n = NULL, Node* p = NULL) { data = d; next = n; prev = p; }

};


class DoublyLinkedList {
protected:
	Node* head;
	Node* tail;

public:
	DoublyLinkedList() { head = tail = NULL; }
	void InsertFront(Data d);
	void InsertRear(Data d);
	Data DeleteFront();
	Data DeleteRear();
	Data PeekFront();
	Data PeekRear();
	void PrintList();
	bool IsEmpty() { return head == NULL; }

};