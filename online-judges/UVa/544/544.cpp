/* Alex Velazquez
 * Start: Thu Nov  1 00:11:59 EDT 2012
 * End  :
*/
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <utility>
#include <vector>

#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()
#define SZ(A)        int((A).size())
#define PB           push_back
#define FST(A)       (A).first
#define SEC(A)       (A).second
#define DEBUG        0

typedef long long int LL;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;

struct Edge {
   string c1;
   string c2;
   int cost;
   Edge (string C1, string C2, int C) : c1(C1), c2(C2), cost(C) {}
};

bool operator < (Edge const& A, Edge const& B) {
   if (A.cost != B.cost)
      return A.cost > B.cost;
   else {
      if (A.c1 != B.c1)
         return A.c1.compare(B.c1) > 0 ? true : false;
      else
         return A.c2.compare(B.c2) > 0 ? true : false;
   }
}

int main ()
{
   int n, m;
   int c = 1;
   while (cin >> n >> m) {
      if (!n && !m) 
         break;
      if (c > 1)
         cout << endl;
      cout << "Scenario #" << c++ << endl;
      set<Edge> edges;
      set<string> nameEdges;
      REP( i, m ) {
         string c1, c2;
         int cost;
         cin >> c1 >> c2 >> cost;
         edges.insert(Edge(c1, c2, cost));
         nameEdges.insert(c1);
         nameEdges.insert(c2);
      }
      string start, end;
      cin >> start >> end;
      set<Edge> tree;
      set<string> inTree;
      map<string, vector< pair<string,int> > > M;
      for( set<Edge>::iterator it = edges.begin(); it != edges.end(); ++it ) {
         if (tree.empty()) {
            tree.insert(*it);
            inTree.insert(it->c1);
            inTree.insert(it->c2);
            M[it->c1].PB(make_pair(it->c2, it->cost));
            M[it->c2].PB(make_pair(it->c1, it->cost));
         }
         else {
            string C1 = it->c1;
            string C2 = it->c2;
            bool C1InTree = inTree.find(C1) != inTree.end();
            bool C2InTree = inTree.find(C2) != inTree.end();
            if ((C1InTree && C2InTree) || (!C1InTree && !C2InTree)) 
               continue;
            else {
               tree.insert(*it);
               if (C1InTree) {
                  inTree.insert(C2);
               }
               else {
                  inTree.insert(C1);
               }
               M[it->c1].PB(make_pair(it->c2, it->cost));
               M[it->c2].PB(make_pair(it->c1, it->cost));
            }
         }
      }
   }
}
