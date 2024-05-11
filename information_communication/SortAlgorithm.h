#pragma once
#include <iostream>
using namespace std;

#define SWAP(a,b) {int c =a; a=b; b=c;}


class SortAlgorithm {
public:
	void PrintSubArray(int a[], int low, int high) {
		for (int i = 0; i <= high; i++) {
			if (i < low) cout << " ";
			else cout << a[i] << " ";
		}
		cout << endl;
	}

	void PrintArray(int a[], int length) {
		PrintSubArray(a, 0, length - 1);
	}

	virtual void Sort(int a[], int length) = 0; //purevirtualfunction


};

class BubbleSort : public SortAlgorithm {
public:
	void Sort(int a[], int length) {
		for (int i = 0; i < length - 1; i++) {
			for (int j = i + 1; j < length; j++) {
				if (a[i] > a[j]) {
					SWAP(a[i], a[j]);
					PrintArray(a, length);
				}
			}
		}
	}
};

class SelectionSort : public SortAlgorithm {
	int Minimum(int a[], int start, int end) {
		int min = start;
		for (int i = start + 1; i <= end; i++) {
			if (a[i] < a[min]) min = i;
		}
		return min;
	}

public:
	void Sort(int a[], int length) {

		for (int i = 0; i < length - 1;i++) {
			int min = Minimum(a, i, length - 1);
			SWAP(a[i], a[min]);
			PrintArray(a, length);
		}
	}
};



class InsertionSort : public SortAlgorithm {
public:
	void Sort(int a[], int length) {
		for (int j, i = 1; i < length; i++) {
			int value = a[i];
			for (j = i; j > 0 && a[j - 1] > value; j--) {
				a[j] = a[j - 1];
			}
			a[j] = value;
			PrintArray(a, length);
		}
	}
};

