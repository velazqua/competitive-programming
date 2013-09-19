/* Alex Velazquez
 * Start: Sun Jul 22 02:57:51 EDT 2012
 * End  : Sun Jul 22 03:05:45 EDT 2012
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
#define SZ(A)        int((A).size())
#define PB           push_back
#define FST(A)       (A).first
#define SEC(A)       (A).second
#define DEBUG        0

typedef long long int LL;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main ()
{
    unsigned int lim = 1000000, i, j;
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
	int size = SZ(P);
	int N;
	while( cin >> N )
	{
		if( !N ) 
			break;
		cout << N << ":" << endl;
		REP( i, size )
		{
			if( 2*P[i] > N )
			{
				cout << "NO WAY!" << endl;
				break;
			}
			if( !primes[N-P[i]] )
			{
				cout << P[i] << "+" << N-P[i] << endl;
				break;
			}
		} 
	}
}
