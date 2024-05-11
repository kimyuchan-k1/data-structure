#include "SortedLinkedList.h"



#define DELETE(a) {Node*temp =a; a = a->next; delete temp;}

Data SortedLinkedList::Search(int key)
{
	Node* p = head.next;
	for (;p != NULL;p = p->next) {
		if (Key(p->data) > key) break;
		if (Key(p->data) == key) return p->data;
	}
	cout << key << "is not found" << endl;
	return  SEARCHE_FAILED;

}


void SortedLinkedList::PrintList()
{
	cout << "[head] => ";
	Node* p = head.next;
	for (;p != NULL;p = p->next)
		cout << p->data << " => ";
	cout << "[null]" << endl;

}


void SortedLinkedList::PrintData(Data d)
{
	if (Key(d) != SEARCHE_FAILED)
		cout << Key(d) << "is found" << endl;
}


Data SortedLinkedList::DeleteFront()
{
	Data d = head.next->data;
	DELETE(head.next); head.data--;
	return d;

}

Data SortedLinkedList::Delete(int key)

{
	Node* p = &head;
	for (;p->next != NULL; p = p->next) {
		if (Key(p->next->data) > key) break;
		if (Key(p->next->data) == key) {
			Data d = p->next->data;
			DELETE(p->next); head.data--;
			return d;
		}
	}

	cout << key << "is not found" << endl;
	return SEARCHE_FAILED;

}

void SortedLinkedList::Insert(Data d)
{
	Node* p = &head;
	for (;p->next != NULL;p = p->next) {
		if (Key(p->next->data) > Key(d)) break;

	}

	p->next = new Node(d, p->next);
	head.data++;
}
