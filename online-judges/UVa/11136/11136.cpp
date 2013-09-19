/* Alex Velazquez
 * Start: Fri Aug 16 20:47:29 EDT 2013
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
  int N;
  while (scanf("%d", &N)) {
    if (!N)
      break;
    multiset<int> allNums;
    int promotion = 0;
    REP(i, N) {
      int b;
      scanf("%d", &b);
      REP(j, b) {
        int num;
        scanf("%d", &num);
        allNums.insert(num);
      }
      multiset<int>::iterator big = allNums.end();
      big--;
      multiset<int>::iterator small = allNums.begin();
      promotion += *big - *small;
      allNums.erase(big);
      allNums.erase(small);
    }
    printf("%d\n", promotion);
  }
}
