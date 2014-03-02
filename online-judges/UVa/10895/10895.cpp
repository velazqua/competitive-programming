/* Alex Velazquez
 * Start: Tue Oct 15 21:58:08 EDT 2013
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

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;

int main ()
{
  int rows, columns;
  cin >> rows >> columns;
  vector< vector< pair<int, int> > > T(columns+1);
  for (int r = 1; r <= rows; r++) {
    int e;
    cin >> e;
    vector<int> C(e), val(e);
    REP(i, e) {
      cin >> C[i];
    }
    REP(i, e) {
      cin >> val[i];
    }
    REP(i, e) {
      T[C[i]].push_back(make_pair(r, val[i]));
    }
  }
  cout << columns << " " << rows << endl;
  for(int r = 1; r <= columns; r++) {
    int size = T[r].size();
    cout << size;
    REP(i, size) {
      cout << " " << T[r][i].first;
    }
    cout << endl;
    REP(i, size) {
      if (i != 0)
        cout << " ";
      cout << T[r][i].second;
    }
    cout << endl;
  }
}
