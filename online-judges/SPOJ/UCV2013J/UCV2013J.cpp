/* Alex Velazquez
 * Start: Tue Jul 23 22:42:45 PDT 2013
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

int computeIndex (int n) {
  int i = 1;
  while (i * 2 <= n)
    i *= 2;
  return i-1;
}

int main ()
{
  int N;
  while (cin >> N) {
    if (!N)
      break;
    int index = computeIndex(N);
    int summ = 0;
    REP(i, N) {
      int num;
      cin >> num;
      if (i >= index)
        summ += num;
    }
    cout << summ << endl;
  }
}
