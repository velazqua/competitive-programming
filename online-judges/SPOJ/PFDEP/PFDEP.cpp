/* Alex Velazquez
 * Start: Sat Sep 15 21:00:51 EDT 2012
 * End  : Sat Sep 15 21:37:20 EDT 2012
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
#define DEBUG 		 0

typedef long long int LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main ()
{
	int N, M;
	cin >> N >> M;
	vector<bool> used( N+1, false );
	vector<bool> hasDep( N+1, false );
	vector<vi>  deps( N+1 );
	REP( i, M )
	{
		int target, k;
		cin >> target >> k;
		hasDep[target] = true;
		deps[target].push_back( k );
		REP( j, k )
		{
			int x;
			cin >> x;
			deps[target].push_back( x );
		}
	}
	#if DEBUG
		cout << "Got all input" << endl;
	#endif
	bool firstTime = true;
	
	while( 1 )
	{
		bool allUsed = true;
		FOR( j, 1, N+1 )
		{
			if( !used[j] )
			{
				#if DEBUG
					cout << "j: " << j << endl;
				#endif
				allUsed = false;
				// assume no dependencies
				bool done = true;
				
				// check for dependencies
				#if DEBUG
					cout << "Does j: " << j << " have dependencies? : " << hasDep[j] << endl;
				#endif
				if( hasDep[j] )
				{
					#if DEBUG
						cout << "checking dependencies" << endl;
					#endif
					for( int d=1; d<=deps[j][0]; ++d )
					{
						#if DEBUG
							cout << "deps[j][d]: " << deps[j][d] << endl;
						#endif
						if( !used[deps[j][d]] )
						{
							done = false;
							break;
						}
					}
				}
										
				if( done )
				{
					used[j] = true;
					if( firstTime )
					{
						firstTime = false;
						cout << j;
					}
					else
						cout << " " << j;
					break;
				} 
			}
		}
		if( allUsed )
			break;
	}

	cout << endl;
}
