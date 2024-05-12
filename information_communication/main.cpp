#pragma once
#include "WinnerTree.h"
#include <iostream>
#include <cstdlib>


// Linked list 에 key 값을 포함하고 있는지 아닌지 판별하는 void Search(int key) 함수를 recursion 형태로 추가하라.
// 포함되어 있으면 "Found" 아니면 "Not Found" 를 출력. Recursion으로 동작시키기 위하여 private 영역에 void Search(Node*n, int key)를 포함 시킨다.
// n 이 NULL 인지 n-> data 가 key 인지 검사한 후 자기 자신을 호출

//linkedlist 형태로 stack 구현하기  stack 구현하려면 front 에서 넣고 front 에서 빼면된다.  stack push와 pop



//퀵정렬은 pivot 을 기준으로 정렬해 나가는 방식 피벗보다 크면 오른쪽 피벗보다 작으면 왼쪽으로 정렬
// 여기서 pivot은 왼쪽 요소로 정했는데 pivot 은 아무 것이나 지정하여도 상관없다.






//마찬가지로 quick select 도 할 수 있다. ---> select한 k값이 피벗보다 작다면 왼쪽영역 크다면 오른쪽 영역


//Winner Tree 생성 Tree 구조를 적용!  1. 자료구조 tree 2. 






int main()
{
	//list 의 순서 변경
	int a[LIST][SIZE + 1] = { {24,12,4,INF},{22,15,3,INF} ,{19,14,6,INF }
	,{21,9,1,INF },{23,11,8,INF },{17,10,5,INF },{16,13,2,INF },{20,18,7,INF } };

	MergeUsingWinnerTree w(a);
	for (int i = 0; i < LIST * SIZE;i++) {
		cout << w.DeleteWinner(a) << " ";
	}

	
	 
}






