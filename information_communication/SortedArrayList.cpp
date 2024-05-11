#include "SortedArrayList.h"

static void Error(string s) { cerr << s;exit(-1); }


int SortedArrayList::SearchPos(int key) {
	int i;
	if (algorithm == LinearSearch) {
		if (Key(data[length - 1]) < key)
			return length - 1;
		int i;
		for (i = 0; Key(data[i]) < key; i++);
		if (printCount)
			cout << "Count = " << i << endl;
		return i;
	}
	else if (algorithm == BinarySearch) {
		int low = 0, mid, high = length - 1;
		for (i = 0; low <= high; i++) {
			mid = (low + high) / 2;
			if (key == Key(data[mid])) break;
			if (key < Key(data[mid])) high = mid - 1;
			else low = mid + 1;
		}
		if (printCount)
			cout << "Count = " << i << endl;
		return mid;
	}
	else
		Error("Illegal search algorithm");
}

void SortedArrayList::Insert(Data d) {
	if (IsFull()) Error("List is full");
	int i = length;
	for (;i > 0 && Key(data[i - 1]) > Key(d); i--) {
		data[i] = data[i - 1];
	}
	data[i] = d; length++;
}

float SortedArrayList::Median()
{
	return (data[(length - 1) / 2] + data[length / 2]) / 2.0;
}

Data SortedArrayList::Search(int key) {
	int pos = SearchPos(key);
	if (Key(data[pos]) == key) return data[pos];
	cout << key << "is not found" << endl;
	return SEARCH_FAILED;
}


Data SortedArrayList::Delete(int key)
{
	int pos = SearchPos(key);
	if (Key(data[pos]) == key) {
		Data d = data[pos];
		for (int i = pos; i < length; i++) {
			data[i] = data[i + 1];
		}
		length--; return d;
	}
	cout << key << "is not found" << endl;
	return SEARCH_FAILED;
}




