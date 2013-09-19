/* Alex Velazquez
 * Start: Sat May 11 17:10:16 EDT 2013
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
  int n1;
  int n2;
  int cost;
  Edge(int a, int b, int c) : n1(a), n2(b), cost(c) {}
};

bool operator < (Edge const& A, Edge const& B) {
  if (A.cost != B.cost)
    return A.cost < B.cost;
  else {
    if (A.n1 != B.n1)
      return A.n1 < B.n1;
    else
      return A.n2 < B.n2;
  }
}

int main ()
{
  int m, n;
  while (cin >> m >> n) {
    if (!m && !n)
      break;
    set<Edge> E;
    int total = 0;
    REP(i, n) {
      int x, y, z;
      cin >> x >> y >> z;
      if (x > y)
        swap(x, y);
      E.insert(Edge(x, y, z));
      total += z;
    }
    int numEdges = 0;
    vector<bool> visited(m, false);
    int ans = 0;
    set<Edge>::iterator it = E.begin();
    visited[it->n1] = true;
    visited[it->n2] = true;
    numEdges++;
    ans += it->cost;
    E.erase(it);
    while (numEdges != m-1) {
      it = E.begin();
      while (it != E.end()) {
        if ((visited[it->n1] && !visited[it->n2]) || (
             !visited[it->n1] && visited[it->n2])) {
          visited[it->n1] = true;
          visited[it->n2] = true;
          ans += it->cost;
          numEdges++;
          E.erase(it);
          break;
        }
        it++;
      }
    }
    cout << total-ans << endl;
  }
}
