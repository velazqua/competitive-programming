/* Alex Velazquez
 * Start: Mon Jan  6 07:45:37 EST 2014
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

string getSeq (int n) {
  string S;
  while (n != 1) {
    S += ((n % 2) ? 'F' : 'M');
    n /= 2;
  }
  S += 'F';
  reverse(S.begin(), S.end());
  return S;
}

double getWeight (string s) {
  int W = 1;
  REP(i, SZ(s)-1) {
    if (s[i] == 'F')
      W *= ((s[i+1] == 'M') ? 2 : 4);
    else
      W *= 2;
  }
  return W;
}

int main ()
{
  int T;
  cin >> T;
  REP(t, T) {
    int x, y, W;
    cin >> x >> y >> W;
    double wx = getWeight(getSeq(x));
    double wy = getWeight(getSeq(y));
    printf("%.6f\n", (wx * W)/wy);
  }
}
