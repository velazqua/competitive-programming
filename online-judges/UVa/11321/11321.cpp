/* Alex Velazquez
 * Start: Tue Oct 23 22:41:46 EDT 2012
 * End  : Wed Oct 24 15:03:40 EDT 2012
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

struct Num {
   int n1;
   int n2;
   Num (int N1, int N2) : n1(N1), n2(N2) {}
};

bool operator < (Num const& A, Num const& B) {
   if (A.n2 < B.n2) {
      return true;
   }
   else if (A.n2 > B.n2) {
      return false;
   }
   else {
      int X = abs(A.n1%2), Y = abs(B.n1%2);
      if (X == 0 && Y == 0) {
         return (A.n1 < B.n1);
      }
      else if (X == 1 && Y == 1) {
         return (B.n1 < A.n1);
      }
      else {
         if (X == 1 && Y == 0) {
            return true;
         }
         else {
            return false;
         }
      }
   }   
}

int main ()
{
   int N, M;
   while (cin >> N >> M) {
      cout << N << " " << M << endl;
      if (!N && !M) {
         break;
      }
      vector<Num> allNumbers;
      REP( i, N ) {
         int n;
         cin >> n;
         allNumbers.push_back(Num(n,n%M));
      }
      sort(allNumbers.begin(), allNumbers.end());
      REP( i, N ) {
         cout << allNumbers[i].n1 << endl;
      }
   }
}
