/* Name: Alex Velazquez
 * Start Date: October 03, 2011 @ 10:20PM
 * End Date:   October 03, 2011 @ ???
 * Purpose: To solve the SPOJ problem EZDIJKST - Easy Dijkstra Problem
 */

#include <iostream>
#include <map>
#include <list>
#include <utility>

#define MAX_INTEGER  2147483647

using namespace std;

struct Edge {
	int n;
	int w;
	Edge (int n_, int w_) : n(n_), w(w_) {}
};

void printGraph (map<int,list<Edge> > &G)
{
	for (map<int,list<Edge> >::iterator it=G.begin();it!=G.end();++it)
	{
		cout << "G[" << it->first << "] = {";
		for (list<Edge>::iterator iter=it->second.begin();iter!=it->second.end();++iter)
		{
			cout << iter->n << ",";
		}
		cout << "}" << endl;
	}
}

int minn (int a, int b)
{
	return (a<b)?a:b;
}

int dijkstra (map<int,list<Edge> > &G, int &start, int &end, int &V, map<int,int> &dist)
{
	// set all distances to each node to infinity
	dist[start] = 0;
	map<int,bool> visited;
	while (1)
	{
		// find the smallest unvisited node and branch from there
		int lowest = MAX_INTEGER;
		for (map<int,int>::iterator s = dist.begin();s!=dist.end();++s)
			if (s->second < lowest && visited[s->first] == false)
				lowest = s->first;
		if (lowest == MAX_INTEGER)
			return MAX_INTEGER;
		visited[lowest] = true;
		if (lowest == end)
			break;
		for (list<Edge>::iterator e = G[lowest].begin(); e!=G[lowest].end(); ++e)
		{
			dist[e->n] = minn (dist[e->n],dist[lowest]+e->w);
		}
	}
	return dist[end];
}

int main ()
{
	int T, V, K, A, B, C;
	cin >> T;
	for (int i=0;i<T;++i)
	{
		cin >> V >> K;
		//cout << "Graph " << i+1 << ":" << endl;
		map<int,list<Edge> > G;
		map<int,int> dist;
		for (int j=0;j<K;++j)
		{
			cin >> A >> B >> C;
			G.insert(make_pair(A,list<Edge>()));
			dist[A] = MAX_INTEGER;
			dist[B] = MAX_INTEGER;
			G[A].push_back(Edge(B,C));
		}
		cin >> A >> B;
		int answer = dijkstra(G,A,B,V,dist);
		if (answer == MAX_INTEGER)
			cout << "NO" << endl;
		else
			cout << answer << endl;
		//printGraph(G);
	}
}
