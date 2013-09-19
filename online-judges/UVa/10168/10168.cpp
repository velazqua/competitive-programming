/* Alex Velazquez
 * Start: Fri May 11 20:35:03 EDT 2012
 * End  : Tue Jul  3 19:39:43 EDT 2012
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

bool isPrime( int X, vector<bool>& primes, vector<int> &P, int size )
{
	if( X <= 1 )
		return false;
	if( X <= 3163 )
		return !primes[X];
	else
	{
		for( int i=0; i<size; ++i )
			if( X % P[i] == 0 )
				return false;
		return true;
	}
}

int main ()
{
    unsigned int lim = 3163, i, j;
    lim += 1;
	vector<bool> primes( lim, false );
    for (i = 2; i*i <= lim-1; i++)
        if (!primes[i])
            for (j = i * i; j <= lim-1; j += i)
                primes[j] = true;
	
	vector<int> P;
    for (i = 2; i <= lim-1; i++)
	    if (!primes[i])
			P.push_back( i );
	int size = P.size();
	int N;
	while( cin >> N )
	{
		if( N < 8 )
		{
			cout << "Impossible." << endl;
			continue;
		}
		if( N%2 == 0 )
		{
			cout << "2 2";
			N -= 4;
		}
		else
		{
			cout << "2 3";
			N -= 5;
		}
		for( int i=2; i<N; ++i )
		{
			if( isPrime( i, primes, P, size ) && isPrime( N-i, primes, P, size ) )
			{
				cout << " " << i << " " << N-i << endl;
				break;
			}
		}
	}
}
