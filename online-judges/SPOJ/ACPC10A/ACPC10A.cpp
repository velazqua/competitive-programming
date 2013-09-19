/* Alex Velazquez
 * Start: Thu Apr 25 22:38:26 EDT 2013
 * End  : Thu Apr 25 22:47:41 EDT 2013
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
  int a, b, c;
  while (cin >> a >> b >> c) {
    if (a == 0 && b == 0 && c == 0)
      break;
    if (a-b == b-c)
      cout << "AP " << 2*c-b << endl;
    else
      cout << "GP " << (b/a)*c << endl;
  }
}
