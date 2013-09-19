/* Alex Velazquez
 * Start: Thu Sep 13 17:34:32 EDT 2012
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
		vector<int> div;
		for( int i=1; i*i<=N; ++i )
		{
			if( N % i == 0 )
			{
				div.push_back( i );
			}
		}
		sort( div.begin(), div.end() );
		int size = SZ(div);
		cout << "SZ: " << size << endl;
		REP( i, size )
		{
			cout << " " << div[i];
		}
		cout << endl;
	}
}
