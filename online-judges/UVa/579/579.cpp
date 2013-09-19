/* Alex Velazquez
 * Start: Sun Sep  8 16:33:03 EDT 2013
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
  int hour, minute;
  char colon;
  while (cin >> hour >> colon >> minute) {
    if (hour == 0 && minute == 0)
      break;
    double hourDegree = (hour % 12) * 30 + minute/2.0;
    double minuteDegree = (36.0 * minute)/6;
    printf("%.3f\n", min(abs(hourDegree-minuteDegree), 360-abs(hourDegree-minuteDegree)));
  }
}
