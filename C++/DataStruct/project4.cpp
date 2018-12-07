#include <iostream>
#include <map>
#include <vector>

struct Edge
{
    Edge(int w, int l, int r): weight(w), left(l), right(r) { ; }
    int left, right;
    int weight;
};

std::vector<Edge*> initialize_graph();

int main()
{
    std::vector<Edge*> graph;
    std::vector<Edge*> min_tree;
    graph = initialize_graph();
    min_tree.push_back(graph[0]);
    int curr_num = 0, nodes_num = graph.size(), i = 1;
    int* finder;
    while (curr_num < nodes_num){
        
        curr_num ++;
    }
}

std::vector<Edge*> initialize_graph()
{
    std::vector<Edge*> graph;
    //initializing minHeap;
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