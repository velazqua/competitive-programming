/* Name: Alex Velazquez
 * Start Date: August 28, 2011 @ 12:25AM
 * End Date:   ???
 * Purpose: To implement Kruskals algorithm (minimum spanning trees) to solve the Project Euler problem #107
 * Link: http://projecteuler.net/index.php?section=problems&id=107
 * */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <set>
#include <cstdlib>

using namespace std;

struct Edge {
	int V1;
	int V2;
	int W;
	Edge (int v1, int v2, int w) : V1(v1), V2(v2), W(w) {}
};

bool operator < (Edge const& E1, Edge const& E2)
{
	if (E1.W < E2.W)
		return true;
	else if (E1.W > E2.W)
		return false;
	else
	{
		if (E1.V1 < E2.V1)
			return true;
		else if (E1.V1 > E2.V1)
			return false;
		else
		{
			if (E1.V2 < E2.V2)
				return true;
			else
				return false;
		}
	}
}

void updatePaths (int C[40][40], int const &V1, int const &V2)
{
	C[V1][V2] = 1;
	C[V2][V1] = 1;
	cout << "sup1" << endl;
	for (int k=0;k<40;++k)
	{
		if (C[V1][k] == 1) 
		{
			//isConnected[V2][k] = 1;
			//isConnected[k][V2] = 1;
			updatePaths(C,k,V2);
		}
		if (C[V2][k] == 1) 
		{
			//isConnected[V1][k] = 1;
			//isConnected[k][V1] = 1;
			updatePaths(C,k,V1);
		}
	}
}
 or A
int main ()
{
	/* we need an array that keeps track of what vertices are connected */
	int V = 40; // network.txt has 40 vertices!
	int isConnected[40][40];
	for (int i=0;i<V;++i)
		for (int j=0;j<V;++j)
			isConnected[i][j] = 0;
	
	/* read input */
	ifstream fin;
	fin.open("network4.txt");
	string input;
	set<Edge> E;
	int i=0;
	int j=0;
	int TOTAL_WEIGHT = 0;

	while (getline(fin,input))
	{
		stringstream ss(input);
		string token;
		j = 0;
		while (getline(ss,token,','))
		{
			if (token != "-")
			{
				//if (j == 38) cout << "TOKEN#38:@" << token << "@" << endl;
				//if (j == 39) cout << "TOKEN#39:@" << token << "@" << endl;
				istringstream t(token);
				//int value = atoi(token.c_str());
				int value;
				t >> value;
				//if (!t.good()) cout << value << " " << i << " " << j << endl;
				cout << "Inserting: " << i << " " << j << " " << value << endl;
				E.insert(Edge(i,j,value));
				TOTAL_WEIGHT += value;	
			}
			++j;
		}
		isConnected[i][i] = 1; // each vertex is connected to itself
		++i;
	}
	TOTAL_WEIGHT /= 2;
	int MINIMUM_WEIGHT = 0;
	while (!E.empty())
	{
		set<Edge>::iterator it = E.begin(); // edge with minimum weight
		//cout << it->V1 << " " << it->V2 << " " << it->W;
		if (isConnected[it->V1][it->V2] == 0) // if there is no path between the vertices
		{
			//cout << " MADE IT";
			cout << it->V1 << " " << it->V2 << " " << it->W << endl;
			MINIMUM_WEIGHT += it->W; 
			isConnected[it->V1][it->V2] = 1;
			isConnected[it->V2][it->V1] = 1;
			// update paths between vertices
			updatePaths(isConnected,it->V1,it->V2);
			/* or A
			for (int k=0;k<V;++k)
			{
				if (isConnected[it->V1][k] == 1 || isConnected[k][it->V1] == 1) 
				{
					isConnected[it->V1][k] = 1;
					isConnected[it->V2][k] = 1;
					isConnected[k][it->V2] = 1;
					isConnected[k][it->V1] = 1;
				}
				if (isConnected[it->V2][k] == 1 || isConnected[k][it->V2] == 1) 
				{
					isConnected[it->V2][k] = 1; 
					isConnected[it->V1][k] = 1;
					isConnected[k][it->V1] = 1;
					isConnected[k][it->V2] = 1;
				}
			}
			**/
				for (int i=0;i<V;++i)
				{
					for (int j=0;j<V;++j)
					{
						cout << isConnected[i][j];
					}
					cout << endl;
				}
			
		}
		E.erase(it);
	}
	
	cout << "Total weight: " << TOTAL_WEIGHT << endl;
	cout << "Minimum weight: " << MINIMUM_WEIGHT << endl;
	cout << "Maximum savings: " << TOTAL_WEIGHT-MINIMUM_WEIGHT << endl;
	fin.close();
}
