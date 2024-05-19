#include "BinarySearchTree.h"


int main(){

	BinarySearchTree b;
	const int SIZE = 10;
	int a[SIZE] = { 27,15,35,10,19,33,42,21,36,8 };
	for (int i = 0; i < SIZE; i++) {
		b.Insert(a[i]);
	}
	b.PrintInorder();
	cout << endl;
	return 0;
	
}