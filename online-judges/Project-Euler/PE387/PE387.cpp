#include <iostream>
#include <vector>
#include <cmath>
#include <list>

using namespace std;

typedef long long LL;

#define LIMIT 10000000

int sumDigits( LL X )
{
	int summ = 0;
	while( X )
	{
		summ += X % 10;
		X /= 10LL;
	}
	return summ;
}

bool isPrime( LL N, vector<LL> &primes, vector<bool> &vP, int const& size )
{
	if( N <= LIMIT )
		return !vP[N];
	for( int i=0; primes[i]*primes[i]<= N; ++i )
		if( N % primes[i] == 0 )
			return false;
	return true;
}

int main ()
{
    int lim = LIMIT, i, j;
    lim += 1;
	vector<bool> primes( lim, false );
    for (i = 2; i*i <= lim-1; i++)
        if (!primes[i])
            for (j = i * i; j <= lim-1; j += i)
                primes[j] = true;
	
	vector<LL> P;
    for (LL i = 2; i <= lim-1; i++)
	    if (!primes[i])
			P.push_back( i );
			
	int sizePrimes = P.size();
	LL primeHarshad = 0LL;
	
	for( LL i=1LL; i<=9LL; ++i )
	{
		list<LL> L;
		L.push_back( i );
		for( int j=0; j<13; ++j )
		{
			list<LL> T;
			while( !L.empty() )
			{
				LL Xo = L.back();
				LL X = Xo * 10;
				L.pop_back();
				for( int k=0; k<=9; ++k )
				{
					LL Y = X + k;
					int sumDig = sumDigits( Y );
					if( Y % sumDig == 0 )
						T.push_back( Y );
					
					if( isPrime( Y, P, primes, sizePrimes ) && isPrime( Xo/sumDigits(Xo), P, primes, sizePrimes ) )
						primeHarshad += Y;
				}
			}
			L.splice( L.begin(), T );
		}
	}
	
	cout << primeHarshad << endl;
}
