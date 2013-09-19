/* Alex Velazquez
 * Start: Mon Apr  2 23:57:10 EDT 2012
 * End  : Tue Apr  3 00:21:29 EDT 2012
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
	//calculate all squares up to 10000
	set<int> isSquare;
	vector<int> square( 10001 );
	for( int i=0; i<=100; ++i )
	{
		isSquare.insert( i*i );
		square[i*i] = i;
	}
	int T;
	cin >> T;
	REP( i, T )
	{
		int A, B, C;
		cin >> A >> B >> C;
		bool found = false;
		for( int x=-100; x<=100 && !found; ++x )
		{
			for( int y=x+1; y<=100 && !found; ++y )
			{
				int s = C - (x*x + y*y);
				if( isSquare.count( s ) > 0 )
				{
					int z = square[s];
					if( x*y*z == B && x+y+z == A && x != z && y != z )
					{
						cout << x << " " << y << " " << z << endl;
						found = true;
						break;
					}
				}
			}
		}
		if( !found )
			cout << "No solution." << endl;
		
	}
}
