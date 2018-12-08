#include <iostream>
#include <vector>
#include <set>

struct Edge
{
	Edge(unsigned int w, unsigned int l, unsigned int r) : weight(w), left(l), right(r) { ; }
	unsigned int left, right;
	unsigned int weight;
};

std::set<std::set<unsigned int>> nodes;
std::vector<Edge*> initialize_graph();
bool add_nodes(unsigned int x, unsigned int y);
void print_edges(std::vector<Edge*> min_tree);
void manage_nodes();

int main()
{
	std::vector<Edge*> graph;
	std::vector<Edge*> min_tree;
	graph = initialize_graph();
	unsigned int curr_num = 0, edges_num = graph.size(), i = 0, nodes_num = 9;
	while (curr_num < nodes_num && i < edges_num) {
		if (add_nodes(graph[i]->left, graph[i]->right)) {
			min_tree.push_back(graph[i]);
			curr_num++;
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

bool add_nodes(unsigned int x, unsigned int y)
{
	if (nodes.empty()) {
		std::set<unsigned int> X = { x, y };
		nodes.insert(X);
		return 1;
	}
	std::set<std::set<unsigned int>>::iterator i;
	for (i = nodes.begin(); i != nodes.end(); i++) {
		if ((*i).find(x) != (*i).end() && (*i).find(y) != (*i).end()) {
			return 0;
		}
	}
	std::set<unsigned int> X = { x, y };
	nodes.insert(X);
	manage_nodes();

	return 1;
}

void manage_nodes() {
	std::set<std::set<unsigned int>>::iterator i, j;
	std::set<unsigned int>::iterator k;
	i = nodes.begin();
	while (i != nodes.end()) {
		j = nodes.begin();
		while (j != nodes.end()) {
			k = (*j).begin();
			while (k != (*j).end()) {
				if (i != j && i->find(*k) != i->end()) {
					std::set<unsigned int> Y;
					Y.insert(i->begin(), i->end());
					Y.insert(j->begin(), j->end());
					nodes.erase(j);
					nodes.erase(i);
					nodes.insert(Y);
					i = nodes.begin();
					j = nodes.begin();
					k = j->begin();
				}
				else {
					k++;
				}
			}
			j++;
		}
		i++;
	}
}

void print_edges(std::vector<Edge*> min_tree)
{
	std::vector<Edge*>::iterator i;
	for (i = min_tree.begin(); i != min_tree.end(); i++)
	{
		std::printf("Edge joining %d and %d\n", (*i)->left, (*i)->right);
	}
}