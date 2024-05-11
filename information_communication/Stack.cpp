#include "Stack.h"

static void Error(string s) { cerr << s; exit(-1); }  //Error(string) 은 string을 err message 로 보여주고 탈출한다.


void Stack::Push(int d) {
	if (IsFull()) Error("Stack is full");
	data[++top] = d;
}



Data Stack::Pop(){ 
	if (IsEmpty()) { Error("Stack is empty"); }
	
	return data[top--];
}

Data Stack::Peek() {
	if (IsEmpty()) Error("Stack is empty");
	return data[top];

}

void Stack::PrintStack() {
	cout << "Stack: ";
	for (int i = 0; i <= top; i++) {
		cout << data[i] << " ";
	}
	cout << endl;

}

void Stack::Clear() {
	
	top = -1;


}

void Stack::Replace(Data d) {
	data[top] = d;

}