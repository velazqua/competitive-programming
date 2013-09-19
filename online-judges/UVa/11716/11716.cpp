/* Alex Velazquez
 * Start: Mon Feb 20 12:55:41 EST 2012
 * End  : Mon Feb 20 13:04:37 EST 2012
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
	int T;
	cin >> T;
	set<int> squares;
	for( int i=1; i*i<=10000; ++i )
		squares.insert( i*i );
	REP( i, T )
	{
		if( i == 0 ) cin.ignore();
		string line;
		getline( cin, line );
		int size = line.size();
		if( squares.count( size ) == 0 )
		{
			cout << "INVALID" << endl;
			continue;
		}
		int S = sqrt( size );
		string newLine = "";
		REP( j, S )
		{
			REP( k, size )
			{
				if( k%S == j )
					newLine += line[k];
			}
		}
		cout << newLine << endl;
	}
}
