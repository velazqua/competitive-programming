/* Alex Velazquez
 * Start: Thu Sep 26 12:27:02 EDT 2013
 * End  : Thu Sep 26 12:37:14 EDT 2013
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
  int T;
  cin >> T;
  REP(t, T) {
    int N;
    cin >> N;
    map<string, int> M;
    REP(i, N) {
      string S;
      int val;
      cin >> S >> val;
      M.insert(make_pair(S, val));
    }
    int D;
    cin >> D;
    string S;
    cin >> S;
    map<string,int>::iterator it = M.find(S);
    cout << "Case " << t+1 << ": ";
    if (it == M.end()) {
      cout << "Do your own homework!" << endl;
    }
    else {
      if (it->second <= D) {
        cout << "Yesss" << endl;
      }
      else if (it->second <= D + 5) {
        cout << "Late" << endl;
      }
      else {
        cout << "Do your own homework!" << endl;
      }
    }
  }
}
