/* Alex Velazquez
 * Start: Wed Sep 26 21:12:12 EDT 2012
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
	int C = 16000;
	REP( t, 10 )
	{
		int N;
		cin >> N;
		vector< pair<int,int> > points;
		vector< set<int> > M( 32100 );
		REP( i, N )
		{
			int x, y;
			cin >> x >> y;
			points.push_back( make_pair( x+C, y+C ) );
			M[x+C].insert( y+C );
		}
		int P = 0;
		FOR( i, 0, N-1 )
		{
			FOR( j, i+1, N )
			{
				int x1 = points[i].first;
				int y1 = points[i].second;
				int x4 = points[j].first;
				int y4 = points[j].second;
				if( x1 != x4 && y1 != y4 )
				{
					// Look for point (points[i].first,points[j].second)
					if( !M[x1].empty() && M[x1].find(y4) != M[x1].end() ){}
					else
						continue;
						
					// Look for point (points[j].first,points[i].second)
					if( !M[x4].empty() && M[x4].find(y1) != M[x4].end() ){}
					else
						continue;
					cout << i+1 << " " << j+1 << endl;
					++P;
				}
			}
		}
		cout << P << endl;
	}
}
