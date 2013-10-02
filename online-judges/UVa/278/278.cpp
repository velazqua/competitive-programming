/* Alex Velazquez
 * Start: Mon Sep 30 14:08:10 EDT 2013
 * End  : Tue Oct  1 20:42:10 EDT 2013
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
    char p;
    cin >> p;
    int r, c;
    cin >> r >> c;
    if (r > c)
      swap(r, c);
    if (p == 'r' || p == 'Q') { //rook
      cout << min(r, c) << endl;
    }
    else if (p == 'k') { //knight
      cout << max((r*c)/2, r*c-(r*c)/2) << endl;
    }
    else if (p == 'K') { //king
      cout << ((c+1)/2)*((r+1)/2) << endl;
    }
  }
}
