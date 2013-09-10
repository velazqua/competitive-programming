#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>
#define NUM 10000000

using namespace std;

double ourLog = log( NUM );

int getMaxX( int X )
{
	return floor( ourLog/log( X ) );
}

int square( int x )
{
	return x*x;
}

int poww( int a, int b )
{
	if( b == 0 )
		return 1;
	if( b == 1 )
		return a;
	if( b%2 == 0 )
		return square( poww( a, b/2 ) );
	else
		return a*square( poww( a, (b-1)/2 ) );
}

int main(void)
{
    unsigned int lim = NUM/2, i, j;
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
	// precalculate all maximum x for which abs(10^7-P^x) is a minimum
	vector<int> maxX( size, 0 );
	for( int i=0; i<size; ++i )
	{
		maxX[i] = getMaxX( P[i] );
	}
	long long summ = 0LL;
	for( int i=0; i<size-1; ++i )
	{
		for( int j=i+1; j<size; ++j )
		{
			//cout << P[i] << " - " << P[j] << endl;
			if( P[i]*P[j] > NUM )
				break;
			int X = maxX[j];
			int diff = NUM;
			int lowest = 0;
			for( int k=1; k<=X; ++k )
			{
				int Y = ( ourLog-k*log( P[j] ) )/log( P[i] );
				int prod = poww( P[i], Y ) * poww( P[j], k );
				int D = abs( NUM-prod );
				//cout << poww( P[i], Y ) << "*" << poww( P[j], k ) << endl;
				if( prod <= NUM && D < diff && Y > 0 )
				{
					diff = D;
					lowest = prod;
				}
			}
			//cout << P[i] << "^x * " << P[j] << "^y = " << lowest << " " << X << endl;
			summ += lowest;
		}
	}
	
	cout << summ << endl;
}
