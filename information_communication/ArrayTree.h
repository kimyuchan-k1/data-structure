#pragma once
#include <iostream>
#include <cstdlib>	
#include <string>
using namespace std;

typedef int Data;  //변경내용

const int NONE = 0;  //변경내용
const int ROOT = 1;
const int TREE_HEIGHT = 8;
const int TREE_SIZE = 1 << TREE_HEIGHT;

class ArrayTree {
	Data data[TREE_SIZE];
	int NumNode(int pos);  //#of nodes
	int NumLeaf(int pos);  //# of leaves
	int Height(int pos);
public:
	ArrayTree();
	void InsertPos(int pos, Data d);
	Data DeletePos(int pos);
	Data Peekpos(int pos);
	int NumNode() { return NumNode(ROOT); }
	int NumLeaf() { return NumLeaf(ROOT); }
	int Height() { return Height(ROOT); }
	void PrintTree();
	void PrintLevelOrder();
	bool IsNone(int pos);
	bool IsLeaf(int pos);



};