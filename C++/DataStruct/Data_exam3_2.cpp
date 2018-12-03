#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>

class Set_ {
public:
	std::set<std::string> content;
	int size = 0;
	Set_(std::string str) {
		std::istringstream iss(str);
		std::string word;
		while (iss >> word) {
			std::transform(word.begin(), word.end(), word.begin(), ::tolower);
			content.insert(word);
		}
		for (std::set<std::string>::iterator it = content.begin(); it != content.end(); it++) {
			size++;
		}

	}

	std::string sortset();
};

std::string Set_::sortset() {
	std::string output;
	int count = 1, loop = 0;
	while (loop < size) {
		for (std::set<std::string>::iterator it = content.begin(); it != content.end(); it++) {
			if ((*it).length() == count) {
				output += (*it);
				output += ", ";
				loop++;
			}
		}
		count++;
	}
	return output;
}

int main()
{
	std::cout << "Enter a sentence" << std::endl;
	std::string input;
	getline(std::cin, input);
	Set_ X(input);
	std::string output = X.sortset();
	std::cout << output << std::endl;
    return 0;
}