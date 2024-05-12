#pragma once
#include <iostream>
#include <cstdlib>	
#include <string>
using namespace std;

const int LIST = 8, SIZE = 3, INF = -999; //INF ����
const int LENGTH = 8;

class Data {
	int value, list;
	Data(int v = 0, int l = 0) { value = v; list = l; }
	friend class MergeUsingWinnerTree;

};

class MergeUsingWinnerTree {
	Data data[2 * LIST];
	int n[LIST];
	//����
	Data Winner(Data left, Data right) {
		return(left.value > right.value) ? left : right;
	}

public:
	MergeUsingWinnerTree(int a[LIST][SIZE + 1]) {
		for (int i = 0; i < LIST; i++) {
			n[i] = 0; data[LIST + i] = Data(a[i][0], i);
		}
		for (int i = LIST - 1; i >= 1; i--) {
			data[i] = Winner(data[i * 2], data[i * 2 + 1]);
		}
	}

	int DeleteWinner(int a[LIST][SIZE + 1]) {
		Data d = data[1];
		int i = LIST + d.list;
		data[i] = Data(a[d.list][++n[d.list]], d.list);
		while (i > 1) {
			i /= 2;
			data[i] = Winner(data[i * 2], data[i * 2 + 1]);
		}
		return d.value;
	}
};

class WinnerTree {
	int data[LENGTH * 2]; //Array ���� (Tree�� �����.)
	int Winner(int left, int right) {
		return max(left, right);
	}

public:
	WinnerTree(int a[]) {
		for (int i = 0; i < LENGTH; i++) {
			data[LENGTH + i] = a[i]; //leaf node �� �ֱ�
		}
		// ���� �̱� index 0 �� �����ϰ� 1~ 7���� 
		for (int j = LENGTH-1; j > 0; j--) {
			int left = j * 2;
			int right = j * 2 + 1;
			data[j] = Winner(data[left], data[right]); // ���� �̱�
		}

	}

	int GetWinner() {
		return data[1];

	}

	void Replace(int pos, int d) {
		//leaf �� �ش� pos �� d�� �����Ѵ�.
		int i = LENGTH + pos;
		data[i] = d;

		//������Ʈ !!
		while (i >= 1) {
			i /= 2;
			data[i] = Winner(data[i * 2], data[i * 2 + 1]);
		}

	}

};