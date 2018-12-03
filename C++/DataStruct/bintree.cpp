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

    Node<T>* insert(Node<T>* root, T tdata);
	Node<T>* pop(Node<T>* root, T t_data);
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
Node<T>* Btree<T>:: insert(Node<T>* root, T t_data){
	if(root == NULL){
		root = createNode(t_data);
	}
	else if(t_data < root->data){
		root->left = insert(root->left,t_data);
	}
	else{
		root->right = insert(root->right,t_data);
	}
	return root;
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
	
	return root;
}

template <class T>
Node<T>* Btree<T>::pop(Node<T>* root, T t_data){
	if (root == NULL){
		return root;
	}
	else if (t_data < root->data){
		pop(root->left, t_data);
	}
	else if (t_data > root->data){
		pop(root->right, t_data);
	}
	else{
		if(root->left == NULL && root->right == NULL){
			delete root;
			return NULL;
		}
		else if(root->left == NULL){
			Node<T>* temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL){
			Node<T>* temp = root;
			root = root->left;
			delete temp;
		}
		else{
			Node<T>* temp = root;
			Node<T>* temp2 = root->right;
			while (temp2->left != NULL){
				temp2 = temp2->left;
			}
			temp2->left = root->left;
			root = root->right;
			delete temp;
		}
	}
	return root;
}

template <class T>
Btree<T>::~Btree(){
	;
}

int main(){
	Node<int> *root = NULL;
	Btree<int> tree;
    tree.setroot(root);

	root = tree.insert(root, 15);
	/*tree.insert(root,12);
	tree.insert(root,13);
	tree.insert(root,16);
	tree.insert(root,20);
	tree.insert(root,19);
	tree.insert(root,25);*/

	cout<< tree.search(root, 25) <<endl;

	return 0;
}
