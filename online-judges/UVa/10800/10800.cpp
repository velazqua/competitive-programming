/* Alex Velazquez
 * Start: Mon Feb 20 14:41:08 EST 2012
 * End  :
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

char toSymbol( char c )
{
	if( c == 'R' ) return '/';
	else if( c == 'C' ) return '_';
	else return '\\';
}

bool comp( pair<char,pair<int,int> > A, pair<char,pair<int,int> > B )
{
	if( A.second.second > B.second.second )
		return true;
	else if( A.second.second < B.second.second )
		return false;
	else
	{
		if( A.second.first < B.second.first )
			return true;
		else
			return false;
	}
}
int main ()
{
	int T;
	cin >> T;
	REP( i, T )
	{
		string line;
		cin >> line;
		cout << "Case #" << i+1 << ":" << endl;
		int size = line.size();
		vector<pair<char,pair<int,int> > > Graph;
		int x = 2;
		int y = 1;
		int lenX = size+3;
		int lenY = y;
		REP( j, size )
		{
			lenY = max( lenY, y );
			char C = toSymbol( line[j] );
			cout << "C: " << C << endl;
			cout << "x: " << x << ". y: " << y << endl;
			Graph.push_back( make_pair( C, make_pair( x, y ) ) );
			if( C == '/' )
				x++, y++;
			else if( C == '_' )
				x++;
			else if( ( C == '\\' ) && (toSymbol( line[j-1] ) == '\\') )
				x++, y--;
			else
				x++;
		}
		sort( Graph.begin(), Graph.end(), comp );
		vector<pair<char,pair<int,int> > >::iterator it = Graph.begin(), itEnd = Graph.end();
		for( ; it!=itEnd; ++it )
		{
			cout << it->second.first << "," << it->second.second << endl;
		}
		lenY++;
		cout << lenX << endl;
		cout << lenY << endl;
	}
}
