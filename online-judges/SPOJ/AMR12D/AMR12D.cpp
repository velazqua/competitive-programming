/* Alex Velazquez
 * Start: Mon Jan  7 08:11:02 EST 2013
 * End  : Mon Jan  7 08:24:37 EST 2013
*/
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <deque>

using namespace std;

#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()
#define SZ(A)        (A).size()
#define FST(A)       (A).first
#define SEC(A)       (A).second
#define DEBUG 0

typedef long long int LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main ()
{
  int T;
  cin >> T;
  REP(i, T) {
    string S;
    cin >> S;
    int size = SZ(S);
    set<string> subs;
    set<string> revs;
    for (int k = 0; k < size; k++) {
      for (int j = 1; k+j-1 < size; j++) {
        string s = S.substr(k, j);
        subs.insert(s);
        reverse(s.begin(), s.end());
        revs.insert(s);
      }
    }
    bool found = true;
    for (set<string>::iterator it = subs.begin(); it != subs.end(); it++) {
      if (revs.find(*it) == revs.end()) {
        found = false;
        break;
      }
    }
    if (!found) {
      cout << "NO" << endl;
    }
    else {
      cout << "YES" << endl;
    }
  }
}
