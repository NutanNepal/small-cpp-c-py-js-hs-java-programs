#include <map>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

map<string, int> add(map<string, int> frequency, string _input) {
	map<string, int>::iterator it = frequency.find(_input);
	if (it == frequency.end()) {
		frequency[_input] = 1;
	}
	else {
		(it->second)++;
	}
	return frequency;
}

void print(map<string, int> frequency) {
	for (map<string, int>::iterator it = frequency.begin(); it != frequency.end(); it++) {
		cout << it->first << ": " << it->second << endl;
	}
}
int main() {
	map<string, int> frequency;
	ifstream myfile("input.txt");
	string address;
	if (myfile.is_open()) {
		while (getline(myfile, address)) {
			frequency = add(frequency, address);
		}
	}
	print(frequency);
	cout << "Enter another address: ";
	getline(cin, address);
	frequency = add(frequency, address);
	print(frequency);
	return 0;
}