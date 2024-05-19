#pragma once
#include<iostream>
#include<cstdlib>

using namespace std;
const int SEARCH_FAILED = -10000000;
typedef int Data;

class Node {
	Data data;
	Node* left;
	Node* right;
	Node(Data d = 0, Node* l = NULL, Node* r = NULL) {
		data = d;
		left = l;
		right = r;

	}

	friend class BinarySearchTree;
	
};


class BinarySearchTree {
protected:
	int Key(Data d) { return d; }
	Node* Insert(Node* n, Data d);
	Data Search(Node* n, int key);
	void DeleteNode(Node* parent, Node* n);
	void PrintInorder(Node* n);
	
public:
	Node* root;
	BinarySearchTree() : root(NULL){} //root의 초기화
	void Insert(Data d) { root = Insert(root, d); }
	Data Search(int key) { return Search(root, key); }
	Data Delete(int key);
	void PrintData(Data d);
	void PrintInorder() { PrintInorder(root); }
	void InsertPos(int pos, Data d) { cout << "InsertPos() is no longer supported" << endl; }

	
};