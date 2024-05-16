#pragma once
#include "BinaryTree.h"
const int SEARCH_FAILED = -10000000;



class BinarySearchTree:public BinaryTree {
protected:
	int Key(Data d) { return d; }
	Node* Insert(Node* n, Data d);
	Data Search(Node* n, int key);
	void DeleteNode(Node* parent, Node* n);

	
public:
	void Insert(Data d) { root = Insert(root, d); }
	Data Search(int key) { return Search(root, key); }
	Data Delete(int key);
	void PrintData(Data d);
	void InsertPos(int pos, Data d) { cout << "InsertPos() is no longer supported" << endl; }

};