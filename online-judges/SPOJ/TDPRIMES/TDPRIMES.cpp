/* Alex Velazquez
 * Start: Sat Sep 29 23:34:07 EDT 2012
 * End  :
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
#include <bitset>

using namespace std;

#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()
#define SZ(A)        (A).size()
#define FST(A)       (A).first
#define SEC(A)       (A).second
#define DEBUG 0

typedef long long int LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main ()
{
	unsigned int lim = 50000000, i, j;
    bitset<50000001> primes;
    //bitset<50000001> primes2;
    lim += 1; 
    for (i = 2; i*i <= lim-1; i++)
        if (!primes[i])
            for (j = i * i; j <= lim-1; j += i)
                primes.set(j);
                //primes[j] = true;
	
	int p = 0;	
    for (i = 2; i <= lim-1; i++)
    {
	    if (!primes[i])
	    {
			++p;
			if( p % 100 == 1 )
				printf( "%d\n", i );
		}
	}		
}
