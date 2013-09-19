/* Alex Velazquez
 * Start: Thu Oct 25 10:18:02 EDT 2012
 * End  : Thu Oct 25 10:27:59 EDT 2012
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

int power2[32];

int GCD (int a, int b) {
   while (b != 0) {
      int t = b;
      b = a % b;
      a = t;
   }
   return a;
}

int toInt (string S) {
   int size = SZ(S);
   int num = 0;
   for (int i=size-1; i>=0; --i) {
      if (S[i] == '1')
         num += power2[size-1-i];
   }
   return num;
}

int main ()
{
   power2[0] = 1;
   for (int i=1; i<31; ++i) {
      power2[i] = power2[i-1]*2;
   }
   int N;
   cin >> N;
   REP( i, N ) {
      string S1, S2;
      cin >> S1 >> S2;
      cout << "Pair #" << i+1 << ": ";
      if (GCD(toInt(S1), toInt(S2)) > 1) {
         cout << "All you need is love!" << endl;
      }
      else {
         cout << "Love is not all you need!" << endl;
      }
   }
}
