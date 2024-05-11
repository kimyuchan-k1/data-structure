#pragma once
#include <iostream>
#include <cstdlib>
#include "ArrayList.h"

enum SearchAlgorithm { LinearSearch, BinarySearch};


class SortedArrayList : public ArrayList {
	SearchAlgorithm algorithm;
	bool printCount;

public:
	SortedArrayList() { algorithm = LinearSearch; printCount = false; }
	void Insert(Data d);
	Data Delete(int key);
	Data Search(int key);
	int SearchPos(int key);
	float Median();
	void SetAlgorithm(SearchAlgorithm a, bool p = false) { algorithm = a; printCount = p; }
	void InsertPos(int pos, Data d) { cout << "InsertPos() is no longer supported" << endl; }

};


class SortedArrayListDescending : public SortedArrayList {
	int Key(Data d) { return -d; }

};