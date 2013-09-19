/* Alex Velazquez
 * Start: Sun Feb 19 18:18:43 EST 2012
 * End  : Sun Feb 19 18:50:51 EST 2012
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

using namespace std;

typedef long long int LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

bool isVowel ( char c )
{
	if( c == 'a' || c == 'e' || c == 'i'
				|| c == 'o' || c == 'u' || c == 'y' )	
		return true;
	else
		return false;
}

int main ()
{
	string line;
	while( getline( cin, line ) )
	{
		if( !line.compare( "e/o/i" ) ) break;
		string tokens;
		stringstream newLine( line );
		int k = 0;
		vector<int> H( 3, 0 );
		while( getline( newLine, tokens, '/' ) )
		{
			int size = tokens.size();
			bool w = false;
			REP( i, size )
			{
				if( w && isVowel( tokens[i] ) )
				{
					continue;
				}
				else if( !w && isVowel( tokens[i] ) )
				{
					w = true;
					H[k]++;
				}
				else if( w && !isVowel( tokens[i] ) )
				{
					w = false;
				}
				else
				{
					w = false;
				}
			}
			++k;
		}
		if( H[0] != 5 )
			cout << "1" << endl;
		else if( H[1] != 7 )
			cout << "2" << endl;
		else if( H[2] != 5 )
			cout << "3" << endl;
		else
			cout << "Y" << endl;
	}
}
