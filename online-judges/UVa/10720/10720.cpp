/* Alex Velazquez
 * Start: Wed Oct 24 15:27:55 EDT 2012
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

int main ()
{
   int N;
   while (cin >> N) {
      if (!N)
         break;
      int summ = 0;
      bool notPossible = false;
      REP( i, N ) {
         int n;
         cin >> n;
         if (n >= N)
            notPossible = true;
         summ += n;
      }
      if (summ%2 || notPossible) {
         cout << "Not possible" << endl;
      }
      else {
         int numEdges = summ/2;
         
         cout << "Possible" << endl;
      }
   }
}
