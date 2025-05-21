#include <iostream>
using namespace std;

class Graph
{
private:
	struct Edgenode {
		int vertex;
		int weight;
		Edgenode* next;

	};

	struct Vertexnode {
		int vertex;
		Edgenode* firstedge;
	};

	int vertices;
	Vertexnode* nodes;
	 
public:
	Graph(int vertices);
	~Graph();
	void addedge(int u, int v, int w);
	void printgraph();
};

Graph::Graph(int vertices) {
	this->vertices = vertices;
	this->nodes = new Vertexnode[vertices];
	for (int i = 0; i < vertices; ++i) {
		nodes[i].vertex = i;
		nodes[i].firstedge = NULL;
	}
}

Graph::~Graph() {
	for (int i = 0; i < vertices; i++) {
		Edgenode* curr = nodes[i].firstedge;
		while (curr) {
			Edgenode* temp = curr;
			curr = curr->next;
			delete temp;
		}
		delete nodes;
	}
}

void Graph::addedge(int u, int v, int w) {
	Edgenode* newnode = new Edgenode;
	newnode->vertex = v;
	newnode->weight = w;
	newnode->next = nodes[u].firstedge;
	nodes[u].firstedge = newnode;
}

void Graph::printgraph() {
	for (int i = 0; i < vertices; i++) {
		Edgenode* curr = nodes[i].firstedge;
		cout << "Vertex" << i << ":";
		while (curr) {
			cout << curr->vertex << "(" << curr->weight << ")";
			curr = curr->next;
		}
		cout << endl;
	}
}

int main()
{
	Graph graph(3);
	graph.addedge(0, 1, 4);
	graph.addedge(0, 2,2);
	graph.addedge( 1,2,3);

	graph.printgraph();
	return 0;
}