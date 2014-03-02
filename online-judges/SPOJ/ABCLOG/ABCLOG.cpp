/* Alex Velazquez
 * Start: Mon Jan  6 07:20:46 EST 2014
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
typedef long long int lld;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;

lld invertBits (lld num) {
  lld newNum = 0;
  while (num != 0) {
    newNum <<= 1;
    newNum |= (num & 1);
    num >>= 1;
  }
  return newNum;
}

int main ()
{
  lld num;
  while (cin >> num) {
    if (num == -1) break;
    cout << invertBits(num) << endl;
  }
}
