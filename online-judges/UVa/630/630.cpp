/* Alex Velazquez
 * Start: Fri Feb 24 19:46:43 EST 2012
 * End  : Wed Feb 29 19:52:01 EST 2012
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
	REP( i, T )
	{
		if ( i != 0 ) cout << endl;
		int N;
		cin >> N;
		vector<string> dict( N );
		REP( j, N )
			cin >> dict[j];
		vector<string> dictP = dict;
		REP( j, N )
			sort( dictP[j].begin(), dictP[j].end() );
			
		string word;
		while( 1 )
		{
			cin >> word;
			if( word.compare( "END" ) == 0 )
				break;
			cout << "Anagrams for: " << word << endl;
			string originalWord = word;
			sort( word.begin(), word.end() );
			int c = 0;
			REP( k, N ) 
			{
				if( !word.compare( dictP[k] ) )
				{
					++c;
					if( c < 10 ) cout << "  ";
					else if( c < 100 ) cout << " ";
					cout << c << ") " << dict[k] << endl;
				}
			}
			if( c == 0 )
				cout << "No anagrams for: " << originalWord << endl; 
		}
	}
}
