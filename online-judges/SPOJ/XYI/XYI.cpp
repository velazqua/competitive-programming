/* Alex Velazquez
 * Start: Thu Jan  2 19:49:33 EST 2014
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
   int T;
   cin >> T;
   REP(t, T) {
    cout << "Case " << t+1 << ": ";
    int N, M;
    cin >> N >> M;
    vector<int> deg(M+1, 0);
    vector<int> vertexDeg(N+1, 0);
    REP(i, M) {
      int a, b;
      cin >> a >> b;
      vertexDeg[a]++;
      vertexDeg[b]++;
    }

    for(int i = 1; i <= N; i++) {
      deg[vertexDeg[i]]++;
    }

    bool invalid = false;
    for(int i = 5; i <= M; i++) {
      if (deg[i] > 0) {
        invalid = true;
        break;
      }
    }
    if (invalid) {
      cout << "NotValid" << endl;
    }
    else {
      if (deg[1] == 4 && deg[3] == 0 && deg[4] == 1) {
        cout << "X" << endl;
      }
      else if (deg[1] == 3 && deg[3] == 1 && deg[4] == 0) {
        cout << "Y" << endl;
      }
      else if (deg[1] == 2 && deg[3] == 0 && deg[4] == 0) {
        cout << "I" << endl;
      }
      else {
        cout << "NotValid" << endl;
      }
    }
  }
}
