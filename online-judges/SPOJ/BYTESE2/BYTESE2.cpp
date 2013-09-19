/* Alex Velazquez
 * Start: Sat Sep 15 19:08:40 EDT 2012
 * End  : Sat Sep 15 19:33:23 EDT 2012
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
	cin >> T;
	REP( t, T )
	{
		int N;
		cin >> N;
		vector< pair<int,int> > P;
		vector<int> nums( 2*N );
		REP( i, N )
		{
			int a, b;
			cin >> a >> b;
			nums[2*i] = a;
			nums[2*i+1] = b; 
			P.push_back( make_pair( a, b ) );
		}
		int maxx = 0;
		REP( i, 2*N )
		{
			int counter = 0;
			for( vector< pair<int,int> >::iterator it = P.begin(); it != P.end(); ++it )
			{
				if( nums[i] >= it->first && nums[i] <= it->second )
					++counter;
			}
			maxx = max( maxx, counter );
		}
		cout << maxx << endl;
	}
}
