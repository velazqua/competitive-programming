#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;
class Node;

class Edge {
	public:
	Node* head_vertex;
	Node* tail_vertex;
	int cost;
	Edge (Node* h, Node* t, int c) : head_vertex(h), tail_vertex(t), cost(c) {}
};

class Node {
	public:
	string key;

	list <Edge> adjNodes;
	
	Node(string k) : key(k) {}
	
	void addAdjNode (Node *n, int c)
	{
		Edge e(this,n,c);
		adjNodes.push_back(e);
	}
	
};

ostream& operator << (ostream& os, Edge const& e)
{
	os << "(" << e.head_vertex->key << "," << e.tail_vertex->key << ")[" << e.cost <<"]";
	return os;
}

class Graph {
	public:
	list <Node*> nodeList;
	void addNode (Node* n)
	{
		nodeList.push_back(n);
	}
};

int main ()
{
	Graph G;
	Node A("A"), B("B"), C("C"), D("D");
	A.addAdjNode(&B,50);
	A.addAdjNode(&C,100);
	B.addAdjNode(&A,150);
	B.addAdjNode(&C,20);
	C.addAdjNode(&D,30);
	D.addAdjNode(&A,30);
	//v = new Node(2);
	//w = new Node(3);
	G.addNode(&A);
	G.addNode(&B);
	G.addNode(&C);
	G.addNode(&D);
	cout << "Graph consists of the following nodes: " << endl;
	for (list<Node*>::iterator i = G.nodeList.begin();i!=G.nodeList.end();++i)
	{
		cout << "vertex: ";
		cout << (*i)->key;
		cout << ". Has edges: ";
	
		for (list<Edge>::iterator j = (*i)->adjNodes.begin(); j!=(*i)->adjNodes.end();++j)
		{
			cout << *j << ", ";
		}
		cout << endl;
	}
}

