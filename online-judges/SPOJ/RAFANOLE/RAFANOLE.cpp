/* Alex Velazquez
 * Start: Tue Jan  7 10:21:42 EST 2014
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

bool wonGame (int a, int b) {
  return a >= 4 && a-b >= 2;
}

int main ()
{
  int T;
  cin >> T;
  REP(t, T) {
    if (t == 0) cin.ignore();
    if (t != 0) cout << endl;
    string line;
    getline(cin, line);
    stringstream ss(line);
    char token;
    int N = 0, D = 0, nSets = 0, dSets = 0;
    bool tiebreak = false;
    while (ss >> token) {
      if (token == 'N') {
        N++;
      }
      else {
        D++;
      }
      if (tiebreak) {
        // do nothing
      }
      else {
        if (wonGame(N, D)) {
          nSets++;
          N = 0, D = 0;
        }
        else if (wonGame(D, N)) {
          dSets++;
          N = 0, D = 0;
        }
        if (nSets == 6 && dSets == 6) {
          tiebreak = true;
          D = 0;
          N = 0;
        }
      }
    }
    // determine who won the game
    if ((dSets > nSets) || (D > N)) {
      cout << "D " << ((!tiebreak) ? dSets : dSets+1);
      if (tiebreak) {
        cout << " (" << D << "-" << N << ")";
      }
      cout << endl;
      cout << "N " << nSets << endl;
    }
    else if ((nSets > dSets) || (N > D)) {
      cout << "N " << ((!tiebreak) ? nSets : nSets+1);
      if (tiebreak) {
        cout << " (" << N << "-" << D << ")";
      }
      cout << endl;
      cout << "D " << dSets << endl;
    }
  }
}
