/* Alex Velazquez
 * Start: Thu May  9 23:54:54 EDT 2013
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

typedef unsigned long long int ulld;
typedef map<int,pair<int,set<int> > > MAP;
typedef MAP::iterator MAP_ITER;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;

int main ()
{
  int N;
  cin >> N;
  vector<int> V(N, 0);
  MAP sums;
  MAP mult;
  REP(i, N) {
    cin >> V[i];
  }
  REP(i, N) {
    FOR(j, i+1, N) {
      MAP_ITER it1 = sums.find(V[i]+V[j]);
      it1.first += 2;
      it1.second.insert(V[i]);
      it1.second.insert(V[j]);

      MAP_ITER it2 = mult.find(V[i]*V[j]);
      it2.first += 2;
      it2.second.insert(V[i]);
      it2.second.insert(V[j]);
    }
  }
  REP(i, N) {
    
  }
}
