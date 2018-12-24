#include<iostream>

using namespace std;

template<class T>
struct Node{
 	T data;
	Node<T>* next;
};

template<class T>
class List{
	Node<T>* head;
	public:
	Node<T>* createNode(T t_data);
	Node<T>* insertNode(T t_data, Node<T>* root);
	void display(Node<T>* root);
	~List();
};

template<class T>
Node<T>* List<T>::createNode(T t_data){
	Node<T>* newNode = new Node<T>;
	newNode->data = t_data;
	newNode->next = NULL;
	return newNode;
}

template<class T>
Node<T>* List<T>::insertNode(T t_data, Node<T>* root){
	if(root == NULL){
        root = createNode(t_data);
        cout << "yayy" << endl;
    }
	else{	
        if (root->data != t_data){
		    root->next = insertNode(t_data,root->next);
	    }
    }
    return root;
}

template<class T>
void List<T>:: display(Node<T>* root){
	if(root!=NULL){
		cout << root->data << endl;
		display(root->next);
	}
}

template<class T>
List<T>::~List(){
	Node<T>* tempNode;
	while(head!=NULL){
		tempNode = head;
		head = head->next;
		delete tempNode;
	}
}

int main(){
    Node<int>* intRoot = NULL;
	List<int> intlist;

    int inp;
    cout << "numbers" << endl;
    cin >> inp;
    int divide = 10000;
    for ( int i = 0; i < 5; i++){
        int nextnum = inp/divide;
        inp = inp % divide;
        divide /= 10;
        cout << "working" << endl;
        intRoot = intlist.insertNode(nextnum, intRoot);
    }
    int x = (intRoot == NULL);
	intlist.display(intRoot);     
    return 0;
}