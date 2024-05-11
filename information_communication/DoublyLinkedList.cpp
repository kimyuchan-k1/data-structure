#include "doublyLinkedList.h"
static void Error(string s) { cerr << s;exit(-1); }	

void DoublyLinkedList::InsertFront(Data d)
{
	if (IsEmpty())
		head = tail = new Node(d, NULL, NULL);
	else
		head = head->prev = new Node(d, head, NULL); // 빈 공간이 아니라면 head 포인터를 앞으로 빼오고 새로운 노드를 생성한다.

}

void DoublyLinkedList::InsertRear(Data d) {
	if (IsEmpty())
		head = tail = new Node(d, NULL, NULL);
	else
		tail = tail->next = new Node(d, NULL, tail);
}

void DoublyLinkedList::PrintList()
{
	cout << "[head] => ";
	for (Node* p = head; p != NULL; p = p->next)
		cout << p->data << " => ";
	cout << "[null]" << endl << "[tail] => ";
	for (Node* p = tail;p != NULL;p = p->prev)
		cout << p->data << " => ";
	cout << "[null]" << endl;
}

Data DoublyLinkedList::DeleteFront() {
	if (IsEmpty()) Error("List is empty");
	Data d = head->data;
	if (head->next == NULL) {
		delete head; head = tail = NULL;
	}
	else {
		head = head->next;
		delete head->prev;
		head->prev = NULL;
	}
	return d;
}

Data DoublyLinkedList::PeekFront()
{
	if (IsEmpty()) Error("List is empty");
	return head->data;

}


Data DoublyLinkedList::DeleteRear()
{
	if (IsEmpty()) Error("List is  empty");
	Data d = tail->data;
	if (tail->prev == NULL) {
		delete tail; head = tail = NULL;
	}
	else {
		tail = tail->prev;
		delete tail->next;
		tail->next = NULL;
	}
	return d;
}


Data DoublyLinkedList::PeekRear()
{
	if (IsEmpty()) Error("List is empty");
	return tail->data;
}