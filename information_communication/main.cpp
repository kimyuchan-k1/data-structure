#pragma once
#include "WinnerTree.h"
#include <iostream>
#include <cstdlib>


// Linked list �� key ���� �����ϰ� �ִ��� �ƴ��� �Ǻ��ϴ� void Search(int key) �Լ��� recursion ���·� �߰��϶�.
// ���ԵǾ� ������ "Found" �ƴϸ� "Not Found" �� ���. Recursion���� ���۽�Ű�� ���Ͽ� private ������ void Search(Node*n, int key)�� ���� ��Ų��.
// n �� NULL ���� n-> data �� key ���� �˻��� �� �ڱ� �ڽ��� ȣ��

//linkedlist ���·� stack �����ϱ�  stack �����Ϸ��� front ���� �ְ� front ���� ����ȴ�.  stack push�� pop



//�������� pivot �� �������� ������ ������ ��� �ǹ����� ũ�� ������ �ǹ����� ������ �������� ����
// ���⼭ pivot�� ���� ��ҷ� ���ߴµ� pivot �� �ƹ� ���̳� �����Ͽ��� �������.






//���������� quick select �� �� �� �ִ�. ---> select�� k���� �ǹ����� �۴ٸ� ���ʿ��� ũ�ٸ� ������ ����


//Winner Tree ���� Tree ������ ����!  1. �ڷᱸ�� tree 2. 






int main()
{
	//list �� ���� ����
	int a[LIST][SIZE + 1] = { {24,12,4,INF},{22,15,3,INF} ,{19,14,6,INF }
	,{21,9,1,INF },{23,11,8,INF },{17,10,5,INF },{16,13,2,INF },{20,18,7,INF } };

	MergeUsingWinnerTree w(a);
	for (int i = 0; i < LIST * SIZE;i++) {
		cout << w.DeleteWinner(a) << " ";
	}

	
	 
}






