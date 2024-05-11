#pragma once
#include <iostream>
#include <cstdlib>
using  namespace std;
const int SEARCHE_FAILED = -1000000;
typedef int Data;

class Node {
	Data data;
	Node* next;
	Node(Data d = 0, Node* n = NULL) {
		data = d; next = n;
	}
	friend class SortedLinkedList;
};

class SortedLinkedList {
protected:
	Node head;
	virtual int Key(Data d) { return d; }
public:
	SortedLinkedList() { head = Node(0, NULL); }
	void Insert(Data d);
	Data Delete(int key);
	Data DeleteFront();
	Data Search(int key);
	void PrintList();
	bool IsEmpty() { return head.next == NULL; }
	void PrintData(Data d);
	int Length() { return head.data; }

};
