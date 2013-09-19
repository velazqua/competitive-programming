/* Alex Velazquez
 * Start: Thu Apr 25 16:28:47 EDT 2013
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

int main ()
{
  int N;
  while (cin >> N) {
    vector< vector<int> > seq;
    int prev = -1;
    vector<int> curr;
    for (int i = 0; i < N; i++) {
      int x;
      cin >> x;
      if (prev == x) {
        seq.push_back(curr);
        curr.clear();
      }
      curr.push_back(x);
      prev = x;
    }
    if (!curr.empty())
      seq.push_back(curr);
    int maxx = 0;
    for(vector<vi>::iterator it = seq.begin();
        it != seq.end();
        it++) {
      vi T = *it;
      int s = it->size();
      vector<int> inc(s, 0);
      vector<int> dec(s, 0);
      int currInc = 0;
      int currDec = 0;
      int prev = -1;
      int prevD = -1;
      for (int i = 0; i < s; i++) {
        if (T[i] > prev)
          currInc++;
        else
          currInc = 1;

        if (T[s-i-1] > prevD)
          currDec++;
        else
          currDec = 1;
        inc[i] = currInc;
        dec[s-i-1] = currDec;
        prev = T[i];
        prevD = T[s-i-1];
      }
      int localMaxx = 0;
      for (int i = 0; i < s; i++) {
        cout << inc[i] << " " << dec[i] << endl;
        localMaxx = max(localMaxx, min(inc[i], dec[i]));
      }
      maxx = max(maxx, localMaxx);
    }
    cout << maxx*2-1 << endl;
  }
}
