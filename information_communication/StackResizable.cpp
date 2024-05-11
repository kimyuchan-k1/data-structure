#include "StackResizable.h"

void Error(string s) { cerr << s; exit(-1); }


void StackResizable::Push(Data d)
{
	data[++top] = d;
	if (IsFull()) IncreaseStackSize();

}

Data StackResizable::Pop() {
	if (IsEmpty()) Error("Stack is Empty");
	return data[top--];
}

Data StackResizable::Peek() {
	return data[top];
}

StackResizable::StackResizable() {
	top = -1;
	stackSize = 3;
	data = new Data[stackSize];
	cout << "Stack size = " << stackSize << endl;
}

void StackResizable::IncreaseStackSize() {
	Data* old = data; //기존의 data 를 old Data에 복사함. 백업
	stackSize *= 3;
	data = new Data[stackSize];
	for (int i = 0; i <= top; i++) {
		data[i] = old[i];  //백업 데이터를 다시 붙여넣기
	}

	delete[] old; //백업 데이터는 삭제
	
	cout << "Stack size = " << stackSize << endl;

}