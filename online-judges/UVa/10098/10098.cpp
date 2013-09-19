/* Alex Velazquez
 * Start: Fri May 11 20:52:45 EDT 2012
 * End  : Fri May 11 21:13:46 EDT 2012
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
#include <cstring>

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
	scanf( "%d", &T );
	REP( i, T )
	{
		char word[13];
		scanf( "%s\n", word );
		int wordLen = strlen( word );
		sort( word, word+wordLen );
		do
		{
			printf( "%s\n", word );
		}while( next_permutation( word, word+wordLen ) );
		printf( "\n" );
	}
}
