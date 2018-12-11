#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <deque>

using namespace std;

struct Vertex{
	Vertex(int v, int val) : vertex_(v), value(val) { ; }
	int vertex_;
	int value;
};

class Graph { //add required methods to implement the pseudo code
private:
	
public:
	int vertices;
	vector<list<pair<int, int>>> neighbor;
	Graph(int n) : vertices(n) {
		for (int i = 0; i < n; i++) {
			list<pair<int, int>> list_;
			neighbor.push_back(list_);
		}
	}
	void PushEdge(int source, int dest, int weight);
};

void Graph::PushEdge(int source, int dest, int weight) {
	neighbor[source].push_back(make_pair(dest, weight));
}

void swap(Vertex* x, Vertex* y) {
	int u = x->vertex_;
	int v = x->value;
	x->value = y->value;
	x->vertex_ = y->vertex_;
	y->value = v;
	y->vertex_ = u;
}

void pop_root(deque<Vertex*> &x, vector<list<pair<int,int>>> neighbor) {
	int root_vertex = x[0]->vertex_;
	int j = 0;
	x.pop_front();
	std::deque<Vertex*>::iterator iter = x.begin();
	std::list<pair<int, int>>::iterator it = neighbor[root_vertex].begin();
	while(iter != x.end()) {
		while (it != neighbor[root_vertex].end()) {
			if ((*iter)->vertex_ = it->first) {
				x.push_front(*iter);
				x.erase(x.begin() + j);
				iter = x.begin();
				iter = x.begin() + j + 1;
			}
			it++;
		}
		iter++;
		j++;
	}
	int i = 0;
	while (true) {
		if (x[i]->value > x[2 * i + 1]->value && (2 * i + 1 < x.size())) {
			swap(x[i], x[2 * i + 1]);
			i = 2 * i + 1;
		}
		else if (x[i]->value > x[2 * i + 2]->value && (2 * i + 2 < x.size())) {
			swap(x[i], x[2 * i + 2]);
			i = 2 * i + 2;
		}
		else {
			break;
		}
	}
}

int main() {
	Graph MyGraph(7);

	MyGraph.PushEdge(0, 1, 5); MyGraph.PushEdge(0, 5, 3);
	MyGraph.PushEdge(1, 0, 5); MyGraph.PushEdge(1, 2, 10);
	MyGraph.PushEdge(1, 4, 1); MyGraph.PushEdge(1, 6, 4);
	MyGraph.PushEdge(2, 1, 10); MyGraph.PushEdge(2, 3, 5);
	MyGraph.PushEdge(2, 6, 8); MyGraph.PushEdge(3, 2, 5);
	MyGraph.PushEdge(3, 4, 7); MyGraph.PushEdge(3, 6, 9);
	MyGraph.PushEdge(4, 1, 1); MyGraph.PushEdge(4, 3, 7);
	MyGraph.PushEdge(4, 5, 6); MyGraph.PushEdge(4, 6, 2);
	MyGraph.PushEdge(5, 0, 3); MyGraph.PushEdge(5, 4, 6);
	MyGraph.PushEdge(6, 1, 4); MyGraph.PushEdge(6, 2, 8);
	MyGraph.PushEdge(6, 3, 9); MyGraph.PushEdge(6, 4, 2);

	deque<Vertex*> minHeap;                   //<0-0,1-inf,2-inf,3-inf,4-inf,5-inf,6-inf> ==> 0, <5-3,1-5,3-inf,4-inf,6-inf>
	int inf = 20;
	minHeap.push_back(new Vertex(0, 0));
	for (int i = 1; i < 7; i++) {
		minHeap.push_back(new Vertex(i, inf));
	}
	vector<int> path;
	while (minHeap.size() > 0) {
		int root_vertex = minHeap[0]->vertex_;
		path.push_back(root_vertex);
		list<pair<int, int>>::iterator it;
		deque<Vertex*>::iterator iter;
		for (iter = minHeap.begin(); iter != minHeap.end(); iter++) {
			for (it = MyGraph.neighbor[root_vertex].begin(); it != MyGraph.neighbor[root_vertex].end(); it++) {
				if ((*iter)->vertex_ == it->first && it->second < (*iter)->value) {
					(*iter)->value = it->second;
				}
			}
		}
		pop_root(minHeap, MyGraph.neighbor);
	}
	cout << "PATH:\n";
	for (std::vector<int>::iterator it = path.begin(); it != path.end(); it++) {
		std::cout << "->" << *it;
	}

	return 0;
}