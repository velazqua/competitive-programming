/* Alex Velazquez
 * Start: Tue Jan 24 20:36:15 EST 2012
 * End  : Tue Jan 24 22:17:00 EST 2012
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

bool isOk( int& i, int& j, int const& N )
{
	return ( i>=0 && i<N && j>=0 && j<N ) ? true : false ;
}

int findNumber( vector<string>& mines, int const& i, int const& j, int const& N )
{
	int x[8] = {-1,0,1,-1,1,-1,0,1};
	int y[8] = {1,1,1,0,0,-1,-1,-1};
	int num = 0;
	REP( k, 8 )
	{
		int xMove = i+x[k];
		int yMove = j+y[k];
		if( isOk( xMove, yMove, N ) && mines[xMove][yMove] == '*' )
			++num;
	}
	return num;
}

int main ()
{
	int T;
	cin >> T;
	REP( i, T )
	{
		int N;
		cin >> N;
		vector<string> mines( N );
		REP( j, N )
			cin >> mines[j];
		vector<string> touched( N );
		REP( j, N )
			cin >> touched[j];
		vector<pair<int,int> > mineLocations;
		REP( j, N )
			REP( k, N )
				if( mines[j][k] == '*' )
					mineLocations.push_back( make_pair( j, k ) );
		bool touchedMine = false;
		for( vector<pair<int,int> >::iterator it=mineLocations.begin();
											  it!=mineLocations.end();
											  ++it )
		{
			if( touched[it->first][it->second] == 'x' )
			{
				touchedMine = true;
				break;
			}
		}

		REP( j, N )
		{
			REP( k, N )
			{
				if( touchedMine && mines[j][k] == '*' )
					cout << '*';
				else if( touched[j][k] == 'x' )
					cout << findNumber( mines, j, k, N );
				else
					cout << '.';
			}
			cout << endl;
		}
		if( i != T-1 )
			cout << endl;
	}
}
