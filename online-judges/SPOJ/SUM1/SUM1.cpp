/* Alex Velazquez
 * Start: Thu May  9 15:55:10 EDT 2013
 * End  : Thu May  9 16:06:24 EDT 2013
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
typedef unsigned long long int ulld;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;

ulld sum (ulld x, ulld N) {
  N--;
  return (N/x * (x + x+(N/x-1)*x))/2LL;
}

int main ()
{
  int T;
  cin >> T;
  REP(t, T) {
    ulld N;
    cin >> N;
    cout << sum(3LL, N) + sum(5LL, N) - sum(15LL, N) << endl;
  }
}
