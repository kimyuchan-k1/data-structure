#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;
typedef int Data;
const int SEARCH_FAILED = -1000000;

class Node {
	Data data;
	Node* next;
	Node(Data d = 0, Node* n = NULL) {
		data = d; next = n;
	}

	friend class LinkedList;
};

class LinkedList {
private:
	Node* head;
	int length;
	virtual int Key(Data d) { return d; }
	void Search(Node*n,int key) {
		if (n == NULL) {
			n = head; cout << "Not found";
			return;
		}
	if (Key(n->data) == key) {
		cout << "Found"; return;
		}
	return Search(n->next, key);
	}
public:
	LinkedList() { head = NULL; length = 0; }
	void InsertPos(int pos, Data d);
	Data DeletePos(int pos);
	Data PeekPos(int pos);
	Data Delete(int key);
	void Search(int key);
	void PrintData(Data d);
	void PrintList();
	bool IsEmpty() { return head == NULL; }
	int Length() { return length; }
	bool Same();

};