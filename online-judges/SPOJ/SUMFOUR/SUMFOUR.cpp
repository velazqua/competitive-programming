/* Alex Velazquez
 * Start: Sat May 26 00:58:00 EDT 2012
 * End  :
*/
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <deque>

using namespace std;

#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()
#define DEBUG 0

typedef long long int LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector<int> pos(540000000, 0);
vector<int> neg(540000000, 0);

int main ()
{
	int N;
	scanf( "%d\n", &N );
	vector<int> A( N ), B( N ), C( N ), D( N );
	REP( i, N )
	{
		scanf( "%d %d %d %d\n", &A[i], &B[i], &C[i], &D[i] );
	}
  int zeros = 0;
	REP( i, N )
	{
		REP( j, N )
		{
      int num = C[i]+D[j];
      if (num > 0)
        pos[num]++;
      else if (num < 0)
        neg[num*-1]++;
      else
        zeros++;
		}
	}
  int total = 0;
  REP(i, N) {
    REP(j, N) {
      int num = A[i]+B[j];
      if (num > 0)
        total += neg[num];
      else if (num < 0)
        total += pos[num*-1];
      else
        total += zeros;
    }
  }
	printf( "%d\n", total );
}
