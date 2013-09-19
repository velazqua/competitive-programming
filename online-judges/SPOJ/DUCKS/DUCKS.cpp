/* Alex Velazquez
 * Start: Sun Apr 15 20:10:35 EDT 2012
 * End  : Sun Apr 15 20:28:46 EDT 2012
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
#define DEBUG 0

typedef long long int LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main ()
{
	int T;
	cin >> T;
	REP( i, T )
	{
		if( i == 0 ) cin.ignore();
		string line;
		getline( cin, line );
		int size = line.size();
		bool found = false;
		vector<bool> D( 5, false );
		REP( c, size )
		{
			if( line[c] == 'D' ) D[0] = true;
			else if( line[c] == 'u' ) D[1] = true;
			else if( line[c] == 'c' ) D[2] = true;
			else if( line[c] == 'k' ) D[3] = true;
			else if( line[c] == 'y' ) D[4] = true;
			else if( line[c] == '.' ) continue;
			else
			{
				if( D[0] && D[1] && D[2] && D[3] && D[4] )
					cout << "DUCKY IS HERE!" << endl;
				else
					cout << "NO DUCKY!" << endl;
				found = true;
				break;
			}
		}
		if( !found )
		{
			//cout << D[0]<< D[1] << D[2] << D[3] << D[4] << endl;
			if( D[0] && D[1] && D[2] && D[3] && D[4] )
				cout << "DUCKY IS HERE!" << endl;
			else
				cout << "NO DUCKY!" << endl;
		}
	}
}
