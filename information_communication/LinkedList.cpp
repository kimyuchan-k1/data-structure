#include "LinkedList.h"

static void Error(string s) { cerr << s; exit(-1); }

#define DELETE(a) {Node*temp=a; a=a->next; delete temp;}


void LinkedList::PrintList()
{
	cout << "[head] => ";
	for (Node* p = head; p != NULL; p = p->next) {
		cout << p->data << " => ";
	}
	cout << "[null]" << endl;
}

void LinkedList::PrintData(Data d)
{
	if (Key(d) != SEARCH_FAILED)
		cout << Key(d) << "is found" << endl;
}

Data LinkedList::PeekPos(int pos) {
	Node* p = head;
	for (int i = 0; p != NULL;p = p->next, i++) {
		if (i == pos) return p->data;
	}
	Error("Illegal position");
}

void LinkedList::InsertPos(int pos, Data d)
{
	length++;
	if (pos == 0)
		head = new Node(d, head);
	else {
		if (IsEmpty()) Error("Illegal position");
		Node* p = head;
		for (int i = 0; p != NULL; p = p->next, i++) {
			if (i == pos - 1) {
				p->next = new Node(d, p->next);
				return;
			}
		}
		Error("Illegal position");
	}
}


Data LinkedList::DeletePos(int pos)
{
	length--;
	if (IsEmpty()) Error("List is empty");
	if (pos == 0)
	{
		Data d = head->data;
		DELETE(head); return d;
	}
	else {
		Node* p = head;
		int i = 0;
		for (;p->next != NULL;p = p->next, i++) {
			if (i == pos - 1) {
				Data d = p->next->data;
				DELETE(p->next); return d;
			}
		}
		Error("Illegal position");
	}
}

Data LinkedList::Delete(int key) {
	if (IsEmpty() == false) {
		if (Key(head->data) == key) {
			Data d = head->data;
			DELETE(head);
			length--; return d;
		}
		Node* p = head;
		for (;p->next != NULL;p = p->next) {
			if (Key(p->next->data) == key) {
				Data d = p->next->data;
				DELETE(p->next);
				length--;
				return d;
			}
		}
	}
	cout << key << "is not found" << endl;
	return SEARCH_FAILED;

}

void LinkedList::Search(int key)
{

	Search(head, key);
	

}

bool LinkedList::Same() {
	if (IsEmpty() || head->next == NULL) { // 노드가 하나거나 비어있는 경우
		return false;
	}

	Node* lastNode = head;

	// 마지막 노드 찾기
	while (lastNode->next != NULL) {
		lastNode = lastNode->next;
	}

	return head->data == lastNode->data;
}