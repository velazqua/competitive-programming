/* Alex Velazquez
 * Start: Fri Sep 14 14:12:49 EDT 2012
 * End  : Fri Sep 14 14:46:19 EDT 2012
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

struct Ring {
	double x;
	double y;
	double r;
	Ring( double X, double Y, double R ) : x(X), y(Y), r(R) {}
};


void explore( vector< vector<bool> > &M, int i, vector<bool> &visited, int &sizeComponent, int &N )
{
	if( !visited[i] )
	{
		sizeComponent++;
		visited[i] = true;
		REP( k, N )
		{
			if( M[i][k] )
			{
				explore( M, k, visited, sizeComponent, N );
			}
		}
	}
}

int main ()
{
	int N;
	while( cin >> N )
	{
		if( N == -1 ) 
			break;
		vector< Ring > rings;
		REP( i, N )
		{
			double x, y, r;
			cin >> x >> y >> r;
			rings.PB( Ring( x, y, r ) );
			#if DEBUG
				cout << "Ring #" << i << endl;
				cout << "x: " << rings[i].x << ". y: " << rings[i].y << ". r: " << rings[i].r << endl;
			#endif
		}
		vector< vector<bool> > M( N, vector<bool> ( N, false ) );
		FOR( i, 0, N-1 )
		{
			FOR( j, i+1, N )
			{
				#if DEBUG
					cout << "Comparing " << i << " and " << j << endl;
					cout << sqrt( (rings[i].x-rings[j].x)*(rings[i].x-rings[j].x) + (rings[i].y-rings[j].y)*(rings[i].y-rings[j].y) )  << " " << (rings[i].r + rings[j].r) << endl;
				#endif
				double d = sqrt( (rings[i].x-rings[j].x)*(rings[i].x-rings[j].x) + (rings[i].y-rings[j].y)*(rings[i].y-rings[j].y ) ); 
				// if these two rings intersect, make a edge in graph
				if( ( rings[i].x == rings[j].x && rings[i].y == rings[j].y && rings[i].r == rings[j].r )
				 || ( ( d <= rings[i].r + rings[j].r) && ( abs(rings[i].r - rings[j].r) <= d ) ) )
				{
					#if DEBUG
						cout << "Rings " << i << " and " << j << " intersect" << endl;
					#endif
					M[i][j] = true;
					M[j][i] = true;
				}
			}
		}
		vector<bool> visited( N, false );
		int maxComponent = 0;
		REP( i, N )
		{
			int sizeComponent = 0;
			explore( M, i, visited, sizeComponent, N );
			maxComponent = max( maxComponent, sizeComponent );
		}
		cout << "The largest component contains " << maxComponent << " ring" << ( ( maxComponent == 1 ) ? "." : "s." ) << endl;
	}
}
