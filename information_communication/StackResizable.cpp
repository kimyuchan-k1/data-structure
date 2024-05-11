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
	Data* old = data; //������ data �� old Data�� ������. ���
	stackSize *= 3;
	data = new Data[stackSize];
	for (int i = 0; i <= top; i++) {
		data[i] = old[i];  //��� �����͸� �ٽ� �ٿ��ֱ�
	}

	delete[] old; //��� �����ʹ� ����
	
	cout << "Stack size = " << stackSize << endl;

}