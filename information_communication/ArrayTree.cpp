#include "ArrayTree.h"


static void Error(string s) { cerr << s; exit(-1); }

ArrayTree::ArrayTree() {
	for (int pos = 1; pos < TREE_SIZE; pos++)
		data[pos] = NONE;
	// ��� ������ none �� �Ҵ��� ""
}


bool ArrayTree::IsNone(int pos) {
	return pos <= 0 || pos >= TREE_SIZE || data[pos] == NONE;
}


bool ArrayTree::IsLeaf(int pos) {
	if (IsNone(pos)) return false;
	int left = pos * 2, right = pos * 2 + 1; //�ڽ� pos �Է�
	return IsNone(left) && IsNone(right); //�ڽ� �� �� none �ϰ�� �� True�� ��ȯ�Ѵ�.
}


void ArrayTree::InsertPos(int pos, Data d) {
	// �����ϴ� �ڸ��� 0 ���� �۰ų� tree size ���� ũ�ų� Ȥ�� �θ� �ƴ����� �θ� ���� ���
	if (pos <= 0 || pos >= TREE_SIZE || (pos != ROOT && IsNone(pos / 2))) Error("Cannot insert");
	data[pos] = d;
	
}

Data ArrayTree::DeletePos(int pos) {
	//���� ! 2���� �ش��ϴ� pos �� ������ ���� ���ų� ������尡 �ƴѰ��
	if (IsNone(pos) || !IsLeaf(pos)) Error("Cannot Delete");
	Data d = data[pos]; data[pos] = NONE;
	return d;
}

Data ArrayTree::Peekpos(int pos) {
	//����: ���� ���� ���
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
	//none �� ��� 0 ��ȯ �ϴ� Ż�� ��
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
	int numNode = NumNode(); //�� ��� ����
	for (int level = 1; numNode > 0; level++) {
		//level 1���� ����
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

