/* Alex Velazquez
 * Start: Sun Apr 15 17:40:55 EDT 2012
 * End  : Sun Apr 15 18:04:41 EDT 2012
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

typedef long long int LL;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main ()
{
	// compute all squares
	set<int> squares;
	map<int,int> squareRoot;
	for( int i=1; i<10000; ++i )
		squares.insert( i*i ), squareRoot[i*i] = i;
	int N;
	while( cin >> N )
	{
		if( !N ) break;
		bool found = false;
		vector<pair<int,int> > sols;
		for( int i=1; i*i<=N; ++i )
		{
			if( N%i == 0 )
			{
				int a = i;
				int b = N/i;
				int checkSquare = (3*a)*(3*a)-12*(a*a-b);
				if( squares.count( checkSquare ) )
				{
					int top = squareRoot[checkSquare]-3*a;
					if( top%6 == 0 )
					{
						if( a+(top/6) > 0 && top/6 > 0 )
						{
							sols.push_back( make_pair( top/6, a+(top/6) ) );
							found = true;
						}
					}	
				}
			}
		}
		if( !found )
			cout << "No solution" << endl;
		else
		{
			sort( sols.begin(), sols.end() );
			cout << sols[0].second << " " << sols[0].first << endl;
		}
	}
}
