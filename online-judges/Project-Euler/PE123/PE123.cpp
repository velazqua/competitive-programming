#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long LL;

LL bigMod( int a, int b, LL m )
{
	LL X = 1LL;
	for( int i=0; i<b; ++i )
		X *= a, X %= m;
	return X;
}

int main ()
{
    int lim = 1000000, i, j;
    lim += 1;
	vector<bool> primes( lim, false );
    for (i = 2; i*i <= lim-1; i++)
        if (!primes[i])
            for (j = i * i; j <= lim-1; j += i)
                primes[j] = true;
	
	vector<LL> P;
    for (i = 2; i <= lim-1; i++)
	    if (!primes[i])
			P.push_back( i );
	
	int size = P.size();
	for( int i=0; i<size; ++i )
	{
		LL p = P[i]*P[i];
		LL A = bigMod( P[i]-1, i+1, p );
		LL B = bigMod( P[i]+1, i+1, p );
		LL R = ( A%p + B%p )%p;
		if( R > 10000000000LL ) 
		{
			cout << i+1 << endl;
			break;
		}
	}
}
