#include "Stackex1.h"

static void Error(string s) { cerr << s; exit(-1); }

void Stack::Push(string n, int i) {
	if (IsFull()) { Error("Stack is Full"); }
	name[++top] = n;
	id[top] = i;
	
}

void Stack::Pop() {
	if (IsEmpty()) Error("Stack is Empty");
	
	cout << "name = " << name[top+1] << ", id = " << id[top--]<<endl;
}


void Stack::Peek() {
	if (IsEmpty()) Error("Stack is Empty");
	cout << "name = " << name[top] << ", id = " << id[top]<<endl;

}
