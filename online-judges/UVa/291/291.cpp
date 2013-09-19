/* Alex Velazquez
 * Start: Fri Jul 12 21:27:02 PDT 2013
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

void dfs(int start, int end, vector<vi>& G, int counter, string path, vector<bool>& visited)
{
  if (!visited[start*end]) {
    visited[start*end] = true;
    counter++;
    path += char(end+48);
    if (counter == 9) {
      cout << path << endl;
    }
    else {
      for(int i = 0; i < int(G[end].size()); i++) {
        dfs(end, G[end][i], G, counter, path, visited);
      }
    }
    visited[start*end] = false;
  }
}

int main ()
{
  vector< vector<int> > V(6);
  V[1].push_back(2); V[1].push_back(3); V[1].push_back(5);
  V[2].push_back(1); V[2].push_back(3); V[2].push_back(5);
  V[3].push_back(1); V[3].push_back(2); V[3].push_back(4); V[3].push_back(5);
  V[4].push_back(3); V[4].push_back(5);
  V[5].push_back(1); V[5].push_back(2); V[5].push_back(3); V[5].push_back(4);
  int counter = 0; // if it reaches 8, output path
  string path;
  vector<bool> visited(21, false);
  dfs(0, 1, V, 0, "", visited);
}
