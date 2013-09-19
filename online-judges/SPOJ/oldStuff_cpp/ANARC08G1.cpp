#include <iostream>
#include <map>
#include <utility>

using namespace std;

void printEdge (map<pair<int,int>,int>::iterator it)
{
	cout << "(" << it->first.first << "," << it->first.second << ") => " << it->second;
}

int main ()
{
	map<pair<int,int>,int> G;
	G.insert(make_pair(make_pair(1,2),50));
	G.insert(make_pair(make_pair(2,1),150));
	G.insert(make_pair(make_pair(1,3),100));
	G.insert(make_pair(make_pair(2,3),20));
	G.insert(make_pair(make_pair(4,1),30));
	G.insert(make_pair(make_pair(3,4),30));
	map<pair<int,int>,int>::iterator it=G.begin();
	map<pair<int,int>,int>::iterator itEnd=G.end();
	map<pair<int,int>,int>::iterator it2=G.begin();
	map<pair<int,int>,int>::iterator itEnd2=G.end();
	
	it=G.begin();
	itEnd=G.end();
	cout << "Before: " << endl;
	int totalCost=0;
	for ( ; it != itEnd ; ++it ) 
	{
		totalCost += it->second;
		cout << "(" << it->first.first << "," << it->first.second << ") => " << it->second << endl;
	}
	
	int X, Y, reducedCost=0;
	it=G.begin();
	itEnd=G.end();
	
	for ( ; it != itEnd ; ++it ) 
	{
		cout << "EDGE1: ";
		printEdge(it);
		cout << endl;
		X = it->first.second;
		for (it2=G.begin() ; it2 != itEnd2 ; ++it2 )
		{
			cout << "EDGE2: ";
			printEdge(it2);
			cout << endl;	
			if (it == it2)
				continue;
			
			Y = it2->first.first;
			if (X == Y) // connection
			{
				if (it->second < it2->second)
				{
					G[make_pair(it2->first.first,it2->first.second)] -= it->second;
					cout << "ERASING: ";
					printEdge(it);
					cout << endl;
					G.erase(it);
					break;
				}
				else if (it->second == it2->second)
				{
					pair <map<pair<int,int>,int>::iterator,bool> checkIt = G.insert(make_pair(make_pair(it->first.first,it2->first.second),it->second));
					if (checkIt.second == false) // not inserted
					{
						G[make_pair(checkIt.first->first.first,checkIt.first->first.second)] += it2->second;
					}
					cout << "ERASING: ";
					printEdge(it);
					cout << " AND ";
					printEdge(it2);
					cout << endl;
					G.erase(it);
					G.erase(it2);
				}
				
				else
				{
					G[make_pair(it->first.first,it->first.second)] -= it2->second;
					//assuming new edge doesnt exist .. we most fix this
					pair<map<pair<int,int>,int>::iterator,bool> checkIt = G.insert(make_pair(make_pair(it->first.first,it2->first.second),it2->second));
					if (checkIt.second == false) // not inserted
					{
						G[make_pair(checkIt.first->first.first,checkIt.first->first.second)] += it2->second;
					}
					cout << "ERASING: "; 
					printEdge(it2); 
					cout << endl;
					G.erase(it2);					
				}
				
			}
		}
	}
	
	it=G.begin();
	itEnd=G.end();
	cout << "After: " << endl;
	for ( ; it != itEnd ; ++it ) 
	{
		reducedCost += it->second;
		cout << "(" << it->first.first << "," << it->first.second << ") => " << it->second << endl;
	}
	
	cout << totalCost << " " << reducedCost << endl;
	
}
