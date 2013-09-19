/* Alex Velazquez
 * Start: Sat Jun 29 22:33:37 PDT 2013
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

int dist (int c1, int c2)
{
  int x = abs(c1-c2) * 9;
  if (c1 >= c2)
    return x;
  else
    return 360-x;
}

int main ()
{
  int init, f, s, t;
  while (cin >> init >> f >> s >> t) {
    if (init == 0 && f == 0 && s == 0 && t == 0)
      break;
    int degrees = 360 * 3; // three full turns
    degrees += dist(init, f);
    degrees += dist(s, f);
    degrees += dist(s, t);
    cout << degrees << endl;
  }
}
