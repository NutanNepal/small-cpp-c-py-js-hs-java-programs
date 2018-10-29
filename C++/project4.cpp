#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
int PRESENT_YEAR;

class Personnel {
	string name;
	int year_of_birth, age;
	
public:
	Personnel(string n, int yob, int age) : name(n), year_of_birth(yob), age(age) {
		;
	}
	void print(ofstream& writefile) {
		writefile << "Name: " << name << endl;
		writefile << "Year of Birth: " << year_of_birth << endl;
		writefile << "Age: " << age << endl;
	}
};

void prompts(string &name, int &yob, int &age) {
	cout << "Enter the name: " << endl;
	cin >> name;
	cout << "Enter the year of birth: " << endl;
	cin >> yob;
	age = PRESENT_YEAR - yob;
}

int main() {
	string name;
	int yob, age;
	cout << "Enter present year: " << endl;
	cin >> PRESENT_YEAR;
	vector<Personnel> users;

	for (int i = 0; i<10; i++) {
		prompts(name, yob, age);
		users.push_back(Personnel(name, yob, age));
	}


	ofstream writefile;
	writefile.open("list.txt");

	for (vector<Personnel>::iterator it = users.begin(); it != users.end(); ++it) {
		it->print(writefile);
	}
	system("pause");
	return 0;
}