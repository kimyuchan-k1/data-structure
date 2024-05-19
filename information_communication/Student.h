#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;


class Student {
	int id;
	string name;
	int age, grade;
	int score;
	
	Student(int i = 0, string n = " ", int a = 0, int g = 0, int s = 0) {
		id = i; name = n; age = a; grade = g; score = s;
	}

	void Print() {
		if (id <= 0) return;
		cout << "ID = " << id << "; Name = " << name << "; Age = " << age;
		if (age <= 0) cout << endl;
		else cout << "; Grade = " << grade << "; Score = " << score << endl;
	}

	int Key() { return id; } 

};


