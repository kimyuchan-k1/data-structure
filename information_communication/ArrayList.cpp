#include "ArrayList.h"

static void Error(string s) { cerr << s; exit(-1); }

void CheckPos(int pos, int maxPos)
{
	if (pos <0 || pos >maxPos) Error("Illegal position");

}

void ArrayList::InsertPos(int pos, Data d)
{
	CheckPos(pos, length);
	if (IsFull()) Error("List is full");
	for (int i = length; i > pos;i--) {
		data[i] = data[i - 1];  //position 전까지 shift right
	}
	data[pos] = d; //position 에는 값을 입력
	length++;

}

Data ArrayList::PeekPos(int pos) {
	CheckPos(pos, length - 1); //pos <=length-1
	return data[pos];
}

Data ArrayList::DeletePos(int pos) {
	CheckPos(pos, length - 1);
	Data d = data[pos]; //position 자리 data 빼내기
	for (int i = pos; i < length; i++) {
		data[i] = data[i + 1]; //left shift
	}

	length--;
	return d;

}

Data ArrayList::search(int key) {
	for (int i = 0; i < length;i++) {
		if (Key(data[i]) == key) return data[i]; //해당 값이 있으면 반환한다.
	}

	cout << key << "is not found" << endl;
	return SEARCH_FAILED;  // 못 찾을 경우 -10000000 반환

}

void ArrayList::PrintList() {
	for (int i = 0; i < length;i++) {
		cout << data[i] << " ";

	}
	cout << endl;
}


void ArrayList::DeleteAll(int key) {
	for (int i = 0; i < length; i++) {
		if (Key(data[i]) == key) {
			length--;
			for (int j =i ; j < length; j++) {
				data[j] = data[j + 1];
			}
		}
	}
}
