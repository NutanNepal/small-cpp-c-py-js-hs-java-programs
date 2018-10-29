#include <iostream>
using namespace std;

template <class T>
struct Node{
	T data;
	Node *left;
	Node *right;
};

template <class T>
class Btree{
    Node<T>* head;
	public:
	Node<T> *createnode(T tdata);
    Node<T> *deleteNode(Node<T>* root, T t_data);

	bool search(Node<T>* root, T tdata);

    void insert(Node<T>* root, T tdata);
    void setroot(Node<T>* root);
    void deleteTree(Node<T>* root);
    void displayAll(Node<T>* root);

	~Btree();
	
};

template <class T>
void Btree<T>::setroot(Node<T>* root){
    head = root;
}

template <class T>
Node<T>* Btree<T>::createnode(T tdata){
	Node<T>* mynode = new Node<T>;
	mynode->data = tdata;
	mynode->left = NULL;
	mynode->right = NULL;
	return mynode;
}

template <class T>
void Btree<T>:: insert(Node<T>* root, T t_data){
    if(root == NULL){
        root = createNode(t_data);
    }
    else if(t_data < root->data){
        insert(root->left,t_data);
    }
    else{
        insert(root->right,t_data);
    }
}

template <class T>
bool Btree<T>::search(Node<T> *root, T tdata){
	if (root == NULL){
        return false;
    }
    else if (root->data > tdata){
        return search(root->left, tdata);
    }
    else if (root->data < tdata){
        return search(root->right, tdata);
    }
	else{
		return true;
	}
}

template <class T>
Node<T>* Btree<T>::deleteNode(Node<T>* root, T t_data){
	if (root==NULL){
		return root;
	}
	else if (t_data < root->data){
		deleteNode(root->left, t_data);
	}
	else if (t_data > root->data){
		deleteNode(root->right, t_data);
	}
	else{
		
	}
}

template <class T>
Btree<T>::~Btree(){
	;
}

int main(){
	Node<int> *root = NULL;
	Btree<int> tree;
    tree.setroot(root);

	tree.insert(root,15);
	tree.insert(root,12);
	tree.insert(root,13);
	tree.insert(root,16);
	tree.insert(root,20);
	tree.insert(root,19);
	tree.insert(root,25);

	cout<< tree.search(root, 25) <<endl;

	return 0;
}
