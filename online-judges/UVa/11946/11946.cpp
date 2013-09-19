/* Alex Velazquez
 * Start: Wed Oct 31 13:59:00 EDT 2012
 * End  : Wed Oct 31 14:49:27 EDT 2012
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
   vector<char> C(300, 0);
   string S1 = "H3LL0 MY L0V3, 1 M H499Y 83C4U53 500N 1 W1LL 83 70 Y0UR 51D3. 7H15 71M3 W17H0U7 Y0U H45 833N 373RN4L. 1 1NV173 Y0U 70 7H3 200 0N3 70 533 7H3 238R45 4ND 60R1L45.";
   string S2 = "HELLO MY LOVE, I M HAPPY BECAUSE SOON I WILL BE TO YOUR SIDE. THIS TIME WITHOUT YOU HAS BEEN ETERNAL. I INVITE YOU TO THE ZOO ONE TO SEE THE ZEBRAS AND GORILAS.";
   int size = SZ(S1);
   REP( i, size ) {
      C[S1[i]] = S2[i];
   }
   int T;
   scanf( "%d\n", &T );
   char c;
   while (1) {
      c = getchar();
      if (c == EOF)
         break;
      else if (c >= '0' && c <= '9'){
         printf( "%c", C[c] );
      }
      else {
         printf( "%c", c );
      }
   }

}
