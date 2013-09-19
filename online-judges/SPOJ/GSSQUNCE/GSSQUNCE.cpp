/* Alex Velazquez
 * Start: Fri Aug 17 00:15:56 EDT 2012
 * End  : Fri Aug 17 00:36:50 EDT 2012
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
#define SZ(A)        (A).size()
#define FST(A)       (A).first
#define SEC(A)       (A).second
#define DEBUG 0

typedef long long int LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main ()
{
	int T;
	scanf( "%d\n", &T );
	REP( t, T )
	{
		int N;
		scanf( "%d\n", &N );

		map<int,int> M;
		bool notFound = true;
		REP( i, N )
		{
			int num;
			scanf( "%d", &num );
			if( notFound )
			{
				int n = ++M[num];
				if( n > 2 )
					notFound = false;
			} 
		}		
		if( N == 1 ) 
		{
			cout << "NO" << endl;
			continue;
		}
		if( notFound )
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
