#include <iostream>
#include <vector>
#include <set>

struct Edge
{
    Edge(int w, int l, int r): weight(w), left(l), right(r) { ; }
    int left, right;
    int weight;
};

std::set<unsigned int> nodes;
std::vector<Edge*> initialize_graph();
bool add_nodes(int x, int y);
void print_edges(std::vector<Edge*> min_tree);

int main()
{
    std::vector<Edge*> graph;
    std::vector<Edge*> min_tree;
    graph = initialize_graph();
    int curr_num = 0, nodes_num = 9, i = 0;
    int* finder;
    while (curr_num < nodes_num){
        if (add_nodes(graph[i]->left, graph[i]->right)){
            min_tree.push_back(graph[i]);
            curr_num ++;
        }
        i++;
    }
    print_edges(min_tree);
    return 0;
}

std::vector<Edge*> initialize_graph()
{
    std::vector<Edge*> graph;   //initializing minHeap;
    graph.push_back(new Edge(1, 7, 6));
    graph.push_back(new Edge(2, 5, 6));
    graph.push_back(new Edge(2, 2, 8));
    graph.push_back(new Edge(4, 0, 1));
    graph.push_back(new Edge(4, 2, 5));
    graph.push_back(new Edge(6, 8, 6));
    graph.push_back(new Edge(7, 7, 8));
    graph.push_back(new Edge(7, 2, 3));
    graph.push_back(new Edge(8, 1, 2));
    graph.push_back(new Edge(8, 7, 0));
    graph.push_back(new Edge(9, 3, 4));
    graph.push_back(new Edge(10, 5, 4));
    graph.push_back(new Edge(11, 7, 1));
    graph.push_back(new Edge(14, 3, 5));

    return graph;
}

bool add_nodes(int x, int y){
    if (nodes.find(x) ==  nodes.end() || nodes.find(y) == nodes.end()){
        return 0;
    }
    nodes.insert(x); nodes.insert(y);
    return 1;
}

void print_edges(std::vector<Edge*> min_tree)
{
    std::vector<Edge*>::iterator i;
    for ( i = min_tree.begin(); i != min_tree.end(); i++)
    {
        std::printf("Edge joining %d and %d\n", (*i)->left, (*i)->right);
    }
}