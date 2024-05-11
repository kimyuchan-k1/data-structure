#pragma once
#include <iostream>
#include <cstdlib>

using namespace std;

typedef int Data;

const int SIZE = 10000;
const int SEARCH_FAILED = -10000000;


class ArrayList {
protected:
	Data data[SIZE];
	virtual int Key(Data d) { return d; }

public:
	int length;
	ArrayList() { length = 0; }
	void InsertPos(int pos, Data d);
	Data DeletePos(int pos);
	Data PeekPos(int pos);
	Data search(int key);
	void DeleteAll(int key); //°úÁ¦ 1
	void PrintList();
	bool IsEmpty() { return length == 0; }
	bool IsFull() { return length == SIZE;	 }
	int Length() { return length; }	

};