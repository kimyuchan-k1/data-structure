#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;
typedef int Data;

struct Node {
	Data data;
	Node* left;
	Node* right;
	Node(Data d = 0, Node* l = NULL, Node* r = NULL) {
		data = d; left = l; right = r;
	}
	bool IsLeaf() {
		return left == NULL && right == NULL;
	}
};


class BinaryTree {
protected:
	Node* root;
	Node* InsertPos(Node* n, int path, Data d);
	Data DeletePos(Node* n, int path);
	Data PeekPos(Node* n, int path);
	int NumNode(Node* n);
	int NumLeaf(Node* n);
	int Height(Node* n);
	void PrintInorder(Node* n);
	void PrintPreorder(Node* n);
	void PrintPostorder(Node* n);
public:
	BinaryTree() { root = NULL; }
	void InsertPos(int pos, Data d);
	Data DeletePos(int pos, Data d);
	Data PeekPos(int pos);
	int NumNode() { return NumNode(root); }
	int NumLeaf() { return NumLeaf(root); }
	int Height() { return Height(root); }
	void PrintInorder() {
		PrintInorder(root); cout << endl;
	}
	void PrintPreorder() {
		PrintPreorder(root); cout << endl;
	}
	void PrintPostorder() {
		PrintPostorder(root); cout << endl;
	}

	void PrintLevelOrder();


};