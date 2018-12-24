#include<iostream>
using namespace std;

template<class T>
struct Node{

	T data;
	Node* left;
	Node* right;
};

template<class T>
class Btree{
	Node<T>* head;
	public:
	Node<T>* createNode( T t_data);
	Node<T>* insert(Node<T>* root,T t_data);
	bool search(Node<T>* root, T t_data);
	void  setHead(Node<T>* root);
	Node<T>* deleteNode (Node<T>* root, T t_data);
	void deleteTree(Node<T>* root);
	void displayAll(Node<T>* root);
	~Btree();
};

template<class T>
Node<T>* Btree<T>::createNode(T t_data){
	Node<T>* newNode = new Node<T>;
	newNode->data = t_data;
	newNode->left = NULL;
	newNode->right= NULL;
return newNode; 
}

template<class T>
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

template<class T>
bool Btree<T>::search(Node<T>* root, T t_data){
	if(root == NULL){return false;}
	else if(t_data < root->data){
		return  search(root->left, t_data);
	}else if(t_data > root->data){
		return  search(root->right,t_data);
	}else if(t_data == root->data){
		return true;
	}
	
}
template<class T>
void  Btree<T>::setHead(Node<T>* root){head = root;}

template<class T>

Node<T>* Btree<T>::deleteNode(Node<T>* root, T t_data){
	
	if(root==NULL){return root;}
	else if(t_data<root->data)
	{
		deleteNode(root->left,t_data);	
	}
	else if(t_data>root->data)
	{
		
deleteNode(root->right,t_data);		
	}
	else
	{
		if(root->left==NULL && root->right==NULL){
			delete root;
			return NULL;
		}else if(root->left == NULL){
			Node<T>* tempNode = root;
			root = root->right;
			delete tempNode;
		}else if(root->right == NULL){
			Node<T>* tempNode = root;
			root = root->left;
			delete tempNode;
		}else{
			Node<T>* tempNode = root;
			while(tempNode->left!=NULL){
				tempNode = tempNode->left;
			}
			root->data = tempNode->data;
			root->right = deleteNode(root->right,tempNode->data);	 
		}
		
	}	
		return root;	
}

template<class T>
void Btree<T>::deleteTree(Node<T>* root){

	if(root==NULL){return;}
	else{
		deleteTree(root->left);
		deleteTree(root->right);
		root = deleteNode(root,root->data);
	}
}

template<class T>
void Btree<T>::displayAll(Node<T>* root) {
	if (root != NULL) {
		displayAll(root->left);
		displayAll(root->right);
		cout << root->data << "---";
	}
}

template<class T>
Btree<T>::~Btree(){
	cout << "Destructor is called!!" <<  endl;
	deleteTree(head);
}

int main(){
	Node<int>* root = NULL;
	Btree<int> myTree;
	
	root = myTree.insert(root, 15);
	root = myTree.insert(root, 10);
	//root = myTree.insert(root, 20);
	root = myTree.insert(root, 8);
	root = myTree.insert(root, 25);
	root = myTree.insert(root, 12);
	root = myTree.insert(root, 19);
	root = myTree.insert(root,21);
	//root = myTree.deleteNode(root,20);
	if(myTree.search(root,19)){cout << "FOUND!!" << endl;}
	else{cout << "NOT FOUND!!" << endl;}
	cout << "wtf" << endl;
	myTree.displayAll(root);
	myTree.setHead(root);

	return 0;
}