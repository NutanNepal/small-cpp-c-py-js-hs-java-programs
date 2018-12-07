#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int counter = 122;
std::string code_ = "";
struct Node
{
	Node(char c, int x) : char_(c), count(x) { ; }
	char char_;
	int count;
	std::string code = "";
	Node* left = NULL;
	Node* right = NULL;
};

void fill_vector(std::vector<Node*> &input);
void count_letters(std::vector<Node*> &input);
void sort_vector(std::vector<Node*> &input);
void get_code(Node* root);
Node* createparent(Node* X, Node* Y);

int main()
{
	std::vector<Node*> letters;
	fill_vector(letters);
	count_letters(letters);
	sort_vector(letters);
	std::vector<Node*> original = letters;

	while (letters.size() > 1) {
		letters.push_back(createparent(letters[0], letters[1]));
		letters.erase(letters.begin(), letters.begin() + 2);
		sort_vector(letters);
	}
	
	get_code(letters[0]);

	for (std::vector<Node*>::iterator it = original.begin(); it != original.end(); it++) {
		std::cout << (*it)->char_ << ": " << (*it)->code << std::endl;
	}

	return 0;
}

Node* createparent(Node* X, Node* Y)
{
	char newchar = counter--;
	Node *Z = new Node(newchar, 0);
	Z->count = X->count + Y->count;
	if (X->count < Y->count) {
		Z->left = X;
		Z->right = Y;
	}
	else {
		Z->left = Y;
		Z->left = X;
	}
	return Z;
}

void fill_vector(std::vector<Node*> &input)
{
	Node* A = new Node('a', 0);
	Node* T = new Node('t', 0);
	Node* G = new Node('g', 0);
	Node* C = new Node('c', 0);
	input.push_back(A);
	input.push_back(T);
	input.push_back(G);
	input.push_back(C);
}

void count_letters(std::vector<Node*> &input)
{
	std::ifstream newfile("dna_text.txt");
	char letter;
	if (newfile.is_open()) {
		while (newfile.get(letter)) {
			switch (letter) {
			case 'a':
				(input[0])->count++;
				break;
			case 't':
				(input[1])->count++;
				break;
			case 'g':
				(input[2])->count++;
				break;
			case 'c':
				(input[3])->count++;
				break;
			}
		}
	}
	newfile.close();
}

void sort_vector(std::vector<Node*> &input)
{
	for (int i = 0; i < input.size(); i++) {
		for (int j = 0; j < input.size(); j++) {
			if (input[i]->count < input[j]->count) {
				Node* temp = input[i];
				input[i] = input[j];
				input[j] = temp;
			}
		}
	}
}

void get_code(Node* root)
{
	if (root->left != NULL) {
		code_ += '0';
		get_code(root->left);
	}
	if (root->right != NULL) {
		code_ += '1';
		get_code(root->right);
	}
	root->code = code_;
	if(code_.length() > 0) code_.pop_back();
}