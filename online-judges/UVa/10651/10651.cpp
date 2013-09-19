/* Alex Velazquez
 * Start: Mon Feb 20 13:10:00 EST 2012
 * End  : Mon Feb 20 13:36:12 EST 2012
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

int countPebbles( string S )
{
	int c = 0;
	REP( i, 12 )
		if( S[i] == 'o' )
			++c;
	return c;
}

int main ()
{
	int T;
	cin >> T;
	REP( i, T )
	{
		string board;
		cin >> board;
		deque<string> B;
		B.push_back( board );
		int minn = 12;
		while( 1 )
		{
			if( B.size() == 0 )
				break;
			string curr = B[0];
			B.pop_front();
			//cout << "curr     : " << curr << endl;
			size_t f = 0;
			f = curr.find( "-oo", f );
			bool first = false;
			while( f != string::npos  )
			{
				first = true;
				int i = f;
				curr[i] = 'o';
				curr[i+1] = curr[i+2] = '-';
				B.push_back( curr );
				//cout << "Inserting: " << curr << endl;
				curr[i] = '-';
				curr[i+1] = curr[i+2] = 'o';
				f = curr.find( "-oo", f+1 );
			}
			f = 0;
			f = curr.find( "oo-", f );
			bool second = false;
			while( f != string::npos  )
			{
				second = true;
				int i = f;
				curr[i+2] = 'o';
				curr[i] = curr[i+1] = '-';
				B.push_back( curr );
				//cout << "Inserting: " << curr << endl;
				curr[i+2] = '-';
				curr[i] = curr[i+1] = 'o';
				f = curr.find( "oo-", f+1 );	
			}
			if( !first && !second )
			{
				minn = min( minn, countPebbles( curr ) );
			}
		}
		cout << minn << endl;
	}
}
