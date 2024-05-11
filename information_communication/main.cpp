#pragma once
#include "ArrayTree.h"
#include <iostream>
#include <cstdlib>


// Linked list �� key ���� �����ϰ� �ִ��� �ƴ��� �Ǻ��ϴ� void Search(int key) �Լ��� recursion ���·� �߰��϶�.
// ���ԵǾ� ������ "Found" �ƴϸ� "Not Found" �� ���. Recursion���� ���۽�Ű�� ���Ͽ� private ������ void Search(Node*n, int key)�� ���� ��Ų��.
// n �� NULL ���� n-> data �� key ���� �˻��� �� �ڱ� �ڽ��� ȣ��

//linkedlist ���·� stack �����ϱ�  stack �����Ϸ��� front ���� �ְ� front ���� ����ȴ�.  stack push�� pop



//�������� pivot �� �������� ������ ������ ��� �ǹ����� ũ�� ������ �ǹ����� ������ �������� ����
// ���⼭ pivot�� ���� ��ҷ� ���ߴµ� pivot �� �ƹ� ���̳� �����Ͽ��� �������.






//���������� quick select �� �� �� �ִ�. ---> select�� k���� �ǹ����� �۴ٸ� ���ʿ��� ũ�ٸ� ������ ����





int main()
{

	ArrayTree a;
	a.InsertPos(1, "10");
	a.InsertPos(2, "20");
	a.InsertPos(3, "30");
	a.InsertPos(4, "40");
	a.InsertPos(5, "50");
	a.InsertPos(7, "60");
	a.InsertPos(8, "70");
	a.PrintLevelOrder();

	cout << a.Peekpos(5) << " ";
	cout << a.DeletePos(7) << endl;
	cout << a.NumNode() << " " << a.NumLeaf() << endl;
	cout << a.Height();




	

}






