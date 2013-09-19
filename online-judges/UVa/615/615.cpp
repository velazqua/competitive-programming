/* Alex Velazquez
 * Start: Thu Oct 25 10:40:25 EDT 2012
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

void dfs( map<int,vi> &G, int i, map<int,bool> &visited, bool &isTree) {
   if (visited[i]) {
      isTree = false;
   }
   else {
      visited[i] = true;
      for (vi::iterator it = G[i].begin(); it != G[i].end(); ++it ) {
         dfs(G, *it, visited, isTree);
      }
   }
}

int main ()
{
   int v1, v2;
   map<int,vi> G;
   set<int> nodes;
   map<int,bool> theRoot;
   int c = 1;
   while (cin >> v1 >> v2) {
      if (v1 < 0 && v2 < 0) {
         break;
      }
      if (v1 == 0 && v2 == 0) {
         cout << "Case " << c++ << " ";
         // check if directed graph is a tree
         
         // check if tree is empty
         if (nodes.empty()) {
            cout << "is a tree." << endl;
            G.clear();
            nodes.clear();
            theRoot.clear();
            continue;
         }
         // find root
         int numRoots = 0;
         int root;
         for (set<int>::iterator it = nodes.begin(); it != nodes.end(); ++it ) {
            if (!theRoot[*it]) {
               numRoots++;
               root = *it;
            }
         }
         if (numRoots != 1) {
            cout << "is not a tree." << endl;
         }
         else {
            map<int,bool> visited;
            bool isTree = true;
            dfs(G,root,visited,isTree);
         
            // check if all nodes have been visited
            for (set<int>::iterator it = nodes.begin(); it != nodes.end(); ++it ) {
               if (!visited[*it]) {
                  isTree = false;
               }
            }
            if (isTree) {
               cout << "is a tree." << endl;
            }
            else {
               cout << "is not a tree." << endl;
            }
         }
         G.clear();
         nodes.clear();
         theRoot.clear();
      }
      else {
         nodes.insert(v1);
         nodes.insert(v2);
         G[v1].push_back(v2);
         theRoot[v2] = true;
      }
      
   }
}
