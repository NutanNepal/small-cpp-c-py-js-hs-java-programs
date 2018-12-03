#include <iostream>
#include <fstream>
#include <vector>

struct Node
{
    Node(char c, int x): char_(c), count(x){ ; }
    char char_;
    int count;
    Node *left = NULL;
    Node *right = NULL;
    Node* createnode(char chardata, int count);
    Node* createparent(Node &X, Node &Y);
};

void count_letters(std::vector<Node> &input);
void sort_vector(std::vector<Node> &input);

Node* Node::createparent(Node &X, Node &Y)
{
    Node* Z = createnode('z', X.count + Y.count);
}

int main()
{
    Node A = {'a', 0}; Node T = {'t', 0}; Node G = {'g', 0}; Node C = {'c', 0};
    std::vector<Node> letters;
    letters.push_back(A); letters.push_back(T);
    letters.push_back(G); letters.push_back(C);

    count_letters(letters);
    sort_vector(letters);

    for (std::vector<Node>::iterator it = letters.begin(); it != letters.end(); it++) {
		std::cout << it->char_ << ": " << it->count << std::endl;
	}
    //while(letters.size() != 1){

    //}

}

void count_letters(std::vector<Node> &input)
{
    std::ifstream newfile("dna_text.txt");
    char letter;
    if (newfile.is_open()){
        while (newfile.get(letter)){
            switch(letter){
                case 'a':
                    (input[0]).count++;
                    break;
                case 't':
                    (input[1]).count++;
                    break;
                case 'g':
                    (input[2]).count++;
                    break;
                case 'c':
                    (input[3]).count++;
                    break;
            }
        }
    }
    newfile.close();
}

void sort_vector(std::vector<Node> &input)
{
    for(int i = 0; i < input.size(); i++){
        for(int j = 0; j < input.size(); j++){
            if (input[i].count < input[j].count){
                Node temp = input[i];
                input[i] = input[j];
                input[j] = temp;
            }
        }
    }
}
