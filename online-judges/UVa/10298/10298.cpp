/* Alex Velazquez
 * Start: Fri Mar 16 20:45:27 EDT 2012
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

int main ()
{
	string S;
	while( cin >> S )
	{
		if( !S.compare( "." ) )
			break;
		int size = S.size();
		bool looksGood = true;
		FOR( j, 1, size+1 )
		{
			string X = S.substr( 0, j );
			looksGood = true;
			for( int k=0; k<size; k+=j )
			{
				if( X.compare( S.substr( k, j ) ) )
				{
					looksGood = false;
					break;
				}
			}
			if( looksGood ) 
			{
				cout << size/j << endl;
				break;
			}
		}
	}
}
