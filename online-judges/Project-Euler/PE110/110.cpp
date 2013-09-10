/* Alex Velazquez
 * Start: Sat Aug 24 14:25:50 EDT 2013
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

/* 1/k = 1/x + 1/y
 * 1/k - 1/y = 1/x
 * x/k - x/y = 1
 * x - x*k/y = k
 * xy - xk = yk
 * x(y-k) = yk
 * x = yk/(y-k)
 * ex. k = 12, y = 13
 * x = (12*13)/(12+13)
 *   = 
*/

int main ()
{
  for(ulld k = 4000000; k < 4001000; k++) {
    int numSolutions = 0;
    for(ulld y = k+1; y <= 2*k; y++) {
      if ((y * k)%(y - k) == 0) {
        numSolutions++;
      }
    }
    cout << "k: " << k << ". numSolutions: " << numSolutions << endl;
  }
}
