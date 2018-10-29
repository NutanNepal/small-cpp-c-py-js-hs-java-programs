#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

template<class T, class U>
struct Node {
	T name;
	U salary;
	Node<T, U>* next;

};

template<class T, class U>
class List {
	Node<T, U>* head;
public:
	Node<T, U>* createNode(T t_name, U t_salary);
	Node<T, U>* insertNode(T t_name, U t_salary, Node<T, U>* root);
	int getFreq(T t_data, Node<T, U>* root);
	void display(Node<T, U>* root);
	Node<T, U>* findMax(Node<T, U>* root);
	Node<T, U>* findMin(Node<T, U>* root);
	void getMaxMinsalary(Node<T, U>* root);
	void getHead(Node<T, U>* root);
	~List();
};

string getName() {
	string str;
	cout << "name:" << endl;
	getline(cin, str);
	return str;
}

int getSalary() {
	int salary;
	cout << "salary:";
	cin >> salary;
	cin.ignore();
	return salary;
}

template<class T, class U>
Node<T, U>* List<T, U>::createNode(T t_name, U t_salary) {
	Node<T, U>* newNode = new Node<T, U>;
	newNode->name = t_name;
	newNode->salary = t_salary;
	newNode->next = NULL;
	return newNode;
}

template<class T, class U>
Node<T, U>* List<T, U>::insertNode(T t_name, U t_salary, Node<T, U>* root) {
	if (root == NULL) { root = createNode(t_name, t_salary); }
	else {
		root->next = insertNode(t_name, t_salary, root->next);
	}
	return root;
}

template<class T, class U>
int List<T, U>::getFreq(T t_data, Node<T, U>* root) {
	int count = 0;
	while (root != NULL) {
		if (makeLowerCase(root->name) == makeLowerCase(t_data)) {
			count++;
		}
		root = root->next;
	}
	return count;
}

template<class T, class U>
void List<T, U>::display(Node<T, U>* root) {
	if (root != NULL) {
		cout << root->name << ":\t" << root->salary << endl;
		display(root->next);
	}
}

template<class T, class U>
Node<T, U>* List<T, U>::findMax(Node<T, U>* root) {
	Node<T, U>* tempMax = root;
	while (root != NULL) {
		if ((root->salary) >= (tempMax->salary)) {
			tempMax = root;
		}
		root = root->next;
	}
	return tempMax;
}
template<class T, class U>
Node<T, U>* List<T, U>::findMin(Node<T, U>* root) {
	Node<T, U>* tempMin = root;
	while (root != NULL) {
		if ((root->salary) <= (tempMin->salary)) {
			tempMin = root;
		}
		root = root->next;
	}
	return tempMin;
}


template<class T, class U>
void List<T, U>::getMaxMinsalary(Node<T, U>* root) {
	Node<T, U>* max = findMax(root);
	Node<T, U>* min = findMin(root);
	vector<Node<T, U>*> maxFreq;
	vector<Node<T, U>*> minFreq;
	while (root != NULL) {
		if ((root->salary) >= max->salary) {
			maxFreq.push_back(root);
		} else if ((root->salary) <= min->salary) {
			minFreq.push_back(root);
		}
		root = root->next;
	}
	cout << endl;
	cout << "max salary:" << endl;
	for (vector<Node<T, U>*>::iterator it = maxFreq.begin(); it != maxFreq.end(); ++it) {
		cout << (*it)->name << ":\t" << (*it)->salary << endl;
	}
	cout << endl;
	cout << "min salary:" << endl;
	for (vector<Node<T, U>*>::iterator it = minFreq.begin(); it != minFreq.end(); ++it) {
		cout << (*it)->name << ":\t" << (*it)->salary << endl;
	}
}

template<class T, class U>
void List<T, U>::getHead(Node<T, U> *root) {
	head = root;
}

template<class T, class U>
List<T, U>::~List() {
	Node<T, U>* tempNode;
	while (head != NULL) {
		tempNode = head;
		head = head->next;
		delete tempNode;
	}
}

int main() {

	string employeeName;
	int salary;
	char input;
	Node<string, int>* root = NULL;
	Node<string, int>* tempRoot = root;
	List<string, int> myList;

	do {
		employeeName = getName();
		salary = getSalary();
		root = myList.insertNode(employeeName, salary, root);
		cout << "Do you want to enter another data (y/n)?";
		cin >> input;
		cin.ignore();
		cout << endl;
	} while (input != 'n' && input == 'y' );
	
	cout << "List of employees and their salary:" << endl;
	myList.display(root);

	myList.getMaxMinsalary(root);
	myList.getHead(root);
	system("pause");
	return 0;
}
