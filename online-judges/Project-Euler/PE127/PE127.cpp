#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef unsigned long long ULL;

bool isPrime( int N )
{
	if( N%2 == 0 ) return false;
	for( int i=3; i*i<=N; ++i )
		if( N%i == 0 )	
			return false;
	return true;
}

int rad( int N, vector<int> &P )
{
	set<int> factors;
	for( int i=0; N != 1; ++i )
	{
		while( N != 1 && !( N%P[i] ) )
			N /= P[i], factors.insert( P[i] );
	}
	int X = 1;
	for( set<int>::iterator it=factors.begin();it!=factors.end();++it)
		X *= *it;
	return X;
}

int gcd( int a, int b )
{
	int t;
	while( b != 0 )
	{
		t = b;
		b = a%b;
		a = t;
	}
	return a;
}

int main ()
{
	vector<int> primes;
	primes.push_back( 2 );
	int LIMIT = 120000;
	for( int i=3; i<=LIMIT; ++i )
		if( isPrime( i ) )
			primes.push_back( i );
	
	ULL counter = 0ULL;
	vector<int> R( LIMIT+1, -1 );
	for( int c=3; c<LIMIT; ++c )
	{
		int k = ( !(c%2) ) ? 2 : 1; 
		for( int a=1; c-a>=a; a+=k )
		{
			int b = c-a;
			if( gcd(a,b)==1 && gcd(a,c)==1 && gcd(b,c)==1 )
			{
				if( R[a] == -1 ) 
					R[a] = rad( a, primes );
				if( R[b] == -1 ) 
					R[b] = rad( b, primes );
				if( R[c] == -1 ) 
					R[c] = rad( c, primes );
		
				if( R[a]*R[b]*R[c] < c )
				{
					counter += c;
					//cout << a << " " << b << " " << c << endl;
				}
			}
		}
	}
	cout << counter << endl;
}
