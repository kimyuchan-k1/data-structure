#include "ArrayTree.h"


static void Error(string s) { cerr << s; exit(-1); }

ArrayTree::ArrayTree() {
	for (int pos = 1; pos < TREE_SIZE; pos++)
		data[pos] = NONE;
	// 모든 공간에 none 을 할당함 ""
}


bool ArrayTree::IsNone(int pos) {
	return pos <= 0 || pos >= TREE_SIZE || data[pos] == NONE;
}


bool ArrayTree::IsLeaf(int pos) {
	if (IsNone(pos)) return false;
	int left = pos * 2, right = pos * 2 + 1; //자식 pos 입력
	return IsNone(left) && IsNone(right); //자식 둘 다 none 일경우 에 True를 반환한다.
}


void ArrayTree::InsertPos(int pos, Data d) {
	// 삽입하는 자리가 0 보다 작거나 tree size 보다 크거나 혹은 부모가 아니지만 부모가 없는 경우
	if (pos <= 0 || pos >= TREE_SIZE || (pos != ROOT && IsNone(pos / 2))) Error("Cannot insert");
	data[pos] = d;
	
}

Data ArrayTree::DeletePos(int pos) {
	//예외 ! 2가지 해당하는 pos 에 제거할 값이 없거나 리프노드가 아닌경우
	if (IsNone(pos) || !IsLeaf(pos)) Error("Cannot Delete");
	Data d = data[pos]; data[pos] = NONE;
	return d;
}

Data ArrayTree::Peekpos(int pos) {
	//예외: 값이 없는 경우
	if (IsNone(pos)) Error("Cannot Peek");
	return data[pos];
}

int ArrayTree::NumNode(int pos) {
	if (IsNone(pos)) return 0; //  no node
	int left = pos * 2, right = pos * 2 + 1;
	return 1 + NumNode(left) + NumNode(right);
}

int ArrayTree::NumLeaf(int pos) {
	if (IsNone(pos)) return 0;
	if (IsLeaf(pos)) return 1;
	int left = pos * 2, right = pos * 2 + 1;
	return NumLeaf(left) + NumLeaf(right);

}


int ArrayTree::Height(int pos) {
	//none 일 경우 0 반환 하는 탈출 문
	if (IsNone(pos)) return 0;
	int left = pos * 2, right = pos * 2 + 1;
	return 1 + max(Height(left), Height(right));
}


void ArrayTree::PrintTree() {
	for (int pos = 1; pos <= TREE_SIZE; pos++) {
		if (IsNone(pos)) continue;
		int left = pos * 2, right = pos * 2 + 1;
		int childNum = !IsNone(left) + !IsNone(right);
		cout << "node " << pos << " value = " << data[pos] << ", # of children = " << childNum;
	}

}

void ArrayTree::PrintLevelOrder() {
	int numNode = NumNode(); //총 노드 개수
	for (int level = 1; numNode > 0; level++) {
		//level 1부터 시작
		cout << "Level " << level << ": ";
		int  length = 1 << (level - 1); 
		int pos = length;
		for (; pos < length * 2; pos++) {
			if (IsNone(pos) == false) {
				cout << data[pos] << " ";
				numNode--;
			}


		}
		cout << endl;

	}

}

