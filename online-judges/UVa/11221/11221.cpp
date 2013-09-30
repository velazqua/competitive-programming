/* Alex Velazquez
 * Start: Mon Sep 30 13:01:41 EDT 2013
 * End  : Mon Sep 30 13:14:36 EDT 2013
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
    if (t == 0) cin.ignore();
    string line;
    getline(cin, line);
    string S;
    REP(i, SZ(line))
      if (line[i] >= 'a' && line[i] <= 'z')
        S += line[i];
    int sq = sqrt(SZ(S));
    cout << "Case #" << t+1 << ":" << endl;
    if (sq*sq == SZ(S)) {
      vector< vector<char> > V(sq, vector<char>(sq, '0'));
      int k = 0;
      REP(i, sq) {
        REP(j, sq) {
          V[i][j] = S[k++];
        }
      }
      bool noMagic = false;

      // (1,1) move down
      k = 0;
      REP(j, sq) {
        if (noMagic)
          break;
        REP(i, sq) {
          if (S[k++] != V[i][j]) {
            noMagic = true;
            break;
          }
        }
      }

      // (K,K) move left
      k = 0;
      for(int i = sq-1; i >= 0; i--) {
        if (noMagic)
          break;
        for(int j = sq-1; j >= 0; j--) {
          if (S[k++] != V[i][j]) {
            noMagic = true;
            break;
          }
        }
      }

      // (K,K) move up
      k = 0;
      for(int j = sq-1; j >= 0; j--) {
        if (noMagic)
          break;
        for(int i = sq-1; i >= 0; i--) {
          if (S[k++] != V[i][j]) {
            noMagic = true;
            break;
          }
        }
      }
      if (!noMagic) {
        cout << sq << endl;
      }
      else {
        cout << "No magic :(" << endl;
      }
    }
    else {
      cout << "No magic :(" << endl;
    }
  }
}
