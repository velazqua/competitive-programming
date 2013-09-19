/* Alex Velazquez
 * Start: Mon Mar 26 22:23:14 EDT 2012
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
	vector<char> alphabet( 27 );
	alphabet[0] = 0;
	FOR( i, 1, 27 )
		alphabet[i] = 96+i;
	map<string,int> M;
	string X;
	int N = 1;
	REP( i, 27 )
	{
		X = "";
		X += alphabet[i]; 
		REP( j, 27 )
		{
			X += alphabet[j];
			REP( k, 27 )
			{
				X += alphabet[k];
				REP( l, 27 )
				{
					X += alphabet[l];
					REP( m, 27 ) 
					{
						X += alphabet[m];
						M[X] = N;
						++N;
					}
				}
			}
		}
	}
}
