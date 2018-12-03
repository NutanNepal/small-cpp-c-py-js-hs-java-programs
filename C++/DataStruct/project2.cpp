#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <fstream>

class Node
{
public:
	char ch;
	std::unordered_map<char, Node*> children;
	std::vector<int> indexes;
	Node(char c) :ch(c) {}
};

int maxLen = 0;
std::string maxStr = "";

void insertInSuffixTree(Node* root, std::string str, int index, std::string originalSuffix, int level = 0)
{
	root->indexes.push_back(index);

	if (root->indexes.size() > 1 && maxLen < level)
	{
		maxLen = level;
		maxStr = originalSuffix.substr(0, level);
	}

	if (str.empty()) return;

	Node* child;
	if (root->children.count(str[0]) == 0) {
		child = new Node(str[0]);
		root->children[str[0]] = child;
	}
	else {
		child = root->children[str[0]];
	}

	insertInSuffixTree(child, str.substr(1), index, originalSuffix, level + 1);
}

int main()
{
	std::ifstream myfile("DNA.txt");
	std::string str, temp;
	if (myfile.is_open()) {
		while (getline(myfile, temp)) {
			str += temp;
			//std::cout << str << std::endl;
		}
	}
	std::cout << str << std::endl;
	myfile.close();
	str.erase(0, 5);
	str.erase(str.end() - 2, str.end());
	std::cout << str << std::endl;
	Node* root = new  Node('@');

	for (int i = 0; i<str.size(); i++) {
		std::string s = str.substr(i);
		insertInSuffixTree(root, s, i, s);
	}

	std::cout << maxLen << "->" << maxStr << std::endl;

	return 1;
}
